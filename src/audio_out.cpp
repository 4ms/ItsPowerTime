#include "audio_out.h"

PWMAudioOutput::PWMAudioOutput() {
	audioout.period_us(1); //1MHz
	audioout.write(0.0);
	is_playing = false;
}


void PWMAudioOutput::start_buzzer(uint16_t frequency) {
	float period_us = 1000000.0f / (float)frequency;
	audioout.period_us(period_us);
	audioout.write(0.5);
	is_playing = true;
}

void PWMAudioOutput::stop() {
	audioout.period_us(1);
	audioout.write(0.0);
	is_playing = false;
}

void PWMAudioOutput::play_wav(uint8_t *wavdata, uint32_t num_samples, uint16_t sample_freq) {
	float period_us = 1000000.0f / (float)sample_freq;
	audioout.period_us(10);

	//Todo: start a timer with an interrupt, and do the playback inside the ISR
	for (uint32_t i=0; i<num_samples; i++) {
		float sample = (float)wavdata[i] / 255.0f;
		audioout.write(sample);
		wait_us(period_us);
	}
	stop();
}


	// uint8_t t[] = {
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// };
	// audioout.play_wav(t, 100, 10000);
