// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="fir_hw,hls_ip_2018_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=1,HLS_INPUT_PART=xc7k70tfbv484-1,HLS_INPUT_CLOCK=100.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.454000,HLS_SYN_LAT=512,HLS_SYN_TPT=none,HLS_SYN_MEM=2,HLS_SYN_DSP=1,HLS_SYN_FF=80,HLS_SYN_LUT=399,HLS_VERSION=2018_2}" *)

module fir_hw (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        input_V,
        res_V,
        res_V_ap_vld
);

parameter    ap_ST_fsm_state1 = 5'd1;
parameter    ap_ST_fsm_state2 = 5'd2;
parameter    ap_ST_fsm_state3 = 5'd4;
parameter    ap_ST_fsm_state4 = 5'd8;
parameter    ap_ST_fsm_state5 = 5'd16;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [23:0] input_V;
output  [23:0] res_V;
output   res_V_ap_vld;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg res_V_ap_vld;

(* fsm_encoding = "none" *) reg   [4:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg   [6:0] tomb_V_address0;
reg    tomb_V_ce0;
reg    tomb_V_we0;
reg   [23:0] tomb_V_d0;
wire  signed [23:0] tomb_V_q0;
wire   [6:0] coeff_hw_V_address0;
reg    coeff_hw_V_ce0;
wire  signed [14:0] coeff_hw_V_q0;
wire   [6:0] i_1_fu_193_p2;
reg   [6:0] i_1_reg_527;
wire    ap_CS_fsm_state2;
wire   [0:0] tmp_2_fu_187_p2;
wire    ap_CS_fsm_state4;
wire   [0:0] tmp_fu_213_p3;
wire   [7:0] i_2_fu_227_p2;
reg   [7:0] i_2_reg_550;
wire  signed [44:0] grp_fu_516_p3;
wire    ap_CS_fsm_state5;
reg   [6:0] i_reg_152;
wire    ap_CS_fsm_state3;
reg   [44:0] p_Val2_s_reg_164;
reg  signed [7:0] i1_reg_176;
wire   [63:0] tmp_5_fu_199_p1;
wire   [63:0] tmp_3_fu_204_p1;
wire   [63:0] tmp_7_fu_221_p1;
wire  signed [31:0] i1_cast_fu_209_p1;
wire   [0:0] tmp_18_fu_267_p1;
wire   [0:0] tmp_16_fu_251_p3;
wire   [14:0] tmp_8_fu_277_p4;
wire   [0:0] tmp_1_fu_271_p2;
wire   [15:0] tmp_9_fu_287_p3;
wire   [0:0] tmp_s_fu_295_p2;
wire   [0:0] signbit_fu_233_p3;
wire   [0:0] qb_assign_fu_301_p2;
wire   [23:0] p_Val2_2_fu_241_p4;
wire   [23:0] tmp_4_fu_307_p1;
wire   [23:0] p_Val2_3_fu_311_p2;
wire   [0:0] newsignbit_fu_317_p3;
wire   [0:0] tmp_17_fu_259_p3;
wire   [0:0] tmp_6_fu_325_p2;
wire   [2:0] tmp_10_fu_345_p4;
wire   [3:0] tmp_11_fu_361_p4;
wire   [0:0] carry_fu_331_p2;
wire   [0:0] Range1_all_ones_fu_371_p2;
wire   [0:0] Range1_all_zeros_fu_377_p2;
wire   [0:0] tmp_20_fu_337_p3;
wire   [0:0] Range2_all_ones_fu_355_p2;
wire   [0:0] tmp_12_fu_391_p2;
wire   [0:0] p_41_i_fu_397_p2;
wire   [0:0] deleted_zeros_fu_383_p3;
wire   [0:0] p_not_i_fu_417_p2;
wire   [0:0] brmerge_i_fu_423_p2;
wire   [0:0] tmp_13_fu_429_p2;
wire   [0:0] deleted_ones_fu_403_p3;
wire   [0:0] p_38_i_fu_411_p2;
wire   [0:0] brmerge40_demorgan_i_fu_441_p2;
wire   [0:0] tmp1_demorgan_fu_447_p2;
wire   [0:0] tmp1_fu_453_p2;
wire   [0:0] underflow_fu_459_p2;
wire   [0:0] overflow_fu_435_p2;
wire   [0:0] tmp2_fu_471_p2;
wire   [0:0] brmerge_i_i_fu_465_p2;
wire   [0:0] underflow_not_fu_477_p2;
wire   [23:0] p_Val2_5_mux_fu_483_p3;
wire   [23:0] p_Val2_5_fu_491_p3;
reg   [4:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 5'd1;
end

fir_hw_tomb_V #(
    .DataWidth( 24 ),
    .AddressRange( 128 ),
    .AddressWidth( 7 ))
tomb_V_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(tomb_V_address0),
    .ce0(tomb_V_ce0),
    .we0(tomb_V_we0),
    .d0(tomb_V_d0),
    .q0(tomb_V_q0)
);

