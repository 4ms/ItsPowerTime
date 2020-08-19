#pragma once
namespace PSProfiles {
enum PSProfileID {
	Pod20_26_32,
	PodX_60,
	RP25,
	RP35,
	RP45,
	Manual,
	Old_Pod20_26_32,
	Old_Pod_Dbl_Nrw,
	Old_Pod_60_2PCBS
};

struct PSProfile {
	PSProfileID psProfileID;
	uint16_t mA_12V;
	uint16_t mA_5V;
	uint16_t mA_N12V;
	uint16_t test_time_s;
	char name[40];
};


//Todo: use to_array() and then kNumProfiles is ProfileArray.size()
//const std::array<psProfile, kNumProfiles> psProfileArray = {
const PSProfile psProfileArray[] = {
	{ Pod20_26_32, 		700, 1000, 280, 10, "Pod 20-32" },
	{ PodX_60,        	1400, 1000, 670, 5*60, "PodX/60" },
	{ RP25,           	1000, 500, 1000, 5*60, "RP 25" },
	{ RP35,           	1500, 1500, 1250, 5*60, "RP 35" },
	{ RP45,           	2000, 1500, 1250, 7*60, "RP 45" },
	{ Manual,         	0 , 0, 0, 30*60, "Manual" },
	{ Old_Pod20_26_32,	700, 200, 280, 5*60, "Old Pod 20-32" },
	{ Old_Pod_Dbl_Nrw,	1400, 500, 670, 5*60, "Old PodDbl/Nar" },
	{ Old_Pod_60_2PCBS,	700, 200, 280, 5*60, "Old Pod60 two PCB" },
};
constexpr uint8_t kNumProfiles = sizeof(psProfileArray) / sizeof(psProfileArray[0]);
};//namespace