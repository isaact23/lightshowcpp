#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "colors.hpp"
#include "datatypes.hpp"
#include "rule.hpp"

// #include "ws28128-rpi/ws2812-rpi.h"

/*
A range of pixels that has its own Rule.
*/
class Segment {

public:
    // Create a new segment between start (inclusive) and end (exclusive).
    Segment(u16 start, u16 end);
    ~Segment(); // Destroy a Segment.
    void setRule(Rule* newRule); // Assign a Rule for LED color generation to this Segment.
    void useRule(); // Use the Rule assigned by setRule() to generate LED colors.
    void write(); // Send Segment LED data to WS2812 LED strip.

private:
    u16 start;
    u16 end;
    Rule* rule;
    Color* pixelColors;
};

#endif
