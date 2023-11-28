#include "layout_ipa.h"
#include "layouts.h"

unsigned long layout_ipa(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0x0251 : 0x0061; // ɑ a
    case 0x05: return (state & LAYOUT_SHIFT) ? 0x03B2 : 0x0062; // β b
    case 0x06: return (state & LAYOUT_SHIFT) ? 0x00E7 : 0x0063; // ç c
    case 0x07: return (state & LAYOUT_SHIFT) ? 0x00F0 : 0x0064; // ð d
    case 0x08: return (state & LAYOUT_SHIFT) ? 0x025B : 0x0065; // ɛ e
    case 0x09: return (state & LAYOUT_SHIFT) ? 0x0271 : 0x0066; // ɱ f
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0x0263 : 0x0067; // ɣ g
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0x0265 : 0x0068; // ɥ h
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0x026A : 0x0069; // ɪ i
    case 0x0D: return (state & LAYOUT_SHIFT) ? 0x0272 : 0x006A; // ɲ j
    case 0x0E: return (state & LAYOUT_SHIFT) ? 0x026C : 0x006B; // ɬ k
    case 0x0F: return (state & LAYOUT_SHIFT) ? 0x028E : 0x006C; // ʎ l
    case 0x10: return (state & LAYOUT_SHIFT) ? 0x026F : 0x006D; // ɯ m
    case 0x11: return (state & LAYOUT_SHIFT) ? 0x014B : 0x006E; // ŋ n
    case 0x12: return (state & LAYOUT_SHIFT) ? 0x0254 : 0x006F; // ɔ o
    case 0x13: return (state & LAYOUT_SHIFT) ? 0x028B : 0x0070; // ʋ p
    case 0x14: return (state & LAYOUT_SHIFT) ? 0x0252 : 0x0071; // ɒ q
    case 0x15: return (state & LAYOUT_SHIFT) ? 0x0281 : 0x0072; // ʁ r
    case 0x16: return (state & LAYOUT_SHIFT) ? 0x0283 : 0x0073; // ʃ s
    case 0x17: return (state & LAYOUT_SHIFT) ? 0x03B8 : 0x0074; // θ t
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x028A : 0x0075; // ʊ u
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x028C : 0x0076; // ʌ v
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0x028D : 0x0077; // ʍ w
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0x03C7 : 0x0078; // χ x
    case 0x1C: return (state & LAYOUT_SHIFT) ? 0x028F : 0x0079; // ʏ y
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0x0292 : 0x007A; // ʒ z
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0xA71C : 0x0268; // ꜜ ɨ
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x0259 : 0x00F8; // ə ø
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x0301 : 0x025C; // ́ ɜ
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x0304 : 0x027E; // ̄ ɾ
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x0300 : 0x026B; // ̀ ɫ
    case 0x23: return (state & LAYOUT_SHIFT) ? 0xA71B : 0x0250; // ꜛ ɐ
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x00E6 : 0x0264; // æ ɤ
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x002A : 0x0275; // * ɵ
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x0028 : 0x0153; // ( œ
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x0029 : 0x0325; // ) ̥
    case 0x2C: return 0x20; // space
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x035C : 0x002D; // ͜ -
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x032F : 0x0329; // ̯ ̩
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x007B : 0x005B; // { [
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x007D : 0x005D; // } ]
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x2016 : 0x007C; // ‖ | (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x2016 : 0x007C; // ‖ | (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x02D0 : 0x02B2; // ː ʲ
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x02CC : 0x02C8; // ˌ ˈ
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x0303 : 0x02DE; // ̃ ˞
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x003C : 0x002C; // < ,
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x003E : 0x002E; // > .
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x0294 : 0x002F; // ʔ /
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x003E : 0x003C; // > < (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F : 0x007C; // _ | (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x2016 : 0x00A5; // ‖ ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_ipa_alt(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0x033A : 0x02B0; // ̺ ʰ
    case 0x05: return (state & LAYOUT_SHIFT) ? 0x0299 : 0x0253; // ʙ ɓ
    case 0x06: return (state & LAYOUT_SHIFT) ? 0x0339 : 0x031C; // ̹ ̜
    case 0x07: return (state & LAYOUT_SHIFT) ? 0x032A : 0x0256; // ̪ ɖ
    case 0x08: return (state & LAYOUT_SHIFT) ? 0x025D : 0x025A; // ɝ ɚ
    case 0x09: return (state & LAYOUT_SHIFT) ? 0x0284 : 0x0257; // ʄ ɗ
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0x0262 : 0x0261; // ɢ ɡ
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0x029C : 0x0266; // ʜ ɦ
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0x1D7B : 0x0268; // ᵻ ɨ
    case 0x0D: return (state & LAYOUT_SHIFT) ? 0x025F : 0x029D; // ɟ ʝ
    case 0x0E: return (state & LAYOUT_SHIFT) ? 0x026E : 0x026D; // ɮ ɭ
    case 0x0F: return (state & LAYOUT_SHIFT) ? 0x029F : 0x027A; // ʟ ɺ
    case 0x10: return (state & LAYOUT_SHIFT) ? 0x0270 : 0x207F; // ɰ ⁿ
    case 0x11: return (state & LAYOUT_SHIFT) ? 0x0274 : 0x0273; // ɴ ɳ
    case 0x12: return (state & LAYOUT_SHIFT) ? 0x0298 : 0x02E1; // ʘ ˡ
    case 0x13: return (state & LAYOUT_SHIFT) ? 0x2198 : 0x0278; // ↘ ɸ
    case 0x14: return (state & LAYOUT_SHIFT) ? 0x033B : 0x02E0; // ̻ ˠ
    case 0x15: return (state & LAYOUT_SHIFT) ? 0x0280 : 0x0279; // ʀ ɹ
    case 0x16: return (state & LAYOUT_SHIFT) ? 0x0282 : 0x0255; // ʂ ɕ
    case 0x17: return (state & LAYOUT_SHIFT) ? 0x2197 : 0x0288; // ↗ ʈ
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x1D7F : 0x0289; // ᵿ ʉ
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x2C71 : 0x028B; // ⱱ ʋ
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0x033C : 0x02B7; // ̼ ʷ
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0x0127 : 0x0267; // ħ ɧ
    case 0x1C: return (state & LAYOUT_SHIFT) ? 0x029B : 0x0260; // ʛ ɠ
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0x0290 : 0x0291; // ʐ ʑ
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x203C : 0x01C3; // ‼ ǃ
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x0258 : 0x033D; // ɘ ̽
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x030B : 0x025E; // ̋ ɞ
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x027B : 0x027D; // ɻ ɽ
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x030F : 0x0334; // ̏ ̴
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x030C : 0x0302; // ̌ ̂
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x0276 : 0x1DC8; // ɶ ᷈
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x1DC4 : 0x1DC5; // ᷄ ᷅
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x0361 : 0x031A; // ͡ ̚
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x035C : 0x032C; // ͜ ̬
    case 0x2C: return 0xA0; // nbsp
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x0320 : 0x203F; // ̠ ‿
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x031F : 0x01C2; // ̟ ǂ
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x0318 : 0x031D; // ̘ ̝
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x0319 : 0x031E; // ̙ ̞
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x01C1 : 0x01C0; // ǁ ǀ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x01C1 : 0x01C0; // ǁ ǀ (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x02D1 : 0x0306; // ˑ ̆
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x0308 : 0x02BC; // ̈ ʼ
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x0330 : 0x0324; // ̰ ̤
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x02A2 : 0x27E8; // ʢ ⟨
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x02A1 : 0x27E9; // ʡ ⟩
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x0295 : 0x02E4; // ʕ ˤ
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x27E9 : 0x27E8; // ⟩ ⟨ (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F : 0x01C0; // _ ǀ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x01C1 : 0x00A5; // ǁ ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_ipa_layered(unsigned char code, unsigned char state) {
  if (state & LAYOUT_ALT) return layout_ipa_alt(code, state);
  return layout_ipa(code, state);
}
