#pragma once
#include "channel_defs.h"

struct CalibrationDefs {
	const static inline SequentialMap<AdcChannels, float, 6> adc_scaling = {{{
		{voltage12V, 	19.0f},
		{voltage5V, 	16.93f},
		{voltageN12V, 	20.12f},
		{current12V, 	2745.0f},
		{current5V, 	2811.0f},
		{currentN12V, 	2852.0f},
	}}};
	const static inline SequentialMap<AdcChannels, float, 6> adc_offset = {{{
		{voltage12V, 	0.f},
		{voltage5V, 	0.f},
		{voltageN12V, 	0.f},
		{current12V, 	16.f},
		{current5V, 	9.f},
		{currentN12V, 	0.f},
	}}};
	const static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_max = {{{
		{Set12V, 2740},
		{Set5V,  2811},
		{SetN12V,2559}
	}}};
	const static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_offset = {{{
		{Set12V, 30},
		{Set5V,  23},
		{SetN12V,15}
	}}};
};

