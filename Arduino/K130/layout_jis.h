#ifndef __LAYOUT_JIS_H__
#define __LAYOUT_JIS_H__

unsigned long layout_jis(unsigned char code, unsigned char state);
unsigned long layout_jis_hiragana_dakuten(unsigned char code, unsigned char state);
unsigned long layout_jis_katakana_dakuten(unsigned char code, unsigned char state);
unsigned long layout_jis_hiragana_handakuten(unsigned char code, unsigned char state);
unsigned long layout_jis_katakana_handakuten(unsigned char code, unsigned char state);
unsigned long layout_jis_hiragana(unsigned char code, unsigned char state);
unsigned long layout_jis_katakana(unsigned char code, unsigned char state);

#endif
