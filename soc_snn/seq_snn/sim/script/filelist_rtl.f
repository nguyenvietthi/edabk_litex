////////////////////////////////////////////////////////////////////////////////
//  File Extension
////////////////////////////////////////////////////////////////////////////////
+libext+.v                       // Verilog wrapper files
+libext+.vh                      // Verilog wrapper files
+libext+.sv                      // System Verilog wrapper files
+libext+.svh                     // System Verilog wrapper files
+libext+.h                       // System Verilog wrapper files

////////////////////////////////////////////////////////////////////////////////
//  Simulation Environment
////////////////////////////////////////////////////////////////////////////////
-sv
+nospecify
+notimingchecks
-timescale "1ns/1ps"
-incr

////////////////////////////////////////////////////////////////////////////////
//  Global Defines and Global Params
////////////////////////////////////////////////////////////////////////////////
// +incdir+../../include

////////////////////////////////////////////////////////////////////////////////
//  Top Level Module
////////////////////////////////////////////////////////////////////////////////
-y ../../seq
../../seq/RANCNetworkGrid_1x1.v
