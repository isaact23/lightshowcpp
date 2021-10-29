#include "segment.hpp"

// Create a new segment between start (inclusive) and end (exclusive).
Segment::Segment(u16 start, u16 end) : start(start), end(end) {
    pixelColors = (Color*) calloc(end - start, sizeof(Color));
}

// Destroy a Segment.
Segment::~Segment() {
    delete rule;
}

void Segment::setRule(Rule* newRule) {
    rule = newRule;
}

// Use the Rule assigned by setRule() to generate LED colors.
void Segment::useRule() {
    for (u16 i = 0; i < end - start; i++) {
        pixelColors[i] = (*rule)(i);
    }
}

// Send Segment LED data to WS2812 LED strip.
void Segment::write() {

}