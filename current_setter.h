#pragma once

#include "mbed.h"
#include "ps_profiles.h"

//Todo: ctor of CurrentSetter constructs PwmOut members and pin numbers are passed as args (so pin numbers can be stored in a central place)
class CurrentSetter {
public:
	CurrentSetter();

	void start();
	void stop();
	void set_profile(const psProfile &ps);
	void set_N12V_mA(uint16_t mA);
	void set_12V_mA(uint16_t mA);
	void set_5V_mA(uint16_t mA);

	void set_max_N12V_mA(uint16_t mA);
	void set_max_12V_mA(uint16_t mA);
	void set_max_5V_mA(uint16_t mA);

private:	
	PwmOut set12A {PB_4}; //is PB_5 on p2 board: won't run (hardfault on init?)
	PwmOut set5A {PB_7};
	PwmOut setN12A {PC_8}; //is PB_6 on p2 board: interferes with screen; PA_0 works PC+8
	uint16_t mA5, mA12, mAN12;
	uint16_t max5, max12, maxN12;
};

