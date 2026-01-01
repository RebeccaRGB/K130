#include "layout_jis.h"
#include "layouts.h"

unsigned long layout_jis(unsigned char code, unsigned char state) {
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
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x22 : 0x32; // " 2
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x23 : 0x33; // # 3
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x24 : 0x34; // $ 4
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x25 : 0x35; // % 5
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x26 : 0x36; // & 6
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x27 : 0x37; // ' 7
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x28 : 0x38; // ( 8
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x29 : 0x39; // ) 9
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x7C : 0x30; // | 0
    case 0x2C: return 0x20; // space
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x3D : 0x2D; // = -
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x7E : 0x5E; // ~ ^
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x60 : 0x40; // ` @
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x7B : 0x5B; // { [
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x7D : 0x5D; // } ] (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x7D : 0x5D; // } ] (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x2B : 0x3B; // + ;
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x2A : 0x3A; // * :
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x5F : 0x5C; // _ \ (ANSI/ISO)
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x3C : 0x2C; // < ,
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x3E : 0x2E; // > .
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x3F : 0x2F; // ? /
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x7C : 0xA5; // | ¥ (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x5F : 0x5C; // _ \ (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x7C : 0xA5; // | ¥ (JIS)
    default: return 0;
  }
}

unsigned long layout_jis_hiragana_dakuten(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0 : 0x3062; // ぢ ji
    case 0x05: return (state & LAYOUT_SHIFT) ? 0 : 0x3054; // ご go
    case 0x06: return (state & LAYOUT_SHIFT) ? 0 : 0x305E; // ぞ zo
    case 0x07: return (state & LAYOUT_SHIFT) ? 0 : 0x3058; // じ zi
    case 0x09: return (state & LAYOUT_SHIFT) ? 0 : 0x3070; // ば ba
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0 : 0x304E; // ぎ gi
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0 : 0x3050; // ぐ gu
    case 0x13: return (state & LAYOUT_SHIFT) ? 0 : 0x305C; // ぜ ze
    case 0x14: return (state & LAYOUT_SHIFT) ? 0 : 0x3060; // だ da
    case 0x15: return (state & LAYOUT_SHIFT) ? 0 : 0x305A; // ず zu
    case 0x16: return (state & LAYOUT_SHIFT) ? 0 : 0x3069; // ど do
    case 0x17: return (state & LAYOUT_SHIFT) ? 0 : 0x304C; // が ga
    case 0x19: return (state & LAYOUT_SHIFT) ? 0 : 0x3073; // び bi
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0 : 0x3067; // で de
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0 : 0x3056; // ざ za
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0 : 0x3065; // づ ju
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0 : 0x3076; // ぶ bu
    case 0x21: return (state & LAYOUT_SHIFT) ? 0 : 0x3094; // ゔ vu
    case 0x2C: return (state & LAYOUT_ALT) ? 0x3099 : 0x309B; // combining / spacing
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0 : 0x307C; // ぼ bo
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0 : 0x3079; // べ be
    case 0x34: return (state & LAYOUT_SHIFT) ? 0 : 0x3052; // げ ge
    default: return 0;
  }
}

unsigned long layout_jis_katakana_dakuten(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0 : 0x30C2; // ヂ ji
    case 0x05: return (state & LAYOUT_SHIFT) ? 0 : 0x30B4; // ゴ go
    case 0x06: return (state & LAYOUT_SHIFT) ? 0 : 0x30BE; // ゾ zo
    case 0x07: return (state & LAYOUT_SHIFT) ? 0 : 0x30B8; // ジ zi
    case 0x09: return (state & LAYOUT_SHIFT) ? 0 : 0x30D0; // バ ba
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0 : 0x30AE; // ギ gi
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0 : 0x30B0; // グ gu
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0x30F9 : 0; // ヹ we
    case 0x13: return (state & LAYOUT_SHIFT) ? 0 : 0x30BC; // ゼ ze
    case 0x14: return (state & LAYOUT_SHIFT) ? 0 : 0x30C0; // ダ da
    case 0x15: return (state & LAYOUT_SHIFT) ? 0 : 0x30BA; // ズ zu
    case 0x16: return (state & LAYOUT_SHIFT) ? 0 : 0x30C9; // ド do
    case 0x17: return (state & LAYOUT_SHIFT) ? 0 : 0x30AC; // ガ ga
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x30F8 : 0; // ヸ wi
    case 0x19: return (state & LAYOUT_SHIFT) ? 0 : 0x30D3; // ビ bi
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0 : 0x30C7; // デ de
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0 : 0x30B6; // ザ za
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0 : 0x30C5; // ヅ ju
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0 : 0x30D6; // ブ bu
    case 0x21: return (state & LAYOUT_SHIFT) ? 0 : 0x30F4; // ヴ vu
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x30FA : 0x30F7; // ヺ wo / ヷ wa
    case 0x2C: return (state & LAYOUT_ALT) ? 0x3099 : 0x309B; // combining / spacing
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0 : 0x30DC; // ボ bo
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0 : 0x30D9; // ベ be
    case 0x34: return (state & LAYOUT_SHIFT) ? 0 : 0x30B2; // ゲ ge
    default: return 0;
  }
}

