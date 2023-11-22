#include "Display.hpp"
#include "Adafruit_SSD1306.h"
#include "Indication.hpp"
#include "Logging.hpp"
#include "Power.hpp"
#include "Wire.h"
#include "ViewQueue.hpp"
#include "Views.hpp"


Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, DISPLAY_RESET);
ViewQueue view_queue;
osMutexId_t view_queue_mutex;

void add_view(View view) {
  osMutexAcquire(view_queue_mutex, 0u);
  view_queue.enqueue(view);
  osMutexRelease(view_queue_mutex);
}

void view_thread(void*) {
  LOG("VIEW_THREAD: Started.");
  osDelay(DISPLAY_LOGO_MS);
  View battery_view(
    BATTERY_LOGO_WIDTH,
    BATTERY_LOGO_HEIGHT,
    battery_bmp
  );
  while (true) {
    View mainView(DISPLAY_WIDTH, DISPLAY_HEIGHT);

    // Add batteries to the view
    mainView += battery_view;
    battery_view.x = LB_BATTERY_LOGO_X;
    battery_view.y = LB_BATTERY_LOGO_Y;
    mainView += battery_view;

    // Get percentage and add battery splits to battery logo
    float battery_percentage = get_co_battery_percentage();
    // 0-100 -> 0-BATTERY_SPLITS
    uint8_t battery_splits_count = (battery_percentage / 100) * BATTERY_SPLITS;
    for (auto i = 0; i < battery_splits_count; i++) {
      View batt_split_view(
        BATTERY_SPLIT_WIDTH,
        BATTERY_SPLIT_HEIGHT,
        CO_BATTERY_LOGO_X + 1 + i,
        CO_BATTERY_LOGO_Y + 1,
        battery_split_bmp
      );
      mainView += batt_split_view;
    }
    // Add actual percentage right after battery logo
    View battery_percentage_view =
      get_percentage_view(
        battery_percentage,
        CO_BATTERY_LOGO_X + BATTERY_LOGO_WIDTH + CHAR_SPACING_MAX,
        CO_BATTERY_LOGO_Y);
    mainView += battery_percentage_view;

    // Same goes for longboard battery:
    // P.S. might change appearance of LB Battery as it probably should be larger.
    // TODO: add some signs or smth else to distiguish controller and lb battery statuses. 
    battery_percentage = lb_battery_percentage;
    battery_splits_count = (battery_percentage / 100) * BATTERY_SPLITS;
    for (auto i = 0; i < battery_splits_count; i++) {
      View batt_split_view(
        BATTERY_SPLIT_WIDTH,
        BATTERY_SPLIT_HEIGHT,
        LB_BATTERY_LOGO_X + 1 + i,
        LB_BATTERY_LOGO_Y + 1,
        battery_split_bmp
      );
      mainView += batt_split_view;
    }
    battery_percentage_view =
      get_percentage_view(
        battery_percentage,
        LB_BATTERY_LOGO_X + BATTERY_LOGO_WIDTH + CHAR_SPACING_MAX,
        LB_BATTERY_LOGO_Y);
    mainView += battery_percentage_view;
    add_view(mainView);
    osDelay(VIEW_THREAD_DELAY);
  }
}

void gui_thread(void*) {
  LOG("GUI_THREAD: Started.");
  View view;
  while(true) {
    if (!view_queue.isEmpty()) {
      osMutexAcquire(view_queue_mutex, 0u);
      view_queue.getFront(view);
      view_queue.dequeue();
      osMutexRelease(view_queue_mutex);
      view.render(display);
      LOG("GUI_THREAD: View rendered.");
    }
    osDelay(GUI_THREAD_DELAY);
  }
}

void begin_display() {
  LOG("DISPLAY_SETUP: Setting up...");
  if (!display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS)) {
    LOGERR("FATAL: DISPLAY_SETUP: Cannot initiate display.");
    ERR_DISP_INIT();
    STOP();
  }
  display.clearDisplay();
  LOG("DISPLAY_SETUP: Display initiated successfully.");

  LOG("DISPLAY_SETUP: Preparing boot view.");
  View boot_view;
  View logo_view(16, 16);
  logo_view.x = DISPLAY_WIDTH / 2 - 16;
  logo_view.y = DISPLAY_HEIGHT / 2 - 16;
  logo_view.pixels = (uint8_t*) logo_bmp;
  boot_view += logo_view;
  add_view(boot_view);
  LOG("DISPLAY_SETUP: Boot view sent to queue.");

  view_queue_mutex = osMutexNew(NULL);
  if (view_queue_mutex == NULL) {
    LOGERR("FATAL: DISPLAY_SETUP: Cannot create view queue mutex.");
    ERR_VIEW_QUE_INIT();
    startup_error = true;
  }
  LOG("DISPLAY_SETUP: View queue created.");
  gui_thread_id = osThreadNew(gui_thread, NULL, NULL);
  if (gui_thread_id == NULL) {
    LOGERR("FATAL: DISPLAY_SETUP: Cannot create GUI thread.");
    ERR_GUI_THR_START();
    startup_error = true;
  }
  view_thread_id = osThreadNew(view_thread, NULL, NULL);
  if (view_thread_id == NULL) {
    LOGERR("FATAL: DISPLAY_SETUP: Cannot create View thread.");
    ERR_VIEW_THR_START();
    startup_error = true;
  }
  LOG("DISPLAY_SETUP: Done setting up.");
}


