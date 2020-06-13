#include "mbed.h"
#include "current_setter.h"

CurrentSetter::CurrentSetter(){
	set12A.period_ms(1);
	set5A.period_ms(1);
	setN12A.period_ms(1);
	stop();

	set_max_12V_mA(3300);
	set_max_5V_mA(3300);
	set_max_N12V_mA(3300);
}

void CurrentSetter::start() {
	set12A.write((float)mA12/(float)max12);
	set5A.write((float)mA5/(float)max5);
	setN12A.write((float)mAN12/(float)maxN12);
}

void CurrentSetter::stop() {
	set12A.write(0.0f);
	set5A.write(0.0f);
	setN12A.write(0.0f);
}

void CurrentSetter::set_profile(const psProfile &ps) {
	set_12V_mA(ps.mA_12V);
	set_5V_mA(ps.mA_5V);
	set_N12V_mA(ps.mA_N12V);
}

psProfile CurrentSetter::get_profile() {
	psProfile ps {mA12, mA5, mAN12};
	return ps;
}

void CurrentSetter::set_12V_mA(uint16_t mA) {
	mA12 = mA;
}

void CurrentSetter::set_5V_mA(uint16_t mA) {
	mA5 = mA;
}

void CurrentSetter::set_N12V_mA(uint16_t mA) {
	mAN12 = mA;
}

void CurrentSetter::set_max_12V_mA(uint16_t mA) {
	max12 = mA;
}

void CurrentSetter::set_max_5V_mA(uint16_t mA) {
	max5 = mA;
}

void CurrentSetter::set_max_N12V_mA(uint16_t mA) {
	maxN12 = mA;
}


