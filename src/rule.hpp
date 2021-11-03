#ifndef RULE_HPP
#define RULE_HPP

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include "clock.hpp"
#include "colors.hpp"
#include "datatypes.hpp"

// Function objects that modify the light strip's color output.
namespace Functors {
    // Params passable to functors, and oft modifiable by functors.
    struct Params {
        Color* color;
        s16* pixel;
    };

    class Base {
    public:
        virtual void operator()(Params params);
    };

    class Fill : public Base {
    public:
        // Constructor
        Fill(Color fillColor, s16 start, s16 end);
        // Color generator
        void operator()(Params params) override;
    private:
        Color fillColor;
        u16 start;
        u16 end;
    };

    class Stripes : public Base {
    public:
        Stripes(Color* colors, u16 colorCount, u16 width);
        void operator()(Params params) override;
    private:
        Color* colors;
        u16 colorCount;
        u16 width;
    };

    class Animate : public Base {
    public:
        Animate(double speed);
        void operator()(Params params) override;
    private:
        double speed;
        std::chrono::time_point<std::chrono::steady_clock> startTime;
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
    Rule* stripes(Color* colors, u16 colorCount, u16 width);

    // Secondary rules
    Rule* animate(double speed);
private:
    std::vector<Functors::Base*> functors;
};

#endif
