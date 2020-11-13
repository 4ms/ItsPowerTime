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

enum EurorackPSRailID :size_t {
	Rail_12V,
	Rail_5V,
	Rail_N12V,
	kNumEurorackPSRails
};

struct PSRail {
	std::string_view name;
	float target_V;
	float tol_V;
	float target_mA;
	float tol_mA;
};

struct PSProfile {
	std::string_view name;
	uint16_t test_time_s;
	SequentialMap<EurorackPSRailID, PSRail, kNumEurorackPSRails> chan;

	bool operator==(const PSProfile &rhs) { return (this->name == rhs.name); }
};

const SequentialMap<PSProfileID, PSProfile, kNumPSProfiles> psProfileArray = {{{
	{ RP25, {
		.name = "RP 25",
		.test_time_s = 1*60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 1000.f, .tol_mA = 150,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 500.f, .tol_mA = 50,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 1000.f, .tol_mA = 150,
			}},
		}}},
	}},
	{ RP35, {
		.name = "RP 35",
		.test_time_s = 2*60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 1500.f, .tol_mA = 150,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 1000.f, .tol_mA = 50,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 1250.f, .tol_mA = 150,
			}},
		}}},
	}},
	{ RP45, {
		.name = "RP 45",
		.test_time_s = 2*60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 2000.f, .tol_mA = 150,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 1500.f, .tol_mA = 50,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 1250.f, .tol_mA = 150,
			}},
		}}},
	}},
	{ Pod20_26_32, {
		.name = "Pod 20-32",
		.test_time_s = 1*60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 700.f, .tol_mA = 100,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 1000.f, .tol_mA = 100,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 280.f, .tol_mA = 30,
			}},
		}}},
	}},
	{ PodX_60, {
		.name = "PodX/60",
		.test_time_s = 1*60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 1400.f, .tol_mA = 100,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 1000.f, .tol_mA = 100,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 670.f, .tol_mA = 30,
			}},
		}}},
	}},
	{ Old_Pod20_26_32, {
		.name = "Old Pod 20-32",
		.test_time_s = 60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 700.f, .tol_mA = 100,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 200.f, .tol_mA = 30,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 280.f, .tol_mA = 30,
			}},
		}}},
	}},
	{ Old_Pod_Dbl_Nrw, {
		.name = "Old PodDbl/Nar",
		.test_time_s = 60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 1400.f, .tol_mA = 150,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 500.f, .tol_mA = 50,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 670.f, .tol_mA = 70,
			}},
		}}},
	}},
	{ Old_Pod_60_2PCBS, {
		.name = "Old Pod60 two PCB",
		.test_time_s = 60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 700.f, .tol_mA = 100,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 0.5f,
				.target_mA = 200.f, .tol_mA = 20,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 0.7f,
				.target_mA = 280.f, .tol_mA = 30,
			}},
		}}},
	}},
	{ Manual, {
		.name = "Manual",
		.test_time_s = 20*60,
		.chan = {{{
			{ Rail_12V, {
				.name = "+12V",
				.target_V = 12.f, .tol_V = 1.0f,
				.target_mA = 0.f, .tol_mA = 20,
			}},
			{Rail_5V, {
				.name = "+5V",
				.target_V = 5.f, .tol_V = 1.0f,
				.target_mA = 0.f, .tol_mA = 20,
			}},
			{Rail_N12V, {
				.name = "-12V",
				.target_V = 12.f, .tol_V = 1.0f,
				.target_mA = 0.f, .tol_mA = 20,
			}},
		}}},
	}},
}}};


} //namespace PSProfiles

