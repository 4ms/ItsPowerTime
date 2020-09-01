#include "measurer.h"

void MeasurementReader::reset_all_averages() {
	for (auto &avg : averages) {
		avg.resetAveraging();
	}
}

void MeasurementReader::reset_all_minmax() {
	for (auto &m : maxes)
		m = -999999999999999.F;
	for (auto &m : mins)
		m = 999999999999999.F;
}

void MeasurementReader::update_all_averages() {
	uint8_t chan = 0;
	for (auto &avg : averages) {
		auto reading = raw_reading(chan);
		avg.addSample(reading);
		if (reading > maxes[chan])
			maxes[chan] = reading;
		if (reading < mins[chan])
			mins[chan] = reading;

		chan++;
	}
}

float MeasurementReader::raw_reading(uint8_t chan) {
	auto adc_chan = static_cast<AdcChannels>(chan);
	return (adcs[chan].read() * CalibrationDefs::adc_scaling[adc_chan]) + CalibrationDefs::adc_offset[adc_chan];
}

float MeasurementReader::get_average(uint8_t chan) {
	return averages[chan].getAverage();
}

float MeasurementReader::get_max(uint8_t chan) {
	return maxes[chan];
}

float MeasurementReader::get_min(uint8_t chan) {
	return mins[chan];
}
