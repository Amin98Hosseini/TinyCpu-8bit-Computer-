// =============================================================================
// Testbench  : tb_s8_cpu_programs
// Tests      : s8_cpu + s8_program_ram + s8_data_ram + s8_bus (Phase-1 core)
// Spec       : Sections 6.7 (golden words), 6.9 (worked programs), 7 (memory
//              map), 8 (FSM), 16.1 (tb_s8_cpu_programs row)
//
// Setup: 50 MHz clock (Farad-1 oscillator, spec 5/B2). The MMIO peripherals
// (gpio/uart_regs, built in later phases) are replaced by tb_mmio_stub at
// the bottom of this file: 4-bit GPIO + a UART loopback with RX_VALID /
// TX_READY status semantics, so the real UART-echo program already runs.
//
// Programs are loaded through the loader port (sel_load=1) while the CPU
// is held in reset - exactly the ownership rule of spec 7.1. cpu_en is
// tied to ~sel_load: the CPU samples `instr` only in FETCH_WAIT, so this
// is functionally identical to a fetch strobe (documented in the guide).
//
// Scenarios (each ends in a checked state; any FAIL line = real bug):
//   T1 GPIO blink-seed (spec 6.9.1): LED holds 1, JMP loop never traps.
//   T2 Main functional program (36 words, see guide): every ISA group +
//      CALL/RET byte order + taken branch + HALT. Final regs/SP/RAM/GPIO/
//      flags pinned to reference-model values.
//   T3 HALT + resume_i: HALT, resume, run on, HALT again.
//   T4 TRAP on opcode 0xE; stays trapped; reset clears.
//   T5 TRAP on non-zero R-format reserved bits (0x0007).
//   T6 Stack overflow: 17x PUSH -> TRAP, SP frozen at 0xE0, M[0xDF] intact.
//   T7 Stack underflow: POP on empty stack -> TRAP, SP stays 0xF0.
//   T8 UART echo (spec 6.9.2) against the loopback stub: 0x55 comes back.
//
// Expected result: "tb_s8_cpu_programs: PASSED (<N> checks, 0 errors)".
// =============================================================================

