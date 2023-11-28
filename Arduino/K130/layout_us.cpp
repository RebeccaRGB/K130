#include "layout_dead_keys.h"
#include "layout_us.h"
#include "layouts.h"

unsigned long layout_us(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x41 : 0x61; // A a
    case 0x05: return (state & LAYOUT_CL_SH) ? 0x42 : 0x62; // B b
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x43 : 0x63; // C c
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x44 : 0x64; // D d
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x45 : 0x65; // E e
    case 0x09: return (state & LAYOUT_CL_SH) ? 0x46 : 0x66; // F f
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x47 : 0x67; // G g
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x48 : 0x68; // H h
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x49 : 0x69; // I i
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0x4A : 0x6A; // J j
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x4B : 0x6B; // K k
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x4C : 0x6C; // L l
    case 0x10: return (state & LAYOUT_CL_SH) ? 0x4D : 0x6D; // M m
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x4E : 0x6E; // N n
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x4F : 0x6F; // O o
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x50 : 0x70; // P p
    case 0x14: return (state & LAYOUT_CL_SH) ? 0x51 : 0x71; // Q q
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x52 : 0x72; // R r
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x53 : 0x73; // S s
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x54 : 0x74; // T t
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x55 : 0x75; // U u
    case 0x19: return (state & LAYOUT_CL_SH) ? 0x56 : 0x76; // V v
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x57 : 0x77; // W w
    case 0x1B: return (state & LAYOUT_CL_SH) ? 0x58 : 0x78; // X x
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x59 : 0x79; // Y y
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x5A : 0x7A; // Z z
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x21 : 0x31; // ! 1
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x40 : 0x32; // @ 2
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x23 : 0x33; // # 3
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x24 : 0x34; // $ 4
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x25 : 0x35; // % 5
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x5E : 0x36; // ^ 6
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x26 : 0x37; // & 7
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x2A : 0x38; // * 8
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x28 : 0x39; // ( 9
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x29 : 0x30; // ) 0
    case 0x2C: return 0x20; // space
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x5F : 0x2D; // _ -
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x2B : 0x3D; // + =
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x7B : 0x5B; // { [
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x7D : 0x5D; // } ]
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x7C : 0x5C; // | \ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x7C : 0x5C; // | \ (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x3A : 0x3B; // : ;
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x22 : 0x27; // " '
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x7E : 0x60; // ~ `
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x3C : 0x2C; // < ,
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x3E : 0x2E; // > .
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x3F : 0x2F; // ? /
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x3E : 0x3C; // > < (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x5F : 0x5C; // _ \ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x7C : 0xA5; // | ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_us_alt(unsigned char code, unsigned char state) {
  if (state & LAYOUT_DEAD_KEY) return layout_dead_key(code, state);
  if (state & LAYOUT_BASE) return layout_us(code, state);
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x00C6 : 0x00E6; // Æ æ
    case 0x05: return (state & LAYOUT_SHIFT) ? 0x2206 : 0x2202; // ∆ ∂
    case 0x06: return (state & LAYOUT_SHIFT) ? 0x2117 : 0x00A9; // ℗ ©
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x00D0 : 0x00F0; // Ð ð
    case 0x08: return (state & LAYOUT_SHIFT) ? 0x2211 : 0x0259; // ∑ ə
    case 0x09: return (state & LAYOUT_SHIFT) ? 0xFB02 : 0x0192; // ﬂ ƒ
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x014A : 0x014B; // Ŋ ŋ
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0x2021 : 0x2020; // ‡ †
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0xFB01 : 0x0131; // ﬁ ı
    case 0x0D: return (state & LAYOUT_SHIFT) ? 0x222B : 0x0237; // ∫ ȷ
    case 0x0E: return (state & LAYOUT_SHIFT) ? 0x25CA : 0x0138; // ◊ ĸ
    case 0x0F: return (state & LAYOUT_SHIFT) ? 0x201E : 0x201A; // „ ‚
    case 0x10: return (state & LAYOUT_SHIFT) ? 0x2318 : 0x2122; // ⌘ ™
    case 0x11: return (state & LAYOUT_SHIFT) ? 0x2116 : 0x0149; // № ŉ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x0152 : 0x0153; // Œ œ
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x220F : 0x03C0; // ∏ π
    case 0x14: return (state & LAYOUT_SHIFT) ? 0x00AA : 0x00B6; // ª ¶
    case 0x15: return (state & LAYOUT_SHIFT) ? 0x221A : 0x00AE; // √ ®
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x1E9E : 0x00DF; // ẞ ß
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x00DE : 0x00FE; // Þ þ
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x03A9 : 0x00B5; // Ω µ
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x2207 : 0x00AC; // ∇ ¬
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0x00BA : 0x00A7; // º §
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0x00A4 : 0x00D7; // ¤ ×
    case 0x1C: return (state & LAYOUT_SHIFT) ? 0x203D : 0x00A5; // ‽ ¥
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0x017F : 0x2026; // ſ …
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x00A1 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_ACUTE   ); // ¡ acute
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x20AC : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_DBLACUTE); // € dblacute
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x00A3 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_DOTABOVE); // £ dotabove
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x00A2 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_DIERESIS); // ¢ dieresis
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x2030 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_RING    ); // ‰ ring
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x00B0 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_CIRCUM  ); // ° circum
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x221E : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_CARON   ); // ∞ caron
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x2022 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_BREVE   ); // • breve
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x00B7 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_TILDE   ); // · tilde
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x00AD : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_MACRON  ); // - macron
    case 0x2C: return 0xA0; // nbsp
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x2014 : 0x2013; // — –
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x00B1 : 0x2260; // ± ≠
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x00AB : 0x2039; // « ‹
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x00BB : 0x203A; // » ›
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x00A6 : 0x00F7; // ¦ ÷ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x00A6 : 0x00F7; // ¦ ÷ (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x201C : 0x2018; // “ ‘
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x201D : 0x2019; // ” ’
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x2248 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_GRAVE   ); // ≈ grave
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x2264 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_CEDILLA ); // ≤ cedilla
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x2265 : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_OGONEK  ); // ≥ ogonek
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x00BF : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_SLASH   ); // ¿ slash
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x2265 : 0x2264; // ≥ ≤ (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F : 0x00F7; // _ ÷ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x00A6 : 0x00A5; // ¦ ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_us_layered(unsigned char code, unsigned char state) {
  if (state & LAYOUT_DEAD_KEY) return layout_dead_key(code, state);
  if (state & LAYOUT_BASE) return layout_us(code, state);
  if (state & LAYOUT_ALT) return layout_us_alt(code, state);
  return layout_us(code, state);
}
