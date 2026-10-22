// =============================================================================
// Module : s8_mmio
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 7.3 (MMIO map),
//          9 (s8_gpio / s8_top rows), 6.6 (HALT/TRAP), 11.1 (soft reset)
//
// Function: the Phase-2 MMIO register file. It sits behind s8_bus (which has
// already decoded 0xF0-0xF7 into mmio_re/mmio_we/mmio_port) and implements
// exactly two things:
//
//   Port 0 GPIO_OUT     R/W  -> s8_gpio (reset 0x00)
//   Port 1 GPIO_IN      R    -> 2FF synchronized pads
//   Port 2 GPIO_DIR     R/W  -> s8_gpio (reset 0x0F)
//   Port 6 CPU_CONTROL  R/W  -> W bit0 = resume pulse, bit1 = soft-reset pulse
//                               R bit0 = HALTED, bit1 = TRAPPED, bit2 = RUNNING
//   Ports 3,4,5,7            -> unimplemented in Phase 2: read 0x00, writes
//                               ignored (spec 7.3: benign, no trap)
//
// Port 3/4 (UART) arrive in Phase 3 (uart_regs) and port 5 (BOOT_STATUS) with
// the boot controller in Phase 4; both then join this read mux, keeping a
// single place where the port map is decoded.
//
// CPU_CONTROL.resume exists because HALT must be exited from OUTSIDE the core
// (Phase-1 design decision D4: a halted CPU executes nothing, so it cannot
// write the register that resumes it). In Phase 2 nothing on the board drives
// that write yet - the Phase-2 testbench forces the resume net directly, which
// is exactly what D4 prescribes, and Phase 3/4 wire uart_regs / the boot
// controller in its place. The register and its pulse are implemented now so
// the decode, the status bits and the CPU handshake are already verified.
//
// Soft reset (bit1) restarts the application: it pulses the CPU's internal
// reset (PC/SP/flags/registers cleared, program RAM untouched), which is the
// Phase-2 form of "re-enter the boot flow with latched MODE" (spec 11.1).
// =============================================================================

module s8_mmio (
    input        clk,
    input        rst,        // active high, async assert

    // ---- CPU bus side (decoded by s8_bus) ----
    // No read strobe: Phase-2 reads have no side effects, so the read mux is
    // purely combinational (same shape as the RAM read path in s8_bus).
    // Phase 3 re-introduces mmio_re for uart_regs' pop-on-read semantics.
    input        mmio_we,
    input  [2:0] mmio_port,
    input  [7:0] mmio_wdata,
    output reg [7:0] mmio_rdata,

    // ---- CPU status (read side of CPU_CONTROL) ----
    input        halted,
    input        trapped,

    // ---- CPU_CONTROL write side ----
    output reg   resume,     // 1-cycle pulse -> s8_cpu.resume_i
    output reg   soft_rst,   // 1-cycle pulse -> CPU internal reset

    // ---- pads (through s8_gpio) ----
    input  [3:0] pad_in,
    output [3:0] pad_out,
    output [3:0] pad_oe,
    output [3:0] gpio_out,   // exported for GPIO_OUT readback
    output [3:0] gpio_dir,   // exported for GPIO_DIR readback
    output [3:0] pad_in_sync // exported for GPIO_IN readback
);

    // ---- write strobes (one port each) ----
    wire out_we = mmio_we & (mmio_port == 3'd0);
    wire dir_we = mmio_we & (mmio_port == 3'd2);
    wire ctl_we = mmio_we & (mmio_port == 3'd6);

    // ---- GPIO ports 0-2 ----
    s8_gpio u_gpio (
        .clk         (clk),
        .rst         (rst),
        .out_wdata   (mmio_wdata[3:0]),
        .out_we      (out_we),
        .dir_wdata   (mmio_wdata[3:0]),
        .dir_we      (dir_we),
        .gpio_out    (gpio_out),
        .gpio_dir    (gpio_dir),
        .pad_in_sync (pad_in_sync),
        .pad_in      (pad_in),
        .pad_out     (pad_out),
        .pad_oe      (pad_oe)
    );

    // ---- CPU_CONTROL write side: exactly one-cycle pulses ----
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            resume   <= 1'b0;
            soft_rst <= 1'b0;
        end else begin
            resume   <= ctl_we & mmio_wdata[0];
            soft_rst <= ctl_we & mmio_wdata[1];
        end
    end

    // ---- read mux (combinational, one cycle, spec 8.3) ----
    // Unimplemented ports read 0x00 and ignore writes (spec 7.3).
    wire running = ~halted & ~trapped;

    always @* begin
        case (mmio_port)
            3'd0:    mmio_rdata = {4'h0, gpio_out};                  // GPIO_OUT
            3'd1:    mmio_rdata = {4'h0, pad_in_sync};               // GPIO_IN
            3'd2:    mmio_rdata = {4'h0, gpio_dir};                  // GPIO_DIR
            3'd6:    mmio_rdata = {5'b0, running, trapped, halted};   // CPU_CONTROL
            default: mmio_rdata = 8'h00;                              // 3,4,5,7
        endcase
    end

endmodule
