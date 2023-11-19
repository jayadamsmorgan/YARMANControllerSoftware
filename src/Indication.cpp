#include "Indication.hpp"
#include "GPIO.hpp"
#include "BLE.h"

void led_indication_error(uint8_t long_ind, uint8_t short_ind) {
  if (led_indication_thread_id != NULL) {
    osThreadTerminate(led_indication_thread_id);
  }

  led_indication_thread_id = osThreadNew(led_indication_error_thr, (int*) (long_ind * 10 + short_ind), NULL);
}

void led_indication_breathe() {
  if (led_indication_thread_id != NULL) {
    osThreadTerminate(led_indication_thread_id);
  }

  led_indication_thread_id = osThreadNew(led_indication_breathe_thr, NULL, NULL);

}

void led_indication_error_thr(void* blink_amount) {
  int amountOfBlinks = (int) blink_amount;
  while (true) {
    for (auto i = 0; i < amountOfBlinks / 10; i++) {
      digitalWrite(PIN_INDICATION_LED, HIGH);
      osDelay(500);
      digitalWrite(PIN_INDICATION_LED, LOW);
      osDelay(500);
    }
    for (auto i = 0; i < amountOfBlinks % 10; i++) {
      digitalWrite(PIN_INDICATION_LED, HIGH);
      osDelay(250);
      digitalWrite(PIN_INDICATION_LED, LOW);
      osDelay(250);
    }
    osDelay(750);
  }
}

void led_indication_breathe_thr(void*) {
  int delayStep = (BREATHE_DELAY / 2) / maxDAC;
  if (delayStep <= 0) {
    delayStep = 1;
  }
  while (true) {
    for (auto i = 0; i < maxDAC; i++) {
      analogWrite(PIN_INDICATION_LED, i);
      osDelay(delayStep);
    }
    for (auto i = maxDAC - 1; i > 0; i--) {
      analogWrite(PIN_INDICATION_LED, i);
      osDelay(delayStep);
    }
  }
}

void led_indication_static_thr(void*) {
  while (true) {
    digitalWrite(PIN_INDICATION_LED, HIGH);
    osDelay(1000);
  }
}

