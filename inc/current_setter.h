#pragma once

#include "mbed.h"
#include "ps_profiles.h"

using namespace PSProfiles;
//Todo: ctor of CurrentSetter constructs PwmOut members and pin numbers are passed as args (so pin numbers can be stored in a central place)
class CurrentSetter {
public:
	CurrentSetter(PSProfile &psRef);

	void start();
	void update_outputs();
	void stop();

	void set_max_N12V_mA(uint16_t mA);
	void set_max_12V_mA(uint16_t mA);
	void set_max_5V_mA(uint16_t mA);

private:
	PwmOut setN12A {PB_4}; //use PB_13 on p4
	PwmOut set5A {PB_7};
	PwmOut set12A {PC_8};
	PSProfile &ps;
	PSProfile max_;

	float adjust_output(uint16_t unadjusted, int16_t offset, uint16_t max);
};

