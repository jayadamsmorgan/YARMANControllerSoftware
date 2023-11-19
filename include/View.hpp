#ifndef VIEW_HPP
#define VIEW_HPP

#include "Adafruit_SSD1306.h"

template<uint_fast8_t width, uint_fast8_t height>
class View {
public:
  uint_fast8_t x = 0;
  uint_fast8_t y = 0;
  uint_fast8_t pixels[width * height];
  View();
  View& operator+=(const View& src);
  void render(Adafruit_SSD1306& display);
  ~View();
};

#endif // VIEW_HPP

