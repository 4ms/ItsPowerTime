#include "mbed.h"
#include "current_setter.h"

CurrentSetter::CurrentSetter(psProfile &psRef)
: ps{psRef}
{
	set12A.period_ms(1);
	set5A.period_ms(1);
	setN12A.period_ms(1);
	stop();

	set_max_12V_mA(2776);
	set_max_5V_mA(2811);
	set_max_N12V_mA(2809);

	offset_.mA_12V = 27;
	offset_.mA_N12V = 15;
	offset_.mA_5V = 23;

}

float CurrentSetter::adjust_output(uint16_t unadjusted, uint16_t offset, uint16_t max) {
	if (unadjusted < offset)
		return 0.0f;
	else
		return ((float)unadjusted - (float)offset) / (float)max;
}

void CurrentSetter::update_outputs() {
	set12A.write(adjust_output(ps.mA_12V, offset_.mA_12V, max_.mA_12V));
	set5A.write(adjust_output(ps.mA_5V, offset_.mA_5V, max_.mA_5V));
	setN12A.write(adjust_output(ps.mA_N12V, offset_.mA_N12V, max_.mA_N12V));
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
	max_.mA_12V = mA;
}

void CurrentSetter::set_max_5V_mA(uint16_t mA) {
	max_.mA_5V = mA;
}

void CurrentSetter::set_max_N12V_mA(uint16_t mA) {
	max_.mA_N12V = mA;
}


