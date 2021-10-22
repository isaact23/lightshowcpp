#ifndef COLORS_HPP
#define COLORS_HPP

// Definitions for colors and sets of colors
#include "datatypes.hpp"

struct Color {
    u8 red;
    u8 green;
    u8 blue;
};

// Colors
#define DARK_RED (80, 0, 0)
#define RED (255, 0, 0)
#define ORANGE (255, 150, 0)
#define YELLOW (255, 255, 0)
#define DARK_GREEN (0, 80, 0)
#define GREEN (0, 255, 0)
#define CYAN (0, 255, 255)
#define DARK_BLUE (0, 0, 80)
#define BLUE (0, 0, 255)
#define PURPLE (150, 0, 255)
#define MAGENTA (255, 0, 255)
#define PINK (255, 0, 80)
#define WHITE (255, 255, 255)
#define GRAY (100, 100, 100)
#define BLACK (0, 0, 0)
#define OFF (0, 0, 0)

/*RAINBOW = (RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE)

# Schools
VT = ((50, 10, 0), (255, 80, 0))

# Countries
USA = (RED, WHITE, BLUE)
GERMANY = (OFF, RED, YELLOW)
MEXICO = (DARK_GREEN, WHITE, RED)  # Also Italy
SPAIN = (RED, (100, 100, 0), RED)
INDIA = (ORANGE, WHITE, DARK_GREEN)
CHINA = (RED, YELLOW)

# Mario characters
MARIO = (RED, BLUE)
LUIGI = (GREEN, BLACK, GREEN, WHITE)
BOWSER = (RED, YELLOW, ORANGE)
WARIO = (YELLOW, BLACK)
WALUIGI = (PURPLE, GRAY)
PEACH = (PINK, WHITE)
BOO = (WHITE, BLACK)
*/

#endif
