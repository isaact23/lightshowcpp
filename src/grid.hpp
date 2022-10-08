#ifndef GRID_HPP
#define GRID_HPP

#include <stdlib.h>

#include "datatypes.hpp"
#include "segment.hpp"
#include "ws2812-rpi/ws2812-rpi.h"

#define SEG_CNT 3
//#define SEG_CNT 44
#define SEG_SIZE 12
#define LED_CNT 150

/*
* Container class for all Segments in the game.
*/
class Grid {

public:
    Grid(NeoPixel* neoPixel); // Create a new Grid.
    ~Grid(); // Destroy a Grid.
    Segment* getSeg(u16 segId); // Get a segment by ID.
    void setRule(Rule* rule); // Set all segment rules to one rule.
    void useRule(float timeElapsed); // Send all Segment LED data to WS2812 LED strip.

private:
    Segment** segs;
    NeoPixel* neoPixel; // LED strip controller
};

#endif
