#pragma once
#include "channel_defs.h"

struct CalibrationDefs {
	static inline SequentialMap<AdcChannels, float, 6> adc_scaling = {{{
		{voltage12V, 	19.16f},
		{voltage5V, 	18.35f},//16.93f},
		{voltageN12V, 	20.46f},
		{current12V, 	2472.f},//2435.f},//2745.0f},
		{current5V, 	2468.f},//2811.0f},
		{currentN12V, 	2667.f},
	}}};
	static inline SequentialMap<AdcChannels, float, 6> adc_offset = {{{
		{voltage12V, 	0.f},
		{voltage5V, 	0.f},
		{voltageN12V, 	0.f},
		{current12V, 	16.f},
		{current5V, 	9.f},
		{currentN12V, 	0.f},
	}}};
	static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_max = {{{
		{Set12V, 2229},
		{Set5V,  2229},
		{SetN12V,2229}
	}}};
	static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_offset = {{{
		{Set12V, 11},
		{Set5V,  8},
		{SetN12V,13}
	}}};
};

