#pragma once

enum AdcChannels : uint8_t {
	voltage12V, voltage5V, voltageN12V,
	current12V, current5V, currentN12V,
	numChannels
};

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

enum CurrentSetChannels : uint8_t {
	Set12V = 0,
	Set5V = 1,
	SetN12V = 2
};

