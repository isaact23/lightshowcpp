#include "main.hpp"
#include "rule.hpp"
#include "colors.hpp"

int main() {
    printf("Hello world!\n");

    Color red = RED;
    printColor(red);

    Rule* rule1 = new Rule();
    (*rule1).fill(GREEN, 0, 16);
    Color* newColor = (*rule1)(8);
    printColor(*newColor);

    delete rule1;
}
