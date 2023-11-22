#include "Logging.hpp"
#include "Power.hpp"
#include "STM32WB.h"
#include "Indication.hpp"
#include "StringQueue.hpp"

#ifdef DEBUG

static StringQueue logging_queue;
static osMutexId_t logging_queue_mtx;

void log_msg(const String& str) {
  osMutexAcquire(logging_queue_mtx, 0u);
  logging_queue.enqueue(str);
  osMutexRelease(logging_queue_mtx);
}

void logging_thread(void*) {
  String buffer;
  LOG("LOGGING_THREAD: Started.");
  while (true) {
    if (logging_queue.isEmpty()) {
      osDelay(100);
    } else {
      osMutexAcquire(logging_queue_mtx, 0u);
      logging_queue.getFront(buffer);
      logging_queue.dequeue();
      osMutexRelease(logging_queue_mtx);
      Serial.println(buffer);
    }
  }
}

void begin_logging() {
  LOG("LOGGING_SETUP: Setting up...");
  Serial.begin(SERIAL_BAUD);
  while (!Serial) { }
  logging_queue_mtx = osMutexNew(NULL);
  if (logging_queue_mtx == NULL) {
    Serial.println("ERROR: LOGGING_SETUP: Cannot create logging queue mutex.");
    ERR_LOG_QUE_INIT();
    startup_error = true;
    return;
  }
  LOG("LOGGING_SETUP: Logging queue created.");
  loggingThreadId = osThreadNew(logging_thread, NULL, NULL);
  if (loggingThreadId == NULL) {
    Serial.println("ERROR: LOGGING_SETUP: Cannot create logging thread.");
    ERR_LOG_THR_START();
    startup_error = true;
  }
  LOG("LOGGING_SETUP: Done setting up.");
}

#endif // DEBUG

