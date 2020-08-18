#include "geometry.h"

#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

enum TouchShapeStates {
    NO_TOUCH,
    TOUCHED_INSIDE,
    TOUCHED_OUTSIDE    
};

bool ts_init(uint32_t x, uint32_t y);  
bool ts_is_touch_detected(uint16_t &x, uint16_t &y);
TouchShapeStates ts_touch_within_rect(RoundedRect &r);

#endif
