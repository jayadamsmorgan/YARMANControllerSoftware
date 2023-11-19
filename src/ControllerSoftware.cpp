#include "Arduino.h"
#include "BLE.hpp"
#include "View.hpp"

void setup() {
  begin_gpio();
  begin_power();
  #ifdef DEBUG
  begin_logging();
  #endif
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
  osThreadExit();
}

void loop() { }

