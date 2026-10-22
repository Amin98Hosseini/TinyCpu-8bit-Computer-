// =============================================================================
// Module : s8_data_ram
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 7.2 and 9
//
// Function: 240 x 8-bit data RAM at data-space addresses 0x00-0xEF
// (software convention: 0x00-0xDF variables, 0xE0-0xEF stack region).
// Synchronous read semantics identical to program RAM: address/write commit
// at the clock edge, read data valid the following edge.
//
// The chip select / address-range check lives in s8_bus (addresses >= 0xF0
// never reach this module). Like program RAM, the array carries no reset
// (distributed-RAM inference; stack discipline re-initialises SP to 0xF0).
//
// Synthesis: infers distributed RAM (~30 LUTs); 0 block-RAM usage.
// =============================================================================

module s8_data_ram (
    input        clk,
    input  [7:0] addr,   // valid range 0x00-0xEF (guaranteed by s8_bus)
    input        re,      // read enable (sync read; data next edge)
    input        we,      // write enable
    input  [7:0] wdata,  // write data
    output reg [7:0] rdata // read data, valid one cycle after re+addr
);

    reg [7:0] mem [0:239];

    always @(posedge clk) begin
        if (we)
            mem[addr] <= wdata;
        if (re)
            rdata <= mem[addr];
    end

    // -- Simulation-only range assertion: the bus must never route an MMIO
    // -- address (0xF0+) into the RAM array (spec 7.2 / 9).
    // synthesis translate_off
    always @(posedge clk) begin
        if ((re || we) && (addr > 8'hEF)) begin
            $display("ERROR @%0t: s8_data_ram: address %02h outside 0x00-0xEF",
                     $time, addr);
            $finish;
        end
    end
    // synthesis translate_on

endmodule
