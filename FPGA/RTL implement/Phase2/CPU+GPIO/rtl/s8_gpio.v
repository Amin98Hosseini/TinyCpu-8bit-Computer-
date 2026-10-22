// =============================================================================
// Module : s8_gpio
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 7.3 (ports 0-2)
//          and 9 (s8_gpio row)
//
// Function: the 4-bit GPIO block behind MMIO ports 0 (GPIO_OUT), 1 (GPIO_IN)
// and 2 (GPIO_DIR). Register semantics and reset values are spec 7.3:
//
//   GPIO_OUT : R/W, bits [3:0] drive the pads where DIR = 1, reset 0x00
//   GPIO_DIR : R/W, bit = 1 -> pad is an output,             reset 0x0F
//   GPIO_IN  : R,   bits [3:0] = two-flop synchronized pads, no write path
//
// The reset value DIR = 0x0F keeps the Farad-1 LED demo working straight out
// of reset (spec 7.3) and guarantees that no pad is floating while the core
// is held in reset in programming mode.
//
// pad_in is sampled through a 2-flop synchronizer (spec 17 rule 9: all
// asynchronous inputs are synchronized; no combinational path from a pad
// into CPU control logic). pad_out/pad_oe are the raw pad drivers; s8_top
// turns them into the IOBUF tristate.
//
// On the Farad-1 in Phase 2 all four pads are LEDs (p105/p104/p102/p101,
// active high, 390 ohm to GND), so an undriven pad reads back low - that is
// what the Phase-2 testbench models with a weak pulldown.
// =============================================================================

module s8_gpio (
    input        clk,
    input        rst,        // active high, async assert (from s8_reset_sync)

    // register write side (from s8_mmio)
    input  [3:0] out_wdata,
    input        out_we,     // CPU wrote port 0
    input  [3:0] dir_wdata,
    input        dir_we,     // CPU wrote port 2

    // register read side (to s8_mmio)
    output reg [3:0] gpio_out,
    output reg [3:0] gpio_dir,
    output     [3:0] pad_in_sync, // 2FF synchronized GPIO_IN value

    // pad side (to s8_top)
    input  [3:0] pad_in,
    output [3:0] pad_out,
    output [3:0] pad_oe
);

    reg [3:0] pin_s1, pin_s2;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            gpio_out <= 4'h0;  // spec 7.3 reset value
            gpio_dir <= 4'hF;  // all outputs (keeps the LED demo working)
            pin_s1   <= 4'h0;
            pin_s2   <= 4'h0;
        end else begin
            if (out_we) gpio_out <= out_wdata;
            if (dir_we) gpio_dir <= dir_wdata;

            // two-flop pad synchronizer (GPIO_IN reads pin_s2)
            pin_s1 <= pad_in;
            pin_s2 <= pin_s1;
        end
    end

    assign pad_in_sync = pin_s2;
    assign pad_out     = gpio_out;
    assign pad_oe      = gpio_dir;

endmodule
