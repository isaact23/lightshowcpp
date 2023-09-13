#ifndef STRIP_HPP
#define STRIP_HPP

#include "../led-control/ws2812-esp32/src/Freenove_WS2812_Lib_for_ESP32.h"
#include "../data/inttypes.hpp"
#include "../data/colors/colors.hpp"

// Wrapper class for light strip control.
class Strip {

public:
  Strip(u32 size, u8 pin, u8 channel);
  ~Strip();

  // Create a segment to control part of this strip.
  Segment* get_segment(u32 start, u32 end);

  // Set an LED color. Return true on success.
  bool set_pixel(u32 index, Color color);

  // Set all LEDs to a color.
  void fill(Color color);

  // Send the color data to the physical LED strip.
  void update_strip();

private:
  Freenove_ESP32_WS2812 ws2812;
  u32 size;
  u8 pin;
  u8 channel;

}

#endif
