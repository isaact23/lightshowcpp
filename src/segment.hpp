#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "datatypes.hpp"
#include "rule.hpp"

// #include "ws28128-rpi/ws2812-rpi.h"

/*
A range of pixels that has its own Rule.
*/
class Segment {

public:
    Segment(u16 start, u16 end);
    ~Segment();
    void setRule(Rule* rule);
    void useRule();

private:
    Rule* rule;
};

#endif
