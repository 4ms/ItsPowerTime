#pragma once
#include "mbed.h"

class BuzzerPlayer {
public:
	BuzzerPlayer(AnalogOut &audioout) : audiodac{audioout} {}
	void play_next_sample();
	void stop();

	AnalogOut &audiodac;
	Ticker callback_timer;
	float sample;
	float period_us;
	float amplitude;
};

class WavPlayer {
public:
	WavPlayer(AnalogOut &audioout) : audiodac{audioout} {}
	void play_next_sample();
	void stop();

	AnalogOut &audiodac;
	Ticker callback_timer;
	const uint8_t *data;
	uint32_t idx;
	uint32_t size;
	uint32_t period_us;
};

class AudioOutput {
public:
	AudioOutput();
	void play_wav(const uint8_t *const wavdata, const uint32_t num_samples, const float sample_freq);
	void play_buzzer(float frequency, float amplitude);
	void stop();

private:
	AnalogOut audiodac{PA_5};
	WavPlayer wav_player{audiodac};
	BuzzerPlayer buzzer_player{audiodac};
};

