#include <usb_keyboard.h>
#include "unicode.h"
#include "usbk.h"

void usbk_clear_report() {
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.set_key2(0);
  Keyboard.set_key3(0);
  Keyboard.set_key4(0);
  Keyboard.set_key5(0);
  Keyboard.set_key6(0);
  Keyboard.send_now();
}

void usbk_type_dec(unsigned long v) {
  unsigned char buf[15];
  unsigned char d;
  int p = 0;
  do buf[p++] = v % 10;
  while ((v /= 10));
  while (p) {
    d = buf[--p];
    d = d ? (d + 0x1D) : 0x27;
    Keyboard.set_key1(d);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
}

void usbk_type_dec_numpad(unsigned long v) {
  unsigned char buf[15];
  unsigned char d;
  int p = 0;
  do buf[p++] = v % 10;
  while ((v /= 10));
  while (p) {
    d = buf[--p];
    d = d ? (d + 0x58) : 0x62;
    Keyboard.set_key1(d);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
}

void usbk_type_hex(unsigned long v, int n, unsigned char shift, unsigned char unshift) {
  unsigned char buf[15];
  unsigned char d;
  int p = 0;
  do { buf[p++] = v & 15; v >>= 4; n--; }
  while (v || (n > 0));
  while (p) {
    d = buf[--p];
    if (d >= 10) {
      Keyboard.set_modifier(shift);
      Keyboard.send_now();
      Keyboard.set_key1(d - 6);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else {
      Keyboard.set_modifier(unshift);
      Keyboard.send_now();
      Keyboard.set_key1(d ? (d + 0x1D) : 0x27);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    }
  }
}

void usbk_type_hex_numpad(unsigned long v, int n, unsigned char shift, unsigned char unshift) {
  unsigned char buf[15];
  unsigned char d;
  int p = 0;
  do { buf[p++] = v & 15; v >>= 4; n--; }
  while (v || (n > 0));
  while (p) {
    d = buf[--p];
    if (d >= 10) {
      Keyboard.set_modifier(shift);
      Keyboard.send_now();
      Keyboard.set_key1(d - 6);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    } else {
      Keyboard.set_modifier(unshift);
      Keyboard.send_now();
      Keyboard.set_key1(d ? (d + 0x58) : 0x62);
      Keyboard.send_now();
      Keyboard.set_key1(0);
      Keyboard.send_now();
    }
  }
}

void usbk_type_unicode_unix(unsigned long cp) {
  usbk_clear_report();
  // Ctrl + Shift + U
  Keyboard.set_modifier(USBK_MOD_LT_CTRL);
  Keyboard.send_now();
  Keyboard.set_modifier(USBK_MOD_LT_CTRL | USBK_MOD_LT_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(USBK_U);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.set_modifier(USBK_MOD_LT_CTRL);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.send_now();
  // Code point in hex
  usbk_type_hex(cp, 0, 0, 0);
  // Enter
  Keyboard.set_key1(USBK_RETURN);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void usbk_type_unicode_win_dec(unsigned long cp) {
  usbk_clear_report();
  // Hold Alt
  Keyboard.set_modifier(USBK_MOD_LT_ALT);
  Keyboard.send_now();
  // Numpad 0
  Keyboard.set_key1(USBK_NUM_0);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  // Code point in dec on numpad
  usbk_type_dec_numpad(cp);
  // Release Alt
  Keyboard.set_modifier(0);
  Keyboard.send_now();
}

void usbk_type_unicode_win_hex(unsigned long cp) {
  usbk_clear_report();
  // Hold Alt
  Keyboard.set_modifier(USBK_MOD_LT_ALT);
  Keyboard.send_now();
  // Numpad +
  Keyboard.set_key1(USBK_NUM_PLUS);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
  // Code point in hex on numpad
  usbk_type_hex_numpad(cp, 0, USBK_MOD_LT_ALT, USBK_MOD_LT_ALT);
  // Release Alt
  Keyboard.set_modifier(0);
  Keyboard.send_now();
}

void usbk_type_unicode_mac(unsigned long cp) {
  usbk_clear_report();
  // Hold Option
  Keyboard.set_modifier(USBK_MOD_LT_ALT);
  Keyboard.send_now();
  // UTF16 code units in hex
  if (cp < 0x10000L) {
    usbk_type_hex(cp, 4, USBK_MOD_LT_ALT, USBK_MOD_LT_ALT);
  } else {
    cp -= 0x10000L;
    unsigned long w1 = ((cp >> 10) & 0x3FF) | 0xD800;
    unsigned long w2 = (cp & 0x3FF) | 0xDC00;
    usbk_type_hex(w1, 4, USBK_MOD_LT_ALT, USBK_MOD_LT_ALT);
    usbk_type_hex(w2, 4, USBK_MOD_LT_ALT, USBK_MOD_LT_ALT);
  }
  // Release Option
  Keyboard.set_modifier(0);
  Keyboard.send_now();
}

int usbk_numeric_value(unsigned char code) {
  if (code < 0x04) return -1;
  if (code < 0x1E) return code + 6;
  if (code < 0x27) return code - 0x1D;
  if (code == 0x27) return 0;
  if (code < 0x59) return -1;
  if (code < 0x62) return code - 0x58;
  if (code == 0x62) return 0;
  if (code < 0xBC) return -1;
  if (code < 0xC2) return code - 0xB2;
  return -1;
}
