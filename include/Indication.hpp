#ifndef INDICATION
#define INDICATION

#include "Logging.hpp"
#include "Arduino.h"
#include "RTOS2.h"


#define ERR_LOG_QUE_INIT()              LED_IND_ERROR(1, 1)
#define ERR_LOG_THR_START()             LED_IND_ERROR(1, 2)

#define ERR_BLE_INIT()                  LED_IND_ERROR(2, 1)
#define ERR_BLE_THR_START()             LED_IND_ERROR(2, 2)

#define ERR_DFU_THR_START()             LED_IND_ERROR(3, 1)
#define ERR_RST_THR_START()             LED_IND_ERROR(3, 2)
#define ERR_TEMP_THR_START()            LED_IND_ERROR(3, 3)
#define ERR_BATT_THR_START()            LED_IND_ERROR(3, 4)

#define ERR_HDL_THR_START()             LED_IND_ERROR(4, 1)

#define ERR_DISP_INIT()                 LED_IND_ERROR(5, 1)
#define ERR_VIEW_QUE_INIT()             LED_IND_ERROR(5, 2)
#define ERR_GUI_THR_START()             LED_IND_ERROR(5, 3)
#define ERR_VIEW_THR_START()            LED_IND_ERROR(5, 4)

#define LED_IND_ERROR(LONG, SHORT)    led_indication_error(LONG, SHORT)

#define BREATHE_DELAY                 2048

static osThreadId_t led_indication_thread_id;

void led_indication_error(uint8_t long_ind, uint8_t short_ind);

void led_indication_breathe();

void led_indication_error_thr(void* blink_amount);

void led_indication_breathe_thr(void*);

void led_indication_static_thr(void*);

void begin_indication();


#endif // INDICATION
