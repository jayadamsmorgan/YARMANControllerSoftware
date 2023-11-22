#ifndef VIEW_HPP
#define VIEW_HPP

#include "Adafruit_SSD1306.h"
#include "Display.hpp"

class View {
public:
  uint8_t width;
  uint8_t height;
  uint8_t x = 0;
  uint8_t y = 0;
  uint8_t* pixels;
  View(uint8_t width = DISPLAY_WIDTH, uint8_t height = DISPLAY_HEIGHT);
  View(uint8_t width, uint8_t height, uint8_t x, uint8_t y, uint8_t pixels[]);
  View& operator+=(const View& src);
  void render(Adafruit_SSD1306& display);
  ~View();
};

#endif // VIEW_HPP

