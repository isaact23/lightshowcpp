#ifndef GRID_HPP
#define GRID_HPP

#include "segment.hpp"

#define SEG_CNT 44

/*
* Container class for all Segments in the game.
*/
class Grid {

public:
    Grid();
    ~Grid();
    Segment* getSeg(u16 segId);

private:
    Segment** segs;
};

#endif
