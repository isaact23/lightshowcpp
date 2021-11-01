#include "main.hpp"

int main() {
    // Set up
    NeoPixel* neoPixel = new NeoPixel(LED_CNT);
    Segment mainSeg = Segment(neoPixel, 0, LED_CNT);

    // Initialize rule
    Color colors[2] = {GREEN, PURPLE};
    mainSeg.setRule(
        (new Rule()) -> stripes(colors, 2, 10) -> animate(3.0)
    );

    clock_t startTime = Clock::now();
    float timeElapsed = 0.0;

    while (timeElapsed < 5.0) {
        mainSeg.useRule();

        timeElapsed = Clock::secs_since(startTime);
        std::cout << timeElapsed << std::endl;
    }

    std::cout << "Done!" << std::endl;

    delete neoPixel;
}
