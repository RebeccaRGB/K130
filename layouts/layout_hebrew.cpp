#include "layout_hebrew.h"
#include "layouts.h"

unsigned long layout_hebrew_qwerty(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B2 : 0x05B7) : ((state & LAYOUT_SHIFT) ? 0x05B8 : 0x05D0);
    case 0x05: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x059C : 0x2018) : ((state & LAYOUT_SHIFT) ? 0x05BC : 0x05D1);
    case 0x06: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x059E : 0x201C) : ((state & LAYOUT_SHIFT) ? 0x05E5 : 0x05E6);
    case 0x07: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x201E : 0x201E) : ((state & LAYOUT_SHIFT) ? 0x201E : 0x05D3);
    case 0x08: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B1 : 0x05B6) : ((state & LAYOUT_SHIFT) ? 0x05B5 : 0x05E2);
    case 0x09: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x20AC : 0x20AC) : ((state & LAYOUT_SHIFT) ? 0x05E3 : 0x05E4);
    case 0x0A: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x201A : 0x201A) : ((state & LAYOUT_SHIFT) ? 0x201A : 0x05D2);
    case 0x0B: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05D7 : 0x05D7) : ((state & LAYOUT_SHIFT) ? 0x05D7 : 0x05D4);
    case 0x0C: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B4 : 0x05B4) : ((state & LAYOUT_SHIFT) ? 0x05F205B7L : 0x05D9);
    case 0x0D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B4 : 0x05B4) : ((state & LAYOUT_SHIFT) ? 0x05F2 : 0x05D7);
    case 0x0E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BA : 0x05BA) : ((state & LAYOUT_SHIFT) ? 0x05DA : 0x05DB);
    case 0x0F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BD : 0x05BD) : ((state & LAYOUT_SHIFT) ? 0x05DC05B9L : 0x05DC);
    case 0x10: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05DD : 0x05DD) : ((state & LAYOUT_SHIFT) ? 0x05DD : 0x05DE);
    case 0x11: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x2019 : 0x2019) : ((state & LAYOUT_SHIFT) ? 0x05DF : 0x05E0);
    case 0x12: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B9 : 0x05B9) : ((state & LAYOUT_SHIFT) ? 0x05D505B9L : 0x05D5);
    case 0x13: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B0 : 0x05B0) : ((state & LAYOUT_SHIFT) ? 0x05E3 : 0x05E4);
    case 0x14: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x2721 : 0x2721) : ((state & LAYOUT_SHIFT) ? 0x05F0 : 0x05E7);
    case 0x15: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B3 : 0x05B8) : ((state & LAYOUT_SHIFT) ? 0x05F1 : 0x05E8);
    case 0x16: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05E905C1L : 0x05E905C1L) : ((state & LAYOUT_SHIFT) ? 0x05E9 : 0x05E1);
    case 0x17: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B3 : 0x05B8) : ((state & LAYOUT_SHIFT) ? 0x05D8 : 0x05EA);
    case 0x18: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BB : 0x05BB) : ((state & LAYOUT_SHIFT) ? 0x05D505BCL : 0x05D5);
    case 0x19: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x201D : 0x201D) : ((state & LAYOUT_SHIFT) ? 0x05D1 : 0x05D5);
    case 0x1A: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05E905C2L : 0x05E905C2L) : ((state & LAYOUT_SHIFT) ? 0x05E905C1L : 0x05E9);
    case 0x1B: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x2014 : 0x2014) : ((state & LAYOUT_SHIFT) ? 0x05DA : 0x05DB);
    case 0x1C: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05F205B7L : 0x05F205B7L) : ((state & LAYOUT_SHIFT) ? 0x05EA : 0x05D8);
    case 0x1D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x2013 : 0x2013) : ((state & LAYOUT_SHIFT) ? 0x05EF : 0x05D6);
    case 0x1E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B2 : 0x05B2) : ((state & LAYOUT_SHIFT) ? 0x0021 : 0x0031);
    case 0x1F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B3 : 0x05B3) : ((state & LAYOUT_SHIFT) ? 0x201C : 0x0032);
    case 0x20: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B1 : 0x05B1) : ((state & LAYOUT_SHIFT) ? 0x0023 : 0x0033);
    case 0x21: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B4 : 0x05B4) : ((state & LAYOUT_SHIFT) ? 0x0024 : 0x0034);
    case 0x22: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B5 : 0x05B5) : ((state & LAYOUT_SHIFT) ? 0x0025 : 0x0035);
    case 0x23: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B7 : 0x05B7) : ((state & LAYOUT_SHIFT) ? 0x201D : 0x0036);
    case 0x24: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B8 : 0x05B8) : ((state & LAYOUT_SHIFT) ? 0x20AA : 0x0037);
    case 0x25: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BB : 0x05BB) : ((state & LAYOUT_SHIFT) ? 0x002A : 0x0038);
    case 0x26: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B6 : 0x05B6) : ((state & LAYOUT_SHIFT) ? 0x0029 : 0x0039);
    case 0x27: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B0 : 0x05B0) : ((state & LAYOUT_SHIFT) ? 0x0028 : 0x0030);
    case 0x2C: return (state & LAYOUT_ALT) ? 0xA0 : 0x20;
    case 0x2D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x002D : 0x002B) : ((state & LAYOUT_SHIFT) ? 0x2014 : 0x2013);
    case 0x2E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x002B : 0x002D) : ((state & LAYOUT_SHIFT) ? 0x002B : 0x003D);
    case 0x2F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007D : 0x005D) : ((state & LAYOUT_SHIFT) ? 0x2018 : 0x05F2);
    case 0x30: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007B : 0x005B) : ((state & LAYOUT_SHIFT) ? 0x2019 : 0x05F205B7L);
    case 0x31: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BF : 0x05BE) : ((state & LAYOUT_SHIFT) ? 0x002D : 0x05BF);
    case 0x32: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BF : 0x05BE) : ((state & LAYOUT_SHIFT) ? 0x002D : 0x05BF);
    case 0x33: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05B0 : 0x05B0) : ((state & LAYOUT_SHIFT) ? 0x003A : 0x003B);
    case 0x34: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x201D : 0x2019) : ((state & LAYOUT_SHIFT) ? 0x05F4 : 0x05F3);
    case 0x35: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BC : 0x05BC) : ((state & LAYOUT_SHIFT) ? 0x05BC : 0x05BC);
    case 0x36: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x201E : 0x201A) : ((state & LAYOUT_SHIFT) ? 0x003E : 0x002C);
    case 0x37: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x2026 : 0x05BC) : ((state & LAYOUT_SHIFT) ? 0x003C : 0x002E);
    case 0x38: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x201C : 0x2018) : ((state & LAYOUT_SHIFT) ? 0x003F : 0x002F);
    case 0x64: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x2019 : 0x2018) : ((state & LAYOUT_SHIFT) ? 0x003C : 0x003E);
    case 0x87: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x005F : 0x05BE) : ((state & LAYOUT_SHIFT) ? 0x005F : 0x05BF);
    case 0x89: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x05BF : 0x00A5) : ((state & LAYOUT_SHIFT) ? 0x002D : 0x00A5);
    default: return 0;
  }
}
