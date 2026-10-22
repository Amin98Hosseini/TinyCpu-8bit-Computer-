# =============================================================================
# build_phase2.tcl - S8 Phase 2 hardware build (Farad-1, xc6slx9-2tqg144)
#
# ISE 14.7 TCL flow: creates the project, adds the Phase-2 sources, runs
# synthesis, translation/map/place & route, and generates the bitstream.
# The same steps are available in the Project Navigator GUI (see
# phase2/PHASE2_GPIO_BRINGUP.md, "Building the bitstream").
#
# Usage (from any directory):
#   xtclsh build_phase2.tcl          # or:  ise -tcl build_phase2.tcl
#
# The script writes everything into phase2/ise/build/ and copies the demo
# image there, because $readmemh (INIT_FILE) is resolved relative to the
# tool's working directory - which for this flow is the project directory.
#
# NOTE: this script has NOT been executed on this machine (ISE is not
# installed here). It uses the documented ISE 14.7 TCL API; if your install
# names a property differently, run the GUI steps and use the script only as
# the source list + option record.
# =============================================================================

set script_dir [file dirname [file normalize [info script]]]
set root       [file normalize [file join $script_dir ..]]
set build_dir  [file join $script_dir build]
set proj_name  "s8_phase2"

file mkdir $build_dir

# ---- demo image must sit in the tool's working directory -------------------
file copy -force [file join $root prog gpio_demo.hex] [file join $build_dir gpio_demo.hex]

# ---- project + part -------------------------------------------------------
cd $build_dir
project new $build_dir $proj_name
project set family  "Spartan6"
project set device  "xc6slx9"
project set package "tqg144"
project set speed   "-2"
project set "Preferred Language" "Verilog"
project set "Verilog 2001"       "True"
project set "Simulator"          "ISim (VHDL/Verilog)"

# ---- sources: Phase-2 RTL (all Verilog-2001, one module per file) ---------
foreach f [lsort [glob -nocomplain [file join $root rtl *.v]]] {
    xfile add $f
}
# testbench: simulation view only - never part of the bitstream
xfile add [file join $root tb tb_s8_top_gpio.v] -view Simulation
# constraints (LOC + IOSTANDARD + PERIOD), spec 15
xfile add [file join $root constraints board_p2.ucf]

project set top "s8_top"

# ---- flow -----------------------------------------------------------------
# Behavioral simulation is run separately with iSIM (phase2/sim/), before
# synthesis, per spec 15 step 3.
set ok 1
foreach step {"Synthesize - XST" "Implement Design" "Generate Programming File"} {
    if {[catch {process run $step} err]} {
        puts "PHASE2 BUILD FAILED at: $step"
        puts $err
        set ok 0
        break
    }
}

if {$ok} {
    puts "PHASE2 BUILD OK - check the reports:"
    puts "  synthesis : $proj_name.syr   (BRAM inference, 'RAM Initial Contents')"
    puts "  timing    : $proj_name.twr   (TS_sys_clk, 20.000 ns)"
    puts "  maps/par  : $proj_name.map / $proj_name.par   (utilization)"
    puts "  bitstream : $proj_name.bit"
} else {
    exit 1
}
