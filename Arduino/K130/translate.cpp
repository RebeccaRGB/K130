#include <Arduino.h>
#include <avr/pgmspace.h>
#include "translate.h"

static const unsigned char translation_table[] PROGMEM = {
  0x29, // 0x00 -> 0x29 esc
  0x35, // 0x01 -> 0x35 ` ~
  0x2B, // 0x02 -> 0x2B tab
  0x39, // 0x03 -> 0x39 caps lock
  0xE1, // 0x04 -> 0xE1 left shift
  0xE0, // 0x05 -> 0xE0 left ctrl
  0x85, // 0x06 -> 0x85 numpad ,
  0x59, // 0x07 -> 0x59 numpad 1
  0x5D, // 0x08 -> 0x5D numpad 5
  0x60, // 0x09 -> 0x60 numpad 8
  0x67, // 0x0A -> 0x67 numpad =
  0x81, // 0x0B -> 0x81 volume down
  0x69, // 0x0C -> 0x69 F14
  0x6B, // 0x0D -> 0x6B F16
  0x6D, // 0x0E -> 0x6D F18
  0x6F, // 0x0F -> 0x6F F20
  0x71, // 0x10 -> 0x71 F22
  0x73, // 0x11 -> 0x73 F24
  0x63, // 0x12 -> 0x63 numpad .
  0x5A, // 0x13 -> 0x5A numpad 2
  0x5E, // 0x14 -> 0x5E numpad 6
  0x61, // 0x15 -> 0x61 numpad 9
  0x54, // 0x16 -> 0x54 numpad /
  0x80, // 0x17 -> 0x80 volume up
  0x68, // 0x18 -> 0x68 F13
  0x6A, // 0x19 -> 0x6A F15
  0x6C, // 0x1A -> 0x6C F17
  0x6E, // 0x1B -> 0x6E F19
  0x70, // 0x1C -> 0x70 F21
  0x72, // 0x1D -> 0x72 F23
  0x58, // 0x1E -> 0x58 numpad enter
  0x5B, // 0x1F -> 0x5B numpad 3
  0x57, // 0x20 -> 0x57 numpad +
  0x56, // 0x21 -> 0x56 numpad -
  0x55, // 0x22 -> 0x55 numpad *
  0x66, // 0x23 -> 0x66 power
  0x3A, // 0x24 -> 0x3A F1
  0x1E, // 0x25 -> 0x1E 1 !
  0x14, // 0x26 -> 0x14 Q
  0x04, // 0x27 -> 0x04 A
  0x64, // 0x28 -> 0x64 ISO \ |
  0x01, // 0x29 -> 0x01 fn
  0x62, // 0x2A -> 0x62 numpad 0
  0x52, // 0x2B -> 0x52 up arrow
  0x5C, // 0x2C -> 0x5C numpad 4
  0x5F, // 0x2D -> 0x5F numpad 7
  0x53, // 0x2E -> 0x53 num lock
  0x7F, // 0x2F -> 0x7F mute
  0x3B, // 0x30 -> 0x3B F2
  0x1F, // 0x31 -> 0x1F 2 @
  0x1A, // 0x32 -> 0x1A W
  0x16, // 0x33 -> 0x16 S
  0x1D, // 0x34 -> 0x1D Z
  0xE3, // 0x35 -> 0xE3 left meta
  0x4F, // 0x36 -> 0x4F right arrow
  0x00, // 0x37 -> 0x00 undefined
  0x00, // 0x38 -> 0x00 undefined
  0x4E, // 0x39 -> 0x4E page down
  0x4B, // 0x3A -> 0x4B page up
  0x48, // 0x3B -> 0x48 pause
  0x3C, // 0x3C -> 0x3C F3
  0x20, // 0x3D -> 0x20 3 #
  0x08, // 0x3E -> 0x08 E
  0x07, // 0x3F -> 0x07 D
  0x1B, // 0x40 -> 0x1B X
  0xE2, // 0x41 -> 0xE2 left alt
  0x51, // 0x42 -> 0x51 down arrow
  0xE5, // 0x43 -> 0xE5 right shift
  0x28, // 0x44 -> 0x28 enter
  0x4D, // 0x45 -> 0x4D end
  0x4A, // 0x46 -> 0x4A home
  0x47, // 0x47 -> 0x47 scroll lock
  0x3D, // 0x48 -> 0x3D F4
  0x21, // 0x49 -> 0x21 4 $
  0x15, // 0x4A -> 0x15 R
  0x09, // 0x4B -> 0x09 F
  0x06, // 0x4C -> 0x06 C
  0x8B, // 0x4D -> 0x8B muhenkan
  0x50, // 0x4E -> 0x50 left arrow
  0x87, // 0x4F -> 0x87 \ _
  0x32, // 0x50 -> 0x32 # ~
  0x4C, // 0x51 -> 0x4C delete
  0x49, // 0x52 -> 0x49 insert
  0x46, // 0x53 -> 0x46 print screen
  0x3E, // 0x54 -> 0x3E F5
  0x22, // 0x55 -> 0x22 5 %
  0x17, // 0x56 -> 0x17 T
  0x0A, // 0x57 -> 0x0A G
  0x19, // 0x58 -> 0x19 V
  0x2C, // 0x59 -> 0x2C space
  0xE4, // 0x5A -> 0xE4 right ctrl
  0x38, // 0x5B -> 0x38 / ?
  0x34, // 0x5C -> 0x34 ' "
  0x31, // 0x5D -> 0x31 ANSI \ |
  0x2A, // 0x5E -> 0x2A backspace
  0x45, // 0x5F -> 0x45 F12
  0x41, // 0x60 -> 0x41 F8
  0x25, // 0x61 -> 0x25 8 *
  0x0C, // 0x62 -> 0x0C I
  0x0E, // 0x63 -> 0x0E K
  0x10, // 0x64 -> 0x10 M
  0x36, // 0x65 -> 0x36 , <
  0xE6, // 0x66 -> 0xE6 right alt
  0x12, // 0x67 -> 0x12 O
  0x26, // 0x68 -> 0x26 9 (
  0x27, // 0x69 -> 0x27 0 )
  0x2D, // 0x6A -> 0x2D - _
  0x42, // 0x6B -> 0x42 F9
  0x40, // 0x6C -> 0x40 F7
  0x24, // 0x6D -> 0x24 7 &
  0x18, // 0x6E -> 0x18 U
  0x0D, // 0x6F -> 0x0D J
  0x11, // 0x70 -> 0x11 N
  0x88, // 0x71 -> 0x88 kana
  0xE7, // 0x72 -> 0xE7 right meta
  0x0F, // 0x73 -> 0x0F L
  0x13, // 0x74 -> 0x13 P
  0x2F, // 0x75 -> 0x2F [ {
  0x2E, // 0x76 -> 0x2E = +
  0x43, // 0x77 -> 0x43 F10
  0x3F, // 0x78 -> 0x3F F6
  0x23, // 0x79 -> 0x23 6 ^
  0x1C, // 0x7A -> 0x1C Y
  0x0B, // 0x7B -> 0x0B H
  0x05, // 0x7C -> 0x05 B
  0x8A, // 0x7D -> 0x8A henkan
  0x65, // 0x7E -> 0x65 menu
  0x37, // 0x7F -> 0x37 . >
  0x33, // 0x80 -> 0x33 ; :
  0x30, // 0x81 -> 0x30 ] }
  0x89, // 0x82 -> 0x89 ¥ |
  0x44, // 0x83 -> 0x44 F11
};

unsigned char translate_scancode(unsigned char packet) {
  return pgm_read_byte(&translation_table[packet]);
}

unsigned int translate_packet(unsigned int packet) {
  unsigned char scancode = translate_scancode(packet);
  return scancode ? ((packet &~ 0xFF) | scancode) : 0;
}
