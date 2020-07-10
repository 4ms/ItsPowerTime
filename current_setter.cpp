#include "mbed.h"
#include "current_setter.h"

CurrentSetter::CurrentSetter(psProfile &psRef)
: ps{psRef}
{
	set12A.period_ms(1);
	set5A.period_ms(1);
	setN12A.period_ms(1);
	stop();

	set_max_12V_mA(2752);
	set_max_5V_mA(2838);
	set_max_N12V_mA(2838);
}

void CurrentSetter::update_outputs() {
	set12A.write((float)ps.mA_12V/(float)maxPs.mA_12V);
	set5A.write((float)ps.mA_5V/(float)maxPs.mA_5V);
	setN12A.write((float)ps.mA_N12V/(float)maxPs.mA_N12V);
}

void CurrentSetter::start() {
	update_outputs();
}

void CurrentSetter::stop() {
	set12A.write(0.0f);
	set5A.write(0.0f);
	setN12A.write(0.0f);
}

void CurrentSetter::set_max_12V_mA(uint16_t mA) {
	maxPs.mA_12V = mA;
}

void CurrentSetter::set_max_5V_mA(uint16_t mA) {
	maxPs.mA_5V = mA;
}

void CurrentSetter::set_max_N12V_mA(uint16_t mA) {
	maxPs.mA_N12V = mA;
}


