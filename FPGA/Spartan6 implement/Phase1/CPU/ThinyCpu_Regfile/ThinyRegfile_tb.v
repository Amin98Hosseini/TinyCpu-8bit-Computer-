// =============================================================================
// Testbench  : tb_s8_regfile
// Tests      : s8_regfile (8x8, sync write, async dual read, sync reset)
// Spec       : Sections 8.1 and 9, Section 16.1 (tb_s8_regfile row)
//
// Checks:
//   1. Sync reset clears R0-R7.
//   2. Write each register, read back on BOTH ports at once.
//   3. Two ports can read two different registers in the same cycle.
//   4. Sync-write timing: read-during-write shows the OLD value; the new
//      value appears only after the clock edge (no read-during-write
//      hazard: the CPU never samples a register it writes same-cycle).
//   5. we=0 never modifies the array.
//
// Expected result: transcript ends with
//   "tb_s8_regfile: PASSED (<N> checks, 0 errors)"
// and $finish. Any "FAIL" line means the regfile (or TB) is wrong.
// =============================================================================

`timescale 1ns / 1ps

module tb_s8_regfile;

    reg        clk, rst;
    reg  [2:0] raddr_a, raddr_b, waddr;
    reg  [7:0] wdata;
    reg        we;
    wire [7:0] rdata_a, rdata_b;

    s8_regfile dut (
        .clk     (clk),
        .rst     (rst),
        .raddr_a (raddr_a),
        .raddr_b (raddr_b),
        .waddr   (waddr),
        .wdata   (wdata),
        .we      (we),
        .rdata_a (rdata_a),
        .rdata_b (rdata_b)
    );

    integer i;
    integer checks, errors;

    // 100 MHz TB clock (timing is not under test; edges only matter)
    initial clk = 0;
    always #5 clk = ~clk;

    task check2;
        input [7:0] exp_a, exp_b;
        input [8*32:1] name;
        begin
            checks = checks + 1;
            #1; // let async reads settle
            if ((rdata_a !== exp_a) || (rdata_b !== exp_b)) begin
                errors = errors + 1;
                $display("FAIL %0s: ra=%0d rb=%0d -> got a=%02h b=%02h, exp a=%02h b=%02h",
                         name, raddr_a, raddr_b, rdata_a, rdata_b, exp_a, exp_b);
            end
        end
    endtask

    initial begin
        checks = 0;
        errors = 0;
        rst = 1; we = 0;
        raddr_a = 0; raddr_b = 0; waddr = 0; wdata = 0;

        // ---- 1. sync reset clears the file (needs an edge while rst=1) ----
        repeat (3) @(posedge clk);
        raddr_a = 3'd0; raddr_b = 3'd7;
        check2(8'h00, 8'h00, "reset clears");
        rst = 0;
        @(posedge clk);

        // ---- 2. write R0-R7 = 0x10..0x17, read back on both ports --------
        for (i = 0; i < 8; i = i + 1) begin
            waddr = i; wdata = 8'h10 + i; we = 1;
            @(posedge clk);
        end
        we = 0;
        @(posedge clk);
        for (i = 0; i < 8; i = i + 1) begin
            raddr_a = i; raddr_b = 7 - i;
            check2(8'h10 + i, 8'h10 + (7 - i), "write/readback");
        end

        // ---- 3. read-during-write shows OLD value until the edge ---------
        raddr_a = 3'd2; raddr_b = 3'd2; // R2 currently 0x12
        waddr = 3'd2; wdata = 8'hAA; we = 1;
        #1; // mid-cycle, before the edge
        checks = checks + 1;
        if ((rdata_a !== 8'h12) || (rdata_b !== 8'h12)) begin
            errors = errors + 1;
            $display("FAIL read-during-write: got %02h/%02h, exp old 12/12",
                     rdata_a, rdata_b);
        end
        @(posedge clk); // commit edge
        we = 0;
        check2(8'hAA, 8'hAA, "post-edge new value");

        // ---- 4. we=0 never modifies --------------------------------------
        waddr = 3'd2; wdata = 8'h55; we = 0;
        repeat (2) @(posedge clk);
        raddr_a = 3'd2; raddr_b = 3'd2;
        check2(8'hAA, 8'hAA, "we=0 holds");

        // ---- 5. reset again clears ---------------------------------------
        rst = 1;
        repeat (2) @(posedge clk);
        rst = 0;
        raddr_a = 3'd2; raddr_b = 3'd5;
        check2(8'h00, 8'h00, "second reset");

        // ---- summary ------------------------------------------------------
        if (errors == 0)
            $display("tb_s8_regfile: PASSED (%0d checks, 0 errors)", checks);
        else
            $display("tb_s8_regfile: FAILED (%0d checks, %0d errors)", checks, errors);
        $finish;
    end

endmodule
