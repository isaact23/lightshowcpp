#ifndef STRIP_HPP
#define STRIP_HPP

#include "./ws2812-esp32/src/Freenove_WS2812_Lib_for_ESP32.h"
#include "../datatypes.hpp"

#define LED_COUNT 10
#define LED_PIN 2
#define CHANNEL 0

// Wrapper class for light strip control.
class Strip {

public:
  Strip(u32 size);
  ~Strip();
  Segment get_segment(u32 start, u32 end);

private:
  Freenove_ESP32_WS2812 ws2812;
}

#endif