unsigned long layout_jis_hiragana_handakuten(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x09: return (state & LAYOUT_SHIFT) ? 0 : 0x3071; // ぱ pa
    case 0x19: return (state & LAYOUT_SHIFT) ? 0 : 0x3074; // ぴ pi
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0 : 0x3077; // ぷ pu
    case 0x2C: return (state & LAYOUT_ALT) ? 0x309A : 0x309C; // combining / spacing
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0 : 0x307D; // ぽ po
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0 : 0x307A; // ぺ pe
    default: return 0;
  }
}

unsigned long layout_jis_katakana_handakuten(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x09: return (state & LAYOUT_SHIFT) ? 0 : 0x30D1; // パ pa
    case 0x19: return (state & LAYOUT_SHIFT) ? 0 : 0x30D4; // ピ pi
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0 : 0x30D7; // プ pu
    case 0x2C: return (state & LAYOUT_ALT) ? 0x309A : 0x309C; // combining / spacing
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0 : 0x30DD; // ポ po
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0 : 0x30DA; // ペ pe
    default: return 0;
  }
}

unsigned long layout_jis_hiragana(unsigned char code, unsigned char state) {
  switch (state & LAYOUT_DEAD_KEY) {
    case LAYOUT_DEAD_DIERESIS: return layout_jis_hiragana_dakuten(code, state);
    case LAYOUT_DEAD_RING: return layout_jis_hiragana_handakuten(code, state);
  }
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0x1B139 : 0x3061; // 　 (chi) / ち chi
    case 0x05: return (state & LAYOUT_SHIFT) ? 0x1B132 : 0x3053; // 𛄲 (ko)  / こ ko
    case 0x06: return (state & LAYOUT_SHIFT) ? 0x1B14D : 0x305D; // 　 (ru)  / そ so
    case 0x07: return (state & LAYOUT_SHIFT) ? 0x1B134 : 0x3057; // 　 (shi) / し shi
    case 0x08: return (state & LAYOUT_SHIFT) ? 0x3043  : 0x3044; // ぃ (i)   / い i
    case 0x09: return (state & LAYOUT_SHIFT) ? 0x1B141 : 0x306F; // 　 (ha)  / は ha
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0x1B130 : 0x304D; // 　 (ki)  / き ki
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0x1B131 : 0x304F; // 　 (ku)  / く ku
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0x3091  : 0x306B; // ゑ we    / に ni
    case 0x0D: return (state & LAYOUT_SHIFT) ? 0x1B150 : 0x307E; // 𛅐 (wi)  / ま ma
    case 0x0E: return (state & LAYOUT_SHIFT) ? 0x1B151 : 0x306E; // 𛅑 (we)  / の no
    case 0x0F: return (state & LAYOUT_SHIFT) ? 0x1B14C : 0x308A; // 　 (ri)  / り ri
    case 0x10: return (state & LAYOUT_SHIFT) ? 0x1B152 : 0x3082; // 𛅒 (wo)  / も mo
    case 0x11: return (state & LAYOUT_SHIFT) ? 0x308E  : 0x307F; // ゎ (wa)  / み mi
    case 0x12: return (state & LAYOUT_SHIFT) ? 0x1B14B : 0x3089; // 　 (ra)  / ら ra
    case 0x13: return (state & LAYOUT_SHIFT) ? 0x30FC  : 0x305B; // ー --    / せ se
    case 0x14: return (state & LAYOUT_SHIFT) ? 0x1B138 : 0x305F; // 　 (ta)  / た ta
    case 0x15: return (state & LAYOUT_SHIFT) ? 0x1B135 : 0x3059; // 　 (su)  / す su
    case 0x16: return (state & LAYOUT_SHIFT) ? 0x1B13B : 0x3068; // 　 (to)  / と to
    case 0x17: return (state & LAYOUT_SHIFT) ? 0x3095  : 0x304B; // ゕ (ka)  / か ka
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x3090  : 0x306A; // ゐ wi    / な na
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x1B142 : 0x3072; // 　 (hi)  / ひ hi
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0x1B13A : 0x3066; // 　 (te)  / て te
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0x1B148 : 0x3055; // 　 (mu)  / さ sa
    case 0x1C: return (state & LAYOUT_SHIFT) ? 0x1B153 : 0x3093; // 　 (n)   / ん n
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0x3063  : 0x3064; // っ (tsu) / つ tsu
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x1B13E : 0x306C; // 　 (nu)  / ぬ nu
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x1B143 : 0x3075; // 　 (fu)  / ふ fu
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x3041  : 0x3042; // ぁ (a)   / あ a
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x3045  : 0x3046; // ぅ (u)   / う u
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x3047  : 0x3048; // ぇ (e)   / え e
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x3049  : 0x304A; // ぉ (o)   / お o
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x3083  : 0x3084; // ゃ (ya)  / や ya
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x3085  : 0x3086; // ゅ (yu)  / ゆ yu
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x3087  : 0x3088; // ょ (yo)  / よ yo
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x3092  : 0x308F; // を wo    / わ wa
    case 0x2C: return 0x3000; // idsp
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x1B145 : 0x307B; // 　 (ho)  / ほ ho
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x1B144 : 0x3078; // 　 (he)  / へ he
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x00A5  : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_DIERESIS); // yen / dakuten
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x300C  : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_RING    ); // 「 / handakuten
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x300D  : 0x3080; // 」 rtbkt / む mu (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x300D  : 0x3080; // 」 rtbkt / む mu (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x1B14E : 0x308C; // 　 (re)  / れ re
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x3096  : 0x3051; // ゖ (ke)  / け ke
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x1B14F : 0x308D; // 　 (ro)  / ろ ro (ANSI/ISO)
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x3001  : 0x306D; // 、 comma / ね ne
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x3002  : 0x308B; // 。 stop  / る ru
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x30FB  : 0x3081; // ・ mdot  / め me
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x007C  : 0x30FC; // |　pipe  / ー -- (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x1B14F : 0x308D; // 　 (ro)  / ろ ro (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x007C  : 0x30FC; // |　pipe  / ー -- (JIS)
    default: return 0;
  }
}

