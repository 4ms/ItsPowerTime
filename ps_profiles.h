#pragma once

struct psProfile {
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
	{ 700, 1000, 280, 5*60, "Pod 20/26/32" },
	{ 1400, 1000, 670, 5*60, "Pod X/60" },
	{ 1000, 500, 1000, 5*60, "RP 25" },
	{ 1500, 1500, 1250, 5*60, "RP 35" },
	{ 2000, 1500, 1250, 7*60, "RP 45" },
	{ 0 , 0, 0, 30*60, "Manual" },
	{ 700, 200, 280, 5*60, "Old Pod" },
	{ 1400, 500, 670, 5*60, "Old PodDbl" },
	{ 700, 200, 280, 5*60, "Old Pod60" },
};

struct psProfiles {
	static constexpr psProfile PodPower = {
		700, 1000, 280, 5*60, "Pod 20/26/32"
	};
	static constexpr psProfile PodPowerDouble = {
		1400, 1000, 670, 5*60, "Pod X/60"
	};
	static constexpr psProfile RowPower25 = {
		1000, 500, 1000, 5*60, "RP 25"
	};
	static constexpr psProfile RowPower35 = {
		1500, 1500, 1250, 5*60, "RP 35"
	};
	static constexpr psProfile RowPower45 = {
		2000, 1500, 1250, 7*60, "RP 45"
	};
	static constexpr psProfile ManualMode = {
		0 , 0, 0, 30*60, "Manual Mode"
	};
	static constexpr psProfile PodPowerV1 = {
		700, 200, 280, 5*60, "Old Pod"
	};
	static constexpr psProfile PodPowerDoubleV1 = {
		1400, 500, 670, 5*60, "Old Pod Dbl/Nar"
	};
	static constexpr psProfile Pod60V1 = {
		700, 200, 280, 5*60, "Old Pod60 x2"
	};
};

