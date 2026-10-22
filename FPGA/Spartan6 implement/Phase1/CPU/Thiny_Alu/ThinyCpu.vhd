// =============================================================================
// Module : s8_alu
// Part of: S8 soft processor (Spartan-6 LX9, Verilog-2001, ISE 14.7 flow)
// Spec   : docs/S8_Technical_Specification_v1.1.md, Section 6.5 (normative
//          flag formulas), Section 9 (s8_alu row)
//
// Function: purely combinational ALU. Computes an 8-bit result and the four
// flags Z, C, N, O exactly per Section 6.5. The CPU (s8_cpu) decides, from the
// decoded opcode, which alu_op to present and whether the flags / rd are
// updated (CMP/CMPI produce flags only - the CPU simply does not write rd).
//
// alu_op map:
//   0 ADD   {C,res} = a + b            -> Z C N O
//   1 SUB   {B,res} = a - b, C=~borrow -> Z C N O   (also used for CMP/CMPI)
//   2 AND   res = a & b                -> Z N, C=0 O=0
//   3 OR    res = a | b                -> Z N, C=0 O=0
//   4 XOR   res = a ^ b                -> Z N, C=0 O=0
//   5 CMP   same datapath as SUB       -> Z C N O   (CPU discards result)
//   6 MOV   res = b                    -> Z N, C=0 O=0
//   7 NOT   res = ~b (source is op_b!) -> Z N, C=0 O=0
//   8 SHL   {C,res} = a << b[2:0], C = last bit shifted out (0 if amount 0)
//   9 SHR   logical right shift, C = last bit shifted out (0 if amount 0)
//  10 ROL   rotate left  through res, no C participation, C=0
//  11 ROR   rotate right through res, no C participation, C=0
//  others: result 0, all flags 0 (CPU never selects these; safe default)
// =============================================================================

