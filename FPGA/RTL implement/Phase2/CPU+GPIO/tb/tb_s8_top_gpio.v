// =============================================================================
// Testbench  : tb_s8_top_gpio
// Tests      : phase2/rtl/s8_top + s8_reset_sync + s8_mode_latch + s8_gpio
//              + s8_mmio (+ the copied Phase-1 CPU/RAM/bus chain)
// Spec       : Sections 6.9.1 (GPIO demo), 7.3 (MMIO map), 8.4 (reset),
//              9 (s8_top/s8_gpio rows), 11.1 (MODE), 16.1/16.4 (Phase-2 gate),
//              17 rules 1/3/9
//
// This is the Phase-2 integration testbench. It instantiates the REAL top
// level - the same file that is synthesised into the bitstream - and drives it
// from the board side only: the 50 MHz clock (p85), the active-low reset
// button (p87), the DIP0 strap (p84) and the four LED pads
// (p105/p104/p102/p101). Nothing inside the design is pre-loaded through a
// test-only port; the application comes from the same INIT_FILE image the
// bitstream uses, which is what makes this a hardware-level test.
//
// Pad model: gpio<3:0> are LEDs (390 ohm + LED to GND, active high). Pads 3:2
// additionally have a WEAK testbench driver so the DIR/tristate behaviour can
// be exercised without ever fighting the FPGA's strong output driver:
//   tb_w = 2'bzz -> pads 3:2 undriven (FPGA released them: the net reads z)
//   tb_w = 2'b00 -> pads 3:2 pulled low  (models the LED load, a read reads 0)
//   tb_w = 2'b11 -> pads 3:2 pulled high (models an external source, reads 1)
// A weak driver loses to the FPGA's strong driver, so there is never a
// contention X, and the tristate behaviour of s8_gpio is measured directly.
//
// Test groups (each prints a one-line summary; the final line is the verdict):
//   T1 power-up image        INIT_FILE really pre-loads program RAM
//   T2 programming boot      reset synchronizer timing, MODE latch, CPU held
//   T3 run boot (GPIO demo)  LED0 lights from the image, strap ignored while
//                            running, asynchronous reset assertion, next boot
//                            re-latches the closed strap
//   T4 GPIO registers/pads   GPIO_OUT/GPIO_IN/GPIO_DIR, pin readback, tristate
//   T5 HALT + CPU_CONTROL    status read, forced resume (Phase-1 decision D4)
//   T6 TRAP path             reserved opcode traps, TRAPPED status readable
//   T7 CPU_CONTROL soft rst  bit1 restarts the application deterministically
//
// Expected result: "tb_s8_top_gpio: PASSED (<N> checks, 0 errors)".
// See phase2/PHASE2_GPIO_BRINGUP.md section 5 for the expected transcript.
// =============================================================================

