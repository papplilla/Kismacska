############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project MedianFilter_HLS
set_top fir_hw
add_files ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/fir_hw.cpp
add_files ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/types.h
add_files ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/fir_hw.cpp
add_files ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/types.h
add_files -tb ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/fir_sw.cpp
add_files -tb ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/main.cpp
add_files -tb ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/fir_sw.cpp
add_files -tb ../Google Drive/Dokumentumok/My eBooks/Egyetem/9. félév/Heterogén számítási rendszerek/Laborok/Labor_05/Starter/_src/main.cpp
open_solution "MedianFilter"
set_part {xc7k70tfbv484-1} -tool vivado
create_clock -period 100 -name default
#source "./MedianFilter_HLS/MedianFilter/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
