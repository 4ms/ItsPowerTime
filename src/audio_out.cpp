#include "audio_out.h"

AudioOutput::AudioOutput() {
}

void AudioOutput::play_buzzer(float frequency, float amplitude) {
	wav_player.stop();
	buzzer_player.start(frequency, amplitude);
}

void AudioOutput::play_wav(const uint8_t * const wavdata, const uint32_t num_samples, const float sample_freq) {
	buzzer_player.stop();
	wav_player.looping = false;
	wav_player.start(wavdata, num_samples, sample_freq, gain);
}

void AudioOutput::play_wav_looping(const uint8_t * const wavdata, const uint32_t num_samples, const float sample_freq) {
	buzzer_player.stop();
	wav_player.looping = true;
	wav_player.start(wavdata, num_samples, sample_freq, gain);
}

void AudioOutput::stop() {
	wav_player.stop();
	buzzer_player.stop();
}

// WavPlayer

void WavPlayer::start(const uint8_t *const wavdata, const uint32_t num_samples, const float sample_freq, const float g) {
	idx = 0;
	size = num_samples;
	data = wavdata;
	gain = g;
	uint32_t period_us = static_cast<uint32_t>(1000000.0f / sample_freq);
	auto cb = callback(this, &WavPlayer::play_next_sample);
	callback_timer.attach_us(cb, period_us);
}

void AudioOutput::set_gain(float g) {
	gain = g;
}

void WavPlayer::play_next_sample() {
	float sample = (float)(data[idx]) / 255.0f;
	sample = (sample - 0.5) * gain + 0.5;
	audiodac.write(sample);
	if (++idx >= size) {
		if (looping) {
			idx = 0;
		} else {
			callback_timer.detach();
			audiodac.write(0.0f);
		}
	}
}

void WavPlayer::stop() {
	callback_timer.detach();
	audiodac.write(0.0f);
}

// BuzzerPlayer

void BuzzerPlayer::start(float frequency, float amplitude) {
	current_sample = 0.0f;
	amp = (amplitude > 1.0f) ? 1.0f : ((amplitude < 0.0f) ? 0.0f : amplitude);
	uint32_t period_us = static_cast<uint32_t>(1000000.0f / frequency);
	period_us = period_us / 2; //two flips per period
	auto cb = callback(this, &BuzzerPlayer::play_next_sample);
	callback_timer.attach_us(cb, period_us);
}

void BuzzerPlayer::play_next_sample() {
	current_sample = current_sample == amp ? 0 : amp;
	audiodac.write(current_sample);
}

void BuzzerPlayer::stop() {
	callback_timer.detach();
	audiodac.write(0.0f);
}

