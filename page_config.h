#pragma once
#include <stdint.h>
#include "page.h"
#include "button.h"

class ConfigPage : public Page {
public:
	ConfigPage();
	void display();
	void update();

	Button TestPS_but;
	Button RP25_but;
	Button RP35_but;
	Button RP45_but;
};

