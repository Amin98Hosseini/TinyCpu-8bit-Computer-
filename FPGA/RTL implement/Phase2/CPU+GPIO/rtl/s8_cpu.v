// =============================================================================
// Module : s8_cpu
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Sections 6 (ISA v1),
//          7 (memory map), 8 (microarchitecture) and 9 (s8_cpu row)
//
// PHASE-2 COPY - one fix relative to rtl/s8_cpu.v:
//   * instr_addr is now combinational (assign instr_addr = pc). The Phase-1
//     copy registered it one edge late, so the synchronous program RAM
//     returned the PREVIOUS word and every instruction executed one behind
//     pc. Details and evidence: phase2/PHASE2_GPIO_BRINGUP.md section 6.
//
// KNOWN OPEN DEFECT (Phase 1, NOT fixed here, NOT exercised by Phase 2):
//   The data-bus READ path commits one cycle too early. LD / POP / RET read
//   bus_rdata at the end of the single MEM cycle, but s8_data_ram presents
//   its data one edge AFTER addr/re are sampled, so the CPU captures the
//   previous cycle's byte. ST / OUT / PUSH (writes) are correct, and IN is
//   correct because MMIO reads are combinational. Consequence: LD returns a
//   stale byte (often 0x00 or the previous read), and RET returns to a wrong
//   address. The fix is a one-cycle read wait in MEM (or presenting the read
//   address combinationally one cycle earlier, as done for instr_addr above);
//   it belongs with the Phase-1 CPU repair and must keep RD_CNT at 5/6
//   cycles. Phase 2 only uses LDI/OUT/IN/JMP/HALT/TRAP, so the GPIO bring-up
//   is unaffected - see section 6 of the Phase-2 doc for the full analysis.
//
// Function: multicycle control FSM + datapath (register file, ALU, PC, SP,
// flags). One instruction per state sequence; no pipelining (spec 8.2).
//
// States (spec 8.2, verbatim - no added states):
//   RESET      init PC/SP/flags/status                -> FETCH_REQ
//   FETCH_REQ  instr_addr = PC                         -> FETCH_WAIT
//   FETCH_WAIT latch instruction word                 -> DECODE
//   DECODE     validate unused-bit rules, else TRAP    -> EXECUTE / TRAP
//   EXECUTE    ALU / branch / latch memory op         -> MEM / FETCH_REQ / HALT / TRAP
//   MEM        bus transfer (+writeback folded in)     -> FETCH_REQ
//   HALT       idle until resume_i or reset            -> FETCH_REQ / HALT
//   TRAP       latched stop                           -> RESET only
//
// Cycle counts: ALU/reg ops 4 cycles, LD/ST/IN/OUT/PUSH/POP 5 cycles,
// CALL/RET 6 cycles (two stack slots - see below). Spec 8.2 quotes 3-5 as
// the unoptimized expectation; the extra cycle on CALL/RET is the
// documented cost of the 2-byte return address (correctness first, spec 8.2).
//
// DESIGN DECISIONS where the spec is silent (frozen here, Phase-1 scope):
//  D1. 12-bit return address on an 8-bit stack: CALL pushes TWO bytes -
//      first the high nibble {4'b0,PC_after[11:8]} at [SP-1], then the low
//      byte PC_after[7:0] at [SP-2]; SP decrements twice. RET pops in
//      reverse (low from [SP], high nibble from [SP+1]) and increments
//      twice. Bounds are checked BEFORE any bus activity, so a faulting
//      CALL/RET leaves SP and memory unmodified (spec 6.6).
//      Valid SP before: CALL [0xE2..0xF0], RET [0xE0..0xEE],
//                       PUSH [0xE1..0xF0], POP [0xE0..0xEF].
//  D2. JP (positive) condition = ~N (zero counts as positive). JO = O flag.
//  D3. B-format (Jcc) bit 8 is unassigned by every golden vector (all have
//      bit 8 = 0); it is treated as a must-be-zero unused bit, i.e. a set
//      bit 8 traps under the spec 6.2 unused-bits rule.
//  D4. resume_i input: a halted CPU executes nothing, so CPU_CONTROL.resume
//      must arrive from OUTSIDE the core (the uart_regs bit). Top level
//      wires it; the Phase-1 testbench drives it directly.
//  D5. IN/OUT reuse the LD/ST bus path with address 0xF0|port (spec 6.4:
//      "identical hardware decode").
//  D8. (Phase 2) instr_addr is driven COMBINATIONALLY from pc, per spec 8.2
//      "FETCH_REQ: Drive program-RAM address = PC" - see the fix note in the
//      file header. Phase-1 D7 (cpu_en tied high) stays valid.
// Reset: rst is active-high, async assert / sync deassert (the top-level
// two-flop synchronizer from spec 2 provides this shape; the testbench
// holds reset for >= 2 clocks). rst is also forwarded to the register
// file, so R0-R7 clear together with the FSM.
// =============================================================================

