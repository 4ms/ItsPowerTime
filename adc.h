#pragma once
#include <mbed.h>
#include <stdint.h>

class CurrentMeasurer {
public:
	float read_12V_mV();
	float read_N12V_mV();
	float read_5V_mV();

	uint16_t read_12V_mA();
	uint16_t read_N12V_mA();
	uint16_t read_5V_mA();

private:
	AnalogIn adc12V {PA_5}; //CH5
	AnalogIn adc5V {PC_3}; //CH1 (moved from PA1 in p2 board)
	AnalogIn adcN12V {PA_7}; //CH7

	AnalogIn adc12A {PC_2}; //CH12 also is LCD CS (moved from PC4 on p2 board)
	AnalogIn adc5A {PF_8};  //ADC3_CH6 also is MEMS Accel MISO (moved from PA2 on p2 board)
	AnalogIn adcN12A {PF_6}; //CH4
};

//PC0: MEMS CS, won't boot
//PA1 won't work
//PA2 won't work
//PC4 sorta ok -- has 10k pull-up and is Enable for STMPS2141STR (1705)
//PC5 sorta ok -- has 47k pullup || 620R+LED, and is Fault output of SRMPS214