module s8_alu (
    input  [7:0] op_a,
    input  [7:0] op_b,
    input  [3:0] alu_op,
    output reg [7:0] result,
    output reg flag_z,   // zero: result == 0
    output reg flag_c,   // carry / NOT-borrow / last-shifted-out
    output reg flag_n,   // negative: result[7]
    output reg flag_o    // signed overflow
);

    // Operation codes (kept identical in s8_cpu; both trace to spec 6.5)
    localparam [3:0] ALU_ADD = 4'd0,
                     ALU_SUB = 4'd1,
                     ALU_AND = 4'd2,
                     ALU_OR  = 4'd3,
                     ALU_XOR = 4'd4,
                     ALU_CMP = 4'd5,
                     ALU_MOV = 4'd6,
                     ALU_NOT = 4'd7,
                     ALU_SHL = 4'd8,
                     ALU_SHR = 4'd9,
                     ALU_ROL = 4'd10,
                     ALU_ROR = 4'd11;

    reg [8:0] sum9;    // 9-bit add/sub intermediate (spec 6.5: sum9 / diff9)
    reg [7:0] sh_tmp;  // shift intermediate
    reg [2:0] amt;     // shift amount = op_b[2:0]

    always @* begin
        // ---- defaults (kill latches) ----
        result = 8'h00;
        flag_z = 1'b0;
        flag_c = 1'b0;
        flag_n = 1'b0;
        flag_o = 1'b0;
        sum9   = 9'h000;
        sh_tmp = 8'h00;
        amt    = op_b[2:0];

        case (alu_op)
            ALU_ADD: begin
                sum9   = {1'b0, op_a} + {1'b0, op_b};
                result = sum9[7:0];
                flag_c = sum9[8];
                flag_z = (result == 8'h00);
                flag_n = result[7];
                // O = (a7 == b7) && (r7 != a7)
                flag_o = (op_a[7] == op_b[7]) && (result[7] != op_a[7]);
            end

            ALU_SUB,
            ALU_CMP: begin
                sum9   = {1'b0, op_a} - {1'b0, op_b}; // diff9
                result = sum9[7:0];
                flag_c = ~sum9[8]; // C = 1 iff a >= b (unsigned)
                flag_z = (result == 8'h00);
                flag_n = result[7];
                // O = (a7 != b7) && (r7 != a7)
                flag_o = (op_a[7] != op_b[7]) && (result[7] != op_a[7]);
            end

            ALU_AND: begin
                result = op_a & op_b;
                flag_z = (result == 8'h00);
                flag_n = result[7];
            end

            ALU_OR: begin
                result = op_a | op_b;
                flag_z = (result == 8'h00);
                flag_n = result[7];
            end

            ALU_XOR: begin
                result = op_a ^ op_b;
                flag_z = (result == 8'h00);
                flag_n = result[7];
            end

            ALU_MOV: begin
                result = op_b;
                flag_z = (result == 8'h00);
                flag_n = result[7];
            end

            ALU_NOT: begin
                result = ~op_b; // NOTE: source is op_b, not op_a (spec 6.4)
                flag_z = (result == 8'h00);
                flag_n = result[7];
            end

            ALU_SHL: begin
                sh_tmp = op_a << amt;
                result = sh_tmp;
                // C = last bit shifted out of position 7 (0 when amount 0)
                case (amt)
                    3'd1: flag_c = op_a[7];
                    3'd2: flag_c = op_a[6];
                    3'd3: flag_c = op_a[5];
                    3'd4: flag_c = op_a[4];
                    3'd5: flag_c = op_a[3];
                    3'd6: flag_c = op_a[2];
                    3'd7: flag_c = op_a[1];
                    default: flag_c = 1'b0; // amount 0: copy, C = 0
                endcase
                flag_z = (result == 8'h00);
                flag_n = result[7];
            end

            ALU_SHR: begin
                sh_tmp = op_a >> amt;
                result = sh_tmp;
                // C = last bit shifted out of position 0 (0 when amount 0)
                case (amt)
                    3'd1: flag_c = op_a[0];
                    3'd2: flag_c = op_a[1];
                    3'd3: flag_c = op_a[2];
                    3'd4: flag_c = op_a[3];
                    3'd5: flag_c = op_a[4];
                    3'd6: flag_c = op_a[5];
                    3'd7: flag_c = op_a[6];
                    default: flag_c = 1'b0; // amount 0: copy, C = 0
                endcase
                flag_z = (result == 8'h00);
                flag_n = result[7];
            end

            ALU_ROL: begin
                case (amt)
                    3'd0: result = op_a;
                    3'd1: result = {op_a[6:0], op_a[7]};
                    3'd2: result = {op_a[5:0], op_a[7:6]};
                    3'd3: result = {op_a[4:0], op_a[7:5]};
                    3'd4: result = {op_a[3:0], op_a[7:4]};
                    3'd5: result = {op_a[2:0], op_a[7:3]};
                    3'd6: result = {op_a[1:0], op_a[7:2]};
                    3'd7: result = {op_a[0],   op_a[7:1]};
                    default: result = op_a;
                endcase
                flag_z = (result == 8'h00);
                flag_n = result[7];
                // C = 0, O = 0 (defaults)
            end

            ALU_ROR: begin
                case (amt)
                    3'd0: result = op_a;
                    3'd1: result = {op_a[0],   op_a[7:1]};
                    3'd2: result = {op_a[1:0], op_a[7:2]};
                    3'd3: result = {op_a[2:0], op_a[7:3]};
                    3'd4: result = {op_a[3:0], op_a[7:4]};
                    3'd5: result = {op_a[4:0], op_a[7:5]};
                    3'd6: result = {op_a[5:0], op_a[7:6]};
                    3'd7: result = {op_a[6:0], op_a[7]};
                    default: result = op_a;
                endcase
                flag_z = (result == 8'h00);
                flag_n = result[7];
                // C = 0, O = 0 (defaults)
            end

            default: begin
                // Unused alu_op: safe zero output (CPU never selects it)
            end
        endcase
    end

endmodule
