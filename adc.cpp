#include "adc.h"

float CurrentMeasurer::read_12V_mV() {
	return adc12V.read() * 19.8f;
}

float CurrentMeasurer::read_N12V_mV() {
	return adcN12V.read() * 23.3f;
}

float CurrentMeasurer::read_5V_mV() {
	return adc5V.read() * 19.8f;
}

uint16_t CurrentMeasurer::read_12V_mA() {
	return adc12A.read() * 3300;
}

uint16_t CurrentMeasurer::read_N12V_mA() {
	return adcN12A.read() * 3300;
}

uint16_t CurrentMeasurer::read_5V_mA() {
	return adc5A.read() * 3300;
}


