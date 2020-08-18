#pragma once

#include <stdint.h>
#include "page.h"
#include "button.h"
#include "measurementTimer.h"
#include "ps_profiles.h"
#include "measurer.h"
#include "audio_out.h"

class MeasuringPage : public Page {
public:
	MeasuringPage(PSProfile &psRef);
	void update();
	void display();
	void cleanup();

protected:
	void display_ps_profile();

private:
	void handle_startup_sound();
	void display_measurements();
	void display_time(float tm);

public:
	Button stop_but;
	MeasurementTimer timer;
	MeasurementReader measurer;

protected:
	PSProfile &ps;
	PWMAudioOutput audioout;
};

