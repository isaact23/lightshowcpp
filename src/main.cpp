using namespace std;
#include "main.hpp"

int main() {
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
        // cout << Clock::secs_since(startTime) << endl;
        
        printColor(mainSeg.getColor(0));
        
        #ifdef USE_NEOPIXEL
        //neoPixel -> setPixelColor(i, color.red, color.green, color.blue);
        #endif
    }

    cout << "Done!" << endl;

    #ifdef USE_NEOPIXEL
    delete neoPixel;
    #endif
}
