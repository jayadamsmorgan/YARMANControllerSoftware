#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "RTOS2.h"

#define SSD1306_NO_SPLASH

#define DISPLAY_LOGO_MS                1000

#define DISPLAY_WIDTH                  128
#define DISPLAY_HEIGHT                 32

#define DISPLAY_RESET                  -1
#define DISPLAY_ADDRESS                0x3C

#define GUI_THREAD_DELAY              200
#define VIEW_THREAD_DELAY             200

static osThreadId_t gui_thread_id;
static osThreadId_t view_thread_id;

void gui_thread(void*);
void view_thread(void*);

void begin_display();

#endif // DISPLAY_HPP

