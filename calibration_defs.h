#pragma once

enum AdcChannels : uint8_t {
	voltage12V, voltage5V, voltageN12V,
	current12V, current5V, currentN12V,
	numChannels
};

enum CurrentSetChannels : uint8_t {
	Set12V = 0,
	Set5V = 1,
	SetN12V = 2
};

struct CalibrationDefs {
	const static inline PinName channelPins[6]= {
		PA_5, PC_3, PA_7,
		PF_8, PC_2, PF_6
	};
	const static inline float adc_scaling[6] {
		17.89f/*18.137f*/, 17.217f, 19.97f,
		2745.0f, 2811.0f, 2852.0f
	};
	const static inline float adc_offset[6] {
		0.0f, 0.f, 0.f,
		16.f, 9.f, 0.f
	};

	const static inline uint16_t current_set_max[3] {
		2740, 2811, 2559
	};
	const static inline int16_t current_set_offset[3] {
		30, 23, 15
	};
};

