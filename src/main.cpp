#include "main.hpp"

int main() {
    Grid* grid = new Grid();
    Color colors[3] = {RED, GREEN, BLUE};
    grid -> getSeg(0) -> setRule(
        (new Rule()) -> stripes(colors, 3, 5)
    );
    grid -> useRule();
    delete grid;
}
