#include "main.hpp"

int main() {
    // Set up
    #ifdef USE_NEOPIXEL
    NeoPixel* neoPixel = new NeoPixel(LED_CNT);
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

    while (Clock::secs_since(startTime) < 5.0) {
        mainSeg.useRule();

        timeElapsed = Clock::secs_since(startTime);
        std::cout << Clock::secs_since(startTime) << std::endl;
    }

    std::cout << "Done!" << std::endl;

    #ifdef USE_NEOPIXEL
    delete neoPixel;
    #endif
}
