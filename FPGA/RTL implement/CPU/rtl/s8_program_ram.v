// =============================================================================
// Module : s8_program_ram
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 7.1 and 9
//
// Function: 4096 x 16-bit program store (8 KiB), word-addressed by the
// 12-bit PC. Synchronous read: address is registered at the clock edge,
// data is valid on the following edge (the CPU FSM accounts for this with
// its FETCH_REQ / FETCH_WAIT states).
//
// Single read port, shared between the CPU fetch path and the boot loader
// (sel_load = 1 gives the loader the port while the CPU is held in reset).
// Read-first behaviour: a simultaneous write+read of the same address
// returns the OLD word (natural result of the non-blocking assignments
// below). Only the loader writes program RAM in v1 - no application write
// port exists.
//
// NOTE on reset: RAM arrays carry no reset (standard practice for BRAM
// inference on Spartan-6; XST infers block RAM only for reset-free arrays).
// The CPU never fetches before the loader (or testbench) has written the
// image. Contents before first write are undefined - programs must never
// rely on zero-filled memory (spec 6.7: 0x0000 is ADD R0,R0, not NOP).
//
// Synthesis: infers 4 x RAMB16BWER (2048x9 mode, 2 wide x 2 deep);
// verify "inferred BRAM, not distributed" in the XST report (spec 15.4).
// =============================================================================

module s8_program_ram (
    input         clk,
    // CPU fetch port (owner while an application runs)
    input  [11:0] cpu_addr,  // word address = PC
    input         cpu_en,    // fetch enable (high during FETCH_REQ)
    output reg [15:0] instr, // word valid one cycle after cpu_en+cpu_addr
    // Loader port (owner only while the CPU is held in reset)
    input  [11:0] load_addr, // word address
    input  [15:0] load_data, // word to program
    input         load_we,   // program strobe
    input         sel_load   // 1 = loader owns the port
);

    reg [15:0] mem [0:4095];

    wire [11:0] raddr = sel_load ? load_addr : cpu_addr;

    always @(posedge clk) begin
        if (sel_load && load_we)
            mem[load_addr] <= load_data;
        if (cpu_en || sel_load)
            instr <= mem[raddr];
    end

    // -- Simulation-only ownership assertion (spec 7.1: the mux must never
    // -- grant both ports in the same cycle).
    // synthesis translate_off
    always @(posedge clk) begin
        if (cpu_en && sel_load) begin
            $display("ERROR @%0t: s8_program_ram: cpu_en and sel_load both high",
                     $time);
            $finish;
        end
    end
    // synthesis translate_on

endmodule
