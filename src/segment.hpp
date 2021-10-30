#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "colors.hpp"
#include "datatypes.hpp"
#include "rule.hpp"
#include "ws2812-rpi/ws2812-rpi.h"

/*
A range of pixels that has its own Rule.
*/
class Segment {

public:
    // Create a new segment on a NeoPixel strip between start (inclusive) and end (exclusive).
    Segment(NeoPixel* neoPixel, u16 start, u16 end);
    ~Segment(); // Destroy a Segment.
    void setRule(Rule* newRule); // Assign a Rule for LED color generation to this Segment.
    void useRule(); // Use the Rule assigned by setRule() to generate LED colors and update WS2812 LED strip.
private:
    NeoPixel* neoPixel;
    u16 start;
    u16 end;
    Rule* rule;
};

#endif
