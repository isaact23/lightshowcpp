#ifndef RULE_HPP
#define RULE_HPP

#include <stdlib.h>
#include <string>
#include <vector>
#include "colors.hpp"
#include "datatypes.hpp"

namespace Functors {
    class Base {
    public:
        virtual Color operator()(u16 pixel);
    };

    class Fill : public Base {
    public:
        // Constructor
        Fill(Color color, u16 start, u16 end) : color(color), start(start), end(end) {}
        // Color generator
        Color operator()(u16 pixel);
    private:
        Color color;
        u16 start;
        u16 end;
    };

    class Stripes : public Base {
    public:
        Stripes(Color* colors, u16 color_count, u16 width) : colors(colors), color_count(color_count), width(width) {}
        Color operator()(u16 pixel);
    private:
        Color* colors;
        u16 color_count;
        u16 width;
    };
}

// Class passable to Segments and LightStrips that determines LED colors at runtime.
class Rule
{
public:
    Rule();
    ~Rule();
    Color* operator()(s16 pixel);

    // Primary rules
    Rule* fill(Color color, s16 start, s16 end);
    Rule* stripes(Color* colors, u16 color_count, u16 width);

    // Secondary rules
    Rule* animate(double speed);
private:
    std::vector<Functors::Base> functors;
};

#endif
