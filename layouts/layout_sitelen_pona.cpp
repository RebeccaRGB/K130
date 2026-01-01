#include "layout_sitelen_pona.h"
#include "layouts.h"

unsigned long layout_sitelen_pona(unsigned char code, unsigned char state) {
  switch (code) {
    case 0x04: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1905 : 0xF1914) : ((state & LAYOUT_SHIFT) ? 0xF1906 : 0xF1900); // 󱤅 󱤔 󱤆 󱤀
    case 0x05: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1935 : 0xF194F) : ((state & LAYOUT_SHIFT) ? 0xF193F : 0xF1941); // 󱤵 󱥏 󱤿 󱥁
    case 0x06: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1984 : 0xF191E) : ((state & LAYOUT_SHIFT) ? 0xF1945 : 0xF194E); // 󱦄 󱤞 󱥅 󱥎
    case 0x07: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1903 : 0xF1925) : ((state & LAYOUT_SHIFT) ? 0xF192A : 0xF1968); // 󱤃 󱤥 󱤪 󱥨
    case 0x08: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF197C : 0xF1953) : ((state & LAYOUT_SHIFT) ? 0xF1956 : 0xF1909); // 󱥼 󱥓 󱥖 󱤉
    case 0x09: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF19A0 : 0xF191A) : ((state & LAYOUT_SHIFT) ? 0xF1950 : 0xF194D); // 󱦠 󱤚 󱥐 󱥍
    case 0x0A: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1985 : 0xF1923) : ((state & LAYOUT_SHIFT) ? 0xF191F : 0xF1946); // 󱦅 󱤣 󱤟 󱥆
    case 0x0B: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF19A2 : 0xF194A) : ((state & LAYOUT_SHIFT) ? 0xF195D : 0xF1942); // 󱦢 󱥊 󱥝 󱥂
    case 0x0C: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1982 : 0xF190F) : ((state & LAYOUT_SHIFT) ? 0xF190E : 0xF190D); // 󱦂 󱤏 󱤎 󱤍
    case 0x0D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1912 : 0xF1910) : ((state & LAYOUT_SHIFT) ? 0xF1913 : 0xF1911); // 󱤒 󱤐 󱤓 󱤑
    case 0x0E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1988 : 0xF191B) : ((state & LAYOUT_SHIFT) ? 0xF1919 : 0xF1918); // 󱦈 󱤛 󱤙 󱤘
    case 0x0F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF192F : 0xF1929) : ((state & LAYOUT_SHIFT) ? 0xF192E : 0xF1927); // 󱤯 󱤩 󱤮 󱤧
    case 0x10: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1933 : 0xF1931) : ((state & LAYOUT_SHIFT) ? 0xF1930 : 0xF1934); // 󱤳 󱤱 󱤰 󱤴
    case 0x11: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1940 : 0xF1920) : ((state & LAYOUT_SHIFT) ? 0xF193B : 0xF1986); // 󱥀 󱤠 󱤻 󱦆
    case 0x12: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF197A : 0xF195C) : ((state & LAYOUT_SHIFT) ? 0xF190C : 0xF1944); // 󱥺 󱥜 󱤌 󱥄
    case 0x13: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1955 : 0xF1952) : ((state & LAYOUT_SHIFT) ? 0xF1948 : 0xF1954); // 󱥕 󱥒 󱥈 󱥔
    case 0x14: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF193A : 0xF191C) : ((state & LAYOUT_SHIFT) ? 0xF1964 : 0xF1959); // 󱤺 󱤜 󱥤 󱥙
    case 0x15: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1987 : 0xF192B) : ((state & LAYOUT_SHIFT) ? 0xF1924 : 0xF196B); // 󱦇 󱤫 󱤤 󱥫
    case 0x16: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1958 : 0xF195B) : ((state & LAYOUT_SHIFT) ? 0xF1960 : 0xF1961); // 󱥘 󱥛 󱥠 󱥡
    case 0x17: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF197E : 0xF1965) : ((state & LAYOUT_SHIFT) ? 0xF196D : 0xF196C); // 󱥾 󱥥 󱥭 󱥬
    case 0x18: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF196F : 0xF1970) : ((state & LAYOUT_SHIFT) ? 0xF1915 : 0xF195E); // 󱥯 󱥰 󱤕 󱥞
    case 0x19: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF197F : 0xF191D) : ((state & LAYOUT_SHIFT) ? 0xF196A : 0xF1977); // 󱥿 󱤝 󱥪 󱥷
    case 0x1A: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1972 : 0xF195A) : ((state & LAYOUT_SHIFT) ? 0xF1975 : 0xF1921); // 󱥲 󱥚 󱥵 󱤡
    case 0x1B: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF195F : 0xF1971) : ((state & LAYOUT_SHIFT) ? 0xF1936 : 0xF1949); // 󱥟 󱥱 󱤶 󱥉
    case 0x1C: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1981 : 0xF1917) : ((state & LAYOUT_SHIFT) ? 0xF1907 : 0xF192C); // 󱦁 󱤗 󱤇 󱤬
    case 0x1D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1938 : 0xF1937) : ((state & LAYOUT_SHIFT) ? 0xF1922 : 0xF1967); // 󱤸 󱤷 󱤢 󱥧
    case 0x1E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1979 : 0xF1957) : ((state & LAYOUT_SHIFT) ? 0xF1939 : 0xF1973); // 󱥹 󱥗 󱤹 󱥳
    case 0x1F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1901 : 0xF1951) : ((state & LAYOUT_SHIFT) ? 0xF193E : 0xF196E); // 󱤁 󱥑 󱤾 󱥮
    case 0x20: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF197D : 0xF190B) : ((state & LAYOUT_SHIFT) ? 0xF193D : 0xF193C); // 󱥽 󱤋 󱤽 󱤼
    case 0x21: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF19A1 : 0xF1932) : ((state & LAYOUT_SHIFT) ? 0xF1908 : 0xF1969); // 󱦡 󱤲 󱤈 󱥩
    case 0x22: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF197B : 0xF1943) : ((state & LAYOUT_SHIFT) ? 0xF194C : 0xF192D); // 󱥻 󱥃 󱥌 󱤭
    case 0x23: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1983 : 0xF1966) : ((state & LAYOUT_SHIFT) ? 0xF1963 : 0xF1928); // 󱦃 󱥦 󱥣 󱤨
    case 0x24: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1980 : 0xF1974) : ((state & LAYOUT_SHIFT) ? 0xF1962 : 0xF190A); // 󱦀 󱥴 󱥢 󱤊
    case 0x25: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1978 : 0xF1926) : ((state & LAYOUT_SHIFT) ? 0xF1976 : 0xF1916); // 󱥸 󱤦 󱥶 󱤖
    case 0x26: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF19A3 : 0xF1947) : ((state & LAYOUT_SHIFT) ? 0xF1990 : 0xF1904); // 󱦣 󱥇 sc 󱤄
    case 0x27: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x1F5E7 : 0xF194B) : ((state & LAYOUT_SHIFT) ? 0xF1991 : 0xF1902); // 🗧  󱥋 ec 󱤂
    case 0x2C: return (state & LAYOUT_ALT) ? 0x3000 : 0x0020; // idsp / space
    case 0x2D: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1992 : 0xF1993) : 0x200D; // cce slp zwj
    case 0x2E: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0xF1999 : 0xF1994) : ((state & LAYOUT_SHIFT) ? 0xF1996 : 0xF1995); // clge clpe scj stj
    case 0x2F: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007B : 0x005B) : ((state & LAYOUT_SHIFT) ? 0xF199A : 0xF1997); // { [ srlg slg
    case 0x30: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007D : 0x005D) : ((state & LAYOUT_SHIFT) ? 0xF199B : 0xF1998); // } ] erlg elg
    case 0x31: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007C : 0x005C) : ((state & LAYOUT_SHIFT) ? 0x005F : 0x002F); // | \ _ / (ANSI)
    case 0x32: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007C : 0x005C) : ((state & LAYOUT_SHIFT) ? 0x005F : 0x002F); // | \ _ / (ISO/JIS)
    case 0x33: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x003A : 0x003B) : ((state & LAYOUT_SHIFT) ? 0xF199D : 0xF199C); // : ; 󱦝󱦜
    case 0x34: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x002A : 0x002B) : ((state & LAYOUT_SHIFT) ? 0x0022 : 0x0027); // * + " '
    case 0x35: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x003E : 0x003C) : ((state & LAYOUT_SHIFT) ? 0x0029 : 0x0028); // > < ) (
    case 0x36: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x300E : 0x002C) : ((state & LAYOUT_SHIFT) ? 0x300C : 0x3001); //『 ,「 、
    case 0x37: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x300F : 0x002E) : ((state & LAYOUT_SHIFT) ? 0x300D : 0x3002); // 』. 」。
    case 0x38: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x003F : 0x0021) : ((state & LAYOUT_SHIFT) ? 0x003D : 0x002D); // ? ! = -
    case 0x64: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x300F : 0x300E) : ((state & LAYOUT_SHIFT) ? 0x300D : 0x300C); // 』『 」「 (ISO)
    case 0x87: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x005F : 0x005C) : ((state & LAYOUT_SHIFT) ? 0x005F : 0x002F); // _ \ _ / (JIS)
    case 0x89: return (state & LAYOUT_ALT) ? ((state & LAYOUT_SHIFT) ? 0x007C : 0x00A5) : ((state & LAYOUT_SHIFT) ? 0x005F : 0x00A5); // | ¥ _ ¥ (JIS)
    default: return 0;
  }
}
