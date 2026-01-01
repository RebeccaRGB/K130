#include "layout_dead_keys.h"
#include "layouts.h"

unsigned long layout_dead_key(unsigned char code, unsigned char state) {
  switch (state & LAYOUT_DEAD_KEY) {
    case LAYOUT_DEAD_GRAVE:    return layout_dead_grave    (code, state);
    case LAYOUT_DEAD_ACUTE:    return layout_dead_acute    (code, state);
    case LAYOUT_DEAD_CIRCUM:   return layout_dead_circum   (code, state);
    case LAYOUT_DEAD_TILDE:    return layout_dead_tilde    (code, state);
    case LAYOUT_DEAD_MACRON:   return layout_dead_macron   (code, state);
    case LAYOUT_DEAD_BREVE:    return layout_dead_breve    (code, state);
    case LAYOUT_DEAD_DOTABOVE: return layout_dead_dotabove (code, state);
    case LAYOUT_DEAD_DIERESIS: return layout_dead_dieresis (code, state);
    case LAYOUT_DEAD_RING:     return layout_dead_ring     (code, state);
    case LAYOUT_DEAD_DBLACUTE: return layout_dead_dblacute (code, state);
    case LAYOUT_DEAD_CARON:    return layout_dead_caron    (code, state);
    case LAYOUT_DEAD_DOTBELOW: return layout_dead_dotbelow (code, state);
    case LAYOUT_DEAD_CEDILLA:  return layout_dead_cedilla  (code, state);
    case LAYOUT_DEAD_OGONEK:   return layout_dead_ogonek   (code, state);
    case LAYOUT_DEAD_SLASH:    return layout_dead_slash    (code, state);
    default: return 0;
  }
}

