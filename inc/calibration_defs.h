#pragma once
#include "channel_defs.h"

struct CalibrationDefs {
	static inline SequentialMap<AdcChannels, float, 6> adc_scaling = {{{
		{voltage12V, 	19.16f},
		{voltage5V, 	17.00f},
		{voltageN12V, 	20.81f},
		{current12V, 	2022.f},
		{current5V, 	2340.f},
		{currentN12V, 	2508.f},
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
		{Set12V, 1813},
		{Set5V,  2131},
		{SetN12V,2090}
	}}};
	static inline SequentialMap<CurrentSetChannel, uint16_t, 3> current_set_offset = {{{
		{Set12V, 11},
		{Set5V,  8},
		{SetN12V,13}
	}}};
};

