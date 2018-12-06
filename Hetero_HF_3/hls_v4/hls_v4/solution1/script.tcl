############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_v4
set_top medianFilter
add_files _src/median_filter.cpp
add_files -tb _src/main.cpp
open_solution "solution1"
set_part {xc7k70tfbg676-1} -tool vivado
create_clock -period 10 -name default
#source "./hls_v4/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
