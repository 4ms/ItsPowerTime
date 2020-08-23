#include "audio_out.h"

PWMAudioOutput::PWMAudioOutput() {
	audioout.period_us(1); //1MHz
	audioout.write(0.0);
	is_playing = false;
	buzzer_freq = 0;
}

uint16_t PWMAudioOutput::get_buzzer_freq() {
	return buzzer_freq;
}

void PWMAudioOutput::start_buzzer(uint16_t frequency) {
	float period_us = 1000000.0f / (float)frequency;
	audioout.period_us(period_us);
	audioout.write(0.5);
	is_playing = true;
	buzzer_freq = frequency;
}

void PWMAudioOutput::stop() {
	audioout.period_us(1);
	audioout.write(0.0);
	is_playing = false;
}

void PWMAudioOutput::play_wav(const uint8_t * const wavdata, const uint32_t num_samples, const float sample_freq) {
	audioout.period_us(64);
	//Todo: is_playing won't work for wav files unless we attach a reference or callback for WavPlayer to do when it's done
	is_playing = true;
	wav_player.idx = 0;
	wav_player.size = num_samples;
	wav_player.data = wavdata;
	wav_player.period_us = static_cast<uint32_t>(1000000.0f / sample_freq);
	//wav_player.callback_timer.attach_us(&wav_player.play_next_sample, wav_player.period_us);
	//wav_callback = wav_player.play_next_sample;
	auto cb = callback(&wav_player, &WavPlayer::play_next_sample);
	wav_player.callback_timer.attach_us(cb, wav_player.period_us);
}

void WavPlayer::play_next_sample() {
	float sample = (float)(data[idx]) / 255.0f;
	audio.write(sample);
	if (++idx >= size) {
		callback_timer.detach();
		audio.write(0.0f);
	}
}

