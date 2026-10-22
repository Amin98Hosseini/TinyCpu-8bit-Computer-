// =============================================================================
// Module : s8_mode_latch
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 9 (s8_top row),
//          11.1 (MODE semantics) and 5/B6 (Farad-1 DIP0 substitute)
//
// Function: synchronize the raw MODE strap and LATCH it once, early in the
// reset sequence. MODE is a boot strap, not a run-time switch (spec 11.1):
// once latched, later pin changes are ignored until the next hard reset.
//
// Farad-1 wiring (spec 5/B6): there is no dedicated MODE pin; DIP0 (p84) is
// pulled up on the board, so an OPEN switch reads 1 and a CLOSED switch reads
// 0. The spec's logical polarity is "1 = programming", which for this board
// means closed = programming, open (the all-off default) = run application.
// That inversion is the MODE_INVERT parameter, and it is applied BEFORE the
// synchronizer so the rest of the design only ever sees the logical value.
//
// Latch timing: `rst` is the output of s8_reset_sync. After it is released,
// s1/s2 need two clock edges to present a settled sample, so the value is
// captured on the third edge (`settle == 2`) - i.e. the design honours the
// "sample+synchronize MODE, >=2 clk settle" requirement of spec 11.2 with a
// full clock of margin. `latched` goes high with `mode` and stays high until
// the next reset.
// =============================================================================

module s8_mode_latch (
    input  clk,
    input  rst,       // internal synchronous reset (active high)
    input  mode_raw,  // raw strap pin (Farad-1: DIP0 on p84)
    output reg mode,  // latched LOGICAL mode: 1 = programming, 0 = run app
    output reg latched
);

    parameter MODE_INVERT = 1; // Farad-1: DIP0 open = 1 = run application

    reg       s1, s2;          // 2-flop synchronizer
    reg [1:0] settle;

    always @(posedge clk) begin
        if (rst) begin
            s1      <= 1'b0;
            s2      <= 1'b0;
            settle  <= 2'd0;
            mode    <= 1'b0;
            latched <= 1'b0;
        end else begin
            // polarity: logical value of the strap as wired on this board
            s1 <= MODE_INVERT ? ~mode_raw : mode_raw;
            s2 <= s1;

            if (!latched) begin
                if (settle == 2'd2) begin // third edge after reset release
                    mode    <= s2;        // s2 has seen two complete clocks
                    latched <= 1'b1;
                end else begin
                    settle <= settle + 2'd1;
                end
            end
            // latched == 1: the strap is now ignored until the next reset
        end
    end

endmodule
