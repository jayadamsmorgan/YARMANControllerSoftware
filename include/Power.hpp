#ifndef POWER_HPP
#define POWER_HPP

#define STOP()            while (1) { osDelay(1); }

#ifdef PIN_RESTART
void restart_thread(void*);
#endif

#ifdef PIN_ENTER_DFU
void dfu_enter_thread(void*);
#endif

#if defined(DEBUG) && !defined(NO_TEMP_THR)
static float co_temperature = 0.0f;
void read_temperature_thread(void*);
#ifndef TEMP_THREAD_DELAY
#define TEMP_THREAD_DELAY 15000
#endif // TEMP_THREAD_DELAY
#endif // DEBUG && NO_TEMP_THR

static bool startup_error = false;

static bool is_lb_charging;
bool is_co_charging();

void begin_power();

#endif // POWER_HPP
