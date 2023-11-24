#include "Power.hpp"
#include "GPIO.hpp"
#include "Indication.hpp"
#include "STM32WB.h"
#include "RTOS2.h"

#ifdef PIN_ENTER_DFU
void dfu_enter_isr() {
  #ifdef DEBUG
  Serial.println("DFU_ENTER_ISR: Entering DFU...");
  osDelay(100);
  #endif // DEBUG
  STM32WB.dfu();
}
#endif // PIN_ENTER_DFU

#ifdef PIN_RESTART
void restart_isr() {
  #ifdef DEBUG
  Serial.println("RESTART_ISR: Restarting controller...");
  osDelay(100);
  #endif // DEBUG
  STM32WB.reset();
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

void read_co_battery_thread(void*) {
  LOG("CONTROLLER_BATTERY_THREAD: Started.");
  while (true) {
    co_battery_percentage = get_co_battery_percentage();
    #ifdef DEBUG
    if (is_co_charging()) {
      LOG("CONTROLLER_BATTERY_THREAD: Battery is charging.");
    } else {
      LOG("CONTROLLER_BATTERY_THREAD: Battery is not charging.");
    }
    #endif // DEBUG
    LOG("CONTROLLER_BATTERY_THREAD: Battery: "
        + String(co_battery_percentage) + "%");
    osDelay(BATT_PERCENTAGE_THREAD_DELAY);
  }
}

uint8_t get_co_battery_percentage() {
  // TODO: get BMS data
  return 55;
}

bool is_co_charging() {
  return digitalRead(PIN_IS_CHARGING) == 1;
}

void begin_power() {
  LOG("POWER_SETUP: Setting up...");
  is_lb_charging = false;
  #ifdef PIN_ENTER_DFU
  LOGCAT("POWER_SETUP: PIN_ENTER_DFU:", PIN_ENTER_DFU);
  attachInterrupt(PIN_ENTER_DFU, dfu_enter_isr, FALLING);
  LOG("POWER_SETUP: ISR Attached to PIN_ENTER_DFU.");
  #endif // PIN_ENTER_DFU
  #ifdef PIN_RESTART
  LOGCAT("RESTART_THREAD: PIN_RESTART:", PIN_RESTART);
  attachInterrupt(PIN_RESTART, restart_isr, FALLING);
  LOG("POWER_SETUP: ISR Attached to PIN_RESTART.");
  #endif // PIN_RESTART
  #if defined(DEBUG) && !defined(NO_TEMP_THR)
  if (osThreadNew(read_temperature_thread, NULL, NULL) == NULL) {
    LOGERR("POWER_SETUP: Cannot start temperature thread.");
    ERR_TEMP_THR_START();
    startup_error = true;
  }
  #endif
  if (osThreadNew(read_co_battery_thread, NULL, NULL) == NULL) {
    LOGERR("POWER_SETUP: Cannot start controller battery percentage thread.");
    ERR_BATT_THR_START();
    startup_error = true;
  }
  LOG("POWER_SETUP: Done setting up.");
}

