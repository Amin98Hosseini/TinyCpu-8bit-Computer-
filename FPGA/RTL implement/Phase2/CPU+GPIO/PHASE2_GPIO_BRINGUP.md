# S8 Phase 2 — First Hardware (CPU + GPIO on the Farad-1)

Target: **XC6SLX9-2TQG144C on Farad-1**, 50.000 MHz (`clk` p85, `rst_n` p87, `mode` p84) ·
Toolchain: **Xilinx ISE 14.7** (Verilog-2001) · Spec: `docs/S8_Technical_Specification_v1.1.md`

This directory is the Phase-2 deliverable from spec §18: **`s8_top` minimal (CPU + GPIO)**, the
Farad-1 constraints, and the ISE build — plus an integration testbench that drives the real
top level from the board side only. It is self-contained on purpose: Phase 1 lives in `rtl/` and
`tb/`, and nothing here edits it (see §6 for the three Phase-1 defects this phase turned up, and
which of them are fixed in this copy).

Everything in this document was **actually simulated** (§5 findings, §6 expected results) with Icarus
Verilog; §8 says what the board should do and what to check in the ISE reports. Where a claim was not
verified, it says so.

---

## 1. Exit gate (spec §18, Phase 2)

| Gate item | Status |
| --- | --- |
| `s8_top` minimal: CPU + GPIO wired end to end | **done** (`rtl/s8_top.v`) |
| Farad-1 UCF from spec §15 (LOC + IOSTANDARD + PERIOD) | **done** (`constraints/board_p2.ucf`, 7 pins used) |
| ISE project runs clean → bitstream | **not run here** (no ISE on this machine); script + GUI steps in §7.2, report checklist in §8.3 |
| GPIO demo (spec 6.9.1) observed on LED0 (p105, active high) | **simulated** (`tb_s8_top_gpio`, T3) — board check pending |
| Timing closure with margin, utilization recorded | **pending** (`trce` / `map` + `par` reports, §8.3) |

Simulation gate: `tb_s8_top_gpio` must print

```
tb_s8_top_gpio: PASSED (72 checks, 0 errors)
```

and it does (§6.2).

---

## 2. File map

```
phase2/
  PHASE2_GPIO_BRINGUP.md      this document
  rtl/
    s8_top.v                  NEW  Phase-2 top level (wiring + reset/MODE control)
    s8_reset_sync.v           NEW  async-assert / sync-deassert reset synchronizer
    s8_mode_latch.v           NEW  MODE strap 2FF synchronizer + boot latch (MODE_INVERT)
    s8_gpio.v                 NEW  4-bit GPIO: OUT/DIR registers, 2FF pad input
    s8_mmio.v                 NEW  MMIO register block: GPIO ports 0-2 + CPU_CONTROL port 6
    s8_program_ram.v          COPY of phase 1 + optional power-up image (INIT_EN/INIT_FILE)
    s8_cpu.v                  COPY of phase 1 + fetch-address fix (see §6)
    s8_bus.v                  COPY of phase 1 + MMIO decode fix (see §6)
    s8_alu.v                  COPY of phase 1, byte-identical
    s8_regfile.v              COPY of phase 1, byte-identical
    s8_data_ram.v             COPY of phase 1, byte-identical
  tb/
    tb_s8_top_gpio.v          NEW  Phase-2 integration testbench (72 self-checks)
  prog/
    gpio_demo.hex             the 3-word spec 6.9.1 demo, $readmemh format
    gpio_demo.s8              same program as assembler source (reference listing)
  constraints/
    board_p2.ucf              Phase-2 UCF (used pins only; later phases commented)
  ise/
    build_phase2.tcl          ISE 14.7 TCL build (project, sources, synth → bitstream)
  sim/
    run_isim.bat / run_isim.sh   one-command iSIM run of the testbench
```

Copy policy: `phase2/rtl/*` is the complete Phase-2 source set — the ISE project must use **only**
these files (`rtl/` at the repo root is Phase 1 and must not be added as well, or every module is
defined twice). The three "COPY + fix" files are explained and justified in §6; the other three are
byte-identical (SHA-256 in the appendix), so drift is easy to spot.

---

## 3. What was implemented