`timescale 1ns / 1ps

module tb_s8_top_gpio;

    // ------------------------------------------------------------------
    // Board-side clock: Farad-1 50.000 MHz oscillator on p85 (20 ns period)
    // ------------------------------------------------------------------
    reg clk;
    initial clk = 1'b0;
    always #10 clk = ~clk;

    // ------------------------------------------------------------------
    // Board-side inputs / pads
    // ------------------------------------------------------------------
    reg        rst_n;    // p87 button S2, active low
    reg        mode_raw; // p84 DIP0: 1 = open (board default), 0 = closed
    tri  [3:0] gpio;     // p105/p104/p102/p101 LEDs

    // weak testbench pull on pads 3:2 (see header)
    reg [1:0] tb_w;
    assign (weak1, weak0) gpio[3:2] = tb_w;

    // ------------------------------------------------------------------
    // Device under test: the synthesised top level, unmodified.
    // INIT_FILE is the same image copy the ISE build uses.
    // ------------------------------------------------------------------
    s8_top #(
        .MODE_INVERT (1),
        .INIT_EN     (1),
        .INIT_FILE   ("../prog/gpio_demo.hex")
    ) u_top (
        .clk    (clk),
        .rst_n  (rst_n),
        .mode   (mode_raw),
        .gpio   (gpio)
    );

    // ------------------------------------------------------------------
    // Bookkeeping
    // ------------------------------------------------------------------
    integer checks, errors, t, k, soft_rst_count;

    // Bounded watchdog: no test may hang the simulator (spec 17 rule 4)
    initial begin
        #2000000;
        $display("FAIL: global watchdog timeout - a test hung");
        $display("tb_s8_top_gpio: FAILED (watchdog)");
        $finish;
    end

    // ==================================================================
    // Check helpers
    // ==================================================================
    task check;                       // generic 1-bit condition
        input cond;
        input [8*64:1] name;
        begin
            checks = checks + 1;
            if (cond !== 1'b1) begin
                errors = errors + 1;
                $display("FAIL %0s", name);
            end
        end
    endtask

    task check4;
        input [3:0] got;
        input [3:0] exp;
        input [8*64:1] name;
        begin
            checks = checks + 1;
            if (got !== exp) begin
                errors = errors + 1;
                $display("FAIL %0s: got %b, exp %b", name, got, exp);
            end
        end
    endtask

    task check8;
        input [7:0] got;
        input [7:0] exp;
        input [8*64:1] name;
        begin
            checks = checks + 1;
            if (got !== exp) begin
                errors = errors + 1;
                $display("FAIL %0s: got %02h, exp %02h", name, got, exp);
            end
        end
    endtask

    task check12;
        input [11:0] got;
        input [11:0] exp;
        input [8*64:1] name;
        begin
            checks = checks + 1;
            if (got !== exp) begin
                errors = errors + 1;
                $display("FAIL %0s: got %03h, exp %03h", name, got, exp);
            end
        end
    endtask

    // ==================================================================
    // Board-side stimulus helpers
    // ==================================================================
    task hold_reset;                  // assert reset, CPU held in reset
        begin
            @(negedge clk);
            rst_n = 1'b0;
            repeat (2) @(posedge clk);
        end
    endtask

    task release_reset;               // release with a chosen raw strap
        input raw;
        begin
            @(negedge clk);
            mode_raw = raw;
            rst_n    = 1'b1;
            // 2 clocks reset synchronizer + 3 clocks MODE settle/latch + margin
            repeat (6) @(posedge clk);
        end
    endtask

    task run_until_halt;              // run until halted/trapped, bounded
        input integer maxc;
        begin
            t = 0;
            while ((u_top.halted !== 1'b1) && (u_top.trapped !== 1'b1) &&
                   (t < maxc)) begin
                @(posedge clk);
                t = t + 1;
            end
        end
    endtask

    task wait_pads;                   // run until the pads reach exp, bounded
        input [3:0] exp;
        input integer maxc;
        begin
            t = 0;
            while ((gpio !== exp) && (t < maxc)) begin
                @(posedge clk);
                t = t + 1;
            end
        end
    endtask

    // ==================================================================
    // Test sequence
    // ==================================================================
    initial begin
        checks   = 0;
        errors   = 0;
        rst_n    = 1'b0;
        mode_raw = 1'b1;
        tb_w     = 2'bzz;
        repeat (4) @(posedge clk);

        // ---------------------------------------------------------------
        // T1 - power-up image (INIT_FILE -> program RAM)
        // The bitstream and this simulation load the same file, so if these
        // three words are right the board will hold the same program.
        // ---------------------------------------------------------------
        check(u_top.u_prom.mem[0] === 16'h1001, "T1 mem[0] = LDI R0,1");
        check(u_top.u_prom.mem[1] === 16'h5000, "T1 mem[1] = OUT GPIO_OUT,R0");
        check(u_top.u_prom.mem[2] === 16'h4002, "T1 mem[2] = JMP 0x002");
        $display("T1 done: power-up image present");

        // ---------------------------------------------------------------
        // T2 - programming boot: reset synchronizer + MODE latch + CPU held
        // DIP0 closed (raw 0) + MODE_INVERT = 1 -> logical MODE = 1.
        // Reset timing is measured on negedges so the checks are free of
        // clock-edge races.
        // ---------------------------------------------------------------
        hold_reset;
        mode_raw = 1'b0;                       // DIP0 closed = programming
        @(negedge clk);
        check(u_top.rst === 1'b1, "T2 rst asserted while rst_n low");
        rst_n = 1'b1;                          // release mid-cycle
        @(posedge clk); #1;                    // 1st edge: stage 1 loads
        check(u_top.rst === 1'b1, "T2 rst still high after the 1st edge");
        @(posedge clk); #1;                    // 2nd edge: stage 2 loads
        check(u_top.rst === 1'b0, "T2 rst released on the 2nd clk edge");
        repeat (4) @(posedge clk);             // MODE settle + latch
        check(u_top.mode_latched === 1'b1, "T2 MODE latched = programming");
        check(u_top.cpu_rst === 1'b1, "T2 CPU held in reset by MODE");
        check12(u_top.u_cpu.pc, 12'h000, "T2 PC held at 0");
        check4(u_top.u_mmio.gpio_dir, 4'hF, "T2 GPIO_DIR reset value 0x0F");
        check4(u_top.u_mmio.gpio_out, 4'h0, "T2 GPIO_OUT reset value 0x00");
        check4(gpio, 4'b0000, "T2 pads driven low, LEDs off");
        repeat (300) @(posedge clk);           // long enough for any program
        check12(u_top.u_cpu.pc, 12'h000, "T2 PC still 0 after 300 clk");
        check4(gpio, 4'b0000, "T2 LEDs still off after 300 clk");
        check(u_top.halted === 1'b0, "T2 halted stays 0 in programming");
        check(u_top.trapped === 1'b0, "T2 trapped stays 0 in programming");
        @(negedge clk);
        mode_raw = 1'b1;                       // open DIP0 while still held
        repeat (50) @(posedge clk);
        check(u_top.mode_latched === 1'b1, "T2 latched MODE ignores strap change");
        check(u_top.cpu_rst === 1'b1, "T2 CPU still held after strap change");
        check4(gpio, 4'b0000, "T2 LEDs still off after strap change");
        $display("T2 done: programming boot holds the CPU, strap latched");

        // ---------------------------------------------------------------
        // T3 - run boot: the GPIO demo from the power-up image
        // ---------------------------------------------------------------
        hold_reset;
        release_reset(1'b1);                   // DIP0 open = run application
        check(u_top.mode_latched === 1'b0, "T3 MODE latched = run application");
        check(u_top.cpu_rst === 1'b0, "T3 CPU released from reset");
        wait_pads(4'b0001, 200);
        check4(gpio, 4'b0001, "T3 LED0 lights from the demo image");
        check4(u_top.u_mmio.gpio_out, 4'h1, "T3 GPIO_OUT = 0x01 after OUT");
        check(u_top.halted === 1'b0, "T3 demo does not halt");
        check(u_top.trapped === 1'b0, "T3 demo does not trap");
        repeat (500) @(posedge clk);
        check4(gpio, 4'b0001, "T3 LED0 holds (JMP self-loop alive)");
        check12(u_top.u_cpu.pc, 12'h002, "T3 PC parked at the JMP (0x002)");
        check(u_top.trapped === 1'b0, "T3 still no trap after 500 clk");
        @(negedge clk);
        mode_raw = 1'b0;                       // close DIP0 while running
        repeat (50) @(posedge clk);
        check(u_top.mode_latched === 1'b0, "T3 running: latched MODE unchanged");
        check(u_top.cpu_rst === 1'b0, "T3 running: strap does not reset CPU");
        check4(gpio, 4'b0001, "T3 running: LED0 stays on");
        @(negedge clk);
        rst_n = 1'b0;                          // asynchronous assertion
        #1;                                    // no clock edge in between
        check(u_top.rst === 1'b1, "T3 rst asserts asynchronously");
        check4(gpio, 4'b0000, "T3 pads clear asynchronously");
        check(u_top.halted === 1'b0, "T3 halt bit cleared by reset");
        repeat (4) @(posedge clk);
        release_reset(1'b0);                   // next boot: closed strap
        check(u_top.mode_latched === 1'b1, "T3 next boot latches closed strap");
        check(u_top.cpu_rst === 1'b1, "T3 next boot holds the CPU again");
        check4(gpio, 4'b0000, "T3 next boot keeps the LEDs off");
        $display("T3 done: GPIO demo runs from the image; MODE is a boot strap");

        // ---------------------------------------------------------------
        // T4 - GPIO_OUT / GPIO_IN / GPIO_DIR at the pins
        //   0: 1005  LDI  R0, 0x05
        //   1: 5000  OUT  GPIO_OUT, R0    ; pads 3:0 = 0101
        //   2: A200  IN   R1, GPIO_OUT    ; R1 = 0x05
        //   3: 1403  LDI  R2, 0x03
        //   4: 5480  OUT  GPIO_DIR, R2    ; pads 3:2 become inputs
        //   5: 5000  OUT  GPIO_OUT, R0
        //   6: A640  IN   R3, GPIO_IN     ; pad readback
        //   7: F000  HALT
        // Run A: pads 3:2 pulled low  -> R3 = 0x01
        // Run B: pads 3:2 pulled high -> R3 = 0x0D
        // ---------------------------------------------------------------
        hold_reset;
        tb_w = 2'b00;
        u_top.u_prom.mem[0] = 16'h1005;
        u_top.u_prom.mem[1] = 16'h5000;
        u_top.u_prom.mem[2] = 16'hA200;
        u_top.u_prom.mem[3] = 16'h1403;
        u_top.u_prom.mem[4] = 16'h5480;
        u_top.u_prom.mem[5] = 16'h5000;
        u_top.u_prom.mem[6] = 16'hA640;
        u_top.u_prom.mem[7] = 16'hF000;
        release_reset(1'b1);
        run_until_halt(2000);
        check(u_top.halted === 1'b1, "T4A program halted");
        check8(u_top.u_cpu.u_regfile.regs[1], 8'h05, "T4A IN GPIO_OUT = 0x05");
        check4(u_top.u_mmio.gpio_dir, 4'h3, "T4A GPIO_DIR = 0x03");
        check4(u_top.u_mmio.gpio_out, 4'h5, "T4A GPIO_OUT = 0x05");
        check8(u_top.u_cpu.u_regfile.regs[3], 8'h01, "T4A GPIO_IN = 0x01");
        check4(gpio, 4'b0001, "T4A pads = 0001");
        tb_w = 2'bzz;                          // prove the pads really released
        #10;
        check(gpio[3] === 1'bz, "T4A pad3 released to z by DIR=0");
        check(gpio[2] === 1'bz, "T4A pad2 released to z by DIR=0");
        $display("T4A done: GPIO registers + tristate verified");

        hold_reset;
        tb_w = 2'b11;                          // same program, pads 3:2 high
        release_reset(1'b1);
        run_until_halt(2000);
        check(u_top.halted === 1'b1, "T4B program halted");
        check8(u_top.u_cpu.u_regfile.regs[1], 8'h05, "T4B IN GPIO_OUT = 0x05");
        check8(u_top.u_cpu.u_regfile.regs[3], 8'h0D, "T4B GPIO_IN = 0x0D");
        check4(gpio, 4'b1101, "T4B pads = 1101");
        $display("T4B done: synchronized pad readback verified");

        // ---------------------------------------------------------------
        // T5 - HALT and CPU_CONTROL (read status, resume from outside)
        //   0: A380  IN  R1, CPU_CONTROL  ; R1 = 0x04 RUNNING
        //   1: 1001  LDI R0, 1
        //   2: F000  HALT
        //   3: 1002  LDI R0, 2
        //   4: 5000  OUT GPIO_OUT, R0     ; pads = 0010
        //   5: F000  HALT
        // Phase-2 note (D4): a halted core cannot write port 6, and no UART
        // or boot controller exists yet, so the testbench forces the resume
        // net - the same "resume comes from outside the core" contract that
        // Phase 3/4 will satisfy with uart_regs / s8_boot_ctrl.
        // ---------------------------------------------------------------
        hold_reset;
        tb_w = 2'bzz;
        u_top.u_prom.mem[0] = 16'hA380;
        u_top.u_prom.mem[1] = 16'h1001;
        u_top.u_prom.mem[2] = 16'hF000;
        u_top.u_prom.mem[3] = 16'h1002;
        u_top.u_prom.mem[4] = 16'h5000;
        u_top.u_prom.mem[5] = 16'hF000;
        release_reset(1'b1);
        run_until_halt(500);
        check(u_top.halted === 1'b1, "T5 first HALT");
        check8(u_top.u_cpu.u_regfile.regs[0], 8'h01, "T5 R0 = 1 before resume");
        check8(u_top.u_cpu.u_regfile.regs[1], 8'h04, "T5 CPU_CONTROL read = RUNNING");
        check8(u_top.u_mmio.mmio_rdata, 8'h01, "T5 CPU_CONTROL read shows HALTED");
        check4(gpio, 4'b0000, "T5 LEDs still off while halted");
        force u_top.resume_cpu = 1'b1;
        repeat (3) @(posedge clk);
        release u_top.resume_cpu;
        run_until_halt(500);
        check(u_top.halted === 1'b1, "T5 second HALT reached after resume");
        check(u_top.trapped === 1'b0, "T5 no trap after resume");
        check8(u_top.u_cpu.u_regfile.regs[0], 8'h02, "T5 R0 = 2 after resume");
        check4(gpio, 4'b0010, "T5 LED1 on after resume");
        $display("T5 done: HALT/status/resume verified");

        // ---------------------------------------------------------------
        // T6 - TRAP path through the top level
        //   0: A380  IN  R1, CPU_CONTROL  ; R1 = 0x04
        //   1: E000  (reserved opcode)    ; TRAP
        //   2: 1001  (must never execute)
        // ---------------------------------------------------------------
        hold_reset;
        u_top.u_prom.mem[0] = 16'hA380;
        u_top.u_prom.mem[1] = 16'hE000;
        u_top.u_prom.mem[2] = 16'h1001;
        release_reset(1'b1);
        run_until_halt(500);
        check(u_top.trapped === 1'b1, "T6 reserved opcode traps");
        check(u_top.halted === 1'b0, "T6 trap does not set the halt bit");
        check8(u_top.u_cpu.u_regfile.regs[0], 8'h00, "T6 R0 untouched");
        check8(u_top.u_cpu.u_regfile.regs[1], 8'h04, "T6 CPU_CONTROL read = RUNNING");
        check8(u_top.u_mmio.mmio_rdata, 8'h02, "T6 CPU_CONTROL read shows TRAPPED");
        check4(gpio, 4'b0000, "T6 pads untouched by the trap");
        repeat (20) @(posedge clk);
        check(u_top.trapped === 1'b1, "T6 trap is latched (no self-exit)");
        $display("T6 done: TRAP path verified");

        // ---------------------------------------------------------------
        // T7 - CPU_CONTROL soft reset (bit1) restarts the application
        //   0: 1005  LDI  R0, 0x05
        //   1: 5000  OUT  GPIO_OUT, R0    ; pads = 0101
        //   2: 1202  LDI  R1, 0x02
        //   3: 5C40  OUT  CPU_CONTROL, R1 ; bit1 -> soft reset
        //   4: 100F  LDI  R0, 0x0F        ; must never retire
        //   5: 5000  OUT  GPIO_OUT, R0    ; would light all four LEDs
        //   6: F000  HALT
        // After a soft reset the core starts at 0 again, so the pads stay at
        // 0101 forever; if bit1 did nothing, instructions 4/5 would run and
        // the pads would become 1111.
        // ---------------------------------------------------------------
        hold_reset;
        u_top.u_prom.mem[0] = 16'h1005;
        u_top.u_prom.mem[1] = 16'h5000;
        u_top.u_prom.mem[2] = 16'h1202;
        u_top.u_prom.mem[3] = 16'h5C40;
        u_top.u_prom.mem[4] = 16'h100F;
        u_top.u_prom.mem[5] = 16'h5000;
        u_top.u_prom.mem[6] = 16'hF000;
        release_reset(1'b1);
        // Count the soft-reset pulses over 400 clocks: each restart produces
        // exactly one, so a dead bit1 would count 0 and a working one many.
        soft_rst_count = 0;
        for (k = 0; k < 400; k = k + 1) begin
            @(posedge clk);
            if (u_top.u_mmio.soft_rst === 1'b1)
                soft_rst_count = soft_rst_count + 1;
        end
        check(soft_rst_count >= 5, "T7 soft reset fires repeatedly (>=5 restarts)");
        check4(gpio, 4'b0101, "T7 pads stay 0101 (restart before instr 4)");
        check(u_top.halted === 1'b0, "T7 core keeps running after soft reset");
        check(u_top.trapped === 1'b0, "T7 soft reset does not trap");
        $display("T7 soft-reset pulses counted: %0d", soft_rst_count);
        $display("T7 done: CPU_CONTROL soft reset verified");

        // ---------------------------------------------------------------
        // T8 - CPU_CONTROL resume pulse generation (port 6, bit0)
        //   0: 1201  LDI R1, 1
        //   1: 5C40  OUT CPU_CONTROL, R1  ; bit0 -> one resume pulse
        //   2: F000  HALT                 ; the pulse must not disturb a
        //                                 ; running core
        // T5 forced the resume net (the only way to leave HALT before Phase 3),
        // so this is what proves the register write really produces the pulse
        // that Phase 3/4 will rely on.
        // ---------------------------------------------------------------
        hold_reset;
        u_top.u_prom.mem[0] = 16'h1201;
        u_top.u_prom.mem[1] = 16'h5C40;
        u_top.u_prom.mem[2] = 16'hF000;
        release_reset(1'b1);
        soft_rst_count = 0;                    // reuse as the resume counter
        t = 0;
        while ((u_top.halted !== 1'b1) && (t < 500)) begin
            @(posedge clk);
            if (u_top.u_mmio.resume === 1'b1)
                soft_rst_count = soft_rst_count + 1;
            t = t + 1;
        end
        check(u_top.halted === 1'b1, "T8 program halts after the write");
        check(soft_rst_count == 1, "T8 CPU_CONTROL bit0 makes exactly one resume pulse");
        check(u_top.trapped === 1'b0, "T8 stray resume does not disturb the core");
        $display("T8 done: resume pulses counted: %0d", soft_rst_count);

        // ---------------------------------------------------------------
        // Verdict
        // ---------------------------------------------------------------
        if (errors == 0)
            $display("tb_s8_top_gpio: PASSED (%0d checks, 0 errors)", checks);
        else
            $display("tb_s8_top_gpio: FAILED (%0d checks, %0d errors)", checks, errors);
        $finish;
    end

endmodule
