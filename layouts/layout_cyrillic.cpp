#include "layout_cyrillic.h"
#include "layouts.h"

unsigned long layout_cyrillic(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x0410 : 0x0430; // А а
    case 0x05: return (state & LAYOUT_CL_SH) ? 0x0411 : 0x0431; // Б б
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x0426 : 0x0446; // Ц ц
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x0414 : 0x0434; // Д д
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0415 : 0x0435; // Е е
    case 0x09: return (state & LAYOUT_CL_SH) ? 0x0424 : 0x0444; // Ф ф
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x0413 : 0x0433; // Г г
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x0427 : 0x0447; // Ч ч
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x0418 : 0x0438; // И и
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0x0419 : 0x0439; // Й й
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x041A : 0x043A; // К к
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x041B : 0x043B; // Л л
    case 0x10: return (state & LAYOUT_CL_SH) ? 0x041C : 0x043C; // М м
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x041D : 0x043D; // Н н
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x041E : 0x043E; // О о
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x041F : 0x043F; // П п
    case 0x14: return (state & LAYOUT_CL_SH) ? 0x042F : 0x044F; // Я я
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x0420 : 0x0440; // Р р
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x0421 : 0x0441; // С с
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x0422 : 0x0442; // Т т
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x0423 : 0x0443; // У у
    case 0x19: return (state & LAYOUT_CL_SH) ? 0x0416 : 0x0436; // Ж ж
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x0412 : 0x0432; // В в
    case 0x1B: return (state & LAYOUT_CL_SH) ? 0x0425 : 0x0445; // Х х
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x042B : 0x044B; // Ы ы
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x0417 : 0x0437; // З з
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x0021 : 0x0031; // ! 1
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x0022 : 0x0032; // " 2
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x2116 : 0x0033; // № 3
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x00A4 : 0x0034; // ¤ 4
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x0025 : 0x0035; // % 5
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x003F : 0x0036; // ? 6
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x0027 : 0x0037; // ' 7
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x002A : 0x0038; // * 8
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x0028 : 0x0039; // ( 9
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x0029 : 0x0030; // ) 0
    case 0x2C: return 0x20; // space
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x005F : 0x002D; // _ -
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x002C : 0x002E; // , .
    case 0x2F: return (state & LAYOUT_CL_SH) ? 0x0428 : 0x0448; // Ш ш
    case 0x30: return (state & LAYOUT_CL_SH) ? 0x0429 : 0x0449; // Щ щ
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x002F : 0x005C; // / \ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x002F : 0x005C; // / \ (ISO/JIS)
    case 0x33: return (state & LAYOUT_CL_SH) ? 0x042A : 0x044A; // Ъ ъ
    case 0x34: return (state & LAYOUT_CL_SH) ? 0x042D : 0x044D; // Э э
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x007E : 0x0060; // ~ `
    case 0x36: return (state & LAYOUT_CL_SH) ? 0x042C : 0x044C; // Ь ь
    case 0x37: return (state & LAYOUT_CL_SH) ? 0x042E : 0x044E; // Ю ю
    case 0x38: return (state & LAYOUT_CL_SH) ? 0x0401 : 0x0451; // Ё ё
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x003E : 0x003C; // > < (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F : 0x005C; // _ \ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x002F : 0x00A5; // / ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_cyrillic_alt(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x04D8 : 0x04D9; // Ә ә
    case 0x05: return (state & LAYOUT_CL_SH) ? 0x04B8 : 0x04B9; // Ҹ ҹ
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x040F : 0x045F; // Џ џ
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x0492 : 0x0493; // Ғ ғ
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x040D : 0x045D; // Ѝ ѝ
    case 0x09: return (state & LAYOUT_CL_SH) ? 0x0403 : 0x0453; // Ѓ ѓ
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x0490 : 0x0491; // Ґ ґ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x04B6 : 0x04B7; // Ҷ ҷ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x0406 : 0x0456; // І і
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0x0407 : 0x0457; // Ї ї
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x049A : 0x049B; // Қ қ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x0409 : 0x0459; // Љ љ
    case 0x10: return (state & LAYOUT_CL_SH) ? 0x04A4 : 0x04A5; // Ҥ ҥ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x04A2 : 0x04A3; // Ң ң
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x04E8 : 0x04E9; // Ө ө
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x04BA : 0x04BB; // Һ һ
    case 0x14: return (state & LAYOUT_CL_SH) ? 0x0408 : 0x0458; // Ј ј
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x0494 : 0x0495; // Ҕ ҕ
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x04AA : 0x04AB; // Ҫ ҫ
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x04AE : 0x04AF; // Ү ү
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x040E : 0x045E; // Ў ў
    case 0x19: return (state & LAYOUT_CL_SH) ? 0x0496 : 0x0497; // Җ җ
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x04E2 : 0x04E3; // Ӣ ӣ
    case 0x1B: return (state & LAYOUT_CL_SH) ? 0x04B2 : 0x04B3; // Ҳ ҳ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x04EE : 0x04EF; // Ӯ ӯ
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x0498 : 0x0499; // Ҙ ҙ
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x201E : 0x00A7; // „ §
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x201C : 0x0040; // “ @
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x20B8 : 0x0023; // ₸ #
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x20AE : 0x0024; // ₮ $
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x20AC : 0x003C; // € <
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x201A : 0x003E; // ‚ >
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x2018 : 0x005B; // ‘ [
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x20BD : 0x005D; // ₽ ]
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x20B4 : 0x007B; // ₴ {
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x20C0 : 0x007D; // ⃀ }
    case 0x2C: return 0xA0; // nbsp
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x002B : 0x003D; // + =
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x003B : 0x003A; // ; :
    case 0x2F: return (state & LAYOUT_CL_SH) ? 0x040B : 0x045B; // Ћ ћ
    case 0x30: return (state & LAYOUT_CL_SH) ? 0x0402 : 0x0452; // Ђ ђ
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x007C : 0x00A5; // | ¥ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x007C : 0x00A5; // | ¥ (ISO/JIS)
    case 0x33: return (state & LAYOUT_CL_SH) ? 0x040A : 0x045A; // Њ њ
    case 0x34: return (state & LAYOUT_CL_SH) ? 0x0404 : 0x0454; // Є є
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x00AC : 0x005E; // ¬ ^
    case 0x36: return (state & LAYOUT_CL_SH) ? 0x040C : 0x045C; // Ќ ќ
    case 0x37: return (state & LAYOUT_CL_SH) ? 0x04A0 : 0x04A1; // Ҡ ҡ
    case 0x38: return (state & LAYOUT_CL_SH) ? 0x049C : 0x049D; // Ҝ ҝ
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x2265 : 0x2264; // ≥ ≤ (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F : 0x00A5; // _ ¥ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x007C : 0x00A5; // | ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_cyrillic_layered(unsigned char code, unsigned char state) {
  if (state & LAYOUT_ALT) return layout_cyrillic_alt(code, state);
  return layout_cyrillic(code, state);
}
