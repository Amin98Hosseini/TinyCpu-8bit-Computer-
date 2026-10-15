# TinyCpu 8bit Computer — This is 8-bit soft processor for Spartan-6 LX9

![TinyCpu Technical Banner](https://github.com/Amin98Hosseini/TinyCpu-8bit-Computer-/blob/main/Docs/TinyCpu_%20Neon%208-Bit%20FPGA%20Showcase.png?raw=true)

TinyCpu 8bit Computer is a small, custom 8-bit soft processor for learning and experimentation on a
Xilinx Spartan-6 FPGA. The FPGA holds the CPU, instruction/data storage, GPIO,
UART, an SPI flash controller, and boot control. A PC-side Rust toolchain
assembles source code into an image and transfers it to the board over USB-UART.
A W25Q64-family SPI NOR flash stores application images persistently, so new
programs can be installed without rebuilding the FPGA bitstream.

This repository is an **implementation plan and specification**, not a working
build. As of v1.1, nothing beyond a Phase-0 learning skeleton (demo CPU with a
hard-coded program, placeholder pins, a divided demo clock) has ever been
synthesized — the documents say so explicitly.

---

## Status

**v1.1** (supersedes v1.0 and the original *S8 Technical Implementation Manual*).
Design intent is frozen; the Farad-1 target board is fully verified (see Section 2).

## Documents (start here)

| Document | Purpose |
| --- | --- |
| [Docs/S8_Technical_Specification_v1.1.md](Docs/S8_Technical_Specification_v1.1.md) | Complete, implementation-ready spec. Any agent that can read and code off this document can build the whole system. |
| [Docs/S8_Technical_Specification_v1.1.pdf](Docs/S8_Technical_Specification_v1.1.pdf) | Same spec, rendered for reading. |
| [Docs/S8_Technical_Specification_v1.1.html](Docs//S8_Technical_Specification_v1.1.html) | Same spec, rendered for the browser. |

Use the PDF or HTML for reading; the Markdown is the working source.

## What you'll find in this repo

```
.
├── README.md                          # this file
├── S8_Technical_Specification_v1.1.*  # v1.1 spec (md / docx / pdf)
├── docs/
│   ├── S8_Technical_Specification_v1.1.*   # md / html (render of the md)
│   └── spec-print.css                     # print stylesheet for the PDF
├── BoardFiles/
│   ├── Farad-1-Schematic.pdf             # 6-sheet schematic, rev 2016-12-29
│   ├── Farad-1-User-Manual.pdf
│   └── Farad1_UCF.ucf                    # vendor example UCF (LOCs correct; missing IOSTANDARDs/PERIOD)
├── tools/
│   ├── render_pdf.ps1                     # renders PDF pages to PNG (built-in Windows API)
│   ├── crop_png.ps1                       # crops a PNG region
│   └── gen_isa_vectors.js                 # generates S8 ISA v1 golden encoding vectors
└── extracted_manual.txt                  # text extraction of the original manual (reference)
```

The project tree described in the spec (`s8-project/rtl/`, `s8-project/tb/`, `s8-project/host/s8/`, …)
and the Phase 0–8 execution walkthrough have **not** been created yet — see Overview, "What remains to do", below.

## Overview — what this is and isn't

S8 is deliberately small:

- 8-bit data path, 8 × 8-bit registers (R0–R7, none hardwired to zero).
- 12-bit program counter (4096 instruction words, 16 bits each, in internal BRAM).
- 8-bit *data* address space (256 bytes) with memory-mapped I/O from 0xF0.
- A multicycle control FSM (not pipelined, not single-cycle).
- GPIO, UART, SPI flash controller, boot control — all in one clock domain, one
  clock source, one active-low reset.
- No interrupts, no external memory bus, no multiply/divide, no caches/pipelines
  in the v1 ISA.

The v1 ISA is **frozen** in [Section 6 of the spec](Docs/S8_Technical_Specification_v1.1.md#6-instruction-set-architecture-v1-frozen):
16 opcodes, with `IN`, 7 conditional branches, an 8-bit `LDI` immediate,
ALU-immediate operations, memory `LD`/`ST`, stack `CALL`/`RET`/`PUSH`/`POP`,
shifts by register value, and peripheral `IN`/`OUT` port fields. Every example
program in the spec assembles against this ISA, and three useful starter encodings
are preserved bit-for-bit from v1.0 (`LDI R0,1` = `0x1001`, `OUT GPIO_OUT,R0` =
`0x5000`, `JMP 0x002` = `0x4002`).

The host toolchain (Phase 3 → 7) is an assembler, image packer, serial uploader,
disassembler, and monitor — all built as a Rust workspace. A C-like compiler is
deferred to Phase 7.

## Target platform — Farad-1 (verified)

The spec's target is the **Farad-1 board** (Farad Andish, schematic rev
2016-12-29). Board facts were verified in v1.1 against the board's 6-sheet schematic
(renders inspected page-by-page) and cross-checked against the vendor UCF and manual:

| Item | Verified value |
| --- | --- |
| FPGA | XC6SLX9-2TQG144C → ISE part `xc6slx9-2tqg144` |
| System clock | 50.000 MHz oscillator on p85 (PERIOD 20.000 ns) |
| Reset | Button S2 → p87, active low, RC-debounced (4.7 K + 4.7 µF) |
| Host link (default) | FT2232H — Channel A = JTAG (iMPACT), Channel B = UART to S8 on p83 (in) / p82 (out); one-time FT_PROG EEPROM change required |
| Host link (fallback) | DB9 + MAX232 on p41/p40 (FPGA-side RX goes through a 5.6 K / 10 K divider ≈ 3.2 V, input-only, safe) |
| LEDs (v1) | p105, p104, p102, p101 — active high (390 Ω → LED → GND) |
| MODE strap | No dedicated pin; DIP0 = p84, pulled up, switch to GND; `MODE_INVERT = 1` in `s8_top`, so open (default) = run app, closed = programming |
| Flash | W25Q64BV — **shared FPGA configuration flash**, master SPI |
| Flash pins | SCK = p70 (CCLK, net FP_PR_CLK), CS# = p38 (CSO_B, board pull-up R6), MOSI = p64 (net MISO0 → DI), MISO = p65 (net MISO1 ← DO), WP# = p62 (no pull-up), HOLD# = p61 (no pull-up) |
| SRAM | IS61WV5128 (512 K × 8, 3.3 V) — reserved for a future XIP/data-expansion phase |
| Power / I/O | All banks VCCO = 3.3 V → every S8 port is LVCMOS33; VCCINT = 1.2 V |

The Farad-1 is **not** a generic reference board — read "Target platform — Farad-1" in
the spec before using any pin. In particular: the W25Q64BV is the configuration flash
(the bitstream lives at 0x000000), so S8 storage is relocated to base `0x060000`,
and WP#/HOLD# must be driven high (they have no board pull-ups).

## How to read the spec

1. **Section 1–4** — scope, architecture, repo tree, board facts (the Farad-1 table).
2. **Section 6** — ISA v1 (frozen), with the encoding tables and 44 nominal golden
   vectors. The `s8-isa` Rust crate and RTL localparams both trace to this section.
3. **Section 7** — memory map (8-bit data space: RAM 0x00–0xEF, MMIO 0xF0–0xFF).
4. **Section 8** — CPU microarchitecture (multicycle FSM, state table, bus interface).
5. **Section 9** — RTL module specs (ports, behavior).
6. **Sections 10–13** — UART, boot/mode, packet protocol (byte-exact, CRC16-CCITT-FALSE
   with check value 0x29B1), SPI flash.
7. **Section 14** — Rust host toolchain (workspace, crates, APIs, CLI).
8. **Section 15** — Xilinx ISE workflow **with the populated Farad-1 UCF** (the vendor
   example UCF is missing IOSTANDARDs, the PERIOD constraint, and the flash pins — all
   supplied here).
9. **Section 16** — verification plan (8 testbenches + behavioral flash model + hardware tests).
10. **Section 17** — safety/reliability rules.
11. **Section 18** — phased execution plan (0–8) with exit gates.
12. **Sections 19–20** — future compiler phase + references.

## What remains to do (by phase)

Phases are carried in the spec's [Section 18](Docs/S8_Technical_Specification_v1.1.md#18-phased-execution-plan).
The project tree listed in the spec has not been scaffolded yet, so the first concrete
work for a new implementer is:

| Phase | Deliverable | Current state |
| --- | --- | --- |
| 0. Foundation | Spec frozen (done in v1.1), board facts verified (done), repo tree + project UCF | **repo tree not yet created; start here** |
| 1. CPU core | RTL: `s8_alu`, `s8_regfile`, `s8_cpu`, `s8_program_ram`, `s8_data_ram`, `s8_bus` + testbenches | **not started** |
| 2. First hardware | `s8_top` minimal (CPU + GPIO), Farad-1 UCF, ISE project | **not started** |
| 3. UART | `baud_gen`, `uart_rx`, `uart_tx`, `uart_regs` + echo program | not started |
| 4. Boot protocol | `s8_boot_ctrl` packet parser + session FSM; host `s8-serial`/`s8-cli` upload/verify | not started |
| 5. SPI discovery | `spi_byte_engine`, `w25q64_controller`, JEDEC read path | not started |
| 6. Persistent slots | Full loader, metadata commit, A/B selection, end-to-end upload | not started |
| 7–8. Compiler / debugger | Future | not started |

## How to start (Phase 0)

1. Lay out the repo tree exactly as in [Section 3 of the spec](Docs/S8_Technical_Specification_v1.1.md#3-project-directory-structure).
2. Drop the populated Farad-1 UCF (from the spec, Section 15) into `constraints/` as `board.ucf` — **never** use the vendor `Farad1_UCF.ucf` alone (it is missing IOSTANDARDs, the PERIOD constraint, and the flash pins).
3. Make `s8-isa` the first crate: it is the single source of truth for encodings, and everything
   else depends on it. Run its golden-vector tests (the 44 vectors in Section 6.7) first.
4. Run `tools/gen_isa_vectors.js` to regenerate the vector files for both the RTL testbenches (`tb/vectors/`) and the Rust golden-data include. Regenerate after any approved ISA change.
5. Build `s8_alu` + `tb_s8_alu` next — the exhaustive flag sweep (Section 16.1) catches encoding/flag misunderstandings before they spread.

## Golden vector rule

If a golden vector ever fails, **fix the code against the spec table, never edit the vector**.
The 44 vectors in Section 6.7 are normative; the three starter ones (`0x1001`, `0x5000`, `0x4002`)
must pass in every environment (Rust workspace, RTL testbenches, simulation).

## Host toolchain usage (when built)

```
s8 asm examples/gpio.s8 -o build/gpio.bin               # assemble (Section 6.9.1)
s8 disasm build/gpio.bin                                 # disassemble
s8 image build/gpio.bin --slot A -o build/gpio.s8img     # pack into .s8img
s8 upload build/gpio.s8img --port <PORT> --baud 115200  # FTPATH B UART (or swap to p41/p40)
s8 verify --port <PORT>                                  # CRC readback
s8 status --port <PORT>                                  # device state
s8 monitor --port <PORT> --baud 115200                  # terminal
```

`--port` is not hard-coded (COM5 / /dev/ttyUSB0); enumerate candidates and confirm.

## Safety rules (the ones that matter)

- Pin assignments come from the schematic only; every top-level port gets LOC + IOSTANDARD; never guess.
- 3.3 V logic only on user I/O; the MAX232 path works as designed because of the 5K6/10K divider on the FPGA side.
- CPU and bootloader ownership are mutually exclusive: the CPU is held in reset for the whole programming state.
- Every length/address/loop/wait is bounded; images larger than 8192 bytes are rejected at the assembler.
- The active slot is never erased; the metadata marker is written last; the two metadata records live in two separate erase sectors.
- The FPGA configuration region is untouchable (Farad-1 specifics in Section 5.4).
- CRC16 is integrity checking, not authentication.

## References

- [AMD/Xilinx UG380 — Spartan-6 FPGA Configuration User Guide](https://docs.amd.com/v/u/en-US/ug380) — required: the Farad-1 shares the configuration flash; S8 accesses it as user I/O after configuration.
- [AMD/Xilinx DS160 — Spartan-6 Family Overview](https://docs.amd.com/api/khub/documents/zd3RzGl6jfg7bYjaTp0k2Q/content) — resource table (9,152 logic cells, 1,430 slices, 32 × 18 Kb BRAM, 16 DSP48A1) used for the Section 5.4 budget.
- Board files in `BoardFiles/` (schematic, user manual, vendor UCF).
- [Winbond W25Q64 family datasheet](https://www.winbond.com/hq/product/code-storage-flash-memory/serial-nor-flash/?__locale=en) — exact suffix W25Q64BV is confirmed on this board.

## License / ownership

Keep an SPDX file (e.g., `LICENSE`) before publishing externally.

---

**Quick start for a coding agent:** read [Docs/S8_Technical_Specification_v1.1.md](Docs/S8_Technical_Specification_v1.1.md) top to bottom, then scaffold the Phase-0/1 repo tree with the populated Farad-1 UCF, build `s8-isa` with its golden-vector tests, and build `s8_alu` + `tb_s8_alu` next — the spec's Section 1 (how to read it) and Appendix A (guide for implementing agents) spell out the order.
