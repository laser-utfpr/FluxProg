#ifndef COLORDATA_HPP
#define COLORDATA_HPP

enum class ColorSelector: char {
  R = 0x00,
  B = 0x01,
  W = 0x02,
  G = 0x03,
};

inline ColorSelector next(ColorSelector c) { return static_cast<ColorSelector>((static_cast<char>(c) + 1) % 4); }
inline int lsb(ColorSelector c) { return static_cast<char>(c) & 0x01; }
inline int msb(ColorSelector c) { return (static_cast<char>(c) & 0x02) >> 1; }

struct Color {
  int r, g, b, w;

  int& operator[](ColorSelector sel) {
    switch (sel) {
    case ColorSelector::R: return r;
    case ColorSelector::G: return g;
    case ColorSelector::B: return b;
    case ColorSelector::W: return w;
    }
  }

  void print(HardwareSerial& serial = Serial) {
    serial.print('{');
    serial.print(r); serial.print(", ");
    serial.print(g); serial.print(", ");
    serial.print(b); serial.print(", ");
    serial.print(w); serial.print('}');
  };
};

inline bool operator==(const Color& a, const Color& b) {
  return a.r == b.r && a.g == b.g && a.b == b.b && a.w == b.w;
}

inline unsigned long euc_dist(Color& a, Color& b) {
  unsigned long dr = a.r - b.r;
  unsigned long dg = a.g - b.g;
  unsigned long db = a.b - b.b;
  unsigned long dw = a.w - b.w;
  return dr*dr + dg*dg + db*db + dw*dw;
}

#endif
