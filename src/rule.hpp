#ifndef RULE_HPP
#define RULE_HPP

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include "colors.hpp"
#include "datatypes.hpp"

namespace Functors {
    class Base {
    public:
        virtual void operator()(Color* color, s16* pixel);
    };

    class Fill : public Base {
    public:
        // Constructor
        Fill(Color fillColor, s16 start, s16 end) : fillColor(fillColor), start(start), end(end) {}
        // Color generator
        void operator()(Color* color, s16* pixel) override;
    private:
        Color fillColor;
        u16 start;
        u16 end;
    };

    class Stripes : public Base {
    public:
        Stripes(Color* colors, u16 color_count, u16 width) : colors(colors), color_count(color_count), width(width) {}
        void operator()(Color* color, s16* pixel) override;
    private:
        Color* colors;
        u16 color_count;
        u16 width;
    };

    class Animate : public Base {
    public:
        Animate(double speed) : speed(speed) {
            startTime = clock();
        }
        void operator()(Color* color, s16* pixel) override;
    private:
        double speed;
        clock_t startTime;
    };
}

// Class passable to Segments and LightStrips that determines LED colors at runtime.
class Rule
{
public:
    Rule();
    ~Rule();
    Color operator()(s16 pixel);

    // Primary rules
    Rule* fill(Color color, s16 start, s16 end);
    Rule* stripes(Color* colors, u16 color_count, u16 width);

    // Secondary rules
    Rule* animate(double speed);
private:
    std::vector<Functors::Base*> functors;
};

#endif
