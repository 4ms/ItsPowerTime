#pragma once
#include <stdint.h>

struct ResultType {
	enum FailCode {
		SPIKE,
		DIP,
		AVERAGE_TOO_HIGH,
		AVERAGE_TOO_LOW,
	};
	bool passed;
	uint32_t fail_time;
	FailCode failure_type;

	void set_result_string(char *str) const {
		switch (failure_type) {
			case (SPIKE):
				strcpy(str, "Spike");
				break;
			case (DIP):
				strcpy(str, "Dip");
				break;
			case (AVERAGE_TOO_LOW):
				strcpy(str, "Low Average");
				break;
			case (AVERAGE_TOO_HIGH):
				strcpy(str, "High Average");
				break;
			default:
				strcpy(str, "?");
				break;
		}
	}
};

