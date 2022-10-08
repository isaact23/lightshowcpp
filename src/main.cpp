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
    Rule* movingStripes = (new Rule()) -> animate(15.0) -> stripes(colors, 6, 10);

    grid -> setRule(movingStripes);

    auto startTime = Clock::now();
    float timeElapsed = 0.0;

    while (timeElapsed < 5.0) {
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
