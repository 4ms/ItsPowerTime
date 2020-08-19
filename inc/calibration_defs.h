#pragma once

struct CalibrationDefs {
	const static inline PinName channelPins[]= {
		PA_5, PC_3, PA_7,
		PF_8, PC_2, PF_6
	};
	const static inline float adc_scaling[] {
		17.89f, 17.217f, 19.97f,
		2745.0f, 2811.0f, 2852.0f
	};
	const static inline float adc_offset[] {
		0.0f, 0.f, 0.f,
		16.f, 9.f, 0.f
	};

	const static inline uint16_t current_set_max[] {
		2740, 2811, 2559
	};
	const static inline int16_t current_set_offset[] {
		30, 23, 15
	};
};

