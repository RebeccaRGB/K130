#ifndef __SUPER_INPUT_H__
#define __SUPER_INPUT_H__

void unicode_input_dec();
void unicode_input_hex();
void unicode_input_end();
unsigned char unicode_input_status();
bool unicode_input(unsigned char r, unsigned char s);

void layout_input_start(unsigned long (*fn)(unsigned char, unsigned char), unsigned char mm);
void layout_input_end();
unsigned char layout_input_status();
bool layout_input(unsigned char r, unsigned char s);

void numpad_numlock_on();
void numpad_numlock_off();
void numpad_numlock_toggle();
bool numpad_numlock_status();
void numpad_hexlock_on();
void numpad_hexlock_off();
void numpad_hexlock_toggle();
bool numpad_hexlock_status();
bool numpad_input(unsigned char r, unsigned char m);

void super_input_dec();
void super_input_hex();
bool super_input(unsigned char r, unsigned char s, unsigned char m);

#endif
