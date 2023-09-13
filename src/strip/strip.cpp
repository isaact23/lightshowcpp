
Strip::Strip() {

  ws2812 = Freenove_ESP32_WS2812(LED_COUNT, LED_PIN, CHANNEL);
  ws2812.begin();
}

Strip::~Strip() {
  delete ws2812;
}

