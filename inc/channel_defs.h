#pragma once
#include "util/sequential_map.hh"

enum AdcChannels : uint8_t {
	voltage12V,
	voltage5V,
	voltageN12V,
	current12V,
	current5V,
	currentN12V,
	numChannels
};

const SequentialMap<AdcChannels, PinName, 6> channelPins = {{{
	{voltage12V, PA_0},
	{voltage5V, PC_3},
	{voltageN12V, PA_7},
	{current12V, PF_8},
	{current5V, PC_2},
	{currentN12V, PF_6},
}}};

struct AdcChannelNames {
	static void get_string(AdcChannels chan, char *str) {
		switch (chan) {
			case (voltage12V):
				strcpy(str, "+12V:");
				break;
			case (voltage5V):
				strcpy(str, "5V:");
				break;
			case (voltageN12V):
				strcpy(str, "-12V:");
				break;
			case (current12V):
				strcpy(str, "+12V mA:");
				break;
			case (current5V):
				strcpy(str, "5V mA:");
				break;
			case (currentN12V):
				strcpy(str, "-12V mA:");
				break;
			default:
				strcpy(str, "?");
				break;
		}
	}
};

enum CurrentSetChannel : uint8_t {
	Set12V,
	Set5V,
	SetN12V
};

struct CurrentSetPins {
	static constexpr inline SequentialMap<CurrentSetChannel, PinName, 3> pin = {{{
		{Set12V, PC_8},
		{Set5V,  PB_7},
		{SetN12V, PE_5},
	}}};
};

