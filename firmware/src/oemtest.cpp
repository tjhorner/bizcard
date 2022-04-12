#ifdef OEMTEST

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "pins.h"

Adafruit_NeoPixel pixels(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  
  for (int n = 0; n < 3; n++) {
    for (int i = 0; i < NEOPIXEL_COUNT; i++) {
      int r = n == 0 ? 255 : 0;
      int g = n == 1 ? 255 : 0;
      int b = n == 2 ? 255 : 0;
      pixels.setPixelColor(i, pixels.Color(r, g, b));
    }

    pixels.show();
    delay(500);
  }

  pixels.clear();
  pixels.show();

  pinMode(BUZZER_PIN, OUTPUT);
  tone(BUZZER_PIN, 440, 500);
}

void loop() { }

#endif