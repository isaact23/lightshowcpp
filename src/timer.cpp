#include "timer.hpp"

namespace Timer {
    clock_t now() {
        return clock();
    }
    // Calculate seconds since time defined by clock_t.
    float secs_since(clock_t before) {
        return ((float)(clock() - before)) / CLOCKS_PER_SEC;
    }
}