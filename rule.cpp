#include "rule.hpp"

// Functor operators
void Functors::Base::operator()(Color* color, u16 pixel) {
    *color = BLACK;
}
void Functors::Fill::operator()(Color* color, u16 pixel) {
    if (pixel >= start && pixel < end) {
        *color = fillColor;
    } else {
        *color = BLACK;
    }
}
void Functors::Stripes::operator()(Color* color, u16 pixel) {
    *color = colors[(pixel / width) % color_count];
}

// Rule class methods

Rule::Rule() {
    
}
Rule::~Rule() {

}
// Evaluate 
Color* Rule::operator()(s16 pixel) {
    Color* color = (Color*) calloc(sizeof(Color), 1);
    // Apply each functor to modify the color
    for (std::vector<Functors::Base*>::iterator it = functors.begin(); it != functors.end(); ++it) {
        Functors::Base func = **it;
        // Modify the pixel color based on the rule
        func(color, pixel);
    }
    return color;
}

// Primary rules

Rule* Rule::fill(Color fillColor, s16 start, s16 end) {
    functors.clear();
    Functors::Fill* f = new Functors::Fill(fillColor, start, end);
    functors.push_back(f);
    return this;
}

Rule* Rule::stripes(Color* colors, u16 color_count, u16 width) {
    functors.clear();
    Functors::Stripes* f = new Functors::Stripes(colors, color_count, width);
    functors.push_back(f);
    return this;
}

// Secondary rules

Rule* Rule::animate(double speed) {
    return this;
}
