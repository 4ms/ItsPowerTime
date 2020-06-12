#pragma once

struct psProfile {
	uint16_t mA_12V;
	uint16_t mA_5V;
	uint16_t mA_N12V;
};

struct psProfiles {
	static inline constexpr psProfile MiniPower = {
		100, 250, 400
	};
	static constexpr psProfile RowPower25 = {
		1000, 1250, 1000
	};
	static constexpr psProfile RowPower35 = {
		1500, 1500, 1250
	};
	static constexpr psProfile RowPower45 = {
		2000, 1500, 1250
	};
};

