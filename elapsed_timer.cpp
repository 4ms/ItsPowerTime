#include "elapsed_timer.h"

ElapsedTimer::ElapsedTimer() {
    val = 0;   
//    SysTick_Config(SystemCoreClock / 100); //10ms
}

void ElapsedTimer::start() {
    //Stop:
//    SysTick->CTRL = (1 << SYSTICK_CLKSOURCE) | (0<<SYSTICK_ENABLE) | (0<<SYSTICK_TICKINT);
    val = 0;
    //Start:    
//    SysTick->CTRL = (1 << SYSTICK_CLKSOURCE) | (1<<SYSTICK_ENABLE) | (1<<SYSTICK_TICKINT);
}

void ElapsedTimer::update() {
    val++;
}

uint32_t ElapsedTimer::get_value() {
    return val;
}
