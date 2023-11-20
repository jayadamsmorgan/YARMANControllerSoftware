#include "Display.hpp"
#include "Adafruit_SSD1306.h"
#include "Logging.hpp"

void gui_thread(void*) {

}

void begin_display() {
  LOG("DISPLAY_SETUP: Setting up...");
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
  LOG("DISPLAY_SETUP: Done setting up.");
}


