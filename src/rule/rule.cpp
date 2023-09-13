#include "rule.hpp"




// Rule class methods
Rule::Rule() {
    
}
Rule::~Rule() {
    // Remove all functors
    for (std::vector<Functors::Base*>::iterator it = functors.begin(); it != functors.end(); ++it) {
        delete *it;
    }
}
// Evaluate 
Color Rule::operator()(s16 pixel, float timeElapsed) {
    // Set up params to pass to each functor
    Color color = {0, 0, 0};
    s16 currentPixel = pixel;
    float timeSinceStart = timeElapsed;
    Functors::Params params = {&color, &currentPixel, &timeSinceStart};

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
    Functors::Stripes* f = new Functors::Stripes(colors, colorCount, width);
    functors.push_back(f);
    return this;
}

// Secondary rules

Rule* Rule::animate(double speed) {
    Functors::Animate* f = new Functors::Animate(speed);
    functors.push_back(f);
    return this;
}