fir_hw_coeff_hw_V #(
    .DataWidth( 15 ),
    .AddressRange( 128 ),
    .AddressWidth( 7 ))
coeff_hw_V_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(coeff_hw_V_address0),
    .ce0(coeff_hw_V_ce0),
    .q0(coeff_hw_V_q0)
);

fir_hw_mac_muladdbkb #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 15 ),
    .din1_WIDTH( 24 ),
    .din2_WIDTH( 45 ),
    .dout_WIDTH( 45 ))
fir_hw_mac_muladdbkb_U1(
    .din0(coeff_hw_V_q0),
    .din1(tomb_V_q0),
    .din2(p_Val2_s_reg_164),
    .dout(grp_fu_516_p3)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        i1_reg_176 <= i_2_reg_550;
    end else if (((tmp_2_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        i1_reg_176 <= 8'd127;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        i_reg_152 <= i_1_reg_527;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_reg_152 <= 7'd127;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        p_Val2_s_reg_164 <= grp_fu_516_p3;
    end else if (((tmp_2_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        p_Val2_s_reg_164 <= 45'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((tmp_2_fu_187_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        i_1_reg_527 <= i_1_fu_193_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((tmp_fu_213_p3 == 1'd0) & (1'b1 == ap_CS_fsm_state4))) begin
        i_2_reg_550 <= i_2_fu_227_p2;
    end
end

always @ (*) begin
    if (((tmp_fu_213_p3 == 1'd1) & (1'b1 == ap_CS_fsm_state4))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((tmp_fu_213_p3 == 1'd1) & (1'b1 == ap_CS_fsm_state4))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        coeff_hw_V_ce0 = 1'b1;
    end else begin
        coeff_hw_V_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((tmp_fu_213_p3 == 1'd1) & (1'b1 == ap_CS_fsm_state4))) begin
        res_V_ap_vld = 1'b1;
    end else begin
        res_V_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        tomb_V_address0 = tmp_7_fu_221_p1;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        tomb_V_address0 = tmp_3_fu_204_p1;
    end else if (((tmp_2_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        tomb_V_address0 = 7'd0;
    end else if (((tmp_2_fu_187_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        tomb_V_address0 = tmp_5_fu_199_p1;
    end else begin
        tomb_V_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state3) | (1'b1 == ap_CS_fsm_state4) | ((tmp_2_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)) | ((tmp_2_fu_187_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2)))) begin
        tomb_V_ce0 = 1'b1;
    end else begin
        tomb_V_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        tomb_V_d0 = tomb_V_q0;
    end else if (((tmp_2_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        tomb_V_d0 = input_V;
    end else begin
        tomb_V_d0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state3) | ((tmp_2_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)))) begin
        tomb_V_we0 = 1'b1;
    end else begin
        tomb_V_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((tmp_2_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        ap_ST_fsm_state4 : begin
            if (((tmp_fu_213_p3 == 1'd1) & (1'b1 == ap_CS_fsm_state4))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign Range1_all_ones_fu_371_p2 = ((tmp_11_fu_361_p4 == 4'd15) ? 1'b1 : 1'b0);

assign Range1_all_zeros_fu_377_p2 = ((tmp_11_fu_361_p4 == 4'd0) ? 1'b1 : 1'b0);

assign Range2_all_ones_fu_355_p2 = ((tmp_10_fu_345_p4 == 3'd7) ? 1'b1 : 1'b0);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign brmerge40_demorgan_i_fu_441_p2 = (newsignbit_fu_317_p3 & deleted_ones_fu_403_p3);

assign brmerge_i_fu_423_p2 = (p_not_i_fu_417_p2 | newsignbit_fu_317_p3);

assign brmerge_i_i_fu_465_p2 = (underflow_fu_459_p2 | overflow_fu_435_p2);

assign carry_fu_331_p2 = (tmp_6_fu_325_p2 & tmp_17_fu_259_p3);

assign coeff_hw_V_address0 = tmp_7_fu_221_p1;

assign deleted_ones_fu_403_p3 = ((carry_fu_331_p2[0:0] === 1'b1) ? p_41_i_fu_397_p2 : Range1_all_ones_fu_371_p2);

assign deleted_zeros_fu_383_p3 = ((carry_fu_331_p2[0:0] === 1'b1) ? Range1_all_ones_fu_371_p2 : Range1_all_zeros_fu_377_p2);

assign i1_cast_fu_209_p1 = i1_reg_176;

assign i_1_fu_193_p2 = ($signed(i_reg_152) + $signed(7'd127));

assign i_2_fu_227_p2 = ($signed(i1_reg_176) + $signed(8'd255));

assign newsignbit_fu_317_p3 = p_Val2_3_fu_311_p2[32'd23];

assign overflow_fu_435_p2 = (tmp_13_fu_429_p2 & brmerge_i_fu_423_p2);

assign p_38_i_fu_411_p2 = (carry_fu_331_p2 & Range1_all_ones_fu_371_p2);

assign p_41_i_fu_397_p2 = (tmp_12_fu_391_p2 & Range2_all_ones_fu_355_p2);

assign p_Val2_2_fu_241_p4 = {{p_Val2_s_reg_164[40:17]}};

assign p_Val2_3_fu_311_p2 = (p_Val2_2_fu_241_p4 + tmp_4_fu_307_p1);

assign p_Val2_5_fu_491_p3 = ((underflow_fu_459_p2[0:0] === 1'b1) ? 24'd8388608 : p_Val2_3_fu_311_p2);

assign p_Val2_5_mux_fu_483_p3 = ((brmerge_i_i_fu_465_p2[0:0] === 1'b1) ? 24'd8388607 : p_Val2_3_fu_311_p2);

assign p_not_i_fu_417_p2 = (deleted_zeros_fu_383_p3 ^ 1'd1);

assign qb_assign_fu_301_p2 = (tmp_s_fu_295_p2 & signbit_fu_233_p3);

assign res_V = ((underflow_not_fu_477_p2[0:0] === 1'b1) ? p_Val2_5_mux_fu_483_p3 : p_Val2_5_fu_491_p3);

assign signbit_fu_233_p3 = p_Val2_s_reg_164[32'd44];

assign tmp1_demorgan_fu_447_p2 = (p_38_i_fu_411_p2 | brmerge40_demorgan_i_fu_441_p2);

assign tmp1_fu_453_p2 = (tmp1_demorgan_fu_447_p2 ^ 1'd1);

assign tmp2_fu_471_p2 = (tmp_13_fu_429_p2 | brmerge40_demorgan_i_fu_441_p2);

assign tmp_10_fu_345_p4 = {{p_Val2_s_reg_164[44:42]}};

assign tmp_11_fu_361_p4 = {{p_Val2_s_reg_164[44:41]}};

assign tmp_12_fu_391_p2 = (tmp_20_fu_337_p3 ^ 1'd1);

assign tmp_13_fu_429_p2 = (signbit_fu_233_p3 ^ 1'd1);

assign tmp_16_fu_251_p3 = p_Val2_s_reg_164[32'd16];

assign tmp_17_fu_259_p3 = p_Val2_s_reg_164[32'd40];

assign tmp_18_fu_267_p1 = p_Val2_s_reg_164[0:0];

assign tmp_1_fu_271_p2 = (tmp_18_fu_267_p1 | tmp_16_fu_251_p3);

assign tmp_20_fu_337_p3 = p_Val2_s_reg_164[32'd41];

assign tmp_2_fu_187_p2 = ((i_reg_152 == 7'd0) ? 1'b1 : 1'b0);

assign tmp_3_fu_204_p1 = i_reg_152;

assign tmp_4_fu_307_p1 = qb_assign_fu_301_p2;

assign tmp_5_fu_199_p1 = i_1_fu_193_p2;

assign tmp_6_fu_325_p2 = (newsignbit_fu_317_p3 ^ 1'd1);

assign tmp_7_fu_221_p1 = $unsigned(i1_cast_fu_209_p1);

assign tmp_8_fu_277_p4 = {{p_Val2_s_reg_164[15:1]}};

assign tmp_9_fu_287_p3 = {{tmp_8_fu_277_p4}, {tmp_1_fu_271_p2}};

assign tmp_fu_213_p3 = i1_reg_176[32'd7];

assign tmp_s_fu_295_p2 = ((tmp_9_fu_287_p3 != 16'd0) ? 1'b1 : 1'b0);

assign underflow_fu_459_p2 = (tmp1_fu_453_p2 & signbit_fu_233_p3);

assign underflow_not_fu_477_p2 = (tmp2_fu_471_p2 | p_38_i_fu_411_p2);

endmodule //fir_hw
