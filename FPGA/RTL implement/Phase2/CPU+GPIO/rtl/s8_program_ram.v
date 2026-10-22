// =============================================================================
// Module : s8_program_ram
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 7.1 and 9
//
// PHASE-2 COPY. Identical to rtl/s8_program_ram.v except for the two new
// parameters INIT_EN / INIT_FILE and the guarded initial block below.
// Rationale: Phase 2 ("first hardware") has no boot loader and no host link,
// so the only way to get an application into program RAM on the board is a
// synthesis-time image. INIT_EN = 0 (the default) reproduces the Phase-1
// behaviour exactly; INIT_EN = 1 makes XST initialise the inferred BRAM from
// an $readmemh file (INIT_00..INIT_3F), which is the documented XST feature
// for pre-loading block RAM. The loader port stays the only *run-time* way to
// write program RAM, so spec 7.1 ("no write port to the application") holds.
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
// image, or before INIT_FILE has pre-loaded it. If neither happened the
// contents are undefined - programs must never rely on zero-filled memory
// (spec 6.7: 0x0000 is ADD R0,R0, not NOP).
//
// Synthesis: infers 4 x RAMB16BWER (2048x9 mode, 2 wide x 2 deep);
// verify "inferred BRAM, not distributed" in the XST report (spec 15.4).
// =============================================================================

module s8_program_ram #(
    parameter INIT_EN   = 0,  // 0 = no power-up image (Phase-1 behaviour)
    parameter INIT_FILE = ""  // $readmemh source, one 16-bit hex word/line
) (
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

    // -- Phase 2: synthesis-time image (XST: block-RAM init from file).
    // -- Guarded by a constant parameter so the default build has no file
    // -- dependency at all.
    initial begin
        if (INIT_EN != 0)
            $readmemh(INIT_FILE, mem);
    end

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
