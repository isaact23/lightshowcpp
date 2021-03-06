#ifndef MAIN_HPP
#define MAIN_HPP

#define LED_CNT 150

#include <iostream>
#include "clock.hpp"
#include "colors.hpp"
#include "datatypes.hpp"
#include "rule.hpp"
#include "segment.hpp"

#ifdef USE_NEOPIXEL
#include "ws2812-rpi/ws2812-rpi.h"
#endif

#define FRAMERATE 60

#endif