```
        p85 clk ────────────────────────────────────────────────┐
        p87 rst_n ──[s8_reset_sync]── rst ──────────────┐        │
        p84 mode  ──[s8_mode_latch]── mode_latched ─┐   │        │
                                                    │   │        │
                                    cpu_rst = rst|mode_latched|soft_rst
                                                    │   │        │
                                        ┌───────────▼───▼────────▼─────────┐
                                        │            s8_cpu                │
                                        │  instr ◄── instr_addr (12)       │
                                        └───┬──────────────────────┬───────┘
                          ┌─────────────────▼────┐      ┌──────────▼───────┐
                          │  s8_program_ram      │      │     s8_bus       │
                          │  4096x16 BRAM        │      │ decode + rdata   │
                          │  + INIT_FILE image   │      └───┬──────────┬───┘
                          └──────────────────────┘          │          │
                                            ┌───────────────▼──┐    ┌──▼─────────────┐
                                            │  s8_data_ram     │    │    s8_mmio     │
                                            │  240x8 @ 00-EF   │    │ GPIO + CTRL    │
                                            └──────────────────┘    └──┬─────────────┘
                                                                       │
        p105/104/102/101 gpio<3:0> ◄──── 4 x IOBUF (pad_oe ? pad_out : z)
```

### 3.1 `s8_reset_sync` — one reset for the whole design

Spec §2/§8.4/§17-rule-9 demand *asynchronous assert, synchronous deassert*. The button on p87 is
asynchronous, so it never touches sequential logic directly:

```
rst_n low  → rst = 1 immediately (async clear of the 2-flop chain)
rst_n high → rst = 0 exactly two clk edges later
```

`rst` (active high) is what the CPU, register file, GPIO and MMIO blocks use.

### 3.2 `s8_mode_latch` — MODE is a boot strap, not a switch