unsigned long layout_jis_katakana(unsigned char code, unsigned char state) {
  switch (state & LAYOUT_DEAD_KEY) {
    case LAYOUT_DEAD_DIERESIS: return layout_jis_katakana_dakuten(code, state);
    case LAYOUT_DEAD_RING: return layout_jis_katakana_handakuten(code, state);
  }
  switch (code) {
    case 0x04: return (state & LAYOUT_SHIFT) ? 0x1B15A : 0x30C1; // 　 (chi) / チ chi
    case 0x05: return (state & LAYOUT_SHIFT) ? 0x1B155 : 0x30B3; // 𛅕 (ko)  / コ ko
    case 0x06: return (state & LAYOUT_SHIFT) ? 0x31FD  : 0x30BD; // ㇽ (ru)  / ソ so
    case 0x07: return (state & LAYOUT_SHIFT) ? 0x31F1  : 0x30B7; // ㇱ (shi) / シ shi
    case 0x08: return (state & LAYOUT_SHIFT) ? 0x30A3  : 0x30A4; // ィ (i)   / イ i
    case 0x09: return (state & LAYOUT_SHIFT) ? 0x31F5  : 0x30CF; // ㇵ (ha)  / ハ ha
    case 0x0A: return (state & LAYOUT_SHIFT) ? 0x1B154 : 0x30AD; // 　 (ki)  / キ ki
    case 0x0B: return (state & LAYOUT_SHIFT) ? 0x31F0  : 0x30AF; // ㇰ (ku)  / ク ku
    case 0x0C: return (state & LAYOUT_SHIFT) ? 0x30F1  : 0x30CB; // ヱ we    / ニ ni
    case 0x0D: return (state & LAYOUT_SHIFT) ? 0x1B164 : 0x30DE; // 𛅤 (wi)  / マ ma
    case 0x0E: return (state & LAYOUT_SHIFT) ? 0x1B165 : 0x30CE; // 𛅥 (we)  / ノ no
    case 0x0F: return (state & LAYOUT_SHIFT) ? 0x31FC  : 0x30EA; // ㇼ (ri)  / リ ri
    case 0x10: return (state & LAYOUT_SHIFT) ? 0x1B166 : 0x30E2; // 𛅦 (wo)  / モ mo
    case 0x11: return (state & LAYOUT_SHIFT) ? 0x30EE  : 0x30DF; // ヮ (wa)  / ミ mi
    case 0x12: return (state & LAYOUT_SHIFT) ? 0x31FB  : 0x30E9; // ㇻ (ra)  / ラ ra
    case 0x13: return (state & LAYOUT_SHIFT) ? 0x30FC  : 0x30BB; // ー --    / セ se
    case 0x14: return (state & LAYOUT_SHIFT) ? 0x1B159 : 0x30BF; // 　 (ta)  / タ ta
    case 0x15: return (state & LAYOUT_SHIFT) ? 0x31F2  : 0x30B9; // ㇲ (su)  / ス su
    case 0x16: return (state & LAYOUT_SHIFT) ? 0x31F3  : 0x30C8; // ㇳ (to)  / ト to
    case 0x17: return (state & LAYOUT_SHIFT) ? 0x30F5  : 0x30AB; // ヵ (ka)  / カ ka
    case 0x18: return (state & LAYOUT_SHIFT) ? 0x30F0  : 0x30CA; // ヰ wi    / ナ na
    case 0x19: return (state & LAYOUT_SHIFT) ? 0x31F6  : 0x30D2; // ㇶ (hi)  / ヒ hi
    case 0x1A: return (state & LAYOUT_SHIFT) ? 0x1B15B : 0x30C6; // 　 (te)  / テ te
    case 0x1B: return (state & LAYOUT_SHIFT) ? 0x31FA  : 0x30B5; // ㇺ (mu)  / サ sa
    case 0x1C: return (state & LAYOUT_SHIFT) ? 0x1B167 : 0x30F3; // 𛅧 (n)   / ン n
    case 0x1D: return (state & LAYOUT_SHIFT) ? 0x30C3  : 0x30C4; // ッ (tsu) / ツ tsu
    case 0x1E: return (state & LAYOUT_SHIFT) ? 0x31F4  : 0x30CC; // ㇴ (nu)  / ヌ nu
    case 0x1F: return (state & LAYOUT_SHIFT) ? 0x31F7  : 0x30D5; // ㇷ (fu)  / フ fu
    case 0x20: return (state & LAYOUT_SHIFT) ? 0x30A1  : 0x30A2; // ァ (a)   / ア a
    case 0x21: return (state & LAYOUT_SHIFT) ? 0x30A5  : 0x30A6; // ゥ (u)   / ウ u
    case 0x22: return (state & LAYOUT_SHIFT) ? 0x30A7  : 0x30A8; // ェ (e)   / エ e
    case 0x23: return (state & LAYOUT_SHIFT) ? 0x30A9  : 0x30AA; // ォ (o)   / オ o
    case 0x24: return (state & LAYOUT_SHIFT) ? 0x30E3  : 0x30E4; // ャ (ya)  / ヤ ya
    case 0x25: return (state & LAYOUT_SHIFT) ? 0x30E5  : 0x30E6; // ュ (yu)  / ユ yu
    case 0x26: return (state & LAYOUT_SHIFT) ? 0x30E7  : 0x30E8; // ョ (yo)  / ヨ yo
    case 0x27: return (state & LAYOUT_SHIFT) ? 0x30F2  : 0x30EF; // ヲ wo    / ワ wa
    case 0x2C: return 0x3000; // idsp
    case 0x2D: return (state & LAYOUT_SHIFT) ? 0x31F9  : 0x30DB; // ㇹ (ho)  / ホ ho
    case 0x2E: return (state & LAYOUT_SHIFT) ? 0x31F8  : 0x30D8; // ㇸ (he)  / ヘ he
    case 0x2F: return (state & LAYOUT_SHIFT) ? 0x00A5  : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_DIERESIS); // yen / dakuten
    case 0x30: return (state & LAYOUT_SHIFT) ? 0x300C  : (LAYOUT_SWITCH_STATE | LAYOUT_DEAD_RING    ); // 「 / handakuten
    case 0x31: return (state & LAYOUT_SHIFT) ? 0x300D  : 0x30E0; // 」 rtbkt / ム mu (ANSI)
    case 0x32: return (state & LAYOUT_SHIFT) ? 0x300D  : 0x30E0; // 」 rtbkt / ム mu (ISO/JIS)
    case 0x33: return (state & LAYOUT_SHIFT) ? 0x31FE  : 0x30EC; // ㇾ (re)  / レ re
    case 0x34: return (state & LAYOUT_SHIFT) ? 0x30F6  : 0x30B1; // ヶ (ke)  / ケ ke
    case 0x35: return (state & LAYOUT_SHIFT) ? 0x31FF  : 0x30ED; // ㇿ (ro)  / ロ ro (ANSI/ISO)
    case 0x36: return (state & LAYOUT_SHIFT) ? 0x3001  : 0x30CD; // 、 comma / ネ ne
    case 0x37: return (state & LAYOUT_SHIFT) ? 0x3002  : 0x30EB; // 。 stop  / ル ru
    case 0x38: return (state & LAYOUT_SHIFT) ? 0x30FB  : 0x30E1; // ・ mdot  / メ me
    case 0x64: return (state & LAYOUT_SHIFT) ? 0x007C  : 0x30FC; // |　pipe  / ー -- (ISO)
    case 0x87: return (state & LAYOUT_SHIFT) ? 0x31FF  : 0x30ED; // ㇿ (ro)  / ロ ro (JIS)
    case 0x89: return (state & LAYOUT_SHIFT) ? 0x007C  : 0x30FC; // |　pipe  / ー -- (JIS)
    default: return 0;
  }
}
