#ifndef HANDLE_HPP
#define HANDLE_HPP

#include "Arduino.h"
#include "Logging.hpp"
#include "RTOS2.h"

#define HDL_THR_DELAY       3

static int handle_val;
static osThreadId_t handle_thread_id;

int filtering(int oldVal);

void handle_thread(void*);

void begin_handle();

#endif // HANDLE_HPP
