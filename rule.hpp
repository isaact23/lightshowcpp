#ifndef RULE_HPP
#define RULE_HPP

#include <string.h>
#include "colors.hpp"
#include "datatypes.hpp"

// Class passable to Segments and LightStrips that determines LED colors at runtime.
class Rule
{
public:
    Rule();
    ~Rule();
    Color eval();

    // Primary rules
    Rule fill(Color color, u16 start, u16 end);
    Rule stripes(Color colors[], u16 width);

    // Secondary rules
    Rule animate(double speed);
private:
};

#endif
