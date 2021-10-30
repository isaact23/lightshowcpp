#include "segment.hpp"

// Create a new segment between start (inclusive) and end (exclusive).
Segment::Segment(NeoPixel* neoPixel, u16 start, u16 end) : neoPixel(neoPixel), start(start), end(end) {}

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
void Segment::useRule() {
    if (rule != NULL) {
        for (u16 i = start; i < end; i++) {
            Color color = (*rule)(i - start);
            neoPixel -> setPixelColor(i, color.red, color.green, color.blue);
        }
    }
}
