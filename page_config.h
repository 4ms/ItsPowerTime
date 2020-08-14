#pragma once
#include <stdint.h>
#include "page.h"
#include "button.h"
#include "ps_profiles.h"

class ConfigButton : public Button {
public:
	uint8_t ps_index;

};

class ConfigPage : public Page {
public:
	ConfigPage();
	void display();
	void update();

	ConfigButton ps_buts[kNumProfiles];
	// Button TestPS_but;
	// Button RP25_but;
	// Button RP35_but;
	// Button RP45_but;
};

