#pragma once

#include <stdint.h>
#include "page.h"
#include "button.h"
#include "measurementTimer.h"
#include "measurer.h"

class MainPage : public Page {
public:
	MainPage();
	void display();
	void update();
	void start();

	Button start_but;
	Button config_but;
	Button manual_but;
	std::string_view psname="";

private:
	void display_measurements();
	void display_one_rail(float val, float expected_val, int pos_x, int pos_y);
	MeasurementTimer timer;
	MeasurementReader measurer;
};

