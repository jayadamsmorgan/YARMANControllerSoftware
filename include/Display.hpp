#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "RTOS2.h"
#include "View.hpp"

#define SCREEN_WIDTH                  128
#define SCREEN_HEIGHT                 32

static osThreadId_t gui_thread_id;

void gui_thread(void*);

void begin_display();

#endif // DISPLAY_HPP

