#include "measurer.h"

void MeasurementReader::reset_all_averages() {
}

void MeasurementReader::update_all_averages() {
}

float MeasurementReader::read_12V_mV() {
	return adc12V.read() * 18.137f;
}

float MeasurementReader::read_N12V_mV() {
	return adcN12V.read() * 19.97f;
}

float MeasurementReader::read_5V_mV() {
	return adc5V.read() * 17.217f;
}

uint16_t MeasurementReader::read_12V_mA() {
	return adc12A.read() * 2752;
}

uint16_t MeasurementReader::read_N12V_mA() {
	return adcN12A.read() * 2838;
}

uint16_t MeasurementReader::read_5V_mA() {
	return adc5A.read() * 2838;
}