module s8_cpu (
    input         clk,
    input         rst,         // active high: async assert, sync deassert
    input         resume_i,    // 1-cycle+ pulse: exit HALT (from CPU_CONTROL)
    // program-memory (fetch) side - s8_program_ram CPU port
    input  [15:0] instr,       // word valid 1 cycle after instr_addr
    // PHASE-2 FIX: the program-RAM address is driven COMBINATIONALLY from pc
    // (spec 8.2 FETCH_REQ: "Drive program-RAM address = PC"). The Phase-1
    // copy registered it one edge late, so the synchronous RAM loaded the
    // PREVIOUS word and every instruction executed was the one before pc.
    // That is why the Phase-1 CPU testbench reports "T1 not trapped" and a
    // divergent T2 under a real simulator. See section 6 of the Phase-2 doc.
    output [11:0] instr_addr,
    // data-bus side - s8_bus CPU port (spec 8.3)
    output reg [7:0] bus_addr,
    output reg       bus_re,
    output reg       bus_we,
    output reg [7:0] bus_wdata,
    input  [7:0]     bus_rdata,
    input            bus_ready,
    // status (feeds CPU_CONTROL read bits, spec 7.3)
    output reg       halted,
    output reg       trapped
);

    // ---- FSM states (spec 8.2) ----
    localparam [2:0] ST_RESET      = 3'd0,
                     ST_FETCH_REQ  = 3'd1,
                     ST_FETCH_WAIT = 3'd2,
                     ST_DECODE     = 3'd3,
                     ST_EXECUTE    = 3'd4,
                     ST_MEM        = 3'd5,
                     ST_HALT       = 3'd6,
                     ST_TRAP       = 3'd7;

    // ---- latched memory-operation codes ----
    localparam [2:0] MEMOP_NONE = 3'd0,
                     MEMOP_RD   = 3'd1, // LD / IN  : 1 read,  write back rd
                     MEMOP_WR   = 3'd2, // ST / OUT : 1 write
                     MEMOP_PUSH = 3'd3, // 1 write at SP-1
                     MEMOP_POP  = 3'd4, // 1 read  at SP,     write back rd
                     MEMOP_CALL = 3'd5, // 2 writes (D1: high nibble, low byte)
                     MEMOP_RET  = 3'd6; // 2 reads  (D1: low byte, high nibble)

    reg [2:0] state;

    // ---- architectural state ----
    reg [11:0] pc;      // word address 0x000-0xFFF
    reg [7:0]  sp;      // byte address, reset 0xF0 (empty stack)
    reg [15:0] ir;      // latched instruction word
    reg        flag_z, flag_c, flag_n, flag_o;

    // ---- datapath instances ----
    wire [3:0] opcode = ir[15:12];
    wire [2:0] rd_f   = ir[11:9];
    wire [2:0] rs_f   = ir[8:6];

    wire [7:0] reg_a, reg_b; // async read data
    reg        rf_we;
    reg  [2:0] rf_waddr;
    reg  [7:0] rf_wdata;

    s8_regfile u_regfile (
        .clk     (clk),
        .rst     (rst),
        .raddr_a ((opcode == 4'h5) ? rs_f : rd_f), // OUT has no rd: needs rs
        .raddr_b (rs_f),
        .waddr   (rf_waddr),
        .wdata   (rf_wdata),
        .we      (rf_we),
        .rdata_a (reg_a),
        .rdata_b (reg_b)
    );

    // ALU operand mux: LDI takes imm8, RI-group takes zero-extended imm6
    wire [7:0] alu_a = reg_a;
    wire [7:0] alu_b = (opcode == 4'h1) ? ir[7:0] :
                       (opcode == 4'h2) ? {2'b00, ir[5:0]} : reg_b;
    reg  [3:0] alu_op;
    wire [7:0] alu_result;
    wire       alu_z, alu_c, alu_n, alu_o;

    s8_alu u_alu (
        .op_a   (alu_a),
        .op_b   (alu_b),
        .alu_op (alu_op),
        .result (alu_result),
        .flag_z (alu_z),
        .flag_c (alu_c),
        .flag_n (alu_n),
        .flag_o (alu_o)
    );

    always @* begin
        case (opcode)
            4'h0:    alu_op = {1'b0, ir[5:3]}; // funct -> ADD..NOT
            4'h1:    alu_op = 4'd6;            // LDI = MOV(imm8)
            4'h2: begin // RI group: funct[8:7]
                case (ir[8:7])
                    2'b00:   alu_op = 4'd0; // ADDI -> ADD
                    2'b01:   alu_op = 4'd2; // ANDI -> AND
                    2'b10:   alu_op = 4'd3; // ORI  -> OR
                    default: alu_op = 4'd5; // CMPI -> CMP
                endcase
            end
            4'hD:    alu_op = {1'b1, ir[5:3]}; // funct -> SHL..ROR (8..11)
            default: alu_op = 4'd0;
        endcase
    end

    // ---- program-RAM address: pc, presented during FETCH_REQ (spec 8.2) ----
    assign instr_addr = pc;

    // ---- branch target: (PC_after + sext(rel8)) mod 4096 (spec 6.4) ----
    wire [11:0] pc_plus1 = (pc + 12'h001) & 12'hFFF;
    wire [12:0] br_sum   = {1'b0, pc_plus1} + {{5{ir[7]}}, ir[7:0]};
    wire [11:0] br_target = br_sum[11:0];

    reg take;
    always @* begin
        case (ir[11:9]) // cond field
            3'd0:    take = flag_z;   // JZ
            3'd1:    take = ~flag_z;  // JNZ
            3'd2:    take = flag_c;   // JC
            3'd3:    take = ~flag_c;  // JNC
            3'd4:    take = flag_n;   // JN
            3'd5:    take = ~flag_n;  // JP (D2: zero counts as positive)
            3'd6:    take = flag_o;   // JO
            default: take = 1'b0;     // cond 7: illegal (traps in DECODE)
        endcase
    end

    // ---- DECODE-time legality check (spec 6.2 unused-bits rule) ----
    reg illegal;
    always @* begin
        case (opcode)
            4'h0,
            4'hD:    illegal = (ir[2:0] != 3'b000); // R: low bits must be 0
            4'h1:    illegal = 1'b0;                // LDI: all bits used
            4'h2:    illegal = ir[6];               // RI: bit 6 must be 0
            4'h3,
            4'h8:    illegal = (ir[5:0] != 6'b0);   // M: low bits must be 0
            4'h4,
            4'h7:    illegal = 1'b0;                // A: all bits used
            4'h5,
            4'hA:    illegal = (ir[5:0] != 6'b0);   // P: low bits must be 0
            4'h6:    illegal = (ir[11:9] == 3'd7) | ir[8]; // cond 7, bit 8 (D3)
            4'h9,
            4'hF:    illegal = (ir[11:0] != 12'b0); // S: must be all zero
            4'hB,
            4'hC:    illegal = (ir[8:0] != 9'b0);   // U: low bits must be 0
            default: illegal = 1'b1;                // 0xE: reserved -> TRAP
        endcase
    end

    // ---- MEM-phase latches ----
    reg [2:0] memop;
    reg       phase;            // 0 = first transfer, 1 = second (CALL/RET)
    reg [7:0] mem_addr1, mem_addr2;
    reg [7:0] mem_wdata1, mem_wdata2;
    reg [2:0] mem_wb;           // rd to write back on reads
    reg [11:0] pc_lat;          // PC commit value for memory ops
    reg [7:0]  sp_lat;          // SP commit value for stack ops
    reg [7:0]  ret_lo;          // RET phase-0 capture (low return byte)

    wire is_read  = (memop == MEMOP_RD) | (memop == MEMOP_POP) |
                    (memop == MEMOP_RET);
    wire is_write = (memop == MEMOP_WR) | (memop == MEMOP_PUSH) |
                    (memop == MEMOP_CALL);
    wire last_phase = (memop == MEMOP_CALL) | (memop == MEMOP_RET)
                      ? phase : 1'b1;
    wire [7:0] cur_addr  = phase ? mem_addr2  : mem_addr1;
    wire [7:0] cur_wdata = phase ? mem_wdata2 : mem_wdata1;

    // ---- main FSM: async assert, sync deassert reset (spec 2) ----
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state      <= ST_RESET;
            pc         <= 12'h000;
            sp         <= 8'hF0;
            ir         <= 16'h0000;
            flag_z     <= 1'b0;
            flag_c     <= 1'b0;
            flag_n     <= 1'b0;
            flag_o     <= 1'b0;
            halted     <= 1'b0;
            trapped    <= 1'b0;
            bus_addr   <= 8'h00;
            bus_re     <= 1'b0;
            bus_we     <= 1'b0;
            bus_wdata  <= 8'h00;
            rf_we      <= 1'b0;
            rf_waddr   <= 3'b000;
            rf_wdata   <= 8'h00;
            memop      <= MEMOP_NONE;
            phase      <= 1'b0;
        end else begin
            // defaults: single-cycle strobes drop unless re-asserted below
            rf_we  <= 1'b0;

            case (state)
                ST_RESET: begin
                    // (outputs already safed by the async branch / defaults)
                    state <= ST_FETCH_REQ;
                end

                ST_FETCH_REQ: begin
                    bus_re     <= 1'b0;
                    bus_we     <= 1'b0;
                    state      <= ST_FETCH_WAIT;
                end

                ST_FETCH_WAIT: begin
                    ir    <= instr; // synchronous-RAM word now valid
                    state <= ST_DECODE;
                end

                ST_DECODE: begin
                    if (illegal) begin
                        trapped <= 1'b1;
                        state   <= ST_TRAP;
                    end else begin
                        state <= ST_EXECUTE;
                    end
                end

                ST_EXECUTE: begin
                    bus_re <= 1'b0;
                    bus_we <= 1'b0;
                    case (opcode)
                        4'h0: begin // ALU reg-reg (CMP: flags only)
                            if (ir[5:3] != 3'd5) begin
                                rf_waddr <= rd_f;
                                rf_wdata <= alu_result;
                                rf_we    <= 1'b1;
                            end
                            flag_z <= alu_z; flag_c <= alu_c;
                            flag_n <= alu_n; flag_o <= alu_o;
                            pc    <= pc_plus1;
                            state <= ST_FETCH_REQ;
                        end

                        4'h1: begin // LDI
                            rf_waddr <= rd_f;
                            rf_wdata <= alu_result;
                            rf_we    <= 1'b1;
                            flag_z <= alu_z; flag_c <= alu_c;
                            flag_n <= alu_n; flag_o <= alu_o;
                            pc    <= pc_plus1;
                            state <= ST_FETCH_REQ;
                        end

                        4'h2: begin // ALU immediate (CMPI: flags only)
                            if (ir[8:7] != 2'b11) begin
                                rf_waddr <= rd_f;
                                rf_wdata <= alu_result;
                                rf_we    <= 1'b1;
                            end
                            flag_z <= alu_z; flag_c <= alu_c;
                            flag_n <= alu_n; flag_o <= alu_o;
                            pc    <= pc_plus1;
                            state <= ST_FETCH_REQ;
                        end

                        4'h3: begin // LD rd, [rs]
                            memop     <= MEMOP_RD;
                            mem_wb    <= rd_f;
                            mem_addr1 <= reg_b;
                            pc_lat    <= pc_plus1;
                            bus_addr  <= reg_b; // early drive: 5-cycle LD
                            bus_re    <= 1'b1;
                            phase     <= 1'b0;
                            state     <= ST_MEM;
                        end

                        4'h4: begin // JMP addr12
                            pc    <= ir[11:0];
                            state <= ST_FETCH_REQ;
                        end

                        4'h5: begin // OUT port, rs (addr 0xF0|port, D5)
                            memop      <= MEMOP_WR;
                            mem_addr1  <= {5'b11110, ir[11:9]};
                            mem_wdata1 <= reg_a; // rs value on port A
                            pc_lat     <= pc_plus1;
                            bus_addr   <= {5'b11110, ir[11:9]};
                            bus_wdata  <= reg_a;
                            bus_we     <= 1'b1;
                            phase      <= 1'b0;
                            state      <= ST_MEM;
                        end

                        4'h6: begin // Jcc rel8
                            pc    <= take ? br_target : pc_plus1;
                            state <= ST_FETCH_REQ;
                        end

                        4'h7: begin // CALL addr12 (D1: two stack slots)
                            if ((sp < 8'hE2) || (sp > 8'hF0)) begin
                                trapped <= 1'b1; // check before commit
                                state   <= ST_TRAP;
                            end else begin
                                memop      <= MEMOP_CALL;
                                mem_addr1  <= sp - 8'h01;
                                mem_wdata1 <= {4'b0000, pc_plus1[11:8]};
                                mem_addr2  <= sp - 8'h02;
                                mem_wdata2 <= pc_plus1[7:0];
                                pc_lat     <= ir[11:0];
                                sp_lat     <= sp - 8'h02;
                                bus_addr   <= sp - 8'h01;
                                bus_wdata  <= {4'b0000, pc_plus1[11:8]};
                                bus_we     <= 1'b1;
                                phase      <= 1'b0;
                                state      <= ST_MEM;
                            end
                        end

                        4'h8: begin // ST rd, [rs]: M[rs] <- rd
                            memop      <= MEMOP_WR;
                            mem_addr1  <= reg_b;
                            mem_wdata1 <= reg_a; // rd value on port A
                            pc_lat     <= pc_plus1;
                            bus_addr   <= reg_b;
                            bus_wdata  <= reg_a;
                            bus_we     <= 1'b1;
                            phase      <= 1'b0;
                            state      <= ST_MEM;
                        end

                        4'h9: begin // RET (D1: two stack slots)
                            if ((sp < 8'hE0) || (sp > 8'hEE)) begin
                                trapped <= 1'b1; // check before commit
                                state   <= ST_TRAP;
                            end else begin
                                memop     <= MEMOP_RET;
                                mem_addr1 <= sp;         // low byte first
                                mem_addr2 <= sp + 8'h01; // then high nibble
                                sp_lat    <= sp + 8'h02;
                                bus_addr  <= sp;
                                bus_re    <= 1'b1;
                                phase     <= 1'b0;
                                state     <= ST_MEM;
                            end
                        end

                        4'hA: begin // IN rd, port (addr 0xF0|port, D5)
                            memop     <= MEMOP_RD;
                            mem_wb    <= rd_f;
                            mem_addr1 <= {5'b11110, ir[8:6]};
                            pc_lat    <= pc_plus1;
                            bus_addr  <= {5'b11110, ir[8:6]};
                            bus_re    <= 1'b1;
                            phase     <= 1'b0;
                            state     <= ST_MEM;
                        end

                        4'hB: begin // PUSH rd
                            if ((sp < 8'hE1) || (sp > 8'hF0)) begin
                                trapped <= 1'b1; // check before commit
                                state   <= ST_TRAP;
                            end else begin
                                memop      <= MEMOP_PUSH;
                                mem_addr1  <= sp - 8'h01;
                                mem_wdata1 <= reg_a;
                                sp_lat     <= sp - 8'h01;
                                pc_lat     <= pc_plus1;
                                bus_addr   <= sp - 8'h01;
                                bus_wdata  <= reg_a;
                                bus_we     <= 1'b1;
                                phase      <= 1'b0;
                                state      <= ST_MEM;
                            end
                        end

                        4'hC: begin // POP rd
                            if ((sp < 8'hE0) || (sp > 8'hEF)) begin
                                trapped <= 1'b1; // check before commit
                                state   <= ST_TRAP;
                            end else begin
                                memop     <= MEMOP_POP;
                                mem_wb    <= rd_f;
                                mem_addr1 <= sp;
                                sp_lat    <= sp + 8'h01;
                                pc_lat    <= pc_plus1;
                                bus_addr  <= sp;
                                bus_re    <= 1'b1;
                                phase     <= 1'b0;
                                state     <= ST_MEM;
                            end
                        end

                        4'hD: begin // SHIFT by Rs[2:0]
                            rf_waddr <= rd_f;
                            rf_wdata <= alu_result;
                            rf_we    <= 1'b1;
                            flag_z <= alu_z; flag_c <= alu_c;
                            flag_n <= alu_n; flag_o <= alu_o;
                            pc    <= pc_plus1;
                            state <= ST_FETCH_REQ;
                        end

                        4'hF: begin // HALT (S-format zero checked in DECODE)
                            halted <= 1'b1;
                            // PC advances past HALT so resume_i continues
                            // with the NEXT instruction (T3 proves it).
                            pc    <= pc_plus1;
                            state <= ST_HALT;
                        end

                        default: begin // 0xE (unreachable: DECODE traps it)
                            trapped <= 1'b1;
                            state   <= ST_TRAP;
                        end
                    endcase
                end // ST_EXECUTE

                ST_MEM: begin
                    if (bus_ready && last_phase) begin
                        // ---- final transfer cycle: capture + commit ----
                        bus_re <= 1'b0;
                        bus_we <= 1'b0;
                        if (is_read && ((memop == MEMOP_RD) ||
                                        (memop == MEMOP_POP))) begin
                            rf_waddr <= mem_wb;  // LD / IN / POP writeback
                            rf_wdata <= bus_rdata;
                            rf_we    <= 1'b1;
                        end
                        if (memop == MEMOP_RET)
                            pc <= {bus_rdata[3:0], ret_lo}; // D1
                        else
                            pc <= pc_lat;
                        if ((memop == MEMOP_PUSH) || (memop == MEMOP_POP) ||
                            (memop == MEMOP_CALL) || (memop == MEMOP_RET))
                            sp <= sp_lat;
                        state <= ST_FETCH_REQ;
                    end else begin
                        // ---- not the final cycle: hold or advance ----
                        if (bus_ready) begin
                            // CALL/RET phase 0 completes here: latch the
                            // RET low byte and PRESENT phase 1 now, so the
                            // phase-1 transfer is captured at next edge.
                            // (Single-phase ops never reach this branch
                            // with ready high - that is the commit case.)
                            if ((memop == MEMOP_RET) && (phase == 1'b0))
                                ret_lo <= bus_rdata;
                            phase     <= phase + 1'b1;
                            bus_addr  <= mem_addr2;
                            bus_wdata <= mem_wdata2;
                        end else begin
                            // ready low: hold the current transfer
                            bus_addr  <= cur_addr;
                            bus_wdata <= cur_wdata;
                        end
                        bus_re <= is_read;
                        bus_we <= is_write;
                    end
                end // ST_MEM

                ST_HALT: begin
                    if (resume_i) begin
                        halted <= 1'b0;
                        state  <= ST_FETCH_REQ; // PC already past HALT
                    end
                end

                ST_TRAP: begin
                    // Latched stop: reset only (spec 6.6 - not resumable)
                end

                default: begin
                    state <= ST_RESET;
                end
            endcase
        end
    end

endmodule
