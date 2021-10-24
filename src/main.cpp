#include "main.hpp"
#include "rule.hpp"
#include "colors.hpp"

int main() {
    Rule rule1 = Rule();
    rule1.fill(GREEN, 0, 16);
    Color* newColor = rule1(8);
    printColor(*newColor);
    free(newColor);

    Rule rule2 = Rule();
    Color stripeColors[3] = {RED, GREEN, BLUE};
    rule2.stripes(stripeColors, 3, 5);
    printColor(*rule2(0));
    printColor(*rule2(3));
    printColor(*rule2(4));
    printColor(*rule2(5));
    printColor(*rule2(10));
}
