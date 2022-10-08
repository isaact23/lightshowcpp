#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

namespace Clock {
    std::chrono::time_point<std::chrono::steady_clock> now(); // Get time representing the time of the call
    double diff_secs(std::chrono::time_point<std::chrono::steady_clock> c2,
                     std::chrono::time_point<std::chrono::steady_clock> c1); // Get seconds between two clocks
    double secs_since(std::chrono::time_point<std::chrono::steady_clock> c1); // Get seconds since a clock time
}

#endif
