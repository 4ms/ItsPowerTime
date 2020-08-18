#include "mbed.h"
#include "current_setter.h"
#include "calibration_defs.h"

CurrentSetter::CurrentSetter(PSProfile &psRef)
: ps{psRef}
{
	stop();
	set12A.period_ms(1);
	set5A.period_ms(1);
	setN12A.period_ms(1);

	set_max_12V_mA(CalibrationDefs::current_set_max[Set12V]);
	set_max_5V_mA(CalibrationDefs::current_set_max[Set5V]);
	set_max_N12V_mA(CalibrationDefs::current_set_max[SetN12V]);
}

float CurrentSetter::adjust_output(uint16_t unadjusted, int16_t offset, uint16_t max) {
	if (unadjusted < offset)
		return 0.0f;
	else
		return ((float)unadjusted - (float)offset) / (float)max;
}

void CurrentSetter::update_outputs() {
	set12A.write(adjust_output(ps.mA_12V, CalibrationDefs::current_set_offset[Set12V], max_.mA_12V));
	set5A.write(adjust_output(ps.mA_5V, CalibrationDefs::current_set_offset[Set5V], max_.mA_5V));
	setN12A.write(adjust_output(ps.mA_N12V, CalibrationDefs::current_set_offset[SetN12V], max_.mA_N12V));
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


