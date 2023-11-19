#include "View.hpp"

template<uint_fast8_t width, uint_fast8_t height>
View<width, height>::View() {
  memset(pixels, 0, sizeof(pixels));
}

template<uint_fast8_t width, uint_fast8_t height>
View<width, height>::~View() {

}

template<uint_fast8_t width, uint_fast8_t height>
void View<width, height>::render(Adafruit_SSD1306& display) {
  display.clearDisplay();
  display.drawBitmap(x, y, pixels, width, height, 1);
  display.display();
}
