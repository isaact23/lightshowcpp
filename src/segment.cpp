#include "segment.hpp"

// Create a new segment between start (inclusive) and end (inclusive).
Segment::Segment(NeoPixel* n, u16 startInput, u16 endInput) {
    if (endInput >= startInput) {
        start = startInput;
        end = endInput;
        flipped = false;
    } else {
        start = endInput;
        end = startInput;
        flipped = true;
    }

    neoPixel = n;
    initPixel = 0; // Starting pixel for color calculation (changes for MultiSegments)
    rule = NULL;
}

// Destroy a Segment.
Segment::~Segment() {
    if (rule != NULL) {
        delete rule;
    }
}

// Update initPixel.
void Segment::setInitPixel(u16 initPixel) {
    initPixel = initPixel;
}

// Assign a Rule for LED color generation to this Segment.
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

