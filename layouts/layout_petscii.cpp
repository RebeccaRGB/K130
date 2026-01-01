#include "layout_petscii.h"
#include "layout_us.h"
#include "layouts.h"

unsigned long layout_petscii_alt(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0x250C  : 0x2660  ; // ┌ ♠
    case 0x05: return (state & LAYOUT_SHIFT) ? 0x259A  : 0x1FB72 ; // ▚ 🭲
    case 0x06: return (state & LAYOUT_SHIFT) ? 0x259D  : 0x1FB78 ; // ▝ 🭸
    case 0x07: return (state & LAYOUT_SHIFT) ? 0x2597  : 0x1FB77 ; // ▗ 🭷
    case 0x08: return (state & LAYOUT_SHIFT) ? 0x2534  : 0x1FB76 ; // ┴ 🭶
    case 0x09: return (state & LAYOUT_SHIFT) ? 0x2596  : 0x1FB7A ; // ▖ 🭺
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0x258F  : 0x1FB71 ; // ▏ 🭱
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0x258E  : 0x1FB74 ; // ▎ 🭴
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0x2584  : 0x256E  ; // ▄ ╮
    case 0x0D: return (state & LAYOUT_SHIFT) ? 0x258D  : 0x2570  ; // ▍ ╰
    case 0x0E: return (state & LAYOUT_SHIFT) ? 0x258C  : 0x256F  ; // ▌ ╯
    case 0x0F: return (state & LAYOUT_SHIFT) ? 0x1FB88 : 0x1FB7C ; // 🮈 🭼
    case 0x10: return (state & LAYOUT_SHIFT) ? 0x2595  : 0x2572  ; // ▕ ╲
    case 0x11: return (state & LAYOUT_SHIFT) ? 0x1FB87 : 0x1FB73 ; // 🮇 🭳
    case 0x12: return (state & LAYOUT_SHIFT) ? 0x2583  : 0x1FB7D ; // ▃ 🭽
    case 0x13: return (state & LAYOUT_SHIFT) ? 0x2582  : 0x1FB7E ; // ▂ 🭾
    case 0x14: return (state & LAYOUT_SHIFT) ? 0x251C  : 0x2022  ; // ├ •
    case 0x15: return (state & LAYOUT_SHIFT) ? 0x252C  : 0x1FB7B ; // ┬ 🭻
    case 0x16: return (state & LAYOUT_SHIFT) ? 0x2510  : 0x2665  ; // ┐ ♥
    case 0x17: return (state & LAYOUT_SHIFT) ? 0x2594  : 0x1FB70 ; // ▔ 🭰
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x1FB83 : 0x256D  ; // 🮃 ╭
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x2598  : 0x1FB79 ; // ▘ 🭹
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0x2524  : 0x25CB  ; // ┤ ○
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0x2518  : 0x2663  ; // ┘ ♣
    case 0x1C: return (state & LAYOUT_SHIFT) ? 0x1FB82 : 0x1FB75 ; // 🮂 🭵
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0x2514  : 0x2666  ; // └ ♦
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x259B  : 0x25D8  ; // ▛ ◘
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x259C  : 0x25D9  ; // ▜ ◙
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x2599  : 0x00A3  ; // ▙ £
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x259F  : 0xF821  ; // ▟ 
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x1FB91 : 0x20AC  ; // 🮑 €
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x1FB94 : 0x2191  ; // 🮔 ↑
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x1FBB1 : 0x2713  ; // 🮱 ✓
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x2580  : 0x1FB98 ; // ▀ 🮘
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x1FB90 : 0x1FB99 ; // 🮐 🮙
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x1FB96 : 0x1FB95 ; // 🮖 🮕
    case 0x2C: return 0xA0; // nbsp
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x1FB8C : 0x2502  ; // 🮌 │
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x2592  : 0x253C  ; // ▒ ┼
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x2581  : 0x1FB7F ; // ▁ 🭿
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x25E5  : 0x2500  ; // ◥ ─
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x1FB8F : 0x25E4  ; // 🮏 ◤ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x1FB8F : 0x25E4  ; // 🮏 ◤ (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x1FB87 : 0x1FB7F ; // 🮇 🭿
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x2595  : 0x2588  ; // ▕ █
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x03C0  : 0x2190  ; // π ←
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x2590  : 0x2571  ; // ▐ ╱
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x259E  : 0x2573  ; // ▞ ╳
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x25E3  : 0x25E2  ; // ◣ ◢
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x00A3  : 0x2191  ; // £ ↑ (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F  : 0x25E4  ; // _ ◤ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x1FB8F : 0x00A5  ; // 🮏 ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_petscii_layered(unsigned char code, unsigned char state) {
  if (state & LAYOUT_ALT) return layout_petscii_alt(code, state);
  return layout_us(code, state);
}
