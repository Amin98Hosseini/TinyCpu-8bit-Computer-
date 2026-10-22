#!/bin/sh
# =============================================================================
# run_isim.sh - compile and run tb_s8_top_gpio with ISE 14.7 iSIM (command line)
#
# The script cds to its own directory because the testbench loads
# ../prog/gpio_demo.hex (INIT_FILE) relative to the working directory.
# Requires fuse/ISim on PATH (ISE 14.7: $XILINX/ISE_DS/ISE/bin/lin).
#
# Expected last line: tb_s8_top_gpio: PASSED (72 checks, 0 errors)
# =============================================================================
set -e
cd "$(dirname "$0")"

RT=../rtl
fuse -o tb_s8_top_gpio.exe \
    ../tb/tb_s8_top_gpio.v \
    "$RT/s8_top.v" "$RT/s8_cpu.v" "$RT/s8_alu.v" "$RT/s8_regfile.v" \
    "$RT/s8_program_ram.v" "$RT/s8_data_ram.v" "$RT/s8_bus.v" \
    "$RT/s8_gpio.v" "$RT/s8_mmio.v" "$RT/s8_reset_sync.v" "$RT/s8_mode_latch.v"

./tb_s8_top_gpio.exe
