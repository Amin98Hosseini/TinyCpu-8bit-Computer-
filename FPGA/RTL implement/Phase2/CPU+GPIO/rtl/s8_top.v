// =============================================================================
// Module : s8_top
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 9 (s8_top row),
//          11.1 (MODE gating), 8.4 (clock/reset), 15 (UCF)
//
// PHASE 2 ("first hardware"): CPU + program/data RAM + bus + GPIO, wired end
// to end so the spec 6.9.1 GPIO demo runs on the Farad-1 and lights LED0.
//
// Everything here is WIRING plus the three control services the spec puts in
// the top level (spec 9: "wiring only ... owns the MODE synchronizer"):
//
//   u_rst_sync   raw active-low button -> internal synchronous active-high rst
//   u_mode       MODE strap synchronizer + boot latch (MODE_INVERT = 1)
//   cpu_rst      rst | mode_latched | soft_rst   (spec 11.1 + CPU_CONTROL)
//
// Deliberately NOT in Phase 2 (they arrive in later phases, and the port list
// grows with them): uart_rxd/uart_txd (Phase 3), cs_n/sck/mosi/miso + WP#/HOLD#
// (Phase 5), and the boot controller that owns the program-RAM loader port
// (Phase 4/6). Until then the loader port is tied idle and the program RAM is
// pre-loaded at configuration time through INIT_EN/INIT_FILE - the only way a
// Phase-2 board can hold an application. No pin number appears in this file:
// every pad comes from phase2/constraints/board_p2.ucf (spec 17 rule 1).
//
// INIT_FILE is resolved by the synthesis/simulation tool relative to its own
// working directory, so the defaults assume the standard layout: the ISE
// project directory (or phase2/sim for ISim) contains/copies gpio_demo.hex.
// Testbench and custom builds override both parameters explicitly.
//
// gpio<3:0> are the four Farad-1 LEDs (p105/p104/p102/p101, active high,
// 390 ohm to GND). They are declared inout because DIR can release a pad and
// GPIO_IN reads it back, exactly as spec 9 describes for s8_gpio.
// =============================================================================