Spec §11.1 + §5/B6. Farad-1 has no MODE pin; DIP0 (p84) plays that role, is pulled **up** on the
board, and the spec's logical polarity is "1 = programming". So `MODE_INVERT = 1` (default):
DIP0 **open = 1 = run application** (the board's all-off default), DIP0 **closed = 0 = programming**.

Implementation: a 2-flop synchronizer plus a `settle` counter. The value is captured on the **third
clock edge after reset release** — the synchronizer has therefore seen two complete clock periods
of stable strap (spec §11.2's "≥2 clk settle"), with a clock of margin. After that, `latched` stays
high and further strap changes are ignored until the next hard reset (proved in T3).

### 3.3 `s8_gpio` — 4 pads, spec §7.3 + §9

| Register | Bits | Access | Reset | Behaviour |
| --- | --- | --- | --- | --- |
| GPIO_OUT (port 0) | [3:0] | R/W | 0x00 | drives a pad when DIR = 1 |
| GPIO_IN (port 1) | [3:0] | R | — | 2-flop synchronized pad samples |
| GPIO_DIR (port 2) | [3:0] | R/W | **0x0F** | 1 = output (reset value keeps the LED demo working) |

`pad_oe = gpio_dir`, `pad_out = gpio_out`, and `s8_top` turns each bit into
`gpio[i] = pad_oe[i] ? pad_out[i] : 1'bz` (XST infers one IOBUF per bit). Reset is asynchronous so
the pads go to a defined state the instant the button is pressed, not on the next clock.

### 3.4 `s8_mmio` — the Phase-2 slice of the MMIO map

| Port | Name | Phase-2 behaviour |
| --- | --- | --- |
| 0 | GPIO_OUT | R/W → `s8_gpio` |
| 1 | GPIO_IN | R ← synchronized pads |
| 2 | GPIO_DIR | R/W → `s8_gpio` |
| 3, 4 | UART_STATUS / UART_DATA | **not implemented**: read 0x00, writes ignored (spec §7.3: benign, no trap) — Phase 3 |
| 5 | BOOT_STATUS | **not implemented**: reads 0x00 — Phase 4 |
| 6 | CPU_CONTROL | R: {RUNNING, TRAPPED, HALTED} at bits 2/1/0. W bit0 = one-cycle `resume` pulse, W bit1 = one-cycle `soft_rst` pulse |
| 7 | reserved | reads 0x00 |

Two design notes worth knowing before Phase 3/4:

* **Why port 6 exists in Phase 2.** A halted core executes nothing, so it cannot write the register
  that resumes it (Phase-1 decision D4: `resume` must come from outside the core). Nothing on a
  Phase-2 board can drive that write yet — no UART, no boot controller — so on hardware a HALT is
  recovered with the reset button. The register, its read mux and its pulse are implemented and
  tested now (T5, T8) so Phase 3 only has to wire `uart_regs` to the same net.
* **Soft reset (bit1)** pulses the CPU's internal reset: PC/SP/flags/registers cleared, program RAM
  and the GPIO registers untouched (the Phase-4 boot controller owns peripheral reset). On the
  board that means "restart the application", the Phase-2 form of spec §11.1's warm hand-off.
* Reads are purely combinational, so there is no `mmio_re` port here. Phase 3 re-introduces it for
  `uart_regs`' pop-on-read.

### 3.5 `s8_top` — wiring only, plus the three control services

Ports are exactly the ones Phase 2 uses, so the UCF has no unmatched constraints and no placeholder
pins (spec §17 rule 1):

```verilog
module s8_top #(
    parameter MODE_INVERT = 1,               // Farad-1 DIP0: open = run
    parameter INIT_EN     = 1,               // pre-load program RAM at configuration
    parameter INIT_FILE   = "gpio_demo.hex"  // $readmemh image
) (
    input clk, input rst_n, input mode, inout [3:0] gpio
);
```

* `cpu_rst = rst | mode_latched | soft_rst` — MODE = 1 holds the CPU in reset for the whole
  programming state (spec §11.1/§17 rule 3); Phase 4 hands the other side of this gate to the boot
  controller and the gate stays.
* Program RAM: `cpu_en = 1'b1` (the CPU samples `instr` only in FETCH_WAIT, so a continuously
  enabled read port is a fetch strobe — Phase-1 decision D7); the loader port is tied idle until
  Phase 4/6 owns it; `bus_ready = 1'b1` (spec §8.3, v1 has no wait states).
* Deliberately absent (they arrive with their phases and the port list grows with them):
  `uart_rxd/uart_txd` (Phase 3), `spi_*` incl. WP#/HOLD# (Phase 5), boot controller (Phase 4/6).

### 3.6 The application image: `INIT_EN` / `INIT_FILE`

Phase 2 has no host link and no loader, so the only way an application can be in BRAM on the board
is a **configuration-time image**. `s8_program_ram` gets two parameters:

```verilog
initial begin
    if (INIT_EN != 0) $readmemh(INIT_FILE, mem);
end
```

`INIT_EN = 0` reproduces Phase-1 behaviour exactly (no file dependency). `INIT_EN = 1` makes XST
initialise the inferred block RAM from the file (INIT_00…INIT_3F); `$readmemh` asks for one 16-bit
hex word per line, which is why `prog/gpio_demo.hex` is simply

```
1001
5000
4002
```

The loader port remains the only *run-time* write path, so spec §7.1 ("no write port to the
application") still holds.

**Tool path caveat.** `$readmemh` resolves relative to the tool's working directory. The defaults
(`"gpio_demo.hex"`) therefore expect the file next to the ISE project / in the directory iSIM runs
from: `ise/build_phase2.tcl` copies it into `phase2/ise/build/`, and `sim/run_isim.*` runs from
`phase2/sim/` and passes `../prog/gpio_demo.hex` from the testbench. Check §8.3 item 2 in the
synthesis report to confirm the initial contents really landed in the BRAM.

### 3.7 Constraints and build

`constraints/board_p2.ucf` — every LOC from spec §15 (schematic-verified), LVCMOS33 everywhere
(all banks are 3.3 V on this board), one PERIOD constraint:

```
NET "clk" TNM_NET = "sys_clk";
TIMESPEC "TS_sys_clk" = PERIOD "sys_clk" 20.000 ns HIGH 50%;
NET "clk" LOC = "P85" | IOSTANDARD = "LVCMOS33";
… rst_n P87, mode P84, gpio<0..3> P105/P104/P102/P101
```

Note the deliberate syntax correction versus the spec's single-line illustration: UCF needs
`TNM_NET` on the net as its own statement; folding it into the `LOC` line is not parseable.

The Phase-3 (UART p83/p82, or DB9 p40/p41) and Phase-5 (flash p70/p38/p64/p65/p62/p61) pins are
present but **commented out** — declaring a LOC for a net that does not exist produces unmatched
constraint warnings, so they get enabled together with their ports.

`ise/build_phase2.tcl` creates the project (`xc6slx9` / `tqg144` / `-2`), adds `phase2/rtl/*.v` to
synthesis and the testbench to the simulation view only, adds the UCF, sets `s8_top` as top and runs
XST → Implement → bitgen into `phase2/ise/build/`.

---

## 4. What the testbench does

`tb/tb_s8_top_gpio.v` instantiates the **real, unmodified `s8_top`** — the same file that becomes the
bitstream — and drives it only from the board side:

| Signal | TB model |
| --- | --- |
| `clk` | 20 ns period (50.000 MHz oscillator, p85) |
| `rst_n` | button S2: held low, released mid-cycle, also dropped mid-run to test async assertion |
| `mode` | DIP0: 1 = open (board default) / 0 = closed, changed both while held in reset and while running |
| `gpio<3:0>` | four LED pads: `tri` net; pads 3:2 also carry a **weak** TB driver (`weak1/weak0`), so the FPGA's strong output always wins and there is never a contention X. `2'bzz` = nothing attached, `2'b00` = LED load pulls low, `2'b11` = external source pulls high |

Applications are *not* loaded through a test-only port: T1–T3 run the real `INIT_FILE` image. Later
groups write the program RAM words through a hierarchical reference (`u_top.u_prom.mem[k]`, the same
simulation-aid technique Phase 1 uses for the register file) while the CPU is held in reset, then
release reset with the strap of their choice. An `#2000000` watchdog kills a hung run.

Test groups (each prints its own `Tn done:` line):

| Group | What it establishes |
| --- | --- |
| **T1** power-up image | `INIT_FILE` really places `1001 / 5000 / 4002` in program RAM (the hardware path, not a TB shortcut) |
| **T2** programming boot | reset asserted while `rst_n` low; still asserted 1 clock after release; released exactly on the 2nd edge; MODE latched = 1; `cpu_rst` held; `PC` frozen at 0 for 300 clocks; GPIO reset values `DIR=0x0F / OUT=0x00`; LEDs dark; changing the strap while held does **not** release the CPU |
| **T3** run boot + GPIO demo | MODE latched = 0, CPU released, LED0 lights **from the image**, GPIO_OUT = 0x01, no halt/trap, LED0 still on 500 clocks later with PC parked on the `JMP` self-loop; closing the strap while running is ignored; dropping `rst_n` mid-cycle asserts `rst` and clears the pads **asynchronously** (checked 1 ns later, no clock edge); the *next* boot latches the now-closed strap and holds the CPU again |
| **T4A/T4B** GPIO at the pins | `OUT GPIO_OUT` → pads 0101; readback of GPIO_OUT = 0x05; `DIR=0x03` releases pads 3:2 (they read **z** with nothing attached); `GPIO_IN` = 0x01 with the released pads low and 0x0D with them high — two runs of the same program, so the synchronizer and the tristate are both exercised |
| **T5** HALT + CPU_CONTROL | first HALT reached, R0 = 1, `IN R1, CPU_CONTROL` = 0x04 (RUNNING), the read mux reports HALTED while halted, LEDs dark; a forced `resume` (see below) continues at the next instruction: R0 = 2, LED1 on, no trap |
| **T6** TRAP | reserved opcode 0xE traps, halt bit stays 0, R0 untouched, read mux reports TRAPPED, pads untouched, trap still latched 20 clocks later |
| **T7** CPU_CONTROL soft reset | writing bit1 restarts the application: the pads stay 0101 and instructions 4/5 (which would light all four LEDs) never retire; the soft-reset pulse is counted over 400 clocks |
| **T8** resume pulse generation | writing bit0 to CPU_CONTROL produces **exactly one** `resume` pulse and does not disturb a running core |

Why T5 *forces* the resume net: a halted core cannot write port 6, and Phase 2 has no UART/boot
controller, so `force u_top.resume_cpu` is the honest implementation of Phase-1 decision D4 ("resume
must come from outside the core; the TB drives it"). T8 covers the register-to-pulse path separately,
so no coverage is lost by the force.

**What this testbench cannot show** (by nature, not by omission): metastability/recovery of the two
synchronizers (a 2-flop synchronizer is invisible in a zero-delay RTL simulation — it is a
structural/CDC property, reviewed by inspection); timing closure (needs `par`/`trce`); anything
electrical; UART/SPI/flash (later phases); and the CPU's `LD`/`POP`/`RET` read path, which has a
known Phase-1 defect (§6.3) that Phase 2 does not use.

---

## 5. Review of the existing project — what running the code actually shows

The Phase-1 documents state that no simulator was installed, so the RTL was verified by a JS
reference model plus a line-by-line audit. That audit missed four defects. To report them
concretely, the Phase-1 and Phase-2 RTL were run under **Icarus Verilog** (WASM build,
`@veriflow/iverilog-wasm` 0.1.4, `-g2005`), installed outside the repository; the repo itself has no
new tool dependency. Results:

| Testbench (Phase 1, unmodified) | Claimed in the guide | Actually |
| --- | --- | --- |
| `tb_s8_regfile` | PASSED (13 checks) | **PASSED (13 checks, 0 errors)** |
| `tb_s8_alu` | PASSED (534553 checks) | **FAILED (534553 checks, 6764 errors)** — testbench bug (§5.2) |
| `tb_s8_cpu_programs` | PASSED (39 checks) | **FAILED (39 checks, 8 errors)** — RTL bugs (§5.1, §5.3) |

### 5.1 RTL defect 1 — the program-RAM address was registered one edge late

`rtl/s8_cpu.v` drove `instr_addr <= pc` *inside* `FETCH_REQ`, i.e. one edge after the synchronous RAM
had already sampled the address. The RAM therefore returned the **previous** word: every instruction
executed was the one before `pc`. Evidence: `tb_s8_cpu_programs` reports `FAIL T1 not trapped`, and a
decode trace shows `pc=002 / ir=5000` then `pc=003 / ir=4002` before the core fetches an
uninitialised word and traps. Spec §8.2 says `FETCH_REQ: Drive program-RAM address = PC`, so the
address must be presented *during* the state.

**Fixed in `phase2/rtl/s8_cpu.v`** (one line + port type):

```verilog
output [11:0] instr_addr;          // was: output reg [11:0]
assign instr_addr = pc;            // was: instr_addr <= pc;  in ST_FETCH_REQ
```

With this fix `T1` (GPIO demo) passes and T2 gets through the whole program bar the stack/LD issues
below.

### 5.2 Testbench defect — `tb_s8_alu` checked stale shift results

In the exhaustive shift sweep the DUT operation was assigned **after** the settle delay:

```verilog
b = k; #1;
begin … op = 8; check(…); end     // op changed after the #1 -> stale `result`
```

so the shift checks compared the *previous* operation's output. All 6764 failures are exactly the four
checks that assign `op` after the delay (SHL exh 1767, SHR exh 1743, ROL exh 1766, ROR himask 1488);
the two that inherit `op` from the previous statement, and every directed shift case (which sets `op`
before the `#1`), pass. The RTL is correct: moving
`op = 8/9/10/11` before the `#1` makes the suite print **PASSED (534553 checks, 0 errors)** — exactly
the count the guide claims. The same `check()` task also uses invalid format specifiers
(`Z%C%N%O`), which is why Icarus prints `<%N>` and garbles those FAIL lines.

Not fixed here (Phase-1 file, untouched); the ALU is copied unchanged into `phase2/rtl/`.

### 5.3 RTL defect 2 — MMIO decode swallowed the stack

`rtl/s8_bus.v` decoded MMIO as `addr[7] & addr[6] & addr[5]`, commented "addr >= 0xF0". That is also
true for `0xE0–0xEF`, which spec §7.2 assigns to **data RAM** (the stack). Every `PUSH`/`CALL`
write to the stack was routed to a non-existent peripheral and silently dropped; `RET` then read
uninitialised memory and returned to `0xaxx`, trapping.

**Fixed in `phase2/rtl/s8_bus.v`:**

```verilog
wire mmio = addr[7] & addr[6] & addr[5] & addr[4];   // addr >= 0xF0
```

With 5.1 + 5.3 applied, `tb_s8_cpu_programs` goes from 8 errors to 4, the stack checks
(`M[0xEF]=0x00`, `M[0xEE]=0x1A`) pass, and the CPU testbench failure list shrinks to the defect in
§5.4.

### 5.4 RTL defect 3 — the data-bus read path commits one cycle too early (still open here)

`LD` / `POP` / `RET` read `bus_rdata` at the end of their single `MEM` cycle, but `s8_data_ram`
presents data one edge *after* `addr`/`re` are sampled (spec §7.1/§7.2: "data valid on the following
edge"). A trace of `LD R5,[R4]` shows `re=1, rdat=xx` in `MEM`, then `rf_we=1, wd=xx` — the register
gets the *previous* byte. `ST`/`OUT`/`PUSH` are fine (writes complete at that edge) and `IN` is fine
(because Phase-2 MMIO is combinational), which is why Phase-2's GPIO path is unaffected.

Consequence for Phase 1: `LD` returns a stale byte, and `RET` returns to a wrong address. It was
masked in the existing testbench by luck (the stale byte happened to be `0x35` in one place).
Remaining Phase-1 failures: `T2 halted`, `T2 not trapped`, `T2 R2`, `T2 gpio=2`.

Not fixed in the Phase-2 copy — it is a Phase-1 CPU/F SM repair (add a read-wait cycle in `MEM`, or
present the read address combinationally one cycle early as done for `instr_addr`, keeping the
documented 5/6-cycle counts). Phase 2 uses only `LDI/OUT/IN/JMP/HALT/TRAP`, so the GPIO bring-up is
not affected; `phase2/rtl/s8_cpu.v` carries a header note so nobody forgets.

### 5.5 Summary of what changed in the Phase-2 copies

| File | Change | Validated by |
| --- | --- | --- |
| `s8_cpu.v` | `instr_addr` combinational (§5.1) | Phase-1 CPU TB: 8 → 4 errors; Phase-2 TB T3/T5/T7 |
| `s8_bus.v` | MMIO decode `addr[4]` term (§5.3) | Phase-1 CPU TB stack checks pass |
| `s8_program_ram.v` | `INIT_EN`/`INIT_FILE` power-up image (§3.6) | Phase-2 TB T1/T3 |
| `s8_alu.v`, `s8_regfile.v`, `s8_data_ram.v` | none (byte-identical) | hashes in the appendix |

`rtl/` and `tb/` at the repo root are **untouched** so the two stages stay separable; §5.1–§5.3 also
need to be back-ported there (and the guide's "PASSED" claims corrected) as a separate change.

---

## 6. Expected results

### 6.1 Verdict line

```
tb_s8_top_gpio: PASSED (72 checks, 0 errors)
```

### 6.2 Full expected transcript

This is the exact output of a passing run (Icarus Verilog, `-g2005`, run from `phase2/sim/`):

```
WARNING: rtl/s8_program_ram.v:62: $readmemh(../prog/gpio_demo.hex): Not enough words in the file for the requested range [0:4095].
T1 done: power-up image present
T2 done: programming boot holds the CPU, strap latched
T3 done: GPIO demo runs from the image; MODE is a boot strap
T4A done: GPIO registers + tristate verified
T4B done: synchronized pad readback verified
T5 done: HALT/status/resume verified
T6 done: TRAP path verified
T7 soft-reset pulses counted: 20
T7 done: CPU_CONTROL soft reset verified
T8 done: resume pulses counted: 1
tb_s8_top_gpio: PASSED (72 checks, 0 errors)
tb/tb_s8_top_gpio.v:461: $finish called at 30370000 (1ps)
```

Notes on comparing:

* The `$readmemh … Not enough words` **warning is expected and benign**: the image is 3 words and
  the array is 4096 deep, so the tool says the file does not fill the range. Simulation is correct
  (T1 proves the three words landed). iSIM words the same warning differently, or may not print it.
* `T7 soft-reset pulses counted: 20` and `T8 … counted: 1` are the only non-pass/fail numbers; they
  are deterministic. `20` = how many soft-reset pulses fit in the 400-clock observation window
  (~5 instructions per restart); `1` = the single pulse T8's program asks for.
* `20 … 30 µs` of simulated time and `$finish` are expected; the final `$finish` line carries the
  simulator's own source reference and can differ in wording.
* iSIM additionally prints `# ** Note: …` / `Loading work.tb…` style lines — ignore them; the
  verdict line is what decides.
* A line starting with `FAIL` names the failed check (and, for value checks, got vs expected). Any
  `FAIL` also changes the verdict to `FAILED (<N> checks, <E> errors)`.

### 6.3 Check budget per group (72 total)

| Group | Checks | What each one pins down |
| --- | --- | --- |
| T1 | 3 | the three image words in program RAM |
| T2 | 16 | async assert, 2-edge sync deassert, MODE latch + polarity, `cpu_rst`, PC frozen, GPIO reset values, pads dark, strap ignored while held (× 300/50-clock windows) |
| T3 | 18 | run boot, LED0 from the image, self-loop alive (PC = 0x002), strap ignored while running, async reset assertion + async pad clear, relatch on the next boot |
| T4A | 8 | halted, OUT readback, DIR, OUT, GPIO_IN = 0x01, pads = 0001, pad3/pad2 = z |
| T4B | 4 | halted, OUT readback, GPIO_IN = 0x0D, pads = 1101 |
| T5 | 9 | first HALT, R0, RUNNING read, HALTED bit in the read mux, LEDs dark, second HALT, no trap, R0 = 2, LED1 |
| T6 | 7 | trap, halt bit clear, R0 untouched, RUNNING read, TRAPPED bit, pads untouched, trap latched |
| T7 | 4 | soft-reset pulse count ≥ 5, pads stuck at 0101, still running, still not trapped |
| T8 | 3 | halted, exactly one resume pulse, core undisturbed |

### 6.4 The testbench has teeth (mutation check)

To make sure the 72 checks are not passing vacuously, the design was mutated nine times and the
testbench re-run. Every mutation is caught:

| Mutation | Result |
| --- | --- |
| `MODE_INVERT` polarity flipped (run/programming swapped) | FAILED, 45 errors (`T2 MODE latched`, `CPU held`, `PC still 0`, …) |
| `pad_oe` stuck high (no tristate) | FAILED, 6 (`T4A pad3/2 released to z`, `GPIO_IN = 0x01`, …) |
| `GPIO_DIR` reset 0x00 instead of 0x0F | FAILED, 13 (`GPIO_DIR reset value`, pads read `zzzz`, …) |
| `resume` pulse never generated | FAILED, 1 (`T8 bit0 makes exactly one resume pulse`) |
| soft-reset bit ignored | FAILED, 3 (`T7 pulses`, pads → 1111, …) |
| CPU no longer gated by MODE | FAILED, 6 |
| reset synchronizer made synchronous-only | FAILED, 2 (`rst asserts asynchronously`, `pads clear asynchronously`) |
| image not pre-loaded (`INIT_EN` forced 0) | FAILED, 10 (`T1 mem…`, `T3 LED0 lights`, …) |
| Phase-1 fetch bug re-introduced (registered address) | FAILED, 3 (`T3 still no trap`, `T5 R0 after resume`, …) |

The one property a zero-delay RTL simulation cannot observe is the pad 2-flop synchronizer (a mutant
that bypasses it passes): that is a structural constraint, checked by inspection, not by this TB.

---

## 7. Running it

### 7.1 Behavioural simulation (do this before synthesis, spec §15 step 3)

iSIM, one command:

```
phase2\sim\run_isim.bat            (Windows, from an ISE command prompt)
phase2/sim/run_isim.sh             (Linux / Wine)
```

or explicitly (equivalent; this is the POSIX form — on Windows use `run_isim.bat`, which spells the
same command with `^` continuations and `..\` paths):

```sh
cd phase2/sim
fuse -o tb.exe ../tb/tb_s8_top_gpio.v ../rtl/s8_top.v ../rtl/s8_cpu.v ../rtl/s8_alu.v \
     ../rtl/s8_regfile.v ../rtl/s8_program_ram.v ../rtl/s8_data_ram.v ../rtl/s8_bus.v \
     ../rtl/s8_gpio.v ../rtl/s8_mmio.v ../rtl/s8_reset_sync.v ../rtl/s8_mode_latch.v
./tb.exe
```

Icarus Verilog works too (this is what produced §6.2):

```
cd phase2/sim
iverilog -g2005 -o tb.vvp ../tb/tb_s8_top_gpio.v ../rtl/*.v && vvp tb.vvp
```

Run from `phase2/sim/` (or put `gpio_demo.hex` in the run directory): the testbench's `INIT_FILE` is
`../prog/gpio_demo.hex`. If the file is missing, T1 and T3 fail loudly with `mem[0]`/LED0 mismatches
rather than silently passing.

Debug hints: any `FAIL` names the check; the interesting signals are `u_top.rst`,
`u_top.mode_latched`, `u_top.cpu_rst`, `u_top.u_cpu.state`, `u_top.u_cpu.pc`, `u_top.u_mmio.gpio_*`.

### 7.2 Synthesis and bitstream

`ise/build_phase2.tcl` (ISE 14.7, `xtclsh build_phase2.tcl` or `ise -tcl build_phase2.tcl`) creates
`phase2/ise/build/s8_phase2.xise`, adds `phase2/rtl/*.v` + the testbench (simulation view) + the UCF,
sets `s8_top` as top and runs Synthesize → Implement → Generate Programming File. The script has not
been executed on this machine (no ISE here); the GUI equivalent is:

1. New project → family Spartan6, device **xc6slx9**, package **tqg144**, speed **-2**
   (`xc6slx9-2tqg144`).
2. Add `phase2/rtl/*.v` as synthesis sources, `phase2/tb/tb_s8_top_gpio.v` as simulation only,
   `phase2/constraints/board_p2.ucf` as constraints. Copy `phase2/prog/gpio_demo.hex` into the
   project directory (working directory of the XST process).
3. Top module `s8_top` (defaults `MODE_INVERT=1`, `INIT_EN=1`, `INIT_FILE="gpio_demo.hex"`).
4. Synthesize, Implement, Generate Programming File; keep a known-good recovery bitstream.

Cross-check performed here on the RTL (not a substitute for XST): Yosys 0.69 (WASM) elaborates all
eleven files with `hierarchy -check` and `check` reporting **0 problems**, no latches, and maps the
design to Spartan-6 primitives — program RAM → `RAMB16BWER`, data RAM → 8 × `RAM256X1S` (distributed),
42 × `FDRE`, ~70 LUTs/`CARRY4`. So the RTL is synthesis-clean and the memories infer as RAM.

---

## 8. On the board

### 8.1 What you should see

1. **Program** the bitstream over JTAG (iMPACT).
2. DIP0 **open** (board default) → **LED0 (p105) lights within microseconds and stays on**. LED1–LED3
   stay off. This is the Phase-2 gate: spec §6.9.1's `LDI R0,1` / `OUT GPIO_OUT,R0` / `JMP` loop,
   running from the configuration-time image.
3. Press **S2 (reset)**: all LEDs go dark immediately (asynchronous reset) and LED0 comes back on
   within a few 20 ns clocks (reset synchronizer + MODE latch + ~11 instruction times).
4. Close DIP0 and press reset: LEDs stay **off** — MODE = 1 holds the CPU in reset. Re-open DIP0 and
   press reset: the demo runs again. A scope on p105 should show a static high level (no toggling).
5. If LED0 stays dark with DIP0 open: check the bitstream's program-RAM initial contents
   (§8.3 item 2), then the reset button (p87) and DIP0 (p84) polarity — those are the only external
   inputs this bitstream uses.

### 8.2 Notes for first bring-up (spec §5.3)

* FT2232H channel A = JTAG; no FT_PROG EEPROM change is needed for Phase 2 (there is no UART yet).
* The flash (W25Q64BV) is **not touched**: nothing in `phase2/rtl` drives p38/p61/p62/p64/p65/p70, and
  the UCF does not assign them, so the configuration region is safe by construction.

### 8.3 Report checklist (record these; §18 asks for them)

1. **BRAM inference** — `s8_program_ram` must appear as block RAM (`RAMB16BWER`, 2048×9 mode, 2 wide ×
   2 deep = 4 blocks, spec §4/§15). If it infers distributed RAM, the array coding was altered.
2. **RAM initial contents** — XST log/`.syr` should mention the initialised memory / no
   "initial value not supported" warning. If the image did not make it, LED0 stays dark: fall back to
   an explicit `INIT_00` attribute or wait for the Phase-4 loader.
3. **Timing** — `trce`/`TS_sys_clk` must meet 20.000 ns with margin; note slack. The design is tiny
   (one 8-bit ALU, one 12-bit adder, one FSM), so expect a large positive slack; a violation means
   something else went wrong (e.g. `-2` speed grade or the PERIOD constraint missing).
4. **Utilization** — `map`/`par` slice, LUT, FF and BRAM counts; the Phase-6 budget is ≤ 60 % slices,
   Phase 2 should be a couple of percent.
5. **Unmatched constraints** — ngdbuild should report none (only the 7 nets used here are assigned).

---

## 9. Exit gate and what comes next

Phase-2 gate status: simulation green (72/72), UCF and top level complete for CPU+GPIO, bitstream
build pending on an ISE machine, board observation pending.

Before Phase 3 (UART), two things are worth doing:

1. **Back-port §5.1/§5.3** to `rtl/s8_cpu.v` and `rtl/s8_bus.v`, fix `tb_s8_alu`'s sweep and message
   format, and correct the Phase-1 guide's "PASSED" claims. Then do §5.4 (the read-wait cycle in
   `MEM`), which Phase 3's echo program does not need but any `LD`-using program does.
2. Keep the phase boundary: Phase 3 adds `baud_gen`, `uart_rx`, `uart_tx`, `uart_regs`, extends
   `s8_mmio` with ports 3/4, grows `s8_top`'s port list by `uart_rxd/uart_txd` and enables those two
   UCF lines.

---

## Appendix A — Program encodings used by the testbench

All words are spec §6.7-conformant; `IN`/`OUT` use the port field.

| Word | Instruction | Word | Instruction |
| --- | --- | --- | --- |
| `1001` | `LDI R0,1` | `A200` | `IN R1,GPIO_OUT` |
| `1005` | `LDI R0,5` | `A380` | `IN R1,CPU_CONTROL` |
| `1201` | `LDI R1,1` | `A640` | `IN R3,GPIO_IN` |
| `1202` | `LDI R1,2` | `5000` | `OUT GPIO_OUT,R0` |
| `1403` | `LDI R2,3` | `5480` | `OUT GPIO_DIR,R2` |
| `4002` | `JMP 0x002` | `5C40` | `OUT CPU_CONTROL,R1` |
| `E000` | reserved opcode → TRAP | `F000` | `HALT` |

## Appendix B — Phase-2 copies vs `rtl/` (SHA-256, first 16 hex digits)

| File | `rtl/` (Phase 1) | `phase2/rtl/` | |
| --- | --- | --- | --- |
| `s8_alu.v` | `08be7144051cfee8` | `08be7144051cfee8` | identical |
| `s8_regfile.v` | `f40a812f94f38ae7` | `f40a812f94f38ae7` | identical |
| `s8_data_ram.v` | `6e2661abe598eb9a` | `6e2661abe598eb9a` | identical |
| `s8_cpu.v` | `2d30dd66c12ecd6a` | `869ad03abffd8245` | fetch fix (§5.1) |
| `s8_bus.v` | `d76125250beccff5` | `ab02ba0738a5be6d` | MMIO decode fix (§5.3) |
| `s8_program_ram.v` | `f2ebce1f146c336b` | `9a9883c627266ddf` | `INIT_EN`/`INIT_FILE` (§3.6) |
