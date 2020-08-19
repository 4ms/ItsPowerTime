#pragma once

#include <stdint.h>
#include "page.h"
#include "measurementTimer.h"
#include "button.h"
#include "audio_out.h"
#include "test_results.h"

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
	MeasurementTimer timer;
	PWMAudioOutput audio;
	uint32_t bg_color;
	uint32_t fg_color;
	uint32_t flash_color_1;
	uint32_t flash_color_2;
	char result_string[5];

	ResultType *test_results;
};

class FailResultsPage : public ResultsPage {
public:
	FailResultsPage();
	virtual void display();
	virtual void start();
	virtual void update();
};

class PassResultsPage : public ResultsPage {
public:
	PassResultsPage();
	virtual void display();
	virtual void start();
	virtual void update();
};
