#include "main.hpp"

int main() {
    Grid* grid = new Grid();
    Color colors[3] = {RED, GREEN, BLUE};
    grid -> getSeg(0) -> setRule(
        (new Rule()) -> stripes(colors, 3, 5) -> animate(3.0)
    );

    clock_t startTime = Clock::now();
    float timeElapsed = 0.0;

    while (timeElapsed < 5.0) {
        grid -> useRule();
        std::cout << timeElapsed << std::endl;

        clock_t currTime = Clock::now();
        timeElapsed = Clock::diff_secs(currTime, startTime);
    }
    delete grid;
}
