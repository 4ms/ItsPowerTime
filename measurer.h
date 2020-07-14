#pragma once
#include <mbed.h>
#include <stdint.h>
#include "filters.hh"

enum AdcChannels : uint8_t {
	voltage12V, voltage5V, voltageN12V,
	current12V, current5V, currentN12V,
	numChannels
};

class MeasurementReader {
	const static inline PinName channelPins[6]= {
		PA_5, PC_3, PA_7,
		PF_8, PC_2, PF_6
	};
public:
	float get_average(uint8_t chan);
	void reset_all_averages();
	void update_all_averages();

private:
	float raw_reading(uint8_t chan);

	const static inline float scaling[6] {
		18.137f, 17.217f, 19.97f,
		2745.0f, 2811.0f, 2852.0f
	};
	const static inline float offset[6] {
		0.0f, 0.f, 0.f,
		16.f, 9.f, 0.f
	};
	AnalogIn adcs[6] {
		channelPins[AdcChannels::voltage12V],
		channelPins[AdcChannels::voltage5V],
		channelPins[AdcChannels::voltageN12V],
		channelPins[AdcChannels::current12V],
		channelPins[AdcChannels::current5V],
		channelPins[AdcChannels::currentN12V]
	};
	SimpleAverage averages[6];
};

//PC0: MEMS CS, won't boot
//PA1 won't work
//PA2 won't work
//PC4 sorta ok -- has 10k pull-up and is Enable for STMPS2141STR (1705)
//PC5 sorta ok -- has 47k pullup || 620R+LED, and is Fault output of SRMPS214
