#include "grid.hpp"

// Create a new Grid.
Grid::Grid(NeoPixel* neoPixel) : neoPixel(neoPixel) {

    segs = (Segment**) malloc(sizeof(Segment*) * SEG_CNT);

    // Sides
    segs[0] = new Segment(neoPixel, 0, 49);
    segs[1] = new Segment(neoPixel, 99, 50);

    for (u16 i = 0; i < SEG_CNT - 2; i++) {
        segs[i] = new Segment(neoPixel, 100 + i * SEG_SIZE, 99 + ((i + 1) * SEG_SIZE));
    }
}

// Destroy a Grid.
Grid::~Grid() {
    for (u16 i = 0; i < SEG_CNT; i++) {
        delete segs[i];
    }
    free(segs);
    delete neoPixel;
}

// Get a segment by ID.
Segment* Grid::getSeg(u16 segId) {
    if (segId < 0 || segId >= SEG_CNT) {
        return NULL;
    }
    return segs[segId];
}

void Grid::setRule(Rule* rule) { // Set all segment rules to one rule.
    for (u16 i = 0; i < SEG_CNT; i++) {
        segs[i] -> setRule(rule);
    }
}

// Send Segment LED data to WS2812 LED strip.
void Grid::useRule(float timeElapsed) {
    for (u16 i = 0; i < SEG_CNT; i++) {
        segs[i] -> useRule(timeElapsed);
    }
}
