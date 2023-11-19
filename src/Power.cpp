#include "Power.hpp"
#include "GPIO.hpp"
#include "Indication.hpp"
#include "STM32WB.h"
#include "RTOS2.h"

#ifdef PIN_ENTER_DFU
void dfu_enter_thread(void*) {
  while (true) {
    if (!digitalRead(PIN_ENTER_DFU)) {
      LOG("DFU_ENTER_THREAD: Entering DFU...");
      osDelay(100);
      STM32WB.dfu();
    }
    osDelay(50);
  }
}
#endif // PIN_ENTER_DFU

#ifdef PIN_RESTART
void restart_thread(void*) {
  while (true) {
    if (!digitalRead(PIN_RESTART)) {
      osDelay(1000);
      if (!digitalRead(PIN_RESTART)) {
        LOG("RESTART_THREAD: Restarting controller...");
        osDelay(100);
        STM32WB.reset();
      }
    }
  }
}
#endif // PIN_RESTART

#if defined(DEBUG) && !defined(NO_TEMP_THR)
void read_temperature_thread(void*) {
  LOG("TEMP_THREAD: Started.");
  while (true) {
    co_temperature = STM32WB.readTemperature();
    LOG("TEMP_THREAD: Temperature: " + String(co_temperature) + "°C");
    osDelay(TEMP_THREAD_DELAY);
  }
}
#endif // DEBUG && NO_TEMP_THR

bool is_co_charging() {
  return digitalRead(PIN_IS_CHARGING) == 1;
}

void begin_power() {
  is_lb_charging = false;
  #ifdef PIN_ENTER_DFU
  if (osThreadNew(dfu_enter_thread, NULL, NULL) == NULL) {
    ERR_DFU_THR_START();
    startup_error = true;
  }
  #endif // PIN_ENTER_DFU
  #ifdef PIN_RESTART
  if (osThreadNew(restart_thread, NULL, NULL) == NULL) {
    ERR_RST_THR_START();
    startup_error = true;
  }
  #endif // PIN_RESTART
  #if defined(DEBUG) && !defined(NO_TEMP_THR)
  if (osThreadNew(read_temperature_thread, NULL, NULL) == NULL) {
    ERR_TEMP_THR_START();
    startup_error = true;
  }
  #endif
}
