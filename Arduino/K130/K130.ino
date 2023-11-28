#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <avr/pgmspace.h>
#include <usb_keyboard.h>
#include <util/delay.h>
#include "layout_arabic.h"
#include "layout_cyrillic.h"
#include "layout_dead_keys.h"
#include "layout_hebrew.h"
#include "layout_ipa.h"
#include "layout_jis.h"
#include "layout_petscii.h"
#include "layout_sitelen_pona.h"
#include "layout_symbol.h"
#include "layout_us.h"
#include "layouts.h"
#include "leds.h"
#include "matrix.h"
#include "remap.h"
#include "super_input.h"
#include "switches.h"
#include "translate.h"
#include "unicode.h"
#include "usbk.h"

void setup() {
  switches_init();
  matrix_init();
  leds_init_rgb_daisy();
}

void loop() {
  unsigned int p = matrix_read_packet();
  if (p) {
    unsigned int q = translate_packet(p);
    if (q) {
      unsigned char r = q;
      unsigned char s = ~switches_read();
      unsigned char m = usbk_output_report()[0];

      switch (s & 3) {
        case 1: r = remap_ansi(r); break;
        case 2: r = remap_iso(r); break;
        case 3: r = remap_jis(r); break;
      }
      if (s & 4) r = remap_mac(r);

      if (s & 32) {
        if (q & MTX_PRESSED) {
          switch (r) {
            case 0x68: super_input_dec(); return;
            case 0x69: super_input_hex(); return;
            case 0x6A: layout_input_start(layout_us_alt, LAYOUT_MODMASK_2LAYER); return;
            case 0x6B: layout_input_start(layout_petscii_alt, LAYOUT_MODMASK_2LAYER); return;
            case 0x6C: layout_input_start(layout_symbol_layered, LAYOUT_MODMASK_4LAYER); return;
            case 0x6D: layout_input_start(layout_cyrillic_layered, LAYOUT_MODMASK_4LAYER); return;
            case 0x6E: layout_input_start(layout_hebrew_qwerty, LAYOUT_MODMASK_4LAYER); return;
            case 0x6F: layout_input_start(layout_arabic_qwerty, LAYOUT_MODMASK_4LAYER); return;
            case 0x70: layout_input_start(layout_ipa_layered, LAYOUT_MODMASK_4LAYER); return;
            case 0x71: layout_input_start(layout_sitelen_pona, LAYOUT_MODMASK_4LAYER); return;
            case 0x72: layout_input_start(layout_jis_hiragana, LAYOUT_MODMASK_2LAYER); return;
            case 0x73: layout_input_start(layout_jis_katakana, LAYOUT_MODMASK_2LAYER); return;
            default: if (super_input(r, s, m)) return;
          }
        }
      } else {
        if (s & 8) r = remap_unix(r);
        if (s & 16) r = remap_hexpad(r);
      }

      if (q & MTX_PRESSED) {
        switch (r) {
          case 0x7F: Keyboard.press((m & USBK_MOD_ANY_ALT) ? KEY_MEDIA_PLAY_PAUSE : KEY_MEDIA_MUTE); break;
          case 0x81: Keyboard.press((m & USBK_MOD_ANY_ALT) ? KEY_MEDIA_PREV_TRACK : KEY_MEDIA_VOLUME_DEC); break;
          case 0x80: Keyboard.press((m & USBK_MOD_ANY_ALT) ? KEY_MEDIA_NEXT_TRACK : KEY_MEDIA_VOLUME_INC); break;
          case 0x66: Keyboard.press((m & USBK_MOD_ANY_ALT) ? KEY_MEDIA_EJECT : KEY_SYSTEM_POWER_DOWN); break;
          default: usbk_key_pressed(r); break;
        }
      }
      if (q & MTX_RELEASED) {
        switch (r) {
          case 0x7F: Keyboard.release(KEY_MEDIA_PLAY_PAUSE); Keyboard.release(KEY_MEDIA_MUTE); break;
          case 0x81: Keyboard.release(KEY_MEDIA_PREV_TRACK); Keyboard.release(KEY_MEDIA_VOLUME_DEC); break;
          case 0x80: Keyboard.release(KEY_MEDIA_NEXT_TRACK); Keyboard.release(KEY_MEDIA_VOLUME_INC); break;
          case 0x66: Keyboard.release(KEY_MEDIA_EJECT); Keyboard.release(KEY_SYSTEM_POWER_DOWN); break;
          default: usbk_key_released(r); break;
        }
      }
    }
  }

  unsigned char r = usbk_read_leds();
  if (unicode_input_status()) r ^= 0x08;
  if (layout_input_status()) r ^= 0x10;
  if (layout_input_status() & 2) r ^= 0x20;
  if (numpad_numlock_status()) r ^= 0x40;
  if (numpad_hexlock_status()) r ^= 0x80;
  if (usbk_get_error_state()) r ^= 0x80;
  leds_write_rgb_daisy(r);
}
