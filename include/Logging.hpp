#ifndef LOGGING_H
#define LOGGING_H

#ifdef DEBUG

#include "RTOS2.h"
#include "StringQueue.hpp"

#if defined(DEBUG) && !defined(SERIAL_BAUD)
#define SERIAL_BAUD             115200
#endif // DEBUG && !SERIAL_BAUD

#define LOG(MSG)        log_msg(String(MSG))
#define LOGCAT(MSG,VAL) LOG(String(MSG) + " '" + String(VAL) + "'.")
#define LOGERR(MSG)     LOG(String("ERROR: ") + String(MSG))

void begin_logging();
static osThreadId_t loggingThreadId;
void log_msg(const String& str);
void logging_task(void*);

#else // DEBUG

#define LOG(MSG)
#define LOGCAT(MSG, VAL)
#define LOGERR(MSG)

#endif // DEBUG

#endif // !LOGGING_H

