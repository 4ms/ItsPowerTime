#pragma once

#include <stdint.h>

class Page {
public:
	virtual void display() = 0;
	virtual void update() = 0;
};

