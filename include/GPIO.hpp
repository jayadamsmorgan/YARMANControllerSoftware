#ifndef GPIO_HPP
#define GPIO_HPP

#include "Arduino.h"

#ifndef ADC_RES
#define ADC_RES                       12
#endif // ADC_RES
#ifndef DAC_RES
#define DAC_RES                       12
#endif // DAC_RES
#ifndef DAC_FREQ
#define DAC_FREQ                      5000
#endif // DAC_FREQ

#ifndef PIN_HANDLE
#define PIN_HANDLE                    PIN_A0
#endif // PIN_HANDLE

#ifndef PIN_IS_CHARGING
#define PIN_IS_CHARGING               12
#endif // PIN_IS_CHARGING

#if !defined(PIN_ENTER_DFU) && defined(DFU_THREAD)
#define PIN_ENTER_DFU                 0
#endif // PIN_ENTER_DFU && DFU_THREAD

#if !defined(PIN_RESTART) && defined(RST_THREAD)
#define PIN_RESTART                   0
#endif // PIN_RESTART && RST_THREAD


#ifndef PIN_INDICATION_LED
#ifdef USB_DONGLE
#define PIN_INDICATION_LED            7
#else // USB_DONGLE
#define PIN_INDICATION_LED            LED_BUILTIN
#endif // USB_DONGLE
#endif // PIN_INDICATION_LED

static const int maxADC = pow(2, ADC_RES);
static const int maxDAC = pow(2, DAC_RES);

void begin_gpio();

#endif // GPIO_HPP
