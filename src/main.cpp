using namespace std;
#include "main.hpp"

int main() {
    Strip strip = Strip(LED_COUNT, LED_PIN, CHANNEL);
    strip.fill(GREEN);
}
