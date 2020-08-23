#pragma once

#include <stdint.h>
#include "page.h"
#include "measurementTimer.h"
#include "button.h"
#include "audio_out.h"
#include "test_results.h"
#include "channel_defs.h"

class ResultsPage : public Page {
public:
	ResultsPage();
	virtual void display();
	virtual void start();
	virtual void update();
	void cleanup();

	void set_results(ResultType *results);

	Button continue_but;

protected:
	void display_flashing();
	MeasurementTimer timer;
	AudioOutput audio;
	uint32_t flash_bg_color;
	uint32_t flash_fg_color;
	uint32_t bg_col;
	char result_string[5];

	ResultType *test_results;
};

class FailResultsPage : public ResultsPage {
public:
	FailResultsPage();
	virtual void display();
	virtual void start();
	virtual void update();
private:
	void display_result(AdcChannels chan);
};

class PassResultsPage : public ResultsPage {
public:
	PassResultsPage();
	virtual void display();
	virtual void start();
	virtual void update();
};
