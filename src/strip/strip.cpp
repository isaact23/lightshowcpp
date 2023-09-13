
Strip::Strip() {

  ws2812 = Freenove_ESP32_WS2812(LED_COUNT, LED_PIN, CHANNEL);
  ws2812.begin();
}

Strip::~Strip() {
  ws2812.setAllLedsColor(0, 0, 0);
  ws2812.show();
  delete ws2812;
}

// Create a segment to control part of this strip.
Segment* Strip::get_segment() {
  throw new Exception("get_segment not implemented");
}

// Set an LED color. Return true on success.
bool Strip::set_pixel(u32 index, Color color) {

  // Check index within bounds of strip
  if (index >= size) return false;

  // Update pixel
  ws2812.setLedColorData(index, color.red, color.green, color.blue);
  return true;
}

// Set all LEDs to a color.
void Strip::fill(Color color) {
  ws2812.setAllLedsColorData(color.red, color.green, color.blue);
}

// Send the color data to the physical LED strip.
void Strip::update_strip() {
  ws2812.show();
}
