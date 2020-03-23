#include <Timer.h>

class MeasurementTimer : public mbed::Timer {
public:
	MeasurementTimer();
	void reset();

	int last_time_read;
};

