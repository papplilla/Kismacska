set C_TypeInfoList {{ 
"fir_hw" : [[], { "return": [[], "void"]} , [{"ExternC" : 0}], [ {"input": [[],{ "pointer": "0"}] }, {"res": [[],{ "pointer": "1"}] }],[],""], 
"1": [ "dout_t", {"typedef": [[[],"2"],""]}], 
"2": [ "ap_fixed<24, 1, 6, 0, 0>", {"hls_type": {"ap_fixed": [[[[], {"scalar": { "int": 24}}],[[], {"scalar": { "int": 1}}],[[], {"scalar": { "3": 6}}],[[], {"scalar": { "4": 0}}],[[], {"scalar": { "int": 0}}]],""]}}], 
"4": [ "ap_o_mode", {"enum": [[],[],[{"SC_SAT":  {"scalar": "__integer__"}},{"SC_SAT_ZERO":  {"scalar": "__integer__"}},{"SC_SAT_SYM":  {"scalar": "__integer__"}},{"SC_WRAP":  {"scalar": "__integer__"}},{"SC_WRAP_SM":  {"scalar": "__integer__"}}],""]}], 
"0": [ "din_t", {"typedef": [[[],"5"],""]}], 
"3": [ "ap_q_mode", {"enum": [[],[],[{"SC_RND":  {"scalar": "__integer__"}},{"SC_RND_ZERO":  {"scalar": "__integer__"}},{"SC_RND_MIN_INF":  {"scalar": "__integer__"}},{"SC_RND_INF":  {"scalar": "__integer__"}},{"SC_RND_CONV":  {"scalar": "__integer__"}},{"SC_TRN":  {"scalar": "__integer__"}},{"SC_TRN_ZERO":  {"scalar": "__integer__"}}],""]}], 
"5": [ "ap_fixed<24, 1, 6, 3, 0>", {"hls_type": {"ap_fixed": [[[[], {"scalar": { "int": 24}}],[[], {"scalar": { "int": 1}}],[[], {"scalar": { "3": 6}}],[[], {"scalar": { "4": 3}}],[[], {"scalar": { "int": 0}}]],""]}}]
}}
set moduleName fir_hw
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {fir_hw}
set C_modelType { void 0 }
set C_modelArgList {
	{ input_V int 24 regular {pointer 0}  }
	{ res_V int 24 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_V", "interface" : "wire", "bitwidth" : 24, "direction" : "READONLY", "bitSlice":[{"low":0,"up":23,"cElement": [{"cName": "input.V","cData": "int24","bit_use": { "low": 0,"up": 23},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "res_V", "interface" : "wire", "bitwidth" : 24, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":23,"cElement": [{"cName": "res.V","cData": "int24","bit_use": { "low": 0,"up": 23},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 9
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ input_V sc_in sc_lv 24 signal 0 } 
	{ res_V sc_out sc_lv 24 signal 1 } 
	{ res_V_ap_vld sc_out sc_logic 1 outvld 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "input_V", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "input_V", "role": "default" }} , 
 	{ "name": "res_V", "direction": "out", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "res_V", "role": "default" }} , 
 	{ "name": "res_V_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "res_V", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3"],
		"CDFG" : "fir_hw",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "512", "EstimateLatencyMax" : "512",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "res_V", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "tomb_V", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "coeff_hw_V", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.tomb_V_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.coeff_hw_V_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fir_hw_mac_muladdbkb_U1", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fir_hw {
		input_V {Type I LastRead 1 FirstWrite -1}
		res_V {Type O LastRead -1 FirstWrite 2}
		tomb_V {Type IO LastRead -1 FirstWrite -1}
		coeff_hw_V {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "512", "Max" : "512"}
	, {"Name" : "Interval", "Min" : "513", "Max" : "513"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	input_V { ap_none {  { input_V in_data 0 24 } } }
	res_V { ap_vld {  { res_V out_data 1 24 }  { res_V_ap_vld out_vld 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
