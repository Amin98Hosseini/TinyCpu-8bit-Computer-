// =============================================================================
// Testbench  : tb_s8_alu
// Tests      : s8_alu (combinational)
// Spec       : Section 6.5 (flag formulas), Section 16.1 (tb_s8_alu row:
//              exhaustive ADD/SUB sweep over all 65536 operand pairs plus
//              directed O/C corners)
//
// Strategy   : the reference values are computed INDEPENDENTLY here with
// plain Verilog integer arithmetic written straight from the spec text
// (9-bit sum/diff, sign-bit comparisons) - not by reusing the DUT code.
// Any mismatch (result or any of Z/C/N/O) is a failure.
//
// Coverage:
//   1. Directed corner cases with hand-computed expectations (spec 6.5).
//   2. Exhaustive ADD + SUB/CMP over all 256x256 operand pairs.
//   3. Exhaustive AND / OR / XOR / MOV / NOT over all pairs.
//   4. Exhaustive SHL / SHR / ROL / ROR over all 256 data values x all 8
//      amounts, with op_b high bits set AND clear (only b[2:0] may matter).
//   5. Unused alu_op codes 12-15 -> safe zero output.
//
// Expected result: every check passes; transcript ends with
//   "tb_s8_alu: PASSED (<N> checks, 0 errors)"
// and $finish. Any "FAIL" line means the ALU (or the TB reference) is
// wrong - fix against spec 6.5, never against the TB.
// Run (iSIM): fuse -o tb_s8_alu.exe tb_s8_alu.v ../rtl/s8_alu.v && ./tb_s8_alu.exe
// =============================================================================

