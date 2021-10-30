#include "grid.hpp"

// Create a new Grid.
Grid::Grid() {
    segs = (Segment**) malloc(sizeof(Segment*) * SEG_CNT);
    neoPixel = new NeoPixel(LED_CNT);
    for (u16 i = 0; i < SEG_CNT; i++) {
        segs[i] = new Segment(neoPixel, i * 12, (i + 1) * 12);
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

// Send Segment LED data to WS2812 LED strip.
void Grid::useRule() {
    for (u16 i = 0; i < SEG_CNT; i++) {
        segs[i] -> useRule();
    }
    neoPixel -> show();
}
