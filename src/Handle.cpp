#include "Handle.hpp"
#include "GPIO.hpp"
#include "Indication.hpp"
#include "Power.hpp"

int filtering(int oldVal) {
  // TODO: filtering
  return oldVal;
}

void handle_thread(void*) {
  LOG("HANDLE_THREAD: Started.");
  while (true) {
    handle_val = filtering(analogRead(PIN_HANDLE));
    osDelay(HDL_THR_DELAY);
  }
}

void begin_handle() {
  handle_thread_id = osThreadNew(handle_thread, NULL, NULL);
  if (handle_thread_id == NULL) {
    LOGERR("HANDLE_SETUP: Cannot create handle thread.");
    ERR_HDL_THR_START();
    STOP();
  }
}

