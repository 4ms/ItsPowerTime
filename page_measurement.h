#pragma once

#include <stdint.h>
#include "page.h"
#include "button.h"
#include "measurementTimer.h"
#include "ps_profiles.h"
#include "adc.h"

class MeasuringPage : public Page {
public:
	MeasuringPage(psProfile &psRef);
	void update();
	void display();
	void display_ps_profile();
	void display_measurements();

	void display_time(float tm);

	Button stop_but;
	MeasurementTimer timer;
	CurrentMeasurer measurer;
	psProfile &ps;
};

