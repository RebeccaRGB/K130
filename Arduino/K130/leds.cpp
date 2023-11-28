#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include "leds.h"

void leds_init() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void leds_write(unsigned char leds) {
  digitalWrite(LED_1, (leds & 0x01) ? HIGH : LOW);
  digitalWrite(LED_2, (leds & 0x02) ? HIGH : LOW);
  digitalWrite(LED_3, (leds & 0x04) ? HIGH : LOW);
}

static const unsigned char gamma_levels[] PROGMEM = {
  0, 1, 2, 4, 8, 15, 24, 35, 50, 68, 89, 114, 143, 176, 213, 255
};

static unsigned long random_color() {
  unsigned char r = 7, g = 7, b = 7;
  switch (random(6)) {
    case 0: r = random(r+1); b = 0; break;
    case 1: r = random(r+1); g = 0; break;
    case 2: g = random(g+1); r = 0; break;
    case 3: g = random(g+1); b = 0; break;
    case 4: b = random(b+1); g = 0; break;
    case 5: b = random(b+1); r = 0; break;
  }
  r = pgm_read_byte(&gamma_levels[r]);
  g = pgm_read_byte(&gamma_levels[g]);
  b = pgm_read_byte(&gamma_levels[b]);
  unsigned long c = r;
  c <<= 8; c |= g;
  c <<= 8; c |= b;
  return c;
}

static void write_led(Adafruit_NeoPixel * strip, unsigned int i, unsigned char leds, unsigned char mask) {
  if (leds & mask) {
    if (!strip->getPixelColor(i)) {
      strip->setPixelColor(i, random_color());
    }
  } else {
    strip->setPixelColor(i, 0);
  }
}

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, LED_1, (NEO_GRB + NEO_KHZ800));
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, LED_2, (NEO_GRB + NEO_KHZ800));
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(1, LED_3, (NEO_GRB + NEO_KHZ800));

void leds_init_rgb() {
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip1.show();
  strip2.show();
  strip3.show();
}

void leds_write_rgb(unsigned char leds) {
  write_led(&strip1, 0, leds, 0x01);
  write_led(&strip2, 0, leds, 0x02);
  write_led(&strip3, 0, leds, 0x04);
  strip1.show();
  strip2.show();
  strip3.show();
}

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, LED_1, (NEO_GRB + NEO_KHZ800));

void leds_init_rgb_daisy() {
  strip.begin();
  strip.show();
}

void leds_write_rgb_daisy(unsigned char leds) {
  write_led(&strip, 0, leds, 0x01);
  write_led(&strip, 1, leds, 0x02);
  write_led(&strip, 2, leds, 0x04);
  write_led(&strip, 3, leds, 0x08);
  write_led(&strip, 4, leds, 0x10);
  write_led(&strip, 5, leds, 0x20);
  write_led(&strip, 6, leds, 0x40);
  write_led(&strip, 7, leds, 0x80);
  strip.show();
}
