// Functions for keeping track of time elapsed.

#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

namespace Timer {
    clock_t now();
    // Calculate seconds since time defined by clock_t.
    float secs_since(clock_t before);
}

#endif
