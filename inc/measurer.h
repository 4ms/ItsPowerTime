#pragma once
#include <mbed.h>
#include <stdint.h>
#include "filters.hh"
#include "calibration_defs.h"

class MeasurementReader {
public:
	float get_average(uint8_t chan);
	void reset_all_averages();
	void update_all_averages();

private:
	float raw_reading(uint8_t chan);

	AnalogIn adcs[6] {
		CalibrationDefs::channelPins[AdcChannels::voltage12V],
		CalibrationDefs::channelPins[AdcChannels::voltage5V],
		CalibrationDefs::channelPins[AdcChannels::voltageN12V],
		CalibrationDefs::channelPins[AdcChannels::current12V],
		CalibrationDefs::channelPins[AdcChannels::current5V],
		CalibrationDefs::channelPins[AdcChannels::currentN12V]
	};
	SimpleAverage averages[6];
};

//PC0: MEMS CS, won't boot
//PA1 won't work
//PA2 won't work
//PC4 sorta ok -- has 10k pull-up and is Enable for STMPS2141STR (1705)
//PC5 sorta ok -- has 47k pullup || 620R+LED, and is Fault output of SRMPS214
