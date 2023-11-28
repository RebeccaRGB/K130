#ifndef __REMAP_H__
#define __REMAP_H__

unsigned char remap_ansi(unsigned char code);
unsigned char remap_iso(unsigned char code);
unsigned char remap_jis(unsigned char code);
unsigned char remap_mac(unsigned char code);
unsigned char remap_unix(unsigned char code);
unsigned char remap_hexpad(unsigned char code);
unsigned char remap_hexlock(unsigned char code);
unsigned char remap_numlock(unsigned char code);

#endif