unsigned long layout_dead_grave(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x00C0 : 0x00E0; // À à
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x00C8 : 0x00E8; // È è
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x00CC : 0x00EC; // Ì ì
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x01F8 : 0x01F9; // Ǹ ǹ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x00D2 : 0x00F2; // Ò ò
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x00D9 : 0x00F9; // Ù ù
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x1E80 : 0x1E81; // Ẁ ẁ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x1EF2 : 0x1EF3; // Ỳ ỳ
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0300 : 0x02CB; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_acute(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x00C1 : 0x00E1; // Á á
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x0106 : 0x0107; // Ć ć
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x00C9 : 0x00E9; // É é
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x01F4 : 0x01F5; // Ǵ ǵ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x00CD : 0x00ED; // Í í
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x1E30 : 0x1E31; // Ḱ ḱ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x0139 : 0x013A; // Ĺ ĺ
    case 0x10: return (state & LAYOUT_CL_SH) ? 0x1E3E : 0x1E3F; // Ḿ ḿ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x0143 : 0x0144; // Ń ń
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x00D3 : 0x00F3; // Ó ó
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x1E54 : 0x1E55; // Ṕ ṕ
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x0154 : 0x0155; // Ŕ ŕ
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x015A : 0x015B; // Ś ś
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x00DA : 0x00FA; // Ú ú
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x1E82 : 0x1E83; // Ẃ ẃ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x00DD : 0x00FD; // Ý ý
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x0179 : 0x017A; // Ź ź
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0301 : 0x00B4; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_circum(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x00C2 : 0x00E2; // Â â
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x0108 : 0x0109; // Ĉ ĉ
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x00CA : 0x00EA; // Ê ê
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x011C : 0x011D; // Ĝ ĝ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x0124 : 0x0125; // Ĥ ĥ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x00CE : 0x00EE; // Î î
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0x0134 : 0x0135; // Ĵ ĵ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x00D4 : 0x00F4; // Ô ô
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x015C : 0x015D; // Ŝ ŝ
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x00DB : 0x00FB; // Û û
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x0174 : 0x0175; // Ŵ ŵ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x0176 : 0x0177; // Ŷ ŷ
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x1E90 : 0x1E91; // Ẑ ẑ
    case 0x1E: return 0x00B9; // ¹
    case 0x1F: return 0x00B2; // ²
    case 0x20: return 0x00B3; // ³
    case 0x21: return 0x2074; // ⁴
    case 0x22: return 0x2075; // ⁵
    case 0x23: return 0x2076; // ⁶
    case 0x24: return 0x2077; // ⁷
    case 0x25: return 0x2078; // ⁸
    case 0x26: return 0x2079; // ⁹
    case 0x27: return 0x2070; // ⁰
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0302 : 0x02C6; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_tilde(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x00C3 : 0x00E3; // Ã ã
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x1EBC : 0x1EBD; // Ẽ ẽ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x0128 : 0x0129; // Ĩ ĩ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x00D1 : 0x00F1; // Ñ ñ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x00D5 : 0x00F5; // Õ õ
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x0168 : 0x0169; // Ũ ũ
    case 0x19: return (state & LAYOUT_CL_SH) ? 0x1E7C : 0x1E7D; // Ṽ ṽ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x1EF8 : 0x1EF9; // Ỹ ỹ
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0303 : 0x02DC; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_macron(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x0100 : 0x0101; // Ā ā
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0112 : 0x0113; // Ē ē
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x1E20 : 0x1E21; // Ḡ ḡ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x012A : 0x012B; // Ī ī
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x014C : 0x014D; // Ō ō
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x016A : 0x016B; // Ū ū
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x0232 : 0x0233; // Ȳ ȳ
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0304 : 0x00AF; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_breve(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x0102 : 0x0103; // Ă ă
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0114 : 0x0115; // Ĕ ĕ
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x011E : 0x011F; // Ğ ğ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x012C : 0x012D; // Ĭ ĭ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x014E : 0x014F; // Ŏ ŏ
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x016C : 0x016D; // Ŭ ŭ
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0306 : 0x02D8; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_dotabove(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x0226 : 0x0227; // Ȧ ȧ
    case 0x05: return (state & LAYOUT_CL_SH) ? 0x1E02 : 0x1E03; // Ḃ ḃ
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x010A : 0x010B; // Ċ ċ
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x1E0A : 0x1E0B; // Ḋ ḋ
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0116 : 0x0117; // Ė ė
    case 0x09: return (state & LAYOUT_CL_SH) ? 0x1E1E : 0x1E1F; // Ḟ ḟ
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x0120 : 0x0121; // Ġ ġ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x1E22 : 0x1E23; // Ḣ ḣ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x0130 : 0x0131; // İ ı
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0      : 0x0237; //   ȷ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x013F : 0x0140; // Ŀ ŀ
    case 0x10: return (state & LAYOUT_CL_SH) ? 0x1E40 : 0x1E41; // Ṁ ṁ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x1E44 : 0x1E45; // Ṅ ṅ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x022E : 0x022F; // Ȯ ȯ
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x1E56 : 0x1E57; // Ṗ ṗ
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x1E58 : 0x1E59; // Ṙ ṙ
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x1E60 : 0x1E61; // Ṡ ṡ
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x1E6A : 0x1E6B; // Ṫ ṫ
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x1E86 : 0x1E87; // Ẇ ẇ
    case 0x1B: return (state & LAYOUT_CL_SH) ? 0x1E8A : 0x1E8B; // Ẋ ẋ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x1E8E : 0x1E8F; // Ẏ ẏ
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x017B : 0x017C; // Ż ż
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0307 : 0x02D9; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_dieresis(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x00C4 : 0x00E4; // Ä ä
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x00CB : 0x00EB; // Ë ë
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x1E26 : 0x1E27; // Ḧ ḧ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x00CF : 0x00EF; // Ï ï
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0x0132 : 0x0133; // Ĳ ĳ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x00D6 : 0x00F6; // Ö ö
    case 0x17: return (state & LAYOUT_CL_SH) ? 0      : 0x1E97; //   ẗ
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x00DC : 0x00FC; // Ü ü
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x1E84 : 0x1E85; // Ẅ ẅ
    case 0x1B: return (state & LAYOUT_CL_SH) ? 0x1E8C : 0x1E8D; // Ẍ ẍ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x0178 : 0x00FF; // Ÿ ÿ
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0308 : 0x00A8; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_ring(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x00C5 : 0x00E5; // Å å
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x016E : 0x016F; // Ů ů
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0      : 0x1E98; //   ẘ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0      : 0x1E99; //   ẙ
    case 0x2C: return (state & LAYOUT_ALT) ? 0x030A : 0x02DA; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_dblacute(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x0150 : 0x0151; // Ő ő
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x0170 : 0x0171; // Ű ű
    case 0x2C: return (state & LAYOUT_ALT) ? 0x030B : 0x02DD; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_caron(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x01CD : 0x01CE; // Ǎ ǎ
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x010C : 0x010D; // Č č
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x010E : 0x010F; // Ď ď
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x011A : 0x011B; // Ě ě
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x01E6 : 0x01E7; // Ǧ ǧ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x021E : 0x021F; // Ȟ ȟ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x01CF : 0x01D0; // Ǐ ǐ
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0      : 0x01F0; //   ǰ
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x01E8 : 0x01E9; // Ǩ ǩ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x013D : 0x013E; // Ľ ľ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x0147 : 0x0148; // Ň ň
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x01D1 : 0x01D2; // Ǒ ǒ
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x0158 : 0x0159; // Ř ř
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x0160 : 0x0161; // Š š
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x0164 : 0x0165; // Ť ť
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x01D3 : 0x01D4; // Ǔ ǔ
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x017D : 0x017E; // Ž ž
    case 0x1E: return 0x2081; // ₁
    case 0x1F: return 0x2082; // ₂
    case 0x20: return 0x2083; // ₃
    case 0x21: return 0x2084; // ₄
    case 0x22: return 0x2085; // ₅
    case 0x23: return 0x2086; // ₆
    case 0x24: return 0x2087; // ₇
    case 0x25: return 0x2088; // ₈
    case 0x26: return 0x2089; // ₉
    case 0x27: return 0x2080; // ₀
    case 0x2C: return (state & LAYOUT_ALT) ? 0x030C : 0x02C7; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_dotbelow(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x1EA0 : 0x1EA1; // Ạ ạ
    case 0x05: return (state & LAYOUT_CL_SH) ? 0x1E04 : 0x1E05; // Ḅ ḅ
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x1E0C : 0x1E0D; // Ḍ ḍ
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x1EB8 : 0x1EB9; // Ẹ ẹ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x1E24 : 0x1E25; // Ḥ ḥ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x1ECA : 0x1ECB; // Ị ị
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x1E32 : 0x1E33; // Ḳ ḳ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x1E36 : 0x1E37; // Ḷ ḷ
    case 0x10: return (state & LAYOUT_CL_SH) ? 0x1E42 : 0x1E43; // Ṃ ṃ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x1E46 : 0x1E47; // Ṇ ṇ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x1ECC : 0x1ECD; // Ọ ọ
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x1E5A : 0x1E5B; // Ṛ ṛ
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x1E62 : 0x1E63; // Ṣ ṣ
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x1E6C : 0x1E6D; // Ṭ ṭ
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x1EE4 : 0x1EE5; // Ụ ụ
    case 0x19: return (state & LAYOUT_CL_SH) ? 0x1E7E : 0x1E7F; // Ṿ ṿ
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x1E88 : 0x1E89; // Ẉ ẉ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x1EF4 : 0x1EF5; // Ỵ ỵ
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x1E92 : 0x1E93; // Ẓ ẓ
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0323 : 0x002E; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_cedilla(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x00C7 : 0x00E7; // Ç ç
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x1E10 : 0x1E11; // Ḑ ḑ
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0228 : 0x0229; // Ȩ ȩ
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x0122 : 0x0123; // Ģ ģ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x1E28 : 0x1E29; // Ḩ ḩ
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x0136 : 0x0137; // Ķ ķ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x013B : 0x013C; // Ļ ļ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x0145 : 0x0146; // Ņ ņ
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x01A0 : 0x01A1; // Ơ ơ
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x0156 : 0x0157; // Ŗ ŗ
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x015E : 0x015F; // Ş ş
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x0162 : 0x0163; // Ţ ţ
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x01AF : 0x01B0; // Ư ư
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0327 : 0x00B8; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_ogonek(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x0104 : 0x0105; // Ą ą
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0118 : 0x0119; // Ę ę
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x012E : 0x012F; // Į į
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x01EA : 0x01EB; // Ǫ ǫ
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x0218 : 0x0219; // Ș ș
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x021A : 0x021B; // Ț ț
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x0172 : 0x0173; // Ų ų
    case 0x2C: return (state & LAYOUT_ALT) ? 0x0328 : 0x02DB; // combining / spacing
    default: return 0;
  }
}

unsigned long layout_dead_slash(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x023A : 0x2C65; // Ⱥ ⱥ
    case 0x05: return (state & LAYOUT_CL_SH) ? 0x0243 : 0x0180; // Ƀ ƀ
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x023B : 0x023C; // Ȼ ȼ
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x0110 : 0x0111; // Đ đ
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0246 : 0x0247; // Ɇ ɇ
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x01E4 : 0x01E5; // Ǥ ǥ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x0126 : 0x0127; // Ħ ħ
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x0197 : 0x0268; // Ɨ ɨ
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0x0248 : 0x0249; // Ɉ ɉ
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0xA740 : 0xA741; // Ꝁ ꝁ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x0141 : 0x0142; // Ł ł
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x00D8 : 0x00F8; // Ø ø
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x2C63 : 0x1D7D; // Ᵽ ᵽ
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x024C : 0x024D; // Ɍ ɍ
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x0166 : 0x0167; // Ŧ ŧ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x024E : 0x024F; // Ɏ ɏ
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x01B5 : 0x01B6; // Ƶ ƶ
    case 0x1E: return 0x215B; // ⅛
    case 0x1F: return 0x00BC; // ¼
    case 0x20: return 0x2153; // ⅓
    case 0x21: return 0x215C; // ⅜
    case 0x22: return 0x00BD; // ½
    case 0x23: return 0x215D; // ⅝
    case 0x24: return 0x2154; // ⅔
    case 0x25: return 0x00BE; // ¾
    case 0x26: return 0x215E; // ⅞
    case 0x27: return 0x215F; // ⅟
    case 0x2C: return 0x2044; // combining / spacing
    default: return 0;
  }
}
