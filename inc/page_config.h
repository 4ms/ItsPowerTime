#pragma once
#include <stdint.h>
#include "page.h"
#include "button.h"
#include "ps_profiles.h"

using namespace PSProfiles;

class ConfigButton : public Button {
public:
	uint8_t ps_index;
};

class ConfigPage : public Page {
public:
	ConfigPage();
	void display();
	void update();

	SequentialMap<PSProfileID, Button, kNumPSProfiles> ps_buts;
	//ConfigButton ps_buts[kNumPSProfiles];
};

