#include "measurer.h"

void MeasurementReader::reset_all_averages() {
	for (auto &avg : averages) {
		avg.resetAveraging();
	}
}

void MeasurementReader::update_all_averages() {
	uint8_t chan = 0;
	for (auto &avg : averages) {
		avg.addSample(raw_reading(chan));
		chan++;
	}
}

float MeasurementReader::raw_reading(uint8_t chan) {
	return (adcs[chan].read() * CalibrationDefs::adc_scaling[chan]) + CalibrationDefs::adc_offset[chan];
}

float MeasurementReader::get_average(uint8_t chan) {
	return averages[chan].getAverage();
}
