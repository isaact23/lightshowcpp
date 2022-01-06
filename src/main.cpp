#include "main.hpp"

int main() {
    // Set up
    #ifdef USE_NEOPIXEL
    NeoPixel* neoPixel = new NeoPixel(LED_CNT);
    neoPixel -> begin();
    Segment mainSeg = Segment(neoPixel, 0, LED_CNT);
    #else
    Segment mainSeg = Segment(0, LED_CNT);
    #endif

    // Initialize rule
    Color colors[2] = {GREEN, PURPLE};
    Rule* movingStripes = (new Rule()) -> stripes(colors, 2, 10) -> animate(3.0);
    mainSeg.setRule(movingStripes);

    auto startTime = Clock::now();
    float timeElapsed = 0.0;

    while (timeElapsed < 5.0) {
        mainSeg.useRule(timeElapsed);
        neoPixel -> show();
        timeElapsed = Clock::secs_since(startTime);
    }
    neoPixel -> clear();

    #ifdef USE_NEOPIXEL
    delete neoPixel;
    #endif
}
