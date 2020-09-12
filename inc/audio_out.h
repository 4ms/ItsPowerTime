#pragma once
#include "mbed.h"

class BuzzerPlayer {
public:
	BuzzerPlayer(AnalogOut &audioout) : audiodac{audioout} {}
	void play_next_sample();
	void start(float frequency, float amplitude);
	void stop();

private:
	AnalogOut &audiodac;
	Ticker callback_timer;
	float current_sample;
	float amp;
};

class WavPlayer {
public:
	WavPlayer(AnalogOut &audioout) : audiodac{audioout} {}
	void play_next_sample();
	void start(const uint8_t *const wavdata, const uint32_t num_samples, const float sample_freq, const float gain);
	void stop();
	bool looping = false;

private:
	AnalogOut &audiodac;
	Ticker callback_timer;
	const uint8_t *data;
	uint32_t idx;
	uint32_t size;
	float gain = 1.0f;
};

class AudioOutput {
public:
	AudioOutput();
	void play_wav(const uint8_t *const wavdata, const uint32_t num_samples, const float sample_freq);
	void play_wav_looping(const uint8_t * const wavdata, const uint32_t num_samples, const float sample_freq);
	void play_buzzer(float frequency, float amplitude);
	void stop();
	void set_gain(float g);

private:
	AnalogOut audiodac{PA_5};
	WavPlayer wav_player{audiodac};
	BuzzerPlayer buzzer_player{audiodac};
	float gain = 1.0f;
};

