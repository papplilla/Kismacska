############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project MedianFilter_HLS
set_top fir_hw
add_files fir_hw.cpp
add_files types.h
add_files fir_hw.cpp
add_files types.h
add_files -tb fir_sw.cpp
add_files -tb main.cpp
add_files -tb fir_sw.cpp
add_files -tb main.cpp
open_solution "MedianFilter"
set_part {xc7k70tfbv484-1} -tool vivado
create_clock -period 100 -name default
#source "./MedianFilter_HLS/MedianFilter/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
