#include <stdio.h>
#include <string.h>
#include "layout_arabic.h"
#include "layout_cyrillic.h"
#include "layout_dead_keys.h"
#include "layout_hebrew.h"
#include "layout_ipa.h"
#include "layout_jis.h"
#include "layout_petscii.h"
#include "layout_sitelen_pona.h"
#include "layout_symbol.h"
#include "layout_us.h"
#include "layouts.h"

int checkUnicodeDefined(unsigned long cp) {
	if (cp >= 0x1B130 && cp <= 0x1B16F) {
		if (cp == 0x1B132) return 1;
		if (cp >= 0x1B150 && cp <= 0x1B152) return 1;
		if (cp == 0x1B155) return 1;
		if (cp >= 0x1B164 && cp <= 0x1B167) return 1;
		return 0;
	}
	return 1;
}

static char _legendItemString[256];

const char * legendItemString(unsigned long code) {
	if (!code) {
		return "<l></l>";
	}
	if (code < LAYOUT_UNICODE_MAX) {
		if (checkUnicodeDefined(code)) {
			snprintf(_legendItemString, 255, "<l>&#%ld;</l>", code);
			return _legendItemString;
		}
		return "<l></l>";
	}
	if (code < LAYOUT_SWITCH_STATE) {
		unsigned long cp1 = ((code >> 16) & 0xFFFFL);
		unsigned long cp2 = (code & 0xFFFFL);
		snprintf(_legendItemString, 255, "<l>&#%ld;&#%ld;</l>", cp1, cp2);
		return _legendItemString;
	}
	switch (code & LAYOUT_DEAD_KEY) {
		case LAYOUT_DEAD_GRAVE: return "<l>&#715;</l>";
		case LAYOUT_DEAD_ACUTE: return "<l>&#714;</l>";
		case LAYOUT_DEAD_CIRCUM: return "<l>&#710;</l>";
		case LAYOUT_DEAD_TILDE: return "<l>&#732;</l>";
		case LAYOUT_DEAD_MACRON: return "<l>&#713;</l>";
		case LAYOUT_DEAD_BREVE: return "<l>&#728;</l>";
		case LAYOUT_DEAD_DOTABOVE: return "<l>&#729;</l>";
		case LAYOUT_DEAD_DIERESIS: return "<l>&#168;</l>";
		case LAYOUT_DEAD_RING: return "<l>&#730;</l>";
		case LAYOUT_DEAD_DBLACUTE: return "<l>&#733;</l>";
		case LAYOUT_DEAD_CARON: return "<l>&#711;</l>";
		case LAYOUT_DEAD_DOTBELOW: return "<l>&#160;&#803;</l>";
		case LAYOUT_DEAD_CEDILLA: return "<l>&#184;</l>";
		case LAYOUT_DEAD_OGONEK: return "<l>&#731;</l>";
		case LAYOUT_DEAD_SLASH: return "<l>&#8260;</l>";
	}
	return "<l></l>";
}

static char _legendString[256];

const char * legendString(unsigned long (*layoutFn)(unsigned char, unsigned char), unsigned char code) {
	strncpy(_legendString, legendItemString(layoutFn(code, 0)), 255);
	strncat(_legendString, legendItemString(layoutFn(code, LAYOUT_SHIFT)), 255);
	strncat(_legendString, legendItemString(layoutFn(code, LAYOUT_ALT)), 255);
	strncat(_legendString, legendItemString(layoutFn(code, LAYOUT_ALT | LAYOUT_SHIFT)), 255);
	return _legendString;
}