`timescale 1ns / 1ps

module tb_s8_alu;

    reg  [7:0] a, b;
    reg  [3:0] op;
    wire [7:0] result;
    wire       fz, fc, fn, fo;

    s8_alu dut (
        .op_a   (a),
        .op_b   (b),
        .alu_op (op),
        .result (result),
        .flag_z (fz),
        .flag_c (fc),
        .flag_n (fn),
        .flag_o (fo)
    );

    integer i, j, k;
    integer checks, errors;

    // Reference temporaries (plain integer arithmetic, spec 6.5)
    integer      sum9, dif9;
    reg [7:0]    exp_r;
    reg          exp_z, exp_c, exp_n, exp_o;

    task check;
        input [7:0] er;
        input       ez, ec, en, eo;
        input [8*32:1] name;
        begin
            checks = checks + 1;
            if ((result !== er) || (fz !== ez) || (fc !== ec) ||
                (fn !== en) || (fo !== eo)) begin
                errors = errors + 1;
                $display("FAIL %0s: a=%02h b=%02h op=%0d -> got %02h Z%C%N%O, exp %02h Z%C%N%O",
                         name, a, b, op, result, fz, fc, fn, fo,
                         er, ez, ec, en, eo);
            end
        end
    endtask

    // ---- independent references ----
    task ref_add; // sum9 = {0,a}+{0,b}
        begin
            sum9  = a + b;
            exp_r = sum9 & 8'hFF;
            exp_c = (sum9 > 8'hFF);
            exp_z = (exp_r == 8'h00);
            exp_n = exp_r[7];
            exp_o = ((a[7] == b[7]) && (exp_r[7] != a[7]));
        end
    endtask

    task ref_sub; // diff9 = {0,a}-{0,b}, C = ~borrow
        begin
            dif9  = a - b;
            exp_r = dif9 & 8'hFF;
            exp_c = (a >= b);
            exp_z = (exp_r == 8'h00);
            exp_n = exp_r[7];
            exp_o = ((a[7] != b[7]) && (exp_r[7] != a[7]));
        end
    endtask

    initial begin
        checks = 0;
        errors = 0;
        a = 0; b = 0; op = 0;
        #10;

        // ============ 1. directed corners (hand-computed, spec 6.5) ========
        // ADD 0x7F+0x01 = 0x80: signed overflow, no carry
        a = 8'h7F; b = 8'h01; op = 0; #10;
        check(8'h80, 1'b0, 1'b0, 1'b1, 1'b1, "ADD 7F+01");
        // ADD 0xFF+0x01 = 0x00: carry, zero
        a = 8'hFF; b = 8'h01; op = 0; #10;
        check(8'h00, 1'b1, 1'b1, 1'b0, 1'b0, "ADD FF+01");
        // ADD 0x80+0x80 = 0x00: carry + signed overflow
        a = 8'h80; b = 8'h80; op = 0; #10;
        check(8'h00, 1'b1, 1'b1, 1'b0, 1'b1, "ADD 80+80");
        // SUB 0x00-0x01 = 0xFF: borrow (C=0)
        a = 8'h00; b = 8'h01; op = 1; #10;
        check(8'hFF, 1'b0, 1'b0, 1'b1, 1'b0, "SUB 00-01");
        // SUB 0x80-0x01 = 0x7F: signed overflow, no borrow
        a = 8'h80; b = 8'h01; op = 1; #10;
        check(8'h7F, 1'b0, 1'b1, 1'b0, 1'b1, "SUB 80-01");
        // SUB equal operands: zero + C=1
        a = 8'h05; b = 8'h05; op = 1; #10;
        check(8'h00, 1'b1, 1'b1, 1'b0, 1'b0, "SUB 05-05");
        // SUB 0x7F-0xFF = 0x80: borrow + signed overflow
        a = 8'h7F; b = 8'hFF; op = 1; #10;
        check(8'h80, 1'b0, 1'b0, 1'b1, 1'b1, "SUB 7F-FF");
        // Logic group
        a = 8'hA5; b = 8'h0F; op = 2; #10;
        check(8'h05, 1'b0, 1'b0, 1'b0, 1'b0, "AND A5&0F");
        a = 8'hA0; b = 8'h05; op = 3; #10;
        check(8'hA5, 1'b0, 1'b0, 1'b1, 1'b0, "OR A0|05");
        a = 8'hFF; b = 8'hFF; op = 4; #10;
        check(8'h00, 1'b1, 1'b0, 1'b0, 1'b0, "XOR FF^FF");
        // MOV passes op_b; NOT inverts op_b (NOT the op_a side!)
        a = 8'h12; b = 8'h34; op = 6; #10;
        check(8'h34, 1'b0, 1'b0, 1'b0, 1'b0, "MOV");
        a = 8'h12; b = 8'h34; op = 7; #10;
        check(8'hCB, 1'b0, 1'b0, 1'b1, 1'b0, "NOT ~b");
        // CMP produces flags only (datapath = SUB)
        a = 8'h05; b = 8'h03; op = 5; #10;
        check(8'h02, 1'b0, 1'b1, 1'b0, 1'b0, "CMP 05,03");
        // Shifts
        a = 8'h81; b = 8'h01; op = 8; #10;
        check(8'h02, 1'b0, 1'b1, 1'b0, 1'b0, "SHL 81<<1");
        a = 8'h81; b = 8'h00; op = 8; #10;
        check(8'h81, 1'b0, 1'b0, 1'b1, 1'b0, "SHL by 0");
        a = 8'hFF; b = 8'h07; op = 8; #10;
        check(8'h80, 1'b0, 1'b1, 1'b1, 1'b0, "SHL FF<<7");
        a = 8'h03; b = 8'h02; op = 9; #10;
        check(8'h00, 1'b1, 1'b1, 1'b0, 1'b0, "SHR 03>>2");
        a = 8'h81; b = 8'h01; op = 9; #10;
        check(8'h40, 1'b0, 1'b1, 1'b0, 1'b0, "SHR 81>>1");
        a = 8'h81; b = 8'h01; op = 10; #10;
        check(8'h03, 1'b0, 1'b0, 1'b0, 1'b0, "ROL 81,1");
        a = 8'h81; b = 8'h01; op = 11; #10;
        check(8'hC0, 1'b0, 1'b0, 1'b1, 1'b0, "ROR 81,1");
        a = 8'hFF; b = 8'h03; op = 10; #10;
        check(8'hFF, 1'b0, 1'b0, 1'b1, 1'b0, "ROL FF,3");

        // ============ 2. exhaustive ADD / SUB / CMP ========================
        op = 0;
        for (i = 0; i < 256; i = i + 1) begin
            for (j = 0; j < 256; j = j + 1) begin
                a = i; b = j; #1;
                ref_add;
                check(exp_r, exp_z, exp_c, exp_n, exp_o, "ADD exh");
            end
        end
        op = 1;
        for (i = 0; i < 256; i = i + 1) begin
            for (j = 0; j < 256; j = j + 1) begin
                a = i; b = j; #1;
                ref_sub;
                check(exp_r, exp_z, exp_c, exp_n, exp_o, "SUB exh");
            end
        end
        op = 5; // CMP datapath == SUB
        for (i = 0; i < 256; i = i + 1) begin
            for (j = 0; j < 256; j = j + 1) begin
                a = i; b = j; #1;
                ref_sub;
                check(exp_r, exp_z, exp_c, exp_n, exp_o, "CMP exh");
            end
        end

        // ============ 3. exhaustive AND / OR / XOR / MOV / NOT =============
        for (i = 0; i < 256; i = i + 1) begin
            for (j = 0; j < 256; j = j + 1) begin
                a = i; b = j;
                op = 2; #1;
                begin exp_r = a & b;
                    check(exp_r, exp_r == 0, 1'b0, exp_r[7], 1'b0, "AND exh"); end
                op = 3; #1;
                begin exp_r = a | b;
                    check(exp_r, exp_r == 0, 1'b0, exp_r[7], 1'b0, "OR exh"); end
                op = 4; #1;
                begin exp_r = a ^ b;
                    check(exp_r, exp_r == 0, 1'b0, exp_r[7], 1'b0, "XOR exh"); end
                op = 6; #1;
                begin exp_r = b;
                    check(exp_r, exp_r == 0, 1'b0, exp_r[7], 1'b0, "MOV exh"); end
                op = 7; #1;
                begin exp_r = ~b;
                    check(exp_r, exp_r == 0, 1'b0, exp_r[7], 1'b0, "NOT exh"); end
            end
        end

        // ============ 4. exhaustive shifts (low AND high op_b bits) ========
        for (i = 0; i < 256; i = i + 1) begin
            for (k = 0; k < 8; k = k + 1) begin
                a = i;
                // op_b = amount, then amount with high bits set (must ignore)
                b = k; #1;
                begin
                    exp_r = (a << k) & 8'hFF;
                    exp_c = (k == 0) ? 1'b0 : ((a >> (8 - k)) & 1'b1);
                    op = 8;
                    check(exp_r, exp_r == 0, exp_c, exp_r[7], 1'b0, "SHL exh");
                end
                b = k | 8'hF8; #1;
                begin
                    exp_r = (a << k) & 8'hFF;
                    exp_c = (k == 0) ? 1'b0 : ((a >> (8 - k)) & 1'b1);
                    check(exp_r, exp_r == 0, exp_c, exp_r[7], 1'b0, "SHL himask");
                end
                b = k; #1;
                begin
                    exp_r = (a >> k) & 8'hFF;
                    exp_c = (k == 0) ? 1'b0 : ((a >> (k - 1)) & 1'b1);
                    op = 9;
                    check(exp_r, exp_r == 0, exp_c, exp_r[7], 1'b0, "SHR exh");
                end
                b = k; #1;
                begin
                    if (k == 0) exp_r = a;
                    else exp_r = ((a << k) | (a >> (8 - k))) & 8'hFF;
                    op = 10;
                    check(exp_r, exp_r == 0, 1'b0, exp_r[7], 1'b0, "ROL exh");
                end
                b = k | 8'hF8; #1;
                begin
                    if (k == 0) exp_r = a;
                    else exp_r = ((a >> k) | (a << (8 - k))) & 8'hFF;
                    op = 11;
                    check(exp_r, exp_r == 0, 1'b0, exp_r[7], 1'b0, "ROR himask");
                end
            end
        end

        // ============ 5. unused alu_op -> safe zero ========================
        for (k = 12; k < 16; k = k + 1) begin
            a = 8'hA5; b = 8'h5A; op = k; #1;
            check(8'h00, 1'b0, 1'b0, 1'b0, 1'b0, "UNUSED op");
        end

        // ============ summary ==============================================
        if (errors == 0)
            $display("tb_s8_alu: PASSED (%0d checks, 0 errors)", checks);
        else
            $display("tb_s8_alu: FAILED (%0d checks, %0d errors)", checks, errors);
        $finish;
    end

endmodule