module s8_top #(
    parameter MODE_INVERT = 1,               // Farad-1 DIP0: open = 1 = run app
    parameter INIT_EN     = 1,               // pre-load program RAM at config
    parameter INIT_FILE   = "gpio_demo.hex"  // $readmemh image (see phase2/prog/)
) (
    input        clk,     // p85, 50.000 MHz oscillator
    input        rst_n,   // p87, button S2, active low, RC-debounced
    input        mode,    // p84, DIP0 strap (logical inversion: MODE_INVERT)
    inout  [3:0] gpio     // p105/p104/p102/p101, LEDs, active high
);

    // ---- reset / mode control ----
    wire rst;             // internal active-high reset (async assert)
    wire mode_latched;    // 1 = programming (CPU held in reset)
    wire soft_rst;        // CPU_CONTROL bit1 one-cycle pulse
    wire cpu_rst;         // CPU reset = power-on | mode gate | soft reset

    // ---- CPU <-> program memory ----
    wire [15:0] instr;
    wire [11:0] instr_addr;

    // ---- CPU <-> data bus ----
    wire [7:0]  bus_addr, bus_wdata, bus_rdata;
    wire        bus_re, bus_we;

    // ---- bus <-> data RAM ----
    wire [7:0]  ram_addr, ram_wdata, ram_rdata;
    wire        ram_re, ram_we;

    // ---- bus <-> MMIO ----
    // (mmio_re is not used in Phase 2: MMIO reads have no side effects yet)
    wire        mmio_we;
    wire [2:0]  mmio_port;
    wire [7:0]  mmio_wdata, mmio_rdata;

    // ---- GPIO ----
    wire [3:0]  gpio_out, gpio_dir, pad_out, pad_oe, pad_in_sync;
    wire [3:0]  pad_in = gpio;   // read what is actually on the pin

    // ---- CPU status ----
    wire halted, trapped;
    wire resume_cpu;

    // ------------------------------------------------------------------
    // Reset: single synchronizer for the whole design (spec 2, 8.4)
    // ------------------------------------------------------------------
    s8_reset_sync u_rst_sync (
        .clk     (clk),
        .rst_n   (rst_n),
        .rst     (rst),
        .rst_n_i ()
    );

    // ------------------------------------------------------------------
    // MODE strap: 2FF synchronizer + latch at reset release (spec 11.1)
    // ------------------------------------------------------------------
    s8_mode_latch #(.MODE_INVERT (MODE_INVERT)) u_mode (
        .clk      (clk),
        .rst      (rst),
        .mode_raw (mode),
        .mode     (mode_latched),
        .latched  ()
    );

    // MODE = 1 -> CPU held in reset for the whole programming state
    // (spec 11.1 / 17 rule 3). Phase 4 hands the other side of this gate to
    // the boot controller; the gate itself stays.
    assign cpu_rst = rst | mode_latched | soft_rst;

    // ------------------------------------------------------------------
    // CPU
    // ------------------------------------------------------------------
    s8_cpu u_cpu (
        .clk        (clk),
        .rst        (cpu_rst),
        .resume_i   (resume_cpu),
        .instr      (instr),
        .instr_addr (instr_addr),
        .bus_addr   (bus_addr),
        .bus_re     (bus_re),
        .bus_we     (bus_we),
        .bus_wdata  (bus_wdata),
        .bus_rdata  (bus_rdata),
        .bus_ready  (1'b1),        // v1: every target answers in one cycle
        .halted     (halted),
        .trapped    (trapped)
    );

    // ------------------------------------------------------------------
    // Program memory: 4096 x 16 BRAM.
    // cpu_en = 1: the CPU samples `instr` only in FETCH_WAIT, so a
    // continuously enabled read port is functionally a fetch strobe
    // (Phase-1 decision D7). The loader port is idle until Phase 4/6.
    // ------------------------------------------------------------------
    s8_program_ram #(
        .INIT_EN   (INIT_EN),
        .INIT_FILE (INIT_FILE)
    ) u_prom (
        .clk       (clk),
        .cpu_addr  (instr_addr),
        .cpu_en    (1'b1),
        .instr     (instr),
        .load_addr (12'h000),
        .load_data (16'h0000),
        .load_we   (1'b0),
        .sel_load  (1'b0)
    );

    // ------------------------------------------------------------------
    // Data RAM + address decode
    // ------------------------------------------------------------------
    s8_data_ram u_dram (
        .clk   (clk),
        .addr  (ram_addr),
        .re    (ram_re),
        .we    (ram_we),
        .wdata (ram_wdata),
        .rdata (ram_rdata)
    );

    s8_bus u_bus (
        .addr       (bus_addr),
        .re         (bus_re),
        .we         (bus_we),
        .wdata      (bus_wdata),
        .rdata      (bus_rdata),
        .ready      (),
        .ram_addr   (ram_addr),
        .ram_re     (ram_re),
        .ram_we     (ram_we),
        .ram_wdata  (ram_wdata),
        .ram_rdata  (ram_rdata),
        .mmio_re    (),
        .mmio_we    (mmio_we),
        .mmio_port  (mmio_port),
        .mmio_wdata (mmio_wdata),
        .mmio_rdata (mmio_rdata)
    );

    // ------------------------------------------------------------------
    // MMIO: GPIO ports 0-2 + CPU_CONTROL port 6
    // ------------------------------------------------------------------
    s8_mmio u_mmio (
        .clk         (clk),
        .rst         (rst),
        .mmio_we     (mmio_we),
        .mmio_port   (mmio_port),
        .mmio_wdata  (mmio_wdata),
        .mmio_rdata  (mmio_rdata),
        .halted      (halted),
        .trapped     (trapped),
        .resume      (resume_cpu),
        .soft_rst    (soft_rst),
        .pad_in      (pad_in),
        .pad_out     (pad_out),
        .pad_oe      (pad_oe),
        .gpio_out    (gpio_out),
        .gpio_dir    (gpio_dir),
        .pad_in_sync (pad_in_sync)
    );

    // ------------------------------------------------------------------
    // Pads: one tristate buffer per bit (XST infers one IOBUF per bit)
    // ------------------------------------------------------------------
    genvar i;
    generate
        for (i = 0; i < 4; i = i + 1) begin : g_pad
            assign gpio[i] = pad_oe[i] ? pad_out[i] : 1'bz;
        end
    endgenerate

endmodule
