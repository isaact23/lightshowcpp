#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

// Handle time measurement.
namespace Clock {

    // Get time representing the time of the call
    std::chrono::time_point<std::chrono::steady_clock> now(); 

    // Get seconds between two clocks
    double diff_secs(std::chrono::time_point<std::chrono::steady_clock> c2,
                     std::chrono::time_point<std::chrono::steady_clock> c1); 

    // Get seconds since a clock time
    double secs_since(std::chrono::time_point<std::chrono::steady_clock> c1); 
}

#endif
