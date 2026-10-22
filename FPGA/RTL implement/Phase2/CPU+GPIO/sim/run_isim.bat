@echo off
REM ============================================================================
REM run_isim.bat - compile and run tb_s8_top_gpio with ISE 14.7 iSIM
REM
REM Run this from an ISE command prompt (or after adding
REM %XILINX%\ISE_DS\ISE\bin\nt to PATH). The script changes to its own
REM directory because the testbench loads ..\prog\gpio_demo.hex (INIT_FILE)
REM relative to the working directory.
REM
REM Expected last line: tb_s8_top_gpio: PASSED (72 checks, 0 errors)
REM ============================================================================
setlocal
cd /d "%~dp0"
set RT=..\rtl

fuse -o tb_s8_top_gpio.exe ^
    ..\tb\tb_s8_top_gpio.v ^
    %RT%\s8_top.v %RT%\s8_cpu.v %RT%\s8_alu.v %RT%\s8_regfile.v ^
    %RT%\s8_program_ram.v %RT%\s8_data_ram.v %RT%\s8_bus.v ^
    %RT%\s8_gpio.v %RT%\s8_mmio.v %RT%\s8_reset_sync.v %RT%\s8_mode_latch.v
if errorlevel 1 goto fail

tb_s8_top_gpio.exe
if errorlevel 1 goto fail
goto end

:fail
echo.
echo PHASE-2 SIMULATION FAILED - see the messages above.
:end
endlocal
