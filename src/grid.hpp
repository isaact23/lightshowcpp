#ifndef GRID_HPP
#define GRID_HPP

#include <stdlib.h>

#include "datatypes.hpp"
#include "segment.hpp"

#define SEG_CNT 44

/*
* Container class for all Segments in the game.
*/
class Grid {

public:
    Grid(); // Create a new Grid.
    ~Grid(); // Destroy a Grid.
    Segment* getSeg(u16 segId); // Get a segment by ID.
    void write(); // Send all Segment LED data to WS2812 LED strip.

private:
    Segment** segs;
};

#endif
