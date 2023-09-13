#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "colors.hpp"
#include "datatypes.hpp"
#include "rule.hpp"

/*
A range of pixels that has its own Rule.
*/
class Segment {

public:
    // Create a new segment on a NeoPixel strip between start (inclusive) and end (exclusive).
    Segment(Strip* strip, u16 start, u16 end);

    // Destroy a Segment.
    ~Segment();

    // Assign a Rule for LED color generation to this Segment.
    void setRule(Rule* newRule);

    // Use the Rule assigned by setRule() to generate LED colors and update WS2812 LED strip.
    void useRule(float timeElapsed);

private:
    Strip* strip;
    u16 start;
    u16 end;
    bool flipped;
    Rule* rule;
};

#endif
