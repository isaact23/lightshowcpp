#include "segment.hpp"

// Create a new segment between start (inclusive) and end (exclusive).
Segment::Segment(NeoPixel* n, u16 start, u16 end) : start(start), end(end) {
    neoPixel = n;
    rule = NULL;
}

// Destroy a Segment.
Segment::~Segment() {
    if (rule != NULL) {
        delete rule;
    }
}

void Segment::setRule(Rule* newRule) {
    if (rule != NULL) {
        delete rule;
    }
    rule = newRule;
}

// Use the Rule assigned by setRule() to generate LED colors and update LED strip.
void Segment::useRule(float timeElapsed) {
    if (rule != NULL) {
        for (u16 i = start; i < end; i++) {
            Color color = (*rule)(i - start, timeElapsed);
            neoPixel -> setPixelColor(i, color.red, color.green, color.blue);
        }
    }
}

