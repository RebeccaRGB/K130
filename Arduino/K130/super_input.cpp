#include <Arduino.h>
#include <usb_keyboard.h>
#include <util/delay.h>
#include "layouts.h"
#include "remap.h"
#include "unicode.h"
#include "usbk.h"

static void type_unicode_cp(unsigned char switches, unsigned long cp) {
  switch (switches & 0x18) {
    case 0x00: usbk_type_unicode_unix(cp); break;
    case 0x08: usbk_type_unicode_win_dec(cp); break;
    case 0x10: usbk_type_unicode_win_hex(cp); break;
    case 0x18: usbk_type_unicode_mac(cp); break;
  }
  delay(50);
}

static bool type_unicode(unsigned char switches, unsigned long cp) {
  if (cp < LAYOUT_UNICODE_MAX) {
    type_unicode_cp(switches, cp);
    return 1;
  } else if (cp < LAYOUT_SWITCH_STATE) {
    type_unicode_cp(switches, (cp >> 16) & 0xFFFFL);
    type_unicode_cp(switches, cp & 0xFFFFL);
    return 2;
  } else {
    return 0;
  }
}

static unsigned char unicodeInput = 0;
static unsigned long unicodeValue = 0;

void unicode_input_dec() {
  unicodeInput = 10;
  unicodeValue = 0;
}

void unicode_input_hex() {
  unicodeInput = 16;
  unicodeValue = 0;
}

void unicode_input_end() {
  unicodeInput = 0;
  unicodeValue = 0;
}

unsigned char unicode_input_status() {
  return unicodeInput;
}

bool unicode_input(unsigned char r, unsigned char s) {
  if (unicodeInput) {
    switch (r) {
      case USBK_RETURN:
      case USBK_TAB:
      case USBK_SPACE:
      case USBK_NUM_ENTER:
        type_unicode(s, unicodeValue);
        // fallthrough;
      case USBK_ESC:
      case USBK_NUM_CLEAR:
        unicodeInput = 0;
        unicodeValue = 0;
        return 1;
      case USBK_BACKSPACE:
      case USBK_DEL:
        unicodeValue /= unicodeInput;
        return 1;
      default:
        int d = usbk_numeric_value(r);
        if (d >= 0 && d < unicodeInput) {
          unicodeValue *= unicodeInput;
          unicodeValue += d;
          return 1;
        }
    }
  }
  return 0;
}

static unsigned long (*layoutFn)(unsigned char, unsigned char) = 0;
static unsigned char layoutModMask = 0;
static unsigned char layoutLock = 0;
static unsigned char layoutState = 0;

void layout_input_start(unsigned long (*fn)(unsigned char, unsigned char), unsigned char mm) {
  if (layoutFn == fn) {
    if (layoutLock) {
      layoutFn = 0;
      layoutModMask = 0;
      layoutLock = 0;
      layoutState = 0;
    } else {
      layoutModMask = mm;
      layoutLock = 1;
    }
  } else {
    layoutFn = fn;
    layoutModMask = mm;
    layoutLock = 0;
    layoutState = 0;
  }
}

void layout_input_end() {
  layoutFn = 0;
  layoutModMask = 0;
  layoutLock = 0;
  layoutState = 0;
}

unsigned char layout_input_status() {
  return layoutFn ? (layoutState + (layoutLock ? 2 : 1)) : 0;
}

bool layout_input(unsigned char r, unsigned char s) {
  if (layoutFn) {
    unsigned char l = usbk_read_leds();
    unsigned char m = usbk_output_report()[0];
    unsigned char n = (((m >> 4) | m) & 6) | ((l >> 1) & 1);
    unsigned long u = (*layoutFn)(r, n | layoutState);
    if (u) {
      if (!type_unicode(s, u)) {
        layoutState = u;
        return 1;
      }
      layoutState = 0;
      if (!layoutLock) {
        layoutModMask = 0;
        layoutFn = 0;
      }
      return 1;
    }
    if (layoutState) {
      unsigned long v = (*layoutFn)(r, n | LAYOUT_BASE);
      unsigned long w = (*layoutFn)(USBK_SPACE, layoutState | LAYOUT_ALT);
      if (v & w) {
        if (!type_unicode(s, v)) {
          layoutState = v;
          return 1;
        }
        if (!type_unicode(s, w)) {
          layoutState = w;
          return 1;
        }
        layoutState = 0;
        if (!layoutLock) {
          layoutModMask = 0;
          layoutFn = 0;
        }
        return 1;
      }
    }
  }
  return 0;
}

static bool numlock = 0;
static bool hexlock = 0;

void numpad_numlock_on() { numlock = 1; }
void numpad_numlock_off() { numlock = 0; }
void numpad_numlock_toggle() { numlock = !numlock; }
bool numpad_numlock_status() { return numlock; }

void numpad_hexlock_on() { hexlock = 1; }
void numpad_hexlock_off() { hexlock = 0; }
void numpad_hexlock_toggle() { hexlock = !hexlock; }
bool numpad_hexlock_status() { return hexlock; }

bool numpad_input(unsigned char r, unsigned char m) {
  unsigned char t = (
    hexlock ? remap_hexlock(r) :
    numlock ? remap_numlock(r) :
    0
  );
  if (t) {
    usbk_clear_report();
    Keyboard.set_modifier((t < 0x1E) ? m : 0);
    Keyboard.send_now();
    Keyboard.set_key1(t);
    Keyboard.send_now();
    return 1;
  }
  return 0;
}

void super_input_dec() {
  if (unicode_input_status() == 10) {
    numpad_numlock_toggle();
    unicode_input_end();
  } else {
    unicode_input_dec();
  }
}

void super_input_hex() {
  if (unicode_input_status() == 16) {
    numpad_hexlock_toggle();
    unicode_input_end();
  } else {
    unicode_input_hex();
  }
}

bool super_input(unsigned char r, unsigned char s, unsigned char m) {
  if (unicodeInput && !(m & 0xDD) && unicode_input(r, s)) return 1;
  if (layoutFn && !(m & layoutModMask) && layout_input(r, s)) return 1;
  if ((numlock || hexlock) && !(m & 0xDD) && numpad_input(r, m)) return 1;
  return 0;
}
