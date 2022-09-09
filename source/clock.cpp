#include "clock.hpp"

// Get time representing the time of the call
std::chrono::time_point<std::chrono::steady_clock> Clock::now() {
    return std::chrono::steady_clock::now();
}

// Get seconds between two clocks
double Clock::diff_secs(std::chrono::time_point<std::chrono::steady_clock> c2,
                        std::chrono::time_point<std::chrono::steady_clock> c1) {
    std::chrono::duration<double> diff = c2 - c1;
    return diff.count();
}

// Get seconds since a clock time
double Clock::secs_since(std::chrono::time_point<std::chrono::steady_clock> c1) {
    return Clock::diff_secs(Clock::now(), c1);
}
