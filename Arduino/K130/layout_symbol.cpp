#include "layout_symbol.h"
#include "layouts.h"

unsigned long layout_symbol(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_CL_SH) ? 0x0391 : 0x03B1; // Α α
    case 0x05: return (state & LAYOUT_CL_SH) ? 0x0392 : 0x03B2; // Β β
    case 0x06: return (state & LAYOUT_CL_SH) ? 0x03A7 : 0x03C7; // Χ χ
    case 0x07: return (state & LAYOUT_CL_SH) ? 0x0394 : 0x03B4; // Δ δ
    case 0x08: return (state & LAYOUT_CL_SH) ? 0x0395 : 0x03B5; // Ε ε
    case 0x09: return (state & LAYOUT_CL_SH) ? 0x03A6 : 0x03C6; // Φ φ
    case 0x0A: return (state & LAYOUT_CL_SH) ? 0x0393 : 0x03B3; // Γ γ
    case 0x0B: return (state & LAYOUT_CL_SH) ? 0x0397 : 0x03B7; // Η η
    case 0x0C: return (state & LAYOUT_CL_SH) ? 0x0399 : 0x03B9; // Ι ι
    case 0x0D: return (state & LAYOUT_CL_SH) ? 0x03D1 : 0x03D5; // ϑ ϕ
    case 0x0E: return (state & LAYOUT_CL_SH) ? 0x039A : 0x03BA; // Κ κ
    case 0x0F: return (state & LAYOUT_CL_SH) ? 0x039B : 0x03BB; // Λ λ
    case 0x10: return (state & LAYOUT_CL_SH) ? 0x039C : 0x03BC; // Μ μ
    case 0x11: return (state & LAYOUT_CL_SH) ? 0x039D : 0x03BD; // Ν ν
    case 0x12: return (state & LAYOUT_CL_SH) ? 0x039F : 0x03BF; // Ο ο
    case 0x13: return (state & LAYOUT_CL_SH) ? 0x03A0 : 0x03C0; // Π π
    case 0x14: return (state & LAYOUT_CL_SH) ? 0x0398 : 0x03B8; // Θ θ
    case 0x15: return (state & LAYOUT_CL_SH) ? 0x03A1 : 0x03C1; // Ρ ρ
    case 0x16: return (state & LAYOUT_CL_SH) ? 0x03A3 : 0x03C3; // Σ σ
    case 0x17: return (state & LAYOUT_CL_SH) ? 0x03A4 : 0x03C4; // Τ τ
    case 0x18: return (state & LAYOUT_CL_SH) ? 0x03A5 : 0x03C8; // Υ ψ
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x03C2 : 0x03D6; // ς ϖ
    case 0x1A: return (state & LAYOUT_CL_SH) ? 0x03A9 : 0x03C9; // Ω ω
    case 0x1B: return (state & LAYOUT_CL_SH) ? 0x039E : 0x03BE; // Ξ ξ
    case 0x1C: return (state & LAYOUT_CL_SH) ? 0x03A8 : 0x03C8; // Ψ ψ
    case 0x1D: return (state & LAYOUT_CL_SH) ? 0x0396 : 0x03B6; // Ζ ζ
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x0021 : 0x0031; // ! 1
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x2245 : 0x0032; // ≅ 2
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x0023 : 0x0033; // # 3
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x20AC : 0x0034; // € 4
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x0025 : 0x0035; // % 5
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x22A5 : 0x0036; // ⊥ 6
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x0026 : 0x0037; // & 7
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x2217 : 0x0038; // ∗ 8
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x0028 : 0x0039; // ( 9
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x0029 : 0x0030; // ) 0
    case 0x2C: return 0x20; // space
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x23AF : 0x2212; // ⎯ −
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x00B1 : 0x2260; // ± ≠
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x007B : 0x005B; // { [
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x007D : 0x005D; // } ]
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x23D0 : 0x2234; // ⏐ ∴ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x23D0 : 0x2234; // ⏐ ∴ (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x2200 : 0x2203; // ∀ ∃
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x2033 : 0x2032; // ″ ′
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x2248 : 0x223C; // ≈ ∼
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x003C : 0x002C; // < ,
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x003E : 0x002E; // > .
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x003F : 0x002F; // ? /
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x003E : 0x003C; // > < (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F : 0x2234; // _ ∴ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x23D0 : 0x00A5; // ⏐ ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_symbol_alt(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0x2135 : 0x221D; // ℵ ∝
    case 0x05: return (state & LAYOUT_SHIFT) ? 0x2022 : 0x22C5; // • ⋅
    case 0x06: return (state & LAYOUT_SHIFT) ? 0x2284 : 0x00A9; // ⊄ ©
    case 0x07: return (state & LAYOUT_SHIFT) ? 0x2207 : 0x2202; // ∇ ∂
    case 0x08: return (state & LAYOUT_SHIFT) ? 0x2209 : 0x2208; // ∉ ∈
    case 0x09: return (state & LAYOUT_SHIFT) ? 0x21E7 : 0x0192; // ⇧ ƒ
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0x21EA : 0x2303; // ⇪ ⌃
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0x21D0 : 0x2190; // ⇐ ←
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0x2111 : 0x221E; // ℑ ∞
    case 0x0D: return (state & LAYOUT_SHIFT) ? 0x21D3 : 0x2193; // ⇓ ↓
    case 0x0E: return (state & LAYOUT_SHIFT) ? 0x21D1 : 0x2191; // ⇑ ↑
    case 0x0F: return (state & LAYOUT_SHIFT) ? 0x21D2 : 0x2192; // ⇒ →
    case 0x10: return (state & LAYOUT_SHIFT) ? 0x2318 : 0x21B5; // ⌘ ↵
    case 0x11: return (state & LAYOUT_SHIFT) ? 0x237B : 0x2713; // ⍻ ✓
    case 0x12: return (state & LAYOUT_SHIFT) ? 0x2205 : 0x00B0; // ∅ °
    case 0x13: return (state & LAYOUT_SHIFT) ? 0x220F : 0x2118; // ∏ ℘
    case 0x14: return (state & LAYOUT_SHIFT) ? 0x2663 : 0x2660; // ♣ ♠
    case 0x15: return (state & LAYOUT_SHIFT) ? 0x211C : 0x00AE; // ℜ ®
    case 0x16: return (state & LAYOUT_SHIFT) ? 0x2211 : 0x222B; // ∑ ∫
    case 0x17: return (state & LAYOUT_SHIFT) ? 0x2325 : 0x2122; // ⌥ ™
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x2229 : 0x222A; // ∩ ∪
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x2227 : 0x2228; // ∧ ∨
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0x2666 : 0x2665; // ♦ ♥
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0x2297 : 0x00D7; // ⊗ ×
    case 0x1C: return (state & LAYOUT_SHIFT) ? 0x221A : 0x03D2; // √ ϒ
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0x25CA : 0x2026; // ◊ …
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x23A0 : 0x239D; // ⎠ ⎝
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x23A6 : 0x23A3; // ⎦ ⎣
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x23AD : 0x23A9; // ⎭ ⎩
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x239F : 0x239C; // ⎟ ⎜
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x23A5 : 0x23A2; // ⎥ ⎢
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x23AC : 0x23A8; // ⎬ ⎨
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x239E : 0x239B; // ⎞ ⎛
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x23A4 : 0x23A1; // ⎤ ⎡
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x23AB : 0x23A7; // ⎫ ⎧
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x23AE : 0x23AA; // ⎮ ⎪
    case 0x2C: return 0xA0; // nbsp
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0xF8E5 : 0x00AC; //  ¬
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x2295 : 0x2261; // ⊕ ≡
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x2286 : 0x2282; // ⊆ ⊂
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x2287 : 0x2283; // ⊇ ⊃
    case 0x31: return (state & LAYOUT_SHIFT) ? 0xF8FF : 0x00F7; //  ÷ (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0xF8FF : 0x00F7; //  ÷ (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x21D4 : 0x2194; // ⇔ ↔
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x220B : 0x220D; // ∋ ∍
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x2321 : 0x2320; // ⌡ ⌠
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x2264 : 0x2329; // ≤ 〈
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x2265 : 0x232A; // ≥ 〉
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x2220 : 0x2044; // ∠ ⁄
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x2265 : 0x2264; // ≥ ≤ (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x005F : 0x00F7; // _ ÷ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0xF8FF : 0x00A5; //  ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_symbol_layered(unsigned char code, unsigned char state) {
  if (state & LAYOUT_ALT) return layout_symbol_alt(code, state);
  return layout_symbol(code, state);
}
