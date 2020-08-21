#pragma once
#include "util/sequential_map.hh"

namespace PSProfiles {
enum PSProfileID : size_t {
	RP25,
	RP35,
	RP45,
	Pod20_26_32,
	PodX_60,
	Old_Pod20_26_32,
	Old_Pod_Dbl_Nrw,
	Old_Pod_60_2PCBS,
	Manual,
	NUM_PSPROFILE_IDS,
};
constexpr size_t kNumPSProfiles = static_cast<size_t>(PSProfileID::NUM_PSPROFILE_IDS);

struct PSProfile {
	uint16_t mA_12V;
	uint16_t mA_5V;
	uint16_t mA_N12V;
	uint16_t test_time_s;
	std::string name;

	bool operator==(const PSProfile &rhs) {
		return (this->name == rhs.name);
	}
};

const SequentialMap<PSProfileID, PSProfile, kNumPSProfiles> psProfileArray = {{{
	{ RP25,           		{ 1000, 500, 1000, 5*60, "RP 25" }},
	{ RP35,           		{ 1500, 1500, 1250, 5*60, "RP 35" }},
	{ RP45,           		{ 2000, 1500, 1250, 7*60, "RP 45" }},
	{ Pod20_26_32, 		{ 700, 1000, 280, 5*60, "Pod 20-32" }},
	{ PodX_60,        		{ 1400, 1000, 670, 5*60, "PodX/60" }},
	{ Old_Pod20_26_32, 	{ 700, 200, 280, 5*60, "Old Pod 20-32" }},
	{ Old_Pod_Dbl_Nrw,		{ 1400, 500, 670, 5*60, "Old PodDbl/Nar" }},
	{ Old_Pod_60_2PCBS,	{ 700, 200, 280, 5*60, "Old Pod60 two PCB" }},
	{ Manual,         		{ 0 , 0, 0, 30*60, "Manual" }},
}}};

} //namespace PSProfiles

//const psProfile psProfileArray[kNumProfiles] = {
//};
//Todo: use to_array() and then kNumProfiles is ProfileArray.size()
//constexpr size_t kNumProfiles = psProfileArray.size();
