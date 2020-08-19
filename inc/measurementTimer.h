#pragma once
#include <Timer.h>

class MeasurementTimer : public mbed::Timer {
public:
	MeasurementTimer();
	void reset();

	int last_time_read;

	static int get_minutes(float seconds) {
		return static_cast<int>(seconds / 60);
	}	
	static float get_seconds(float seconds) {
		return seconds - (get_minutes(seconds) * 60);
	}	
};

