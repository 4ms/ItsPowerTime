#include "mbed.h"

class ElapsedTimer {
public:
    ElapsedTimer();
    
    void start();
    void update();
    uint32_t get_value();

private:
    uint32_t val;
};
