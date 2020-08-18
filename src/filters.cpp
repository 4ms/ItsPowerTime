#include "filters.hh"

SimpleAverage::SimpleAverage() {
    resetAveraging();
}

SimpleAverage::SimpleAverage(sumType initialsum) {
    resetAveraging();
    sum_ = initialsum;
}

void SimpleAverage::resetAveraging()
{
    sum_ = 0;
    num_samples_ = 0;
}

SimpleAverage::sumType SimpleAverage::getAverage()
{
    if (num_samples_ > 0)
        return (sumType)sum_ / (sumType)num_samples_;
    else
        return 0.0f;
}

uint32_t SimpleAverage::getNumSamplesSummed()
{
    return num_samples_;
}

void SimpleAverage::addSample(float sample)
{
    sumType overflowCheck = sum_ + (sumType)sample;
    if (overflowCheck >= sum_) {
        num_samples_++;
        sum_ += sample;
    }
}

