#pragma once

#include "mbed.h"
#include "ps_profiles.h"

//Todo: ctor of CurrentSetter constructs PwmOut members and pin numbers are passed as args (so pin numbers can be stored in a central place)
class CurrentSetter {
public:
	CurrentSetter(psProfile &psRef);

	void start();
	void update_outputs();
	void stop();

	void set_max_N12V_mA(uint16_t mA);
	void set_max_12V_mA(uint16_t mA);
	void set_max_5V_mA(uint16_t mA);

private:
	PwmOut setN12A {PB_4}; //is PB_5 on p2 board: won't run (hardfault on init?)
	PwmOut set5A {PB_7};
	PwmOut set12A {PC_8}; //is PB_6 on p2 board: interferes with screen
	psProfile &ps;
	psProfile maxPs;
};

