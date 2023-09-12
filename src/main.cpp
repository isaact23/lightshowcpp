using namespace std;
#include "main.hpp"

int main() {
    
    Color colors[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    Rule* movingStripesRule = (new Rule()) -> animate(4.0) -> stripes(colors, 6, 4);

    auto startTime = Clock::now();
    auto lastUpdateTime = startTime;
    float timeElapsed = 0.0;

    while (timeElapsed < 5.0) {
        if (Clock::secs_since(lastUpdateTime) >= 1.0 / FPS) {
            grid -> useRule(timeElapsed);
            timeElapsed = Clock::secs_since(startTime);
            lastUpdateTime = Clock::now();
        }
        // cout << Clock::secs_since(startTime) << endl;
    }

    delete strip;
}
