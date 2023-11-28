#ifndef __LEDS_H__
#define __LEDS_H__

#define LED_1  33
#define LED_2  32
#define LED_3  13

void leds_init();
void leds_write(unsigned char leds);

void leds_init_rgb();
void leds_write_rgb(unsigned char leds);

void leds_init_rgb_daisy();
void leds_write_rgb_daisy(unsigned char leds);

#endif
