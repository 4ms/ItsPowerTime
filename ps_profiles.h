#pragma once

enum class PSProfileID {
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

struct psProfile {
	PSProfileID psProfileID;
	uint16_t mA_12V;
	uint16_t mA_5V;
	uint16_t mA_N12V;
	uint16_t test_time_s;
	char name[40];
};

//Todo: use to_array() and then kNumProfiles is ProfileArray.size()
constexpr uint8_t kNumProfiles = 9;
//const std::array<psProfile, kNumProfiles> psProfileArray = {
const psProfile psProfileArray[kNumProfiles] = {
	{ PSProfileID::Pod20_26_32, 700, 1000, 280, 5*60, "Pod 20-32" },
	{ PSProfileID::PodX_60,        	1400, 1000, 670, 5*60, "PodX/60" },
	{ PSProfileID::RP25,           	1000, 500, 1000, 5*60, "RP 25" },
	{ PSProfileID::RP35,           	1500, 1500, 1250, 5*60, "RP 35" },
	{ PSProfileID::RP45,           	2000, 1500, 1250, 7*60, "RP 45" },
	{ PSProfileID::Manual,         	0 , 0, 0, 30*60, "Manual" },
	{ PSProfileID::Old_Pod20_26_32,	700, 200, 280, 5*60, "Old Pod 20-32" },
	{ PSProfileID::Old_Pod_Dbl_Nrw,	1400, 500, 670, 5*60, "Old PodDbl/Nar" },
	{ PSProfileID::Old_Pod_60_2PCBS,	700, 200, 280, 5*60, "Old Pod60 two PCB" },
};

