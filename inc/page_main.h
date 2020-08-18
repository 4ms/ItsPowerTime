#pragma once

#include <stdint.h>
#include "page.h"
#include "button.h"

class MainPage : public Page {
public:
	MainPage();
	void display();
	void update();

	Button start_but;
	Button config_but;
	Button manual_but;
};

