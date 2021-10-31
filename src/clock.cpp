#include "clock.hpp"

// Get a clock_t representing the time of the call
clock_t Clock::now() {
    return clock();
}

// Get seconds between two clocks
float Clock::diff_secs(clock_t c2, clock_t c1) {
    return ((float) (c2 - c1)) * 10 / CLOCKS_PER_SEC;
}