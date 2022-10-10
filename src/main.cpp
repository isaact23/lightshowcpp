using namespace std;
#include "main.hpp"

int main() {
    // Initialize Neopixel
    #ifdef USE_NEOPIXEL
    NeoPixel* neoPixel = new NeoPixel(LED_CNT);
    neoPixel -> begin();
    #endif
    
    Grid* grid = new Grid(neoPixel);

    Color colors[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    Rule* movingStripesRule = (new Rule()) -> animate(4.0) -> stripes(colors, 6, 4);

    grid -> getSeg(0) -> setRule(movingStripesRule);
    grid -> getSeg(1) -> setRule(movingStripesRule);

    Rule* solidColorRule = (new Rule()) -> fill(BLUE, 0, 1000);

    for (u16 i = 2; i < SEG_CNT; i++) {
        grid -> getSeg(i) -> setRule(solidColorRule);
    }

    auto startTime = Clock::now();
    float timeElapsed = 0.0;

    while (timeElapsed < 1000.0) {
        grid -> useRule(timeElapsed);
        timeElapsed = Clock::secs_since(startTime);
        // cout << Clock::secs_since(startTime) << endl;
        
        #ifdef USE_NEOPIXEL
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