void printLayout(unsigned long (*layoutFn)(unsigned char, unsigned char)) {
	printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	printf("<!DOCTYPE keyCapLayout PUBLIC \"-//Kreative//DTD KreativeKeyCaps 1.0//EN\" \"http://www.kreativekorp.com/dtd/kkcx.dtd\">\n");
	printf("<keyCapLayout>\n");
	printf("\t<k usb=\"0x68\" x=\"0u\" y=\"5.25u\">F13&#10;Help&#10;Dec</k>\n");
	printf("\t<k usb=\"0x69\">F14&#10;&#10;Hex</k>\n");
	printf("\t<k usb=\"0x29\" x=\"2.5u\" y=\"5.25u\">Esc</k>\n");
	printf("\t<k usb=\"0x3A\" x=\"4.5u\" y=\"5.25u\">F1</k>\n");
	printf("\t<k usb=\"0x3B\">F2</k>\n");
	printf("\t<k usb=\"0x3C\">F3</k>\n");
	printf("\t<k usb=\"0x3D\">F4</k>\n");
	printf("\t<k usb=\"0x3E\" x=\"9u\" y=\"5.25u\">F5</k>\n");
	printf("\t<k usb=\"0x3F\">F6</k>\n");
	printf("\t<k usb=\"0x40\">F7</k>\n");
	printf("\t<k usb=\"0x41\">F8</k>\n");
	printf("\t<k usb=\"0x42\" x=\"13.5u\" y=\"5.25u\">F9</k>\n");
	printf("\t<k usb=\"0x43\">F10</k>\n");
	printf("\t<k usb=\"0x44\">F11</k>\n");
	printf("\t<k usb=\"0x45\">F12</k>\n");
	printf("\t<k usb=\"0x46\" x=\"18u\" y=\"5.25u\">Print&#10;Screen</k>\n");
	printf("\t<k usb=\"0x47\">Scroll&#10;Lock</k>\n");
	printf("\t<k usb=\"0x48\"><l>Pause</l><l>Break</l></k>\n");
	printf("\t<k usb=\"0x7F\" x=\"21.5u\" y=\"5.25u\"><l>&#128263;</l><l>&#9199;</l></k>\n");
	printf("\t<k usb=\"0x81\"><l>&#128265;</l><l>&#9198;</l></k>\n");
	printf("\t<k usb=\"0x80\"><l>&#128266;</l><l>&#9197;</l></k>\n");
	printf("\t<k usb=\"0x66\"><l>&#9211;</l><l>&#9167;</l></k>\n");
	printf("\t<k usb=\"0x6A\" x=\"0u\" y=\"4u\">F15&#10;Stop&#10;AltGr</k>\n");
	printf("\t<k usb=\"0x6B\">F16&#10;Again&#10;PETSCII</k>\n");
	printf("\t<k usb=\"0x35\" x=\"2.5u\" y=\"4u\">%s</k>\n", legendString(layoutFn, 0x35));
	printf("\t<k usb=\"0x1E\">%s</k>\n", legendString(layoutFn, 0x1E));
	printf("\t<k usb=\"0x1F\">%s</k>\n", legendString(layoutFn, 0x1F));
	printf("\t<k usb=\"0x20\">%s</k>\n", legendString(layoutFn, 0x20));
	printf("\t<k usb=\"0x21\">%s</k>\n", legendString(layoutFn, 0x21));
	printf("\t<k usb=\"0x22\">%s</k>\n", legendString(layoutFn, 0x22));
	printf("\t<k usb=\"0x23\">%s</k>\n", legendString(layoutFn, 0x23));
	printf("\t<k usb=\"0x24\">%s</k>\n", legendString(layoutFn, 0x24));
	printf("\t<k usb=\"0x25\">%s</k>\n", legendString(layoutFn, 0x25));
	printf("\t<k usb=\"0x26\">%s</k>\n", legendString(layoutFn, 0x26));
	printf("\t<k usb=\"0x27\">%s</k>\n", legendString(layoutFn, 0x27));
	printf("\t<k usb=\"0x2D\">%s</k>\n", legendString(layoutFn, 0x2D));
	printf("\t<k usb=\"0x2E\">%s</k>\n", legendString(layoutFn, 0x2E));
	printf("\t<k usb=\"0x89\">%s</k>\n", legendString(layoutFn, 0x89));
	printf("\t<k usb=\"0x2A\">Back&#10;Space</k>\n");
	printf("\t<k usb=\"0x49\" x=\"18u\" y=\"4u\">Insert</k>\n");
	printf("\t<k usb=\"0x4A\">Home</k>\n");
	printf("\t<k usb=\"0x4B\">Page&#10;Up</k>\n");
	printf("\t<k usb=\"0x53\" x=\"21.5u\" y=\"4u\" type=\"N\"><l lh=\"0.5\">Num&#10;Lock</l><l>A</l></k>\n");
	printf("\t<k usb=\"0x67\" type=\"N\"><l>=</l><l>B</l></k>\n");
	printf("\t<k usb=\"0x54\" type=\"N\"><l>/</l><l>C</l></k>\n");
	printf("\t<k usb=\"0x55\" type=\"N\"><l>*</l><l>D</l></k>\n");
	printf("\t<k usb=\"0x6C\" x=\"0u\" y=\"3u\">F17&#10;Props&#10;Greek</k>\n");
	printf("\t<k usb=\"0x6D\">F18&#10;Undo&#10;Cyrillic</k>\n");
	printf("\t<k usb=\"0x2B\" x=\"2.5u\" y=\"3u\" shape=\"1.5u\">Tab</k>\n");
	printf("\t<k usb=\"0x14\">%s</k>\n", legendString(layoutFn, 0x14));
	printf("\t<k usb=\"0x1A\">%s</k>\n", legendString(layoutFn, 0x1A));
	printf("\t<k usb=\"0x08\">%s</k>\n", legendString(layoutFn, 0x08));
	printf("\t<k usb=\"0x15\">%s</k>\n", legendString(layoutFn, 0x15));
	printf("\t<k usb=\"0x17\">%s</k>\n", legendString(layoutFn, 0x17));
	printf("\t<k usb=\"0x1C\">%s</k>\n", legendString(layoutFn, 0x1C));
	printf("\t<k usb=\"0x18\">%s</k>\n", legendString(layoutFn, 0x18));
	printf("\t<k usb=\"0x0C\">%s</k>\n", legendString(layoutFn, 0x0C));
	printf("\t<k usb=\"0x12\">%s</k>\n", legendString(layoutFn, 0x12));
	printf("\t<k usb=\"0x13\">%s</k>\n", legendString(layoutFn, 0x13));
	printf("\t<k usb=\"0x2F\">%s</k>\n", legendString(layoutFn, 0x2F));
	printf("\t<k usb=\"0x30\">%s</k>\n", legendString(layoutFn, 0x30));
	printf("\t<k usb=\"0x31\" shape=\"1.5u\">%s</k>\n", legendString(layoutFn, 0x31));
	printf("\t<k usb=\"0x4C\" x=\"18u\" y=\"3u\">Delete</k>\n");
	printf("\t<k usb=\"0x4D\">End</k>\n");
	printf("\t<k usb=\"0x4E\">Page&#10;Down</k>\n");
	printf("\t<k usb=\"0x5F\" x=\"21.5u\" y=\"3u\" type=\"N\"><l>7</l><l>Home</l></k>\n");
	printf("\t<k usb=\"0x60\" type=\"N\"><l>8</l><l>&#8593;</l></k>\n");
	printf("\t<k usb=\"0x61\" type=\"N\"><l>9</l><l>PgUp</l></k>\n");
	printf("\t<k usb=\"0x56\" type=\"N\"><l>-</l><l>E</l></k>\n");
	printf("\t<k usb=\"0x6E\" x=\"0u\" y=\"2u\">F19&#10;Front&#10;Hebrew</k>\n");
	printf("\t<k usb=\"0x6F\">F20&#10;Copy&#10;Arabic</k>\n");
	printf("\t<k usb=\"0x39\" x=\"2.5u\" y=\"2u\" shape=\"1.75u\">Caps Lock</k>\n");
	printf("\t<k usb=\"0x04\">%s</k>\n", legendString(layoutFn, 0x04));
	printf("\t<k usb=\"0x16\">%s</k>\n", legendString(layoutFn, 0x16));
	printf("\t<k usb=\"0x07\">%s</k>\n", legendString(layoutFn, 0x07));
	printf("\t<k usb=\"0x09\">%s</k>\n", legendString(layoutFn, 0x09));
	printf("\t<k usb=\"0x0A\">%s</k>\n", legendString(layoutFn, 0x0A));
	printf("\t<k usb=\"0x0B\">%s</k>\n", legendString(layoutFn, 0x0B));
	printf("\t<k usb=\"0x0D\">%s</k>\n", legendString(layoutFn, 0x0D));
	printf("\t<k usb=\"0x0E\">%s</k>\n", legendString(layoutFn, 0x0E));
	printf("\t<k usb=\"0x0F\">%s</k>\n", legendString(layoutFn, 0x0F));
	printf("\t<k usb=\"0x33\">%s</k>\n", legendString(layoutFn, 0x33));
	printf("\t<k usb=\"0x34\">%s</k>\n", legendString(layoutFn, 0x34));
	printf("\t<k usb=\"0x32\">%s</k>\n", legendString(layoutFn, 0x32));
	printf("\t<k usb=\"0x28\" shape=\"1.25u\">Enter</k>\n");
	printf("\t<k usb=\"0x5C\" x=\"21.5u\" y=\"2u\" type=\"N\"><l>4</l><l>&#8592;</l></k>\n");
	printf("\t<k usb=\"0x5D\" type=\"N\">5</k>\n");
	printf("\t<k usb=\"0x5E\" type=\"N\"><l>6</l><l>&#8594;</l></k>\n");
	printf("\t<k usb=\"0x57\" type=\"N\"><l>+</l><l>F</l></k>\n");
	printf("\t<k usb=\"0x70\" x=\"0u\" y=\"1u\">F21&#10;Open&#10;IPA</k>\n");
	printf("\t<k usb=\"0x71\">F22&#10;Paste&#10;CS</k>\n");
	printf("\t<k usb=\"0xE1\" x=\"2.5u\" y=\"1u\" shape=\"1.25u\">Shift</k>\n");
	printf("\t<k usb=\"0x64\">%s</k>\n", legendString(layoutFn, 0x64));
	printf("\t<k usb=\"0x1D\">%s</k>\n", legendString(layoutFn, 0x1D));
	printf("\t<k usb=\"0x1B\">%s</k>\n", legendString(layoutFn, 0x1B));
	printf("\t<k usb=\"0x06\">%s</k>\n", legendString(layoutFn, 0x06));
	printf("\t<k usb=\"0x19\">%s</k>\n", legendString(layoutFn, 0x19));
	printf("\t<k usb=\"0x05\">%s</k>\n", legendString(layoutFn, 0x05));
	printf("\t<k usb=\"0x11\">%s</k>\n", legendString(layoutFn, 0x11));
	printf("\t<k usb=\"0x10\">%s</k>\n", legendString(layoutFn, 0x10));
	printf("\t<k usb=\"0x36\">%s</k>\n", legendString(layoutFn, 0x36));
	printf("\t<k usb=\"0x37\">%s</k>\n", legendString(layoutFn, 0x37));
	printf("\t<k usb=\"0x38\">%s</k>\n", legendString(layoutFn, 0x38));
	printf("\t<k usb=\"0x87\">%s</k>\n", legendString(layoutFn, 0x87));
	printf("\t<k usb=\"0xE5\" shape=\"1.75u\">Shift</k>\n");
	printf("\t<k usb=\"0x52\" x=\"19u\" y=\"1u\">&#8593;</k>\n");
	printf("\t<k usb=\"0x59\" x=\"21.5u\" y=\"1u\" type=\"N\"><l>1</l><l>End</l></k>\n");
	printf("\t<k usb=\"0x5A\" type=\"N\"><l>2</l><l>&#8595;</l></k>\n");
	printf("\t<k usb=\"0x5B\" type=\"N\"><l>3</l><l>PgDn</l></k>\n");
	printf("\t<k usb=\"0x72\" x=\"0u\" y=\"0u\">F23&#10;Find&#10;Hiragana</k>\n");
	printf("\t<k usb=\"0x73\">F24&#10;Cut&#10;Katakana</k>\n");
	printf("\t<k usb=\"0xE0\" x=\"2.5u\" y=\"0u\">Ctrl</k>\n");
	printf("\t<k usb=\"0x01\">Fn</k>\n");
	printf("\t<k usb=\"0xE3\">Meta</k>\n");
	printf("\t<k usb=\"0xE2\">Alt</k>\n");
	printf("\t<k usb=\"0x8B\" shape=\"1.5u\">Muhenkan</k>\n");
	printf("\t<k usb=\"0x2C\" shape=\"2.75u\"></k>\n");
	printf("\t<k usb=\"0x8A\" shape=\"1.5u\">Henkan</k>\n");
	printf("\t<k usb=\"0x88\" shape=\"1.25u\">Kana</k>\n");
	printf("\t<k usb=\"0xE6\">Alt</k>\n");
	printf("\t<k usb=\"0xE7\">Meta</k>\n");
	printf("\t<k usb=\"0x65\">Menu</k>\n");
	printf("\t<k usb=\"0xE4\">Ctrl</k>\n");
	printf("\t<k usb=\"0x50\" x=\"18u\" y=\"0u\">&#8592;</k>\n");
	printf("\t<k usb=\"0x51\">&#8595;</k>\n");
	printf("\t<k usb=\"0x4F\">&#8594;</k>\n");
	printf("\t<k usb=\"0x62\" x=\"21.5u\" y=\"0u\" type=\"N\"><l>0</l><l>Ins</l></k>\n");
	printf("\t<k usb=\"0x85\" type=\"N\"><l>,</l><l>Copy</l></k>\n");
	printf("\t<k usb=\"0x63\" type=\"N\"><l>.</l><l>Del</l></k>\n");
	printf("\t<k usb=\"0x58\" shape=\"1+2u\">Enter</k>\n");
	printf("</keyCapLayout>\n");
}

