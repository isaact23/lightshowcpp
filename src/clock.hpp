#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>

namespace Clock {
    clock_t now(); // Get a clock_t representing the time of the call
    float diff_secs(clock_t c2, clock_t c1); // Get seconds between two clocks
}

#endif
