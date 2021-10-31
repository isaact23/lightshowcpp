#include "rule.hpp"

// Functor operators
void Functors::Base::operator()(Functors::Params params) {
    *(params.color) = BLACK;
}

Functors::Fill::Fill(Color fillColor, s16 start, s16 end) : fillColor(fillColor), start(start), end(end) {}
void Functors::Fill::operator()(Functors::Params params) {
    s16 pixel = *(params.pixel);
    if (pixel >= start && pixel < end) {
        *(params.color) = fillColor;
    } else {
        *(params.color) = BLACK;
    }
}

Functors::Stripes::Stripes(Color* colors, u16 colorCount, u16 width) : colors(colors), colorCount(colorCount), width(width) {}
void Functors::Stripes::operator()(Functors::Params params) {
    *(params.color) = colors[(*(params.pixel) / width) % colorCount];
}

Functors::Animate::Animate(double speed) : speed(speed) {
    startTime = Clock::now();
}
void Functors::Animate::operator()(Functors::Params params) {
    clock_t currTime = Clock::now();
    float timeElapsed = Clock::diff_secs(currTime, startTime)
    s16 pixelShift = (s16) (timeElapsed * speed);
    *(params.pixel) += pixelShift;
}

// Rule class methods
Rule::Rule() {
    
}
Rule::~Rule() {

}
// Evaluate 
Color Rule::operator()(s16 pixel) {
    // Set up params to pass to each functor
    Color color = {0, 0, 0};
    s16 currentPixel = pixel;
    Functors::Params params = {&color, &currentPixel};

    // Apply each functor to modify the color
    for (std::vector<Functors::Base*>::iterator it = functors.begin(); it != functors.end(); ++it) {
        Functors::Base* func = *it;
        // Modify the pixel color based on the rule
        (*func)(params);
    }
    return color;
}

// Primary rules

Rule* Rule::fill(Color fillColor, s16 start, s16 end) {
    //functors.clear();
    Functors::Fill* f = new Functors::Fill(fillColor, start, end);
    functors.push_back(f);
    return this;
}

Rule* Rule::stripes(Color* colors, u16 colorCount, u16 width) {
    //functors.clear();
    Functors::Stripes* f = new Functors::Stripes(colors, colorCount, width);
    functors.push_back(f);
    return this;
}

// Secondary rules

Rule* Rule::animate(double speed) {
    return this;
}