unsigned long layout_jis_hiragana_layered(unsigned char code, unsigned char state) {
	if (state & LAYOUT_ALT) return layout_jis_hiragana(code, state);
	return layout_jis(code, state);
}

unsigned long layout_jis_katakana_layered(unsigned char code, unsigned char state) {
	if (state & LAYOUT_ALT) return layout_jis_katakana(code, state);
	return layout_jis(code, state);
}

int main(int argc, char ** argv) {
	for (int i = 1; i < argc; i++) {
		if (!strcasecmp(argv[i], "us")) printLayout(layout_us_layered);
		if (!strcasecmp(argv[i], "altgr")) printLayout(layout_us_layered);
		if (!strcasecmp(argv[i], "petscii")) printLayout(layout_petscii_layered);
		if (!strcasecmp(argv[i], "symbol")) printLayout(layout_symbol_layered);
		if (!strcasecmp(argv[i], "greek")) printLayout(layout_symbol_layered);
		if (!strcasecmp(argv[i], "cyrillic")) printLayout(layout_cyrillic_layered);
		if (!strcasecmp(argv[i], "hebrew")) printLayout(layout_hebrew_qwerty);
		if (!strcasecmp(argv[i], "arabic")) printLayout(layout_arabic_qwerty);
		if (!strcasecmp(argv[i], "ipa")) printLayout(layout_ipa_layered);
		if (!strcasecmp(argv[i], "sp")) printLayout(layout_sitelen_pona);
		if (!strcasecmp(argv[i], "sitelenpona")) printLayout(layout_sitelen_pona);
		if (!strcasecmp(argv[i], "hiragana")) printLayout(layout_jis_hiragana_layered);
		if (!strcasecmp(argv[i], "katakana")) printLayout(layout_jis_katakana_layered);
	}
	return 0;
}
