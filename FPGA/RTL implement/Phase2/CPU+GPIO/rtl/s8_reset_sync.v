// =============================================================================
// Module : s8_reset_sync
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 2 ("Reset policy"),
//          8.4 ("Clock and reset") and 17 rule 9
//
// Function: the single reset synchronizer for the whole design. The Farad-1
// reset button S2 (p87, active low, RC-debounced) is asynchronous to clk, so
// it may only ever reach sequential logic through this block:
//
//   rst_n low          -> rst asserted ASYNCHRONOUSLY (no clock needed)
//   rst_n high         -> rst released exactly two clk edges later, i.e.
//                         synchronously, with no recovery/removal race
//
// The two-flop shift register is pre-loaded with 2'b00 by the asynchronous
// clear, so after release it takes two clock edges before sync[1] becomes 1.
// `rst` (active high) is what s8_cpu, s8_regfile, s8_mmio and s8_gpio use;
// `rst_n_i` is the synchronized active-low form (kept for status/waveforms).
// =============================================================================

module s8_reset_sync (
    input  clk,
    input  rst_n,   // raw board reset, active low, asynchronous
    output rst,     // internal reset, active high: async assert / sync deassert
    output rst_n_i  // synchronized active-low reset (inverse of rst)
);

    reg [1:0] sync;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            sync <= 2'b00;          // asynchronous assert
        else
            sync <= {sync[0], 1'b1}; // synchronous, 2-edge deassert
    end

    assign rst     = ~sync[1];
    assign rst_n_i =  sync[1];

endmodule
