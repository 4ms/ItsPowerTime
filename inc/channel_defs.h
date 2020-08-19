#pragma once

enum AdcChannels : uint8_t {
	voltage12V, voltage5V, voltageN12V,
	current12V, current5V, currentN12V,
	numChannels
};

enum CurrentSetChannels : uint8_t {
	Set12V = 0,
	Set5V = 1,
	SetN12V = 2
};
