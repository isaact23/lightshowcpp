#ifndef SEGMENT_HPP
#define SEGMENT_HPP

// Comment out below line to disable NeoPixel
#define USE_NEOPIXEL

#include "colors.hpp"
#include "datatypes.hpp"
#include "rule.hpp"

#ifdef USE_NEOPIXEL
#include "ws2812-rpi/ws2812-rpi.h"
#endif

/*
A range of pixels that has its own Rule.
*/
class Segment {

public:
    // Create a new segment on a NeoPixel strip between start (inclusive) and end (exclusive) with rules starting at initPixel.
    #ifdef USE_NEOPIXEL
    Segment(NeoPixel* neoPixel, u16 start, u16 end, u16 initPixel);
    #else
    Segment(u16 start, u16 end);
    #endif
    ~Segment(); // Destroy a Segment.
    void setRule(Rule* newRule); // Assign a Rule for LED color generation to this Segment.
    void useRule(float timeElapsed); // Use the Rule assigned by setRule() to generate LED colors and update WS2812 LED strip.

private:
    #ifdef USE_NEOPIXEL
    NeoPixel* neoPixel;
    #endif
    u16 start;
    u16 end;
    bool flipped;
    Rule* rule;
};

#endif
