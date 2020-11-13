#pragma once
#include "channel_defs.h"
//Unit 1:
//struct CalibrationDefs {
////	//reading = (raw reading * scaling) + offset
//	static inline SequentialMap<AdcChannels, float, 6> adc_scaling = {{{
//		{voltage12V, 	19.16f},
//		{voltage5V, 	18.08f},
//		{voltageN12V, 	20.81f},
//		{current12V, 	2381.f},
//		{current5V, 	2674.f},
//		{currentN12V, 	2814.f},
//	}}};
//	static inline SequentialMap<AdcChannels, float, 6> adc_offset = {{{
//		{voltage12V, 	0.f},
//		{voltage5V, 	0.f},
//		{voltageN12V, 	0.f},
//		{current12V, 	-6.f},
//		{current5V, 	9.f},
//		{currentN12V, 	-9.f},
//	}}};
//	//current setter PWM_duty_cycle = ((requested_mA - offset)/max);
//	static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_max = {{{
//		{Set12V, 2131},
//		{Set5V,  2393},
//		{SetN12V,2347} 
//	}}};
//	static inline SequentialMap<CurrentSetChannel, int16_t, 3> current_set_offset = {{{
//		{Set12V, 0},
//		{Set5V,  12},
//		{SetN12V,0}
//	}}};
//};

//Unit 2:
struct CalibrationDefs {
//	//reading = (raw reading * scaling) + offset
	static inline SequentialMap<AdcChannels, float, 6> adc_scaling = {{{
		{voltage12V, 	19.16f},
		{voltage5V, 	18.08f},
		{voltageN12V, 	20.81f},
		{current12V, 	1893.f},
		{current5V, 	2763.f},
		{currentN12V, 	2929.f},
	}}};
	static inline SequentialMap<AdcChannels, float, 6> adc_offset = {{{
		{voltage12V, 	0.f},
		{voltage5V, 	0.f},
		{voltageN12V, 	0.f},
		{current12V, 	12.f},
		{current5V, 	29.f},
		{currentN12V, 	-18.f},
	}}};
	//current setter PWM_duty_cycle = ((requested_mA - offset)/max);
	static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_max = {{{
		{Set12V, 1701},
		{Set5V,  2500},
		{SetN12V,2421} 
	}}};
	static inline SequentialMap<CurrentSetChannel, int16_t, 3> current_set_offset = {{{
		{Set12V, 11},
		{Set5V,  24},
		{SetN12V,0}
	}}};
};


//Unit 3:
//struct CalibrationDefs {
//	//reading = (raw reading * scaling) + offset
//	static inline SequentialMap<AdcChannels, float, 6> adc_scaling = {{{
//		{voltage12V, 	19.16f},
//		{voltage5V, 	18.4f},
//		{voltageN12V, 	20.31f},
//		{current12V, 	1984.f},
//		{current5V, 	2785.f},
//		{currentN12V, 	2870.f},
//	}}};
//	static inline SequentialMap<AdcChannels, float, 6> adc_offset = {{{
//		{voltage12V, 	0.f},
//		{voltage5V, 	0.f},
//		{voltageN12V, 	0.f},
//		{current12V, 	-140.f},
//		{current5V, 	16.f},
//		{currentN12V, 	0.f},
//	}}};
//	//current setter PWM_duty_cycle = ((requested_mA - offset)/max);
//	static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_max = {{{
//		{Set12V, 1750},
//		{Set5V,  2497},
//		{SetN12V,2402} 
//	}}};
//	static inline SequentialMap<CurrentSetChannel, int16_t, 3> current_set_offset = {{{
//		{Set12V, 10},
//		{Set5V,  20},
//		{SetN12V,-11}
//	}}};
//};


//Todo: use a structure like this:
// Then calculate
struct CalibrationReadings {

	//Actual readings from ADC when a {low, high} signal is applied.
	//Signal 		LOW 		HIGH
	//------------  ----------  ------------
	//voltage12V:  	2V 			10V
	//voltage5V:  	2V 			10V
	//voltageN12V: 	-2V 		-10V
	//current12V:  	200mA 		1000mA
	//current5V:  	200mA 		1000mA
	//currentN12V: 	200mA 		1000mA

	SequentialMap<AdcChannels, std::pair<uint16_t, uint16_t>, 6> adc_low_high_reading {{{
		{voltage12V, 	{19, 4000}},
		{voltage5V, 	{17, 4000}},
		{voltageN12V, 	{20, 4000}},
		{current12V, 	{20, 4000}},
		{current5V, 	{23, 4000}},
		{currentN12V, 	{28, 4000}},
	}}};

	//Actual load current as measured by a DMM measuring mA,
	//when an uncalibrated ItsPowerTime is told to set {low, high} raw values
	//
	//Signal 		LOW 		HIGH
	//------------  ----------  ------------
	//Set12V:  		0.2 		0.8
	//Set5V:  		0.2 		0.8
	//SetN12V: 		0.2 		0.8
	SequentialMap<CurrentSetChannel, std::pair<float, float>, 3> current_set_actual = {{{
		{Set12V, {400.f, 1800.f}},
		{Set5V,  {400.f, 1800.f}},
		{SetN12V,{400.f, 1800.f}},
	}}};

};
