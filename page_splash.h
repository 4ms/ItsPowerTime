#pragma once

#include <stdint.h>
#include "page.h"

class SplashPage : public Page {
public:
	SplashPage();
	void display();
	void update();
};

class TSErrorPage : public Page {
public:
	TSErrorPage();
	void display();
	void update();
};

