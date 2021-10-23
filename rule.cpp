#include "rule.hpp"

// Functor operators
Color Functors::Base::operator()(u16 pixel) {
    return BLACK;
}
Color Functors::Fill::operator()(u16 pixel) {
    if (pixel >= start && pixel < end) {
        return color;
    } else {
        return BLACK;
    }
}
Color Functors::Stripes::operator()(u16 pixel) {
    return colors[(pixel / width) % color_count];
}

// Rule class methods

Rule::Rule() {
    
}
Rule::~Rule() {

}
Color* Rule::operator()(s16 pixel) {
    Color* col = (Color*) malloc(sizeof(Color));
    return col;
}

// Primary rules

Rule* Rule::fill(Color color, s16 start, s16 end) {
    Functors::Fill f = Functors::Fill(color, start, end);
    functors.push_back(f);
    return this;
}

Rule* Rule::stripes(Color* colors, u16 color_count, u16 width) {
    Functors::Stripes f = Functors::Stripes(colors, color_count, width);
    functors.push_back(f);
    return this;
}

// Secondary rules

Rule* Rule::animate(double speed) {
    return this;
}