`timescale 1ns / 1ps

module tb_s8_cpu_programs;

    reg clk;
    reg rst;                 // active high (sync-deassert shape, TB-held)
    reg resume_tb;           // drives CPU resume_i
    initial clk = 0;
    always #10 clk = ~clk;   // 50 MHz Farad-1 clock (spec 5, B2)

    // ---- CPU <-> memories/bus wiring ----
    wire [15:0] prom_instr;
    wire [11:0] cpu_paddr;
    wire [7:0]  bus_addr, bus_wdata, bus_rdata;
    wire        bus_re, bus_we;
    wire        halted, trapped;

    reg         sel_load;
    reg  [11:0] load_addr;
    reg  [15:0] load_data;
    reg         load_we;

    s8_cpu u_cpu (
        .clk        (clk),
        .rst        (rst),
        .resume_i   (resume_tb),
        .instr      (prom_instr),
        .instr_addr (cpu_paddr),
        .bus_addr   (bus_addr),
        .bus_re     (bus_re),
        .bus_we     (bus_we),
        .bus_wdata  (bus_wdata),
        .bus_rdata  (bus_rdata),
        .bus_ready  (1'b1),          // v1: every target answers in 1 cycle
        .halted     (halted),
        .trapped    (trapped)
    );

    s8_program_ram u_prom (
        .clk       (clk),
        .cpu_addr  (cpu_paddr),
        .cpu_en    (~sel_load),      // loader owns port while sel_load=1
        .instr     (prom_instr),
        .load_addr (load_addr),
        .load_data (load_data),
        .load_we   (load_we),
        .sel_load  (sel_load)
    );

    wire [7:0] ram_addr, ram_wdata, ram_rdata;
    wire       ram_re, ram_we;

    s8_data_ram u_dram (
        .clk   (clk),
        .addr  (ram_addr),
        .re    (ram_re),
        .we    (ram_we),
        .wdata (ram_wdata),
        .rdata (ram_rdata)
    );

    wire       mmio_re, mmio_we;
    wire [2:0] mmio_port;
    wire [7:0] mmio_wdata, mmio_rdata;

    s8_bus u_bus (
        .addr      (bus_addr),
        .re        (bus_re),
        .we        (bus_we),
        .wdata     (bus_wdata),
        .rdata     (bus_rdata),
        .ready     (),
        .ram_addr  (ram_addr),
        .ram_re    (ram_re),
        .ram_we    (ram_we),
        .ram_wdata (ram_wdata),
        .ram_rdata (ram_rdata),
        .mmio_re   (mmio_re),
        .mmio_we   (mmio_we),
        .mmio_port (mmio_port),
        .mmio_wdata(mmio_wdata),
        .mmio_rdata(mmio_rdata)
    );

    reg  [3:0] switches;
    reg  [7:0] rx_inject;
    reg        rx_inject_we;
    wire [3:0] gpio_out;
    wire [7:0] tx_byte;
    wire       tx_valid;

    tb_mmio_stub u_mmio (
        .clk         (clk),
        .rst         (rst),
        .mmio_re     (mmio_re),
        .mmio_we     (mmio_we),
        .mmio_port   (mmio_port),
        .mmio_wdata  (mmio_wdata),
        .mmio_rdata  (mmio_rdata),
        .gpio_out    (gpio_out),
        .switches    (switches),
        .rx_inject   (rx_inject),
        .rx_inject_we(rx_inject_we),
        .tx_byte     (tx_byte),
        .tx_valid    (tx_valid)
    );

    integer checks, errors;
    integer k, t;

    // ============ helpers ============
    task prog_write;
        input [11:0] a;
        input [15:0] d;
        begin
            @(negedge clk);
            sel_load = 1; load_addr = a; load_data = d; load_we = 1;
            @(negedge clk);
            load_we = 0;
            @(negedge clk);
            sel_load = 0;
        end
    endtask

    task reset_cpu;
        begin
            rst = 1;
            repeat (4) @(posedge clk);
            rst = 0;
            @(posedge clk);
        end
    endtask

    task run_cycles;
        input integer n;
        integer c;
        begin
            for (c = 0; c < n; c = c + 1) @(posedge clk);
        end
    endtask

    // run until halted or trapped, bounded (spec invariant 4)
    task run_until_stop;
        input integer maxc;
        begin
            t = 0;
            while (!halted && !trapped && (t < maxc)) begin
                @(posedge clk);
                t = t + 1;
            end
        end
    endtask

    task check;
        input cond;
        input [8*48:1] name;
        begin
            checks = checks + 1;
            if (!cond) begin
                errors = errors + 1;
                $display("FAIL %0s", name);
            end
        end
    endtask

    task check_reg;
        input [2:0] idx;
        input [7:0] exp;
        input [8*32:1] name;
        begin
            checks = checks + 1;
            if (u_cpu.u_regfile.regs[idx] !== exp) begin
                errors = errors + 1;
                $display("FAIL %0s: R%0d=%02h, exp %02h",
                         name, idx, u_cpu.u_regfile.regs[idx], exp);
            end
        end
    endtask

    task check_dmem;
        input [7:0] addr;
        input [7:0] exp;
        input [8*32:1] name;
        begin
            checks = checks + 1;
            if (u_dram.mem[addr] !== exp) begin
                errors = errors + 1;
                $display("FAIL %0s: M[%02h]=%02h, exp %02h",
                         name, addr, u_dram.mem[addr], exp);
            end
        end
    endtask

    task uart_inject;
        input [7:0] b;
        begin
            @(negedge clk);
            rx_inject = b; rx_inject_we = 1;
            @(negedge clk);
            rx_inject_we = 0;
        end
    endtask

    // global watchdog: no test may hang the simulator (spec invariant 4)
    initial begin
        #2000000;
        $display("FAIL: global watchdog timeout - a test hung");
        $finish;
    end

    // ============ test sequence ============
    initial begin
        checks = 0; errors = 0;
        rst = 1; resume_tb = 0; sel_load = 0;
        load_we = 0; load_addr = 0; load_data = 0;
        switches = 4'hA; rx_inject = 0; rx_inject_we = 0;

        // ---------------- T1: GPIO blink-seed (spec 6.9.1) ----------------
        prog_write(0, 16'h1001); // LDI R0,1
        prog_write(1, 16'h5000); // OUT GPIO_OUT,R0
        prog_write(2, 16'h4002); // JMP 0x002 (self loop)
        reset_cpu;
        run_cycles(120);
        check(gpio_out === 4'h1, "T1 gpio holds 1");
        check(halted === 1'b0, "T1 not halted");
        check(trapped === 1'b0, "T1 not trapped");
        run_cycles(200);
        check(gpio_out === 4'h1, "T1 gpio still 1 (JMP loop alive)");
        $display("T1 done: gpio=%h halted=%b trapped=%b", gpio_out, halted, trapped);

        // ---------------- T2: main functional program -------------------
        // (words verified by the independent JS reference model)
        prog_write( 0, 16'h1005); // LDI R0,5
        prog_write( 1, 16'h1203); // LDI R1,3
        prog_write( 2, 16'h0040); // ADD R0,R1        -> R0=8
        prog_write( 3, 16'h0048); // SUB R0,R1        -> R0=5
        prog_write( 4, 16'h0050); // AND R0,R1        -> R0=1
        prog_write( 5, 16'h0058); // OR  R0,R1        -> R0=3
        prog_write( 6, 16'h0060); // XOR R0,R1        -> R0=0,Z=1
        prog_write( 7, 16'h14FF); // LDI R2,0xFF
        prog_write( 8, 16'h2401); // ADDI R2,1        -> R2=0,Z=1,C=1
        prog_write( 9, 16'h16A5); // LDI R3,0xA5
        prog_write(10, 16'h268F); // ANDI R3,0x0F     -> R3=0x05
        prog_write(11, 16'h2730); // ORI  R3,0x30     -> R3=0x35
        prog_write(12, 16'h1810); // LDI R4,0x10
        prog_write(13, 16'h8700); // ST R3,[R4]       -> M[0x10]=0x35
        prog_write(14, 16'h1A00); // LDI R5,0
        prog_write(15, 16'h3B00); // LD R5,[R4]       -> R5=0x35
        prog_write(16, 16'h1C01); // LDI R6,1
        prog_write(17, 16'h1E81); // LDI R7,0x81
        prog_write(18, 16'hDF80); // SHL R7,R6        -> R7=0x02,C=1
        prog_write(19, 16'hDF88); // SHR R7,R6        -> R7=0x01,C=0
        prog_write(20, 16'hDF90); // ROL R7,R6        -> R7=0x02
        prog_write(21, 16'hDF98); // ROR R7,R6        -> R7=0x01
        prog_write(22, 16'hBA00); // PUSH R5          -> SP=0xEF
        prog_write(23, 16'h1A00); // LDI R5,0
        prog_write(24, 16'hCA00); // POP R5           -> R5=0x35,SP=0xF0
        prog_write(25, 16'h7022); // CALL 34
        prog_write(26, 16'h5000); // OUT GPIO_OUT,R0  -> gpio=2
        prog_write(27, 16'hA440); // IN R2,GPIO_IN    -> R2=0x0A
        prog_write(28, 16'h258A); // CMPI R2,0x0A     -> Z=1
        prog_write(29, 16'h6002); // JZ 32 (taken, skips 30)
        prog_write(30, 16'h14EE); // LDI R2,0xEE      (skipped)
        prog_write(31, 16'h4021); // JMP 33           (skipped)
        prog_write(32, 16'h1442); // LDI R2,0x42
        prog_write(33, 16'hF000); // HALT
        prog_write(34, 16'h2002); // sub: ADDI R0,2  -> R0=2
        prog_write(35, 16'h9000); // RET
        reset_cpu;
        run_until_stop(2000);
        check(halted === 1'b1, "T2 halted");
        check(trapped === 1'b0, "T2 not trapped");
        check_reg(0, 8'h02, "T2 R0");
        check_reg(1, 8'h03, "T2 R1");
        check_reg(2, 8'h42, "T2 R2 (branch taken)");
        check_reg(3, 8'h35, "T2 R3");
        check_reg(4, 8'h10, "T2 R4");
        check_reg(5, 8'h35, "T2 R5");
        check_reg(6, 8'h01, "T2 R6");
        check_reg(7, 8'h01, "T2 R7");
        check(u_cpu.sp === 8'hF0, "T2 SP back to F0");
        check_dmem(8'h10, 8'h35, "T2 M[0x10]");
        // CALL byte order (design D1): high nibble at [SP-1], low at [SP-2]
        check_dmem(8'hEF, 8'h00, "T2 stack hi nibble");
        check_dmem(8'hEE, 8'h1A, "T2 stack lo byte (ret=26)");
        check(gpio_out === 4'h2, "T2 gpio=2");
        check({u_cpu.flag_z, u_cpu.flag_c, u_cpu.flag_n, u_cpu.flag_o} === 4'b0000,
              "T2 flags ZCN O=0 (last writer LDI)");
        $display("T2 done: R0=%02h R2=%02h SP=%02h gpio=%h",
                 u_cpu.u_regfile.regs[0], u_cpu.u_regfile.regs[2],
                 u_cpu.sp, gpio_out);

        // ---------------- T3: HALT + resume ------------------------------
        prog_write(0, 16'h1001); // LDI R0,1
        prog_write(1, 16'hF000); // HALT
        prog_write(2, 16'h1002); // LDI R0,2
        prog_write(3, 16'hF000); // HALT
        reset_cpu;
        run_until_stop(500);
        check(halted === 1'b1, "T3 first HALT");
        check_reg(0, 8'h01, "T3 R0=1 before resume");
        @(negedge clk); resume_tb = 1;
        repeat (2) @(posedge clk); // resume pulse (>=1 cycle)
        @(negedge clk); resume_tb = 0;
        run_until_stop(500);
        check(halted === 1'b1, "T3 second HALT");
        check(trapped === 1'b0, "T3 not trapped");
        check_reg(0, 8'h02, "T3 R0=2 after resume");
        $display("T3 done: resume works, R0=%02h",
                 u_cpu.u_regfile.regs[0]);

        // ---------------- T4: TRAP on opcode 0xE -------------------------
        prog_write(0, 16'hE000); // reserved opcode
        prog_write(1, 16'h1001); // must never execute
        reset_cpu;
        run_cycles(30);
        check(trapped === 1'b1, "T4 trapped on 0xE");
        check(halted === 1'b0, "T4 halt bit not set by trap");
        check_reg(0, 8'h00, "T4 R0 untouched");
        run_cycles(20);
        check(trapped === 1'b1, "T4 trap latched (no self-exit)");
        reset_cpu;
        check(trapped === 1'b0, "T4 reset clears trap");
        $display("T4 done");

        // ---------------- T5: TRAP on reserved R-bits --------------------
        prog_write(0, 16'h0007); // ADD R0,R0 with low bits 111
        reset_cpu;
        run_cycles(30);
        check(trapped === 1'b1, "T5 trapped on reserved bits");
        $display("T5 done");

        // ---------------- T6: stack overflow (17x PUSH) -------------------
        u_dram.mem[223] = 8'hAA; // M[0xDF] sentinel: must survive the fault
        for (k = 0; k < 17; k = k + 1)
            prog_write(k, 16'hB000); // PUSH R0
        reset_cpu;
        run_until_stop(1000);
        check(trapped === 1'b1, "T6 trapped on 17th PUSH");
        check(u_cpu.sp === 8'hE0, "T6 SP frozen at 0xE0");
        check_dmem(8'hDF, 8'hAA, "T6 M[0xDF] unmodified by fault");
        $display("T6 done: SP=%02h", u_cpu.sp);

        // ---------------- T7: stack underflow (POP empty) ----------------
        prog_write(0, 16'hC000); // POP R0, SP=0xF0
        reset_cpu;
        run_cycles(30);
        check(trapped === 1'b1, "T7 trapped on empty POP");
        check(u_cpu.sp === 8'hF0, "T7 SP stays 0xF0");
        $display("T7 done");

        // ---------------- T8: UART echo (spec 6.9.2) ----------------------
        prog_write(0, 16'hA2C0); // start: IN R1,UART_STATUS
        prog_write(1, 16'h2281); // ANDI R1,0x01 (RX_VALID)
        prog_write(2, 16'h60FD); // JZ start
        prog_write(3, 16'hA100); // IN R0,UART_DATA (pop)
        prog_write(4, 16'hA2C0); // wait: IN R1,UART_STATUS
        prog_write(5, 16'h2282); // ANDI R1,0x02 (TX_READY)
        prog_write(6, 16'h60FD); // JZ wait
        prog_write(7, 16'h5800); // OUT UART_DATA,R0
        prog_write(8, 16'h4000); // JMP start
        reset_cpu;
        uart_inject(8'h55);
        t = 0;
        while (!tx_valid && (t < 2000)) begin
            @(posedge clk);
            t = t + 1;
        end
        check(tx_valid === 1'b1, "T8 byte echoed");
        check(tx_byte === 8'h55, "T8 echo value 0x55");
        check(trapped === 1'b0, "T8 not trapped");
        $display("T8 done: echoed %02h", tx_byte);

        // ---------------- summary ----------------
        if (errors == 0)
            $display("tb_s8_cpu_programs: PASSED (%0d checks, 0 errors)", checks);
        else
            $display("tb_s8_cpu_programs: FAILED (%0d checks, %0d errors)", checks, errors);
        $finish;
    end

endmodule

// =============================================================================
// Phase-1 MMIO stub (TESTBENCH ONLY - replaced by s8_gpio + uart_regs in
// Phases 2-3). Models ports 0-4 with the exact spec 7.3 semantics the CPU
// depends on: GPIO_OUT/DIR read-write, GPIO_IN from TB switches,
// UART_STATUS {TX_READY=1, RX_VALID}, UART_DATA pop-on-read loopback.
// Ports 5-7 read 0x00. Reserved 0xF8-0xFF never arrive (s8_bus filters).
// =============================================================================
module tb_mmio_stub (
    input        clk,
    input        rst,
    input        mmio_re,
    input        mmio_we,
    input  [2:0] mmio_port,
    input  [7:0] mmio_wdata,
    output reg [7:0] mmio_rdata,
    output reg [3:0] gpio_out,
    input  [3:0] switches,
    input  [7:0] rx_inject,
    input        rx_inject_we,
    output reg [7:0] tx_byte,
    output reg       tx_valid
);

    reg [3:0] gpio_dir;
    reg       rx_valid;
    reg [7:0] rx_byte;

    always @(posedge clk) begin
        if (rst) begin
            gpio_out <= 4'h0;
            gpio_dir <= 4'hF; // spec 7.3 reset default: all outputs
            rx_valid <= 1'b0;
            rx_byte  <= 8'h00;
            tx_byte  <= 8'h00;
            tx_valid <= 1'b0;
        end else begin
            if (rx_inject_we) begin // TB: a byte "arrives" on the RX line
                rx_byte  <= rx_inject;
                rx_valid <= 1'b1;
            end
            if (mmio_we) begin
                case (mmio_port)
                    3'd0: gpio_out <= mmio_wdata[3:0];
                    3'd2: gpio_dir <= mmio_wdata[3:0];
                    // UART loopback: TX byte is captured AND re-presented
                    // as RX so the echo program can run unmodified.
                    3'd4: begin
                        tx_byte  <= mmio_wdata;
                        tx_valid <= 1'b1;
                        rx_byte  <= mmio_wdata;
                        rx_valid <= 1'b1;
                    end
                    default: ;
                endcase
            end
            // UART_DATA read pops the RX FIFO and clears sticky bits
            if (mmio_re && (mmio_port == 3'd4))
                rx_valid <= 1'b0;
        end
    end

    always @* begin
        case (mmio_port)
            3'd0:    mmio_rdata = {4'b0000, gpio_out};
            3'd1:    mmio_rdata = {4'b0000, switches};
            3'd2:    mmio_rdata = {4'b0000, gpio_dir};
            // UART_STATUS: bit1 TX_READY=1, bit0 RX_VALID (err bits 0 here)
            3'd3:    mmio_rdata = {6'b000000, 1'b1, rx_valid};
            3'd4:    mmio_rdata = rx_byte;
            default: mmio_rdata = 8'h00; // ports 5-7
        endcase
    end

endmodule
