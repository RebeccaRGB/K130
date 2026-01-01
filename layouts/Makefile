all: kkcxgen xml svg

clean:
	rm -f kkcxgen
	rm -rf xml
	rm -rf svg

kkcxgen:
	g++ -o kkcxgen kkcxgen.c *.cpp

xml: kkcxgen
	mkdir -p xml
	./kkcxgen us > xml/us-altgr.kkcx
	./kkcxgen petscii > xml/petscii.kkcx
	./kkcxgen symbol > xml/symbol.kkcx
	./kkcxgen cyrillic > xml/cyrillic.kkcx
	./kkcxgen hebrew > xml/hebrew.kkcx
	./kkcxgen arabic > xml/arabic.kkcx
	./kkcxgen ipa > xml/ipa.kkcx
	./kkcxgen sitelenpona > xml/sitelenpona.kkcx
	./kkcxgen hiragana > xml/jis-hiragana.kkcx
	./kkcxgen katakana > xml/jis-katakana.kkcx

svg: xml
	mkdir -p svg
	java -jar ../../keyboards/java/KeyCaps/keycaps.jar --svg -m max -u 54 -o svg -f xml

.PHONY: all clean
