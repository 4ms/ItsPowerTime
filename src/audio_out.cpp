#include "audio_out.h"

AudioOutput::AudioOutput() {
}

void AudioOutput::play_buzzer(float frequency, float amplitude) {
	wav_player.stop();
	buzzer_player.sample = 0;
	buzzer_player.amplitude = amplitude > 1.0f ? 1.0f : amplitude < 0.0f ? 0.0f : amplitude;
	buzzer_player.period_us = static_cast<uint32_t>(1000000.0f / frequency);
	auto cb = callback(&buzzer_player, &BuzzerPlayer::play_next_sample);
	buzzer_player.callback_timer.attach_us(cb, buzzer_player.period_us);
}

void AudioOutput::stop() {
	wav_player.stop();
	buzzer_player.stop();
}

void AudioOutput::play_wav(const uint8_t * const wavdata, const uint32_t num_samples, const float sample_freq) {
	buzzer_player.stop();
	wav_player.idx = 0;
	wav_player.size = num_samples;
	wav_player.data = wavdata;
	wav_player.period_us = static_cast<uint32_t>(1000000.0f / sample_freq);
	auto cb = callback(&wav_player, &WavPlayer::play_next_sample);
	wav_player.callback_timer.attach_us(cb, wav_player.period_us);
}

void WavPlayer::play_next_sample() {
	float sample = (float)(data[idx]) / 255.0f;
	audiodac.write(sample);
	if (++idx >= size) {
		callback_timer.detach();
		audiodac.write(0.0f);
	}
}

void WavPlayer::stop() {
	callback_timer.detach();
}

void BuzzerPlayer::stop() {
	callback_timer.detach();
}

void BuzzerPlayer::play_next_sample() {
	sample = sample ? 0.0f : amplitude;
	audiodac.write(sample);
}

