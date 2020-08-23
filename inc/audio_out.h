#pragma once
#include "mbed.h"

class WavPlayer {
public:
	WavPlayer(PwmOut &audioout) : audio{audioout} {}
	void play_next_sample();
	PwmOut &audio;
	Ticker callback_timer;
	const uint8_t *data;
	uint32_t idx;
	uint32_t size;
	uint32_t period_us;
};

class PWMAudioOutput {
public:
	PWMAudioOutput();
	void write_value();
	void play_wav(const uint8_t *const wavdata, const uint32_t num_samples, const float sample_freq);
	void start_buzzer(uint16_t frequency);
	uint16_t get_buzzer_freq();
	void stop();

	bool is_playing;

private:
	uint16_t buzzer_freq;
	PwmOut audioout{PE_5}; //PE_5
	WavPlayer wav_player{audioout};
	// std::function<void(void)> wav_callback;
};

