#pragma once

#include "mbed.h"
#include "ps_profiles.h"
#include "calibration_defs.h"

using namespace PSProfiles;
//Todo: pass a calibration def object to CurrentSetCtl ctor
//Todo: how can we construct a struct {PwmOut setter; uint16_t val;} from PinName... pinList ?
//...then we could do for (auto & chan : channels) chan.val = 0.0f; chan.setter.write(chan.val)
template <unsigned int N>
class CurrentSetCtl {
public:
	template <typename... T>
	CurrentSetCtl(T... ts)
		: setter{ts...}
	{
		for (auto & chan : setter) {
			chan.write(0.0f);
			chan.period_ms(1);
		}
	}
	void set_val(CurrentSetChannel chan, uint16_t value) {
		auto adjusted_val = adjust_output(value, CalibrationDefs::current_set_offset[chan], CalibrationDefs::current_set_max[chan]);
		setter[chan].write(adjusted_val);
	}

	void stop() {
		for (auto & chan : setter)
			chan.write(0.0f);
	}

private:
	std::array<PwmOut, N> setter;

	float adjust_output(uint16_t unadjusted, int16_t offset, uint16_t max) {
		if (unadjusted < offset)
			return 0.0f;
		else
			return ((float)unadjusted - (float)offset) / (float)max;
	}
};


