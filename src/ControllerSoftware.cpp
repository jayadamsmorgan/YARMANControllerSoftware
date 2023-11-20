#include "Arduino.h"
#include "BLE.hpp"
#include "Display.hpp"

void setup() {
  LOG("SETUP: Booting...");
  begin_gpio();
  begin_power();
  #ifdef DEBUG
  begin_logging();
  #endif
  begin_display();
  begin_handle();
  begin_ble();
  #ifdef DEBUG
  if (!startup_error) {
    for (auto i = 0; i < 2; i++) {
      digitalWrite(PIN_INDICATION_LED, HIGH);
      osDelay(250);
      digitalWrite(PIN_INDICATION_LED, LOW);
      osDelay(250);
    }
  }
  #endif // DEBUG
  LOG("SETUP: Device booted successfully");
  osThreadExit();
}

void loop() { }

