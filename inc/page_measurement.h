#pragma once

#include <stdint.h>
#include "page.h"
#include "button.h"
#include "measurementTimer.h"
#include "ps_profiles.h"
#include "measurer.h"
#include "audio_out.h"
#include "test_results.h"

using namespace PSProfiles;

class MeasuringPage : public Page {
public:
	MeasuringPage(PSProfile &psRef);
	void update();
	void display();
	void start();
	void cleanup();
	bool passed() { return did_pass; }
	bool failed() { return did_fail; }

protected:
	void display_ps_profile();

private:
	void handle_startup_sound();
	void display_measurements();
	void display_time(float tm);
	void check_for_failure(AdcChannels chan, float expected_val, float tolerance);
	void check_for_failures();
	void register_fail(AdcChannels chan, float bad_value, ResultType::FailCode code);

public:
	Button stop_but;
	MeasurementTimer timer;
	MeasurementReader measurer;
	ResultType results[AdcChannels::numChannels];

protected:
	PSProfile &ps;
	PWMAudioOutput audioout;

private:
	bool did_fail;
	bool did_pass;
};

