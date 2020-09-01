#pragma once
#include <mbed.h>
#include <stdint.h>
#include "filters.hh"
#include "calibration_defs.h"
#include "channel_defs.h"

class MeasurementReader {
public:
	float get_average(uint8_t chan);
	float get_max(uint8_t chan);
	float get_min(uint8_t chan);
	void reset_all_averages();
	void reset_all_minmax();
	void update_all_averages();

private:
	float raw_reading(uint8_t chan);

	//Todo: how to initialize the elements of an array of one class with elements of another array of another class?
	AnalogIn adcs[6] {
		channelPins[AdcChannels::voltage12V],
		channelPins[AdcChannels::voltage5V],
		channelPins[AdcChannels::voltageN12V],
		channelPins[AdcChannels::current12V],
		channelPins[AdcChannels::current5V],
		channelPins[AdcChannels::currentN12V]
	};
	SimpleAverage averages[6];
	float maxes[6] = {-999999999.F};
	float mins[6] = {999999999.F};
};

