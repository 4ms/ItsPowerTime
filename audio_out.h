#pragma once
#include "mbed.h"

class PWMAudioOutput {
public:
	PWMAudioOutput();
	void write_value();
	void play_wav(uint8_t *wavdata, uint32_t num_samples, uint16_t sample_freq);
	void play_wav(uint16_t *wavdata, uint32_t num_samples, uint16_t sample_freq);
	void start_buzzer(uint16_t frequency);
	void stop();

	bool is_playing;

private:
	PwmOut audioout {PE_5};
};

