#include "remap.h"

unsigned char remap_ansi(unsigned char code) {
  switch (code) {
    case 0x32: return 0x28; // # ~      -> enter
    case 0x64: return 0xE1; // ISO \ |  -> left shift
    case 0x87: return 0xE5; // \ _      -> right shift
    case 0x88: return 0x2C; // kana     -> space
    case 0x89: return 0x2A; // ¥ |      -> backspace
    case 0x8A: return 0x2C; // henkan   -> space
    case 0x8B: return 0x2C; // muhenkan -> space
    default: return code;
  }
}

unsigned char remap_iso(unsigned char code) {
  switch (code) {
    case 0x31: return 0x28; // ANSI \ | -> enter
    case 0x87: return 0xE5; // \ _      -> right shift
    case 0x88: return 0x2C; // kana     -> space
    case 0x89: return 0x2A; // ¥ |      -> backspace
    case 0x8A: return 0x2C; // henkan   -> space
    case 0x8B: return 0x2C; // muhenkan -> space
    default: return code;
  }
}

unsigned char remap_jis(unsigned char code) {
  switch (code) {
    case 0x31: return 0x28; // ANSI \ | -> enter
    case 0x64: return 0xE1; // ISO \ |  -> left shift
    default: return code;
  }
}

unsigned char remap_mac(unsigned char code) {
  switch (code) {
    case 0xE2: return 0xE3; // left alt   -> left meta
    case 0xE3: return 0xE2; // left meta  -> left alt
    case 0xE6: return 0xE7; // right alt  -> right meta
    case 0xE7: return 0xE6; // right meta -> right alt
    default: return code;
  }
}

unsigned char remap_unix(unsigned char code) {
  switch (code) {
    case 0x68: return 0x75; // F13 -> help
    case 0x69: return 0x75; // F14 -> help
    case 0x6A: return 0x78; // F15 -> stop
    case 0x6B: return 0x79; // F16 -> again
    case 0x6C: return 0x76; // F17 -> props
    case 0x6D: return 0x7A; // F18 -> undo
    case 0x6E: return 0x77; // F19 -> front
    case 0x6F: return 0x7C; // F20 -> copy
    case 0x70: return 0x74; // F21 -> open
    case 0x71: return 0x7D; // F22 -> paste
    case 0x72: return 0x7E; // F23 -> find
    case 0x73: return 0x7B; // F24 -> cut
    default: return code;
  }
}

unsigned char remap_hexpad(unsigned char code) {
  switch (code) {
    case 0x53: return 0x04; // num lock -> A
    case 0x54: return 0x06; // numpad / -> C
    case 0x55: return 0x07; // numpad * -> D
    case 0x56: return 0x08; // numpad - -> E
    case 0x57: return 0x09; // numpad + -> F
    case 0x63: return 0x1B; // numpad . -> X
    case 0x67: return 0x05; // numpad = -> B
    default: return code;
  }
}

unsigned char remap_hexlock(unsigned char code) {
  switch (code) {
    case 0x53: return 0x04; // num lock -> A
    case 0x54: return 0x06; // numpad / -> C
    case 0x55: return 0x07; // numpad * -> D
    case 0x56: return 0x08; // numpad - -> E
    case 0x57: return 0x09; // numpad + -> F
    case 0x59: return 0x1E; // numpad 1 -> 1 !
    case 0x5A: return 0x1F; // numpad 2 -> 2 @
    case 0x5B: return 0x20; // numpad 3 -> 3 #
    case 0x5C: return 0x21; // numpad 4 -> 4 $
    case 0x5D: return 0x22; // numpad 5 -> 5 %
    case 0x5E: return 0x23; // numpad 6 -> 6 ^
    case 0x5F: return 0x24; // numpad 7 -> 7 &
    case 0x60: return 0x25; // numpad 8 -> 8 *
    case 0x61: return 0x26; // numpad 9 -> 9 (
    case 0x62: return 0x27; // numpad 0 -> 0 )
    case 0x63: return 0x1B; // numpad . -> X
    case 0x67: return 0x05; // numpad = -> B
    case 0x85: return 0x36; // numpad , -> , >
    default: return 0;
  }
}

unsigned char remap_numlock(unsigned char code) {
  switch (code) {
    case 0x59: return 0x1E; // numpad 1 -> 1 !
    case 0x5A: return 0x1F; // numpad 2 -> 2 @
    case 0x5B: return 0x20; // numpad 3 -> 3 #
    case 0x5C: return 0x21; // numpad 4 -> 4 $
    case 0x5D: return 0x22; // numpad 5 -> 5 %
    case 0x5E: return 0x23; // numpad 6 -> 6 ^
    case 0x5F: return 0x24; // numpad 7 -> 7 &
    case 0x60: return 0x25; // numpad 8 -> 8 *
    case 0x61: return 0x26; // numpad 9 -> 9 (
    case 0x62: return 0x27; // numpad 0 -> 0 )
    case 0x63: return 0x37; // numpad . -> . >
    case 0x85: return 0x36; // numpad , -> , >
    default: return 0;
  }
}
