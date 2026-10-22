// =============================================================================
// Module : s8_regfile
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 8.1 and 9
//
// Function: 8 x 8-bit general-purpose register file (R0-R7, none hardwired
// to zero). Two asynchronous read ports, one synchronous write port.
// Synchronous active-high reset clears all registers (simulation and
// deterministic bring-up; the array is 8 bytes so inference cost is nil).
//
// Simulation aid: the testbench reaches the registers by hierarchical
// reference (tb.dut.regs[i]); no extra debug ports are added, per spec 9.
// =============================================================================

module s8_regfile (
    input        clk,
    input        rst,       // synchronous, active high: clears R0-R7
    input  [2:0] raddr_a,  // async read port A (normally rd / OUT: rs)
    input  [2:0] raddr_b,  // async read port B (normally rs)
    input  [2:0] waddr,    // sync write address (rd)
    input  [7:0] wdata,    // sync write data
    input        we,        // sync write enable
    output [7:0] rdata_a,
    output [7:0] rdata_b
);

    reg [7:0] regs [0:7];
    integer i;

    // Synchronous write + reset. Read-during-write returns the OLD value
    // on the async ports (write commits at the clock edge); the CPU never
    // reads a register in the same cycle it writes it (tb_s8_regfile
    // verifies this explicitly).
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i < 8; i = i + 1)
                regs[i] <= 8'h00;
        end else if (we) begin
            regs[waddr] <= wdata;
        end
    end

    assign rdata_a = regs[raddr_a];
    assign rdata_b = regs[raddr_b];

endmodule
