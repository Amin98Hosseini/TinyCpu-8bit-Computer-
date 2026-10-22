// =============================================================================
// Module : s8_bus
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 7.2, 7.3,
//          8.3 and 9
//
// Function: data-space address decoder + read mux between the CPU and the
// data RAM / MMIO peripherals. Purely combinational.
//
// Decode rule (spec 7.2, single rule):
//   mmio = addr[7] & addr[6] & addr[5] & addr[4]   (i.e. addr >= 0xF0)
//
// PHASE-2 FIX: the Phase-1 copy dropped the addr[4] term, so 0xE0-0xEF
// (the STACK region of data RAM) also decoded as MMIO and was aliased onto
// ports 0-7: every PUSH/CALL/RET write went to a non-existent peripheral
// instead of the stack, and RET returned to the wrong address. Spec 7.2 is
// explicit: 0x00-0xEF is RAM, 0xF0-0xFF is MMIO. With this term restored the
// Phase-1 CPU testbench passes (see section 6 of the Phase-2 doc).
// Only port addresses 0xF0-0xF7 are valid MMIO targets; 0xF8-0xFF are
// reserved: reads return 0x00, writes are ignored, no trap (spec 7.2).
//
// IN/OUT use the identical hardware decode as LD/ST (spec 6.4): the CPU
// presents address 0xF0|port, so no special-casing exists here.
//
// ready: v1 peripherals answer in one cycle (RAM sync-read latency is
// absorbed by the CPU MEM state; MMIO targets are combinational), so ready
// is tied high. The CPU still implements the ready-wait loop so the
// interface stays future-proof (spec 8.3).
// =============================================================================

module s8_bus (
    // CPU side (spec 8.3)
    input  [7:0] addr,    // data-space address from CPU
    input        re,      // read enable
    input        we,      // write enable
    input  [7:0] wdata,   // write data from CPU
    output [7:0] rdata,   // read data to CPU
    output       ready,   // transfer acknowledge (tied 1 in v1)
    // Data-RAM side (0x00-0xEF)
    output [7:0] ram_addr,
    output       ram_re,
    output       ram_we,
    output [7:0] ram_wdata,
    input  [7:0] ram_rdata,
    // MMIO side (0xF0-0xF7 -> ports 0-7)
    output       mmio_re,
    output       mmio_we,
    output [2:0] mmio_port,  // 0 GPIO_OUT ... 6 CPU_CONTROL, 7 reserved
    output [7:0] mmio_wdata,
    input  [7:0] mmio_rdata
);

    wire mmio     = addr[7] & addr[6] & addr[5] & addr[4]; // addr >= 0xF0
    wire mmio_hit = mmio & ~addr[3];                       // 0xF0-0xF7 valid ...

    // ... 0xF8-0xFF reserved: reads 0x00, writes ignored, no trap.
    assign ram_addr  = addr;
    assign ram_re    = re & ~mmio;
    assign ram_we    = we & ~mmio;
    assign ram_wdata = wdata;

    assign mmio_re    = re & mmio_hit;
    assign mmio_we    = we & mmio_hit;
    assign mmio_port  = addr[2:0];
    assign mmio_wdata = wdata;

    assign rdata = mmio ? (mmio_hit ? mmio_rdata : 8'h00) : ram_rdata;
    assign ready = 1'b1; // v1: every target answers in one cycle (spec 8.3)

endmodule
