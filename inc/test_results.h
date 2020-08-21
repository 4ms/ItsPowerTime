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
	float failed_value;
	FailCode fail_code;
	char fail_type_string[20];

	void set_fail_code(const FailCode code) {
		fail_code = code;
		set_result_string();
	}

private:
	void set_result_string() {
		switch (fail_code) {
			case (SPIKE):
				strcpy(fail_type_string, "Spike");
				break;
			case (DIP):
				strcpy(fail_type_string, "Dip");
				break;
			case (AVERAGE_TOO_LOW):
				strcpy(fail_type_string, "Low Average");
				break;
			case (AVERAGE_TOO_HIGH):
				strcpy(fail_type_string, "High Average");
				break;
			default:
				strcpy(fail_type_string, "?");
				break;
		}
	}
};

