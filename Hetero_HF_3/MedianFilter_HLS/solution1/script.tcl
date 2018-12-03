############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project MedianFilter_HLS
set_top fir_hw
add_files fir_hw.cpp
add_files MedianFilter_HLS/_src/types.h
add_files -tb MedianFilter_HLS/_src/fir_sw.cpp
add_files -tb MedianFilter_HLS/_src/main.cpp
open_solution "solution1"
set_part {xc7k70tfbv484-1} -tool vivado
create_clock -period 100 -name default
#source "./MedianFilter_HLS/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
