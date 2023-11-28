#include "layout_arabic.h"
#include "layouts.h"

unsigned long layout_arabic_qwerty(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x064B : 0x064E) : ((state & LAYOUT_SHIFT) ? 0x0622 : 0x0627);
    case 0x05: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0679 : 0x067E) : ((state & LAYOUT_SHIFT) ? 0x067E : 0x0628);
    case 0x06: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0686 : 0x062B) : ((state & LAYOUT_SHIFT) ? 0x0636 : 0x0635);
    case 0x07: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0688 : 0x0636) : ((state & LAYOUT_SHIFT) ? 0x0630 : 0x062F);
    case 0x08: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06D1 : 0x06CC) : ((state & LAYOUT_SHIFT) ? 0x063A : 0x0639);
    case 0x09: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06A4 : 0x06A4) : ((state & LAYOUT_SHIFT) ? 0x0642 : 0x0641);
    case 0x0A: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06AF : 0x0639) : ((state & LAYOUT_SHIFT) ? 0x0639 : 0x063A);
    case 0x0B: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0686 : 0x0647) : ((state & LAYOUT_SHIFT) ? 0x062E : 0x062D);
    case 0x0C: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x064D : 0x0650) : ((state & LAYOUT_SHIFT) ? 0x0649 : 0x064A);
    case 0x0D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0698 : 0x062E) : ((state & LAYOUT_SHIFT) ? 0x0686 : 0x062C);
    case 0x0E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06A9 : 0x062E) : ((state & LAYOUT_SHIFT) ? 0x06AF : 0x0643);
    case 0x0F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0654 : 0x0655) : ((state & LAYOUT_SHIFT) ? 0x0653 : 0x0644);
    case 0x10: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0622 : 0x0622) : ((state & LAYOUT_SHIFT) ? 0x0622 : 0x0645);
    case 0x11: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06BA : 0x06C1) : ((state & LAYOUT_SHIFT) ? 0x062B : 0x0646);
    case 0x12: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06D5 : 0x0652) : ((state & LAYOUT_SHIFT) ? 0x0629 : 0x0647);
    case 0x13: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x067E : 0x0651) : ((state & LAYOUT_SHIFT) ? 0x062A : 0x0629);
    case 0x14: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06AF : 0x06A4) : ((state & LAYOUT_SHIFT) ? 0x06A4 : 0x0642);
    case 0x15: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0691 : 0x063A) : ((state & LAYOUT_SHIFT) ? 0x0632 : 0x0631);
    case 0x16: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0651 : 0x0635) : ((state & LAYOUT_SHIFT) ? 0x0634 : 0x0633);
    case 0x17: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0629 : 0x0637) : ((state & LAYOUT_SHIFT) ? 0x062B : 0x062A);
    case 0x18: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x064C : 0x064F) : ((state & LAYOUT_SHIFT) ? 0x06D2 : 0x0648);
    case 0x19: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06A4 : 0x0638) : ((state & LAYOUT_SHIFT) ? 0x062F : 0x0630);
    case 0x1A: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0651 : 0x0651) : ((state & LAYOUT_SHIFT) ? 0x0651 : 0x0634);
    case 0x1B: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x06D3 : 0x062D) : ((state & LAYOUT_SHIFT) ? 0x062D : 0x062E);
    case 0x1C: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0649 : 0x062B) : ((state & LAYOUT_SHIFT) ? 0x0638 : 0x0637);
    case 0x1D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0698 : 0x0638) : ((state & LAYOUT_SHIFT) ? 0x0698 : 0x0632);
    case 0x1E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0021 : 0x0625) : ((state & LAYOUT_SHIFT) ? 0x0021 : 0x0661);
    case 0x1F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x066D : 0x274A) : ((state & LAYOUT_SHIFT) ? 0x0621 : 0x0662);
    case 0x20: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0023 : 0x0023) : ((state & LAYOUT_SHIFT) ? 0x0623 : 0x0663);
    case 0x21: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x20AC : 0x0024) : ((state & LAYOUT_SHIFT) ? 0x0622 : 0x0664);
    case 0x22: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x066A : 0x066A) : ((state & LAYOUT_SHIFT) ? 0x0625 : 0x0665);
    case 0x23: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0026 : 0x0026) : ((state & LAYOUT_SHIFT) ? 0x0626 : 0x0666);
    case 0x24: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x005E : 0x005E) : ((state & LAYOUT_SHIFT) ? 0x0624 : 0x0667);
    case 0x25: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x002A : 0x002A) : ((state & LAYOUT_SHIFT) ? 0x0649 : 0x0668);
    case 0x26: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0029 : 0x0029) : ((state & LAYOUT_SHIFT) ? 0x0029 : 0x0669);
    case 0x27: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0028 : 0x0028) : ((state & LAYOUT_SHIFT) ? 0x0028 : 0x0660);
    case 0x2C: return (state & LAYOUT_ALT) ? 0xA0 : 0x20;
    case 0x2D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x005F : 0x005F) : ((state & LAYOUT_SHIFT) ? 0x005F : 0x002D);
    case 0x2E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x002B : 0x002B) : ((state & LAYOUT_SHIFT) ? 0x002B : 0x003D);
    case 0x2F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007D : 0x005D) : ((state & LAYOUT_SHIFT) ? 0x007D : 0x062B);
    case 0x30: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007B : 0x005B) : ((state & LAYOUT_SHIFT) ? 0x007B : 0x0638);
    case 0x31: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0622 : 0x0623) : ((state & LAYOUT_SHIFT) ? 0x0625 : 0x0621);
    case 0x32: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0622 : 0x0623) : ((state & LAYOUT_SHIFT) ? 0x0625 : 0x0621);
    case 0x33: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x066B : 0xA789) : ((state & LAYOUT_SHIFT) ? 0x003A : 0x061B);
    case 0x34: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x066C : 0x0671) : ((state & LAYOUT_SHIFT) ? 0x0022 : 0x0027);
    case 0x35: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x003C : 0x003E) : ((state & LAYOUT_SHIFT) ? 0x0640 : 0x0640);
    case 0x36: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x274A : 0x00BB) : ((state & LAYOUT_SHIFT) ? 0x003E : 0x060C);
    case 0x37: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x066D : 0x00AB) : ((state & LAYOUT_SHIFT) ? 0x003C : 0x002E);
    case 0x38: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x005C : 0x002F) : ((state & LAYOUT_SHIFT) ? 0x061F : 0x005C);
    case 0x64: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x00AB : 0x00BB) : ((state & LAYOUT_SHIFT) ? 0x003C : 0x003E);
    case 0x87: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x005F : 0x0623) : ((state & LAYOUT_SHIFT) ? 0x005F : 0x0621);
    case 0x89: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x0622 : 0x00A5) : ((state & LAYOUT_SHIFT) ? 0x0625 : 0x00A5);
    default: return 0;
  }
}
