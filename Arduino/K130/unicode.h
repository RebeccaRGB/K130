#ifndef __UNICODE_H__
#define __UNICODE_H__

void usbk_clear_report();
void usbk_type_dec(unsigned long v);
void usbk_type_dec_numpad(unsigned long v);
void usbk_type_hex(unsigned long v, int n, unsigned char shift, unsigned char unshift);
void usbk_type_hex_numpad(unsigned long v, int n, unsigned char shift, unsigned char unshift);
void usbk_type_unicode_unix(unsigned long cp);
void usbk_type_unicode_win_dec(unsigned long cp);
void usbk_type_unicode_win_hex(unsigned long cp);
void usbk_type_unicode_mac(unsigned long cp);
int usbk_numeric_value(unsigned char code);

#endif
