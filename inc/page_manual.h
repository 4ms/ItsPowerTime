#pragma once

#include <stdint.h>
#include "page.h"
#include "button.h"
#include "ps_profiles.h"
#include "page_measurement.h"

class ManualMeasuringPage : public MeasuringPage {
public:
	ManualMeasuringPage(PSProfile &psRef);
	void display();
	void update();

	Button p12_up, p12_down;
	Button n12_up, n12_down;
	Button p5_up, p5_down;
	uint16_t inc_mA(uint16_t mA);
	uint16_t dec_mA(uint16_t mA);
};

