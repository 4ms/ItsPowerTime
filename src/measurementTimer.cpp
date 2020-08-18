#include "measurementTimer.h"

MeasurementTimer::MeasurementTimer() {
	last_time_read = 0;
}

void MeasurementTimer::reset() {
	last_time_read = 0;
	Timer::reset();
}

