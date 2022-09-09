using namespace std;
#include "main.hpp"

int main() {
    #ifdef USE_NEOPIXEL
    NeoPixel* neoPixel = new NeoPixel(LED_CNT);
    neoPixel -> begin();
    #endif
    
    Segment mainSeg = Segment(neoPixel, 0, LED_CNT);

    // Initialize rule
    Color colors[2] = {GREEN, PURPLE};
    Rule* movingStripes = (new Rule()) -> animate(8.0) -> stripes(colors, 2, 10);
    mainSeg.setRule(movingStripes);

    auto startTime = Clock::now();
    float timeElapsed = 0.0;

    while (timeElapsed < 5.0) {
        mainSeg.useRule(timeElapsed);
        timeElapsed = Clock::secs_since(startTime);
        // cout << Clock::secs_since(startTime) << endl;
        
        #ifdef USE_NEOPIXEL
        //neoPixel -> setPixelColor(i, color.red, color.green, color.blue);
        neoPixel -> show();
        #endif
    }

    cout << "Done!" << endl;

    #ifdef USE_NEOPIXEL
    neoPixel -> clear();
    neoPixel -> show();
    delete neoPixel;
    #endif
}
