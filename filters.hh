#pragma once
#include <stdint.h>

class SimpleAverage {
using sumType = float;

public:
    SimpleAverage();
    SimpleAverage(sumType initialsum);
    sumType getAverage();
    void resetAveraging();
    uint32_t getNumSamplesSummed();
    void addSample(float sample);

private:
    sumType sum_;
    uint32_t num_samples_;
};
