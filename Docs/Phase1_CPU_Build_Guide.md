# S8 Phase-1 Build Guide — CPU Core (RTL + Testbenches + Expected Results)

Target: **XC6SLX9-2TQG144C on Farad-1** (50 MHz, `rst_n` p87) · Toolchain: **Xilinx ISE 14.7**
(Verilog-2001, iSIM for simulation) · Spec: `docs/S8_Technical_Specification_v1.1.md`

This file is the single reference for Phase 1 (spec §18: CPU core). It contains every
HDL file, every testbench, and — for each testbench — exactly what the simulation
transcript must show. **If a result below does not reproduce, the code is wrong;
fix it against the spec sections quoted, never against these expected values.**

> No simulator (iSIM/XST) is installed on this machine, so the RTL was verified by
> (a) an independent JS ISA reference model (encoding + execution semantics written
> separately from the spec text — all 36 program words and the full final state
> below are machine-confirmed), and (b) a line-by-line audit of the Verilog
> (including a real MEM-sequencing bug and a HALT-resume bug that were found and
> fixed during review — see §7). Run the `fuse` commands in §6 on your ISE machine;
> every TB is self-checking and must end in `PASSED … 0 errors`.

## Contents

1. [File map](#1-file-map)
2. [Step 1 — `s8_alu` (combinational ALU)](#2-step-1--s8_alu-combinational-alu)
3. [Step 2 — `s8_regfile`](#3-step-2--s8_regfile)
4. [Step 3 — `s8_program_ram`](#4-step-3--s8_program_ram)
5. [Step 4 — `s8_data_ram`](#5-step-4--s8_data_ram)
6. [Step 5 — `s8_bus`](#6-step-5--s8_bus)
7. [Step 6 — `s8_cpu` (control FSM + datapath)](#7-step-6--s8_cpu-control-fsm--datapath)
8. [Testbenches + expected results](#8-testbenches--expected-results)
9. [How to run in ISE 14.7](#9-how-to-run-in-ise-147)
10. [Phase-1 exit gate status](#10-phase-1-exit-gate-status)

## 1. File map

```
rtl/
  s8_alu.v            Step 1 - combinational ALU (spec 6.5, 9)
  s8_regfile.v        Step 2 - 8x8 register file (spec 8.1, 9)
  s8_program_ram.v    Step 3 - 4096x16 BRAM, CPU/loader shared port (spec 7.1, 9)
  s8_data_ram.v       Step 4 - 240x8 distributed RAM 0x00-0xEF (spec 7.2, 9)
  s8_bus.v            Step 5 - decode + read mux, MMIO rule (spec 7.2, 7.3, 8.3, 9)
  s8_cpu.v            Step 6 - FSM + datapath (spec 6, 7, 8, 9)
tb/
  tb_s8_alu.v         ~534k self-checks: directed corners + exhaustive sweeps
  tb_s8_regfile.v     13 self-checks: reset, ports, write timing, we=0
  tb_s8_cpu_programs.v  39 self-checks: 8 scenarios (T1-T8, §8.4)
```

Build order matters: ALU → regfile → memories/bus → CPU. Each step simulates
standalone before the next begins.

## 2. Step 1 — `s8_alu` (combinational ALU)

Spec: §6.5 flag formulas (normative), §9 `s8_alu` row. Pure `always @*`, no clock,
no reset. `alu_op`: 0 ADD, 1 SUB, 2 AND, 3 OR, 4 XOR, 5 CMP, 6 MOV, 7 NOT,
8 SHL, 9 SHR, 10 ROL, 11 ROR (others → safe zero).

```verilog
// (full listing of rtl/s8_alu.v - 12 ops per §6.5; SHL/SHR carry = last bit
// shifted out, 0 when amount==0; ROL/ROR carry = 0; NOT sources op_b)
```

The complete file is `rtl/s8_alu.v` (written in this repo). Key lines to get right:

- ADD: `sum9 = {1'b0,op_a}+{1'b0,op_b}; C=sum9[8]; O=(a7==b7)&&(r7!=a7)`
- SUB/CMP: `diff9 = {1'b0,op_a}-{1'b0,op_b}; C=~diff9[8]` (C=1 iff a>=b)
- Logic/MOV/NOT/LDI: Z,N from result; `C=0; O=0`
- SHL amount `amt=op_b[2:0]`: `C` = bit leaving position 7 (`op_a[8-amt]`,
  `C=0` when `amt==0`); SHR mirrored from position 0; ROL/ROR `C=0`

### Expected `tb_s8_alu` result

Directed corners (all must match exactly):

| Stimulus | result | Z | C | N | O |
|---|---|---|---|---|---|
| ADD 7F+01 | 80 | 0 | 0 | 1 | 1 |
| ADD FF+01 | 00 | 1 | 1 | 0 | 0 |
| ADD 80+80 | 00 | 1 | 1 | 0 | 1 |
| SUB 00-01 | FF | 0 | 0 | 1 | 0 |
| SUB 80-01 | 7F | 0 | 1 | 0 | 1 |
| SUB 05-05 | 00 | 1 | 1 | 0 | 0 |
| SUB 7F-FF | 80 | 0 | 0 | 1 | 1 |
| AND A5,0F | 05 | 0 | 0 | 0 | 0 |
| OR A0,05 | A5 | 0 | 0 | 1 | 0 |
| XOR FF,FF | 00 | 1 | 0 | 0 | 0 |
| MOV (a=12,b=34) | 34 | 0 | 0 | 0 | 0 |
| NOT (a=12,b=34) | CB | 0 | 0 | 1 | 0 |
| CMP 05,03 | 02 | 0 | 1 | 0 | 0 |
| SHL 81 by 1 | 02 | 0 | 1 | 0 | 0 |
| SHL 81 by 0 | 81 | 0 | 0 | 1 | 0 |
| SHL FF by 7 | 80 | 0 | 1 | 1 | 0 |
| SHR 03 by 2 | 00 | 1 | 1 | 0 | 0 |
| SHR 81 by 1 | 40 | 0 | 1 | 0 | 0 |
| ROL 81 by 1 | 03 | 0 | 0 | 0 | 0 |
| ROR 81 by 1 | C0 | 0 | 0 | 1 | 0 |
| ROL FF by 3 | FF | 0 | 0 | 1 | 0 |

Then exhaustive sweeps (reference computed independently in the TB):
ADD 65 536 pairs, SUB 65 536, CMP 65 536, AND/OR/XOR/MOV/NOT 5×65 536,
shifts 2 048 (a,k) × 5 variants (incl. `op_b` high-bits-set masking proof),
unused opcodes 12–15 → zero. **Transcript must end with:**

```
tb_s8_alu: PASSED (534553 checks, 0 errors)
```

## 3. Step 2 — `s8_regfile`

Spec: §8.1, §9. 8×8 bits, async dual read, sync write, sync active-high reset
clears R0–R7. No debug ports — the TB uses hierarchical references
(`u_cpu.u_regfile.regs[i]`), per §9. Full listing: `rtl/s8_regfile.v`.

Read-during-write rule (verified in TB): the async ports show the OLD value
until the clock edge commits the write; the CPU never samples a register it
writes in the same cycle, so no bypass logic exists by design.

### Expected `tb_s8_regfile` result

1. Reset (3 edges, `rst=1`) → R0=R7=`0x00`.
2. Write R0–R7 = `0x10`–`0x17` → both ports read back correctly, including
   split pairs (port A = Ri, port B = R7−i).
3. Mid-cycle read-during-write shows OLD (`0x12`); after the edge both ports
   show new (`0xAA`).
4. `we=0` for 2 cycles leaves the array untouched.
5. Second reset clears again. **Transcript must end with:**

```
tb_s8_regfile: PASSED (13 checks, 0 errors)
```

## 4. Step 3 — `s8_program_ram`

Spec: §7.1, §9. 4096×16 synchronous BRAM, word-addressed by PC. Address in at
one edge, word out at the next (this is why the CPU has FETCH_REQ + FETCH_WAIT).
Single read port shared CPU/loader via `sel_load`; the loader writes only while
the CPU is held in reset. Read-first (simultaneous write+read returns OLD data).
**No reset on the array** (required for BRAM inference). Sim-only assertion:
`cpu_en && sel_load` in one cycle → `$display` + `$finish`.
Full listing: `rtl/s8_program_ram.v`.

XST check (spec §15 step 4): report must show **RAMB16BWER inference
(2048×9 mode, 2 wide × 2 deep = 4 blocks)** — if it infers distributed RAM,
the array coding was altered; fix it, the TB below assumes 1-cycle sync read.

## 5. Step 4 — `s8_data_ram`

Spec: §7.2, §9. 240×8 at 0x00–0xEF (0x00–0xDF variables, 0xE0–0xEF stack),
same sync-read semantics as program RAM. Range check lives in `s8_bus`;
sim-only assertion fires if `addr > 0xEF` with `re/we`. No reset on the array
(distributed-RAM inference, ~30 LUTs, 0 BRAM). Full listing: `rtl/s8_data_ram.v`.

## 6. Step 5 — `s8_bus`

Spec: §7.2, §7.3, §8.3, §9. Purely combinational. Single decode rule:

```
mmio     = addr[7] & addr[6] & addr[5]   // addr >= 0xF0
mmio_hit = mmio & ~addr[3]               // 0xF0-0xF7 valid
```

RAM gets everything below 0xF0. `0xF8–0xFF` reserved: reads `0x00`, writes
ignored, no trap (§7.2). IN/OUT need no special case — the CPU presents
`0xF0|port` (§6.4 "identical hardware decode"). `ready` tied 1 in v1 (§8.3:
the CPU still implements the wait loop for future peripherals).
Full listing: `rtl/s8_bus.v`. No standalone TB (covered inside T2/T8 below:
LD/ST paths, MMIO filter via GPIO/UART ports, reserved-range behavior is
structural from the two assign lines).

## 7. Step 6 — `s8_cpu` (control FSM + datapath)

Spec: §6 (ISA), §7 (map), §8 (microarchitecture), §9. Full listing: `rtl/s8_cpu.v`.
States are §8.2 verbatim — RESET, FETCH_REQ, FETCH_WAIT, DECODE, EXECUTE, MEM,
HALT, TRAP — no added states.

Datapath wiring:

- `raddr_a = (opcode==OUT) ? rs : rd`, `raddr_b = rs` (async; settled by EXECUTE).
- `alu_a = reg_a`; `alu_b = imm8 (LDI) / {2'b0,imm6} (RI) / reg_b`.
- `alu_op`: R-funct 0–7 direct; LDI→MOV(6); RI-funct→ADD/AND/OR/CMP;
  SHIFT-funct→8–11. CMP/CMPI update flags but the CPU suppresses the rd write.
- Branch: `target = (PC+1 + sext(rel8)) mod 4096`; conditions Z NZ C NC N **P O**
  on `ir[11:9]`.
- DECODE illegality (trap before EXECUTE): R/SHIFT low 3 bits; RI bit 6;
  M/P low 6 bits; Jcc cond==7 **or bit 8**; S low 12 bits; U low 9 bits;
  opcode `0xE`.
- EXECUTE drives the bus early for memory ops (address+re/we), so LD/ST finish
  in a single MEM cycle; MEM commits writeback/SP/PC when `bus_ready`.
  CALL/RET use two MEM phases (two stack slots — see D1).

Cycle counts: ALU/reg/branch 4 · LD/ST/IN/OUT/PUSH/POP 5 · CALL/RET 6.

Frozen design decisions (spec is silent; do not "re-decide" per build):

| # | Decision |
|---|---|
| D1 | 12-bit return address = **two stack bytes**: CALL writes `{4'b0,PC_after[11:8]}` to `[SP−1]`, then `PC_after[7:0]` to `[SP−2]`; RET pops low from `[SP]`, high nibble from `[SP+1]`. Pre-checks (fault leaves SP/memory untouched): CALL SP∈[E2..F0], RET SP∈[E0..EE], PUSH SP∈[E1..F0], POP SP∈[E0..EF] |
| D2 | `JP` = `~N` (zero counts as positive); `JO` = O flag |
| D3 | Jcc bit 8 (unassigned by every golden vector) = must-be-zero; set → TRAP |
| D4 | `resume_i` input pin: a halted core executes nothing, so `CPU_CONTROL.resume` must come from outside (top level wires the `uart_regs` bit; TB drives it) |
| D5 | IN/OUT reuse the LD/ST bus path at address `0xF0\|port` |
| D6 | HALT advances PC past itself, so `resume_i` continues with the next instruction |
| D7 | TB/top ties `cpu_en = ~sel_load`: the CPU samples `instr` only in FETCH_WAIT, so this is functionally identical to a fetch strobe |

## 8. Testbenches + expected results

Full listings: `tb/tb_s8_alu.v`, `tb/tb_s8_regfile.v`, `tb/tb_s8_cpu_programs.v`
(the latter includes the Phase-1 `tb_mmio_stub`: GPIO regs + UART loopback with
RX_VALID/TX_READY semantics, replaced by `s8_gpio`/`uart_regs` in Phases 2–3).

### 8.1 `tb_s8_cpu_programs` scenarios

50 MHz TB clock. Programs load via the loader port with the CPU in reset
(spec §7.1 ownership rule). A global watchdog `#2000000` kills a hung run.

**T1 — GPIO blink-seed (spec §6.9.1).** Load `1001 / 5000 / 4002`, run 120 +
200 cycles. Expect: `gpio_out == 4'h1` both times, `halted == 0`,
`trapped == 0` (proves the `JMP 0x002` self-loop is alive).

**T2 — Main functional program (36 words).** Every ISA group, CALL/RET byte
order, a taken branch, HALT. Words (machine-verified by the reference model):

| addr | word | instruction | addr | word | instruction |
|---|---|---|---|---|---|
| 0 | 1005 | LDI R0,5 | 18 | DF80 | SHL R7,R6 → R7=02,C=1 |
| 1 | 1203 | LDI R1,3 | 19 | DF88 | SHR R7,R6 → R7=01,C=0 |
| 2 | 0040 | ADD R0,R1 → R0=8 | 20 | DF90 | ROL R7,R6 → R7=02 |
| 3 | 0048 | SUB R0,R1 → R0=5 | 21 | DF98 | ROR R7,R6 → R7=01 |
| 4 | 0050 | AND R0,R1 → R0=1 | 22 | BA00 | PUSH R5 (SP→EF) |
| 5 | 0058 | OR R0,R1 → R0=3 | 23 | 1A00 | LDI R5,0 |
| 6 | 0060 | XOR R0,R1 → R0=0,Z=1 | 24 | CA00 | POP R5 → R5=35,SP=F0 |
| 7 | 14FF | LDI R2,FF | 25 | 7022 | CALL 34 |
| 8 | 2401 | ADDI R2,1 → R2=0,Z=1,C=1 | 26 | 5000 | OUT GPIO_OUT,R0 → gpio=2 |
| 9 | 16A5 | LDI R3,A5 | 27 | A440 | IN R2,GPIO_IN → R2=0A |
| 10 | 268F | ANDI R3,0F → R3=05 | 28 | 258A | CMPI R2,0A → Z=1 |
| 11 | 2730 | ORI R3,30 → R3=35 | 29 | 6002 | JZ 32 (taken, skips 30–31) |
| 12 | 1810 | LDI R4,10 | 30 | 14EE | LDI R2,EE (skipped) |
| 13 | 8700 | ST R3,[R4] → M[10]=35 | 31 | 4021 | JMP 33 (skipped) |
| 14 | 1A00 | LDI R5,0 | 32 | 1442 | LDI R2,42 |
| 15 | 3B00 | LD R5,[R4] → R5=35 | 33 | F000 | HALT |
| 16 | 1C01 | LDI R6,1 | 34 | 2002 | sub: ADDI R0,2 → R0=2 |
| 17 | 1E81 | LDI R7,81 | 35 | 9000 | RET (SP→F0) |

Run until `halted` (34 instructions retire). **Expected final state:**

```
R0=02 R1=03 R2=42 R3=35 R4=10 R5=35 R6=01 R7=01
SP=F0  M[0x10]=35  M[0xEF]=00 (return-ad high nibble)  M[0xEE]=1A (return lo = 26)
gpio_out=2  flags Z=C=N=O=0 (last writer: LDI)  halted=1  trapped=0
```

R2 ending `0x42` (not `0xEE`) is the taken-branch proof; `M[EF]/M[EE]`
pin the D1 CALL byte order.

**T3 — HALT + resume.** `[1001, F000, 1002, F000]`: halt with R0=1 → 2-cycle
`resume_i` pulse → run on → halt again with R0=2, never trapped.

**T4 — TRAP on opcode 0xE.** `[E000, …]`: `trapped=1`, `halted=0`, R0 untouched,
still trapped 20 cycles later (latched, §6.6), `trapped=0` after reset.

**T5 — TRAP on reserved bits.** `[0007]` (ADD R0,R0, low bits 111): trapped.

**T6 — Stack overflow.** 17× `PUSH R0`: trapped on the 17th, `SP==0xE0`
(16 pushes land EF…E0), sentinel `M[0xDF]==0xAA` proves the faulting push
wrote nothing (check-before-commit, §6.6).

**T7 — Stack underflow.** `[C000]` on empty stack: trapped, `SP==0xF0`.

**T8 — UART echo (spec §6.9.2).** Load
`A2C0 2281 60FD A100 A2C0 2282 60FD 5800 4000`, inject `0x55`:
TB must observe `tx_valid` with `tx_byte == 0x55`, no trap.

**Transcript must end with:**

```
tb_s8_cpu_programs: PASSED (39 checks, 0 errors)
```

## 9. How to run in ISE 14.7

In the ISE project (exact part `xc6slx9-2tqg144`): add `rtl/*.v` to the
**synthesis** sources, `tb/*.v` to the **simulation** (test-bench) sources.
Behavioral simulation **before** any synthesis (spec §15 steps 2–3):

```tcl
# ISim command line (or the GUI equivalent: Simulate Behavioral Model)
fuse -o tb_s8_alu.exe tb_s8_alu.v ../rtl/s8_alu.v && ./tb_s8_alu.exe
fuse -o tb_s8_regfile.exe tb_s8_regfile.v ../rtl/s8_regfile.v && ./tb_s8_regfile.exe
fuse -o tb_cpu.exe tb_s8_cpu_programs.v ../rtl/s8_cpu.v ../rtl/s8_alu.v \
     ../rtl/s8_regfile.v ../rtl/s8_program_ram.v ../rtl/s8_data_ram.v \
     ../rtl/s8_bus.v && ./tb_cpu.exe
```

Any `FAIL` line names the check; wave-debug from the named signal
(e.g. `u_cpu/state`, `u_cpu/sp`). Then synthesis: confirm **BRAM inference
for `s8_program_ram`** and record utilization against the §5.4 budget
(≤ 60 % slices at end of Phase 6).

## 10. Phase-1 exit gate status

Spec §18 gate: `tb_s8_alu` + `tb_s8_regfile` + `tb_s8_cpu_programs` pass,
golden-vector sweep green, HALT/TRAP/stack-fault green.

- RTL + TB written: `s8_alu`, `s8_regfile`, `s8_program_ram`, `s8_data_ram`,
  `s8_bus`, `s8_cpu`, `tb_s8_alu`, `tb_s8_regfile`, `tb_s8_cpu_programs`.
- Reference-model verification (this machine): CRC/encodings reproduce the
  spec tables; all 36 T2 words and the full §8.1 final state machine-confirmed.
- Two genuine RTL bugs were caught in review and fixed: (1) CALL/RET phase-1
  transfer never presented (MEM advanced without driving it); (2) HALT did not
  advance PC, so resume re-executed HALT. Both are covered by T2/T3.
- Remaining step on your ISE machine: run the three `fuse` commands above —
  all must print `PASSED … 0 errors`. Then Phase 2 (`s8_top` + `constraints/board.ucf`
  from spec §15, GPIO demo on LED0/p105) can start.

*End of Phase-1 build guide.*
