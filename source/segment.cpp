#include "segment.hpp"

// Create a new segment between start (inclusive) and end (exclusive).
Segment::Segment(u16 start, u16 end) : start(start), end(end) {
    rule = NULL;
    colors = (Color*) calloc(end - start, sizeof(Color));
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
            colors[i] = color;
        }
    }
}

// Get the color of pixel p
Color Segment::getColor(int p) {
    return colors[p];
}
