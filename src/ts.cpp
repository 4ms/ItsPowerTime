#include "TS_DISCO_F429ZI.h"
#include "button.h"

//TS returns flipped Y coordinates in rev E (not in rev B)
//MV1075E appear to all be blue PCBs, vs older rev B are green
#define PCB_IS_MB1075E

static TS_DISCO_F429ZI ts;
static uint32_t notouch_ctr = 0;
static uint16_t last_x = 0, last_y = 0;

bool ts_init(uint32_t x, uint32_t y) {
    uint8_t status = ts.Init(x, y);
    bool did_ts_init_ok = (status == TS_OK);
    return did_ts_init_ok;
}

bool ts_is_touch_detected(uint16_t &x, uint16_t &y) {
    TS_StateTypeDef TS_State;
    
    ts.GetState(&TS_State);      
    if (TS_State.TouchDetected) {
        notouch_ctr = 0;
        x = TS_State.X;
#ifdef PCB_IS_MB1075E
        y = 320 - TS_State.Y;
#else
        y = TS_State.Y;
#endif
        last_x = x;
        last_y = y;
        return true;
    }
    else {
        notouch_ctr++;
        if (notouch_ctr > 100) {
            return false;
        }
        else {
            x = last_x;
            y = last_y;
            return true;   
        }
    }
}

TouchShapeStates ts_touch_within_rect(RoundedRect &r) {
    uint16_t x, y;
    
    if (ts_is_touch_detected(x, y)) {
        if (x >= r.x && x <= (r.x+r.width) && y >= r.y && y <= (r.y+r.height))
            return TOUCHED_INSIDE;
        else
            return TOUCHED_OUTSIDE;
    }
    return NO_TOUCH;
}
