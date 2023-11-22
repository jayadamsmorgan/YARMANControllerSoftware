#include "View.hpp"

View::View(uint8_t width, uint8_t height) : width(width), height(height) {
  pixels = new uint8_t[(width * height + 7) / 8]{};
}

View::View(uint8_t width, uint8_t height, uint8_t x, uint8_t y, uint8_t pixels[])
        : width(width), height(height), x(x), y(y) {
  this->pixels = (uint8_t*) pixels;
}

View::~View() {
  delete[] pixels;
}

View& View::operator+=(const View& src) {
  // Calculate overlapping area
  uint8_t startX = max(x, src.x);
  uint8_t endX = min(x + width, src.x + src.width);
  uint8_t startY = max(y, src.y);
  uint8_t endY = min(y + height, src.y + src.height);
  for (uint8_t yy = startY; yy < endY; ++yy) {
    for (uint8_t xx = startX; xx < endX; ++xx) {
      // Calculate the index and bit position in the pixels array
      uint8_t index = yy * width + xx;
      uint8_t bitPos = index % 8;
      index /= 8;
      uint8_t srcIndex = (yy - src.y) * src.width + (xx - src.x);
      uint8_t srcBitPos = srcIndex % 8;
      srcIndex /= 8;
      // Overwrite the bit
      if (src.pixels[srcIndex] & (1 << srcBitPos)) {
          pixels[index] |= (1 << bitPos);
      } else {
          pixels[index] &= ~(1 << bitPos);
      }
    }
  }
  return *this;
}

void View::render(Adafruit_SSD1306& display) {
  display.clearDisplay();
  display.drawBitmap(x, y, pixels, width, height, 1);
  display.display();
}
