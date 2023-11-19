#include "GPIO.hpp"
#include "Logging.hpp"

void begin_gpio() {
  analogReadResolution(ADC_RES);
  analogWriteResolution(DAC_RES);
  analogWriteFrequency(DAC_FREQ);
  LOGCAT("GPIO_SETUP: ADC_RESOLUTION:", ADC_RES);
  LOGCAT("GPIO_SETUP: DAC_RESOLUTION:", DAC_RES);
  LOGCAT("GPIO_SETUP: DAC_FREQUENCY: ", DAC_FREQ);
  pinMode(PIN_HANDLE, OUTPUT);
  pinMode(PIN_INDICATION_LED, OUTPUT);
  pinMode(PIN_IS_CHARGING, INPUT);
  #ifdef PIN_ENTER_DFU
  pinMode(PIN_ENTER_DFU, INPUT_PULLUP);
  #endif // PIN_ENTER_DFU
  #ifdef PIN_RESTART
  pinMode(PIN_RESTART, INPUT_PULLUP);
  #endif // PIN_RESTART
}
