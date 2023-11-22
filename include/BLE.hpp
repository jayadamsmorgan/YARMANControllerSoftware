#ifndef BLE_HPP
#define BLE_HPP

#include "Arduino.h"
#include "BLE.h"
#include "Handle.hpp"
#include "Logging.hpp"
#include "Indication.hpp"
#include "Power.hpp"
#include "GPIO.hpp"
#include "RTOS2.h"

#define BLE_LOCAL_NAME          "YARMAN_CONTROLLER"

#define BLE_POWER_LEVEL         2

#ifndef CONTROLLER_DATA_STRING
#define CONTROLLER_DATA_STRING      "YARMAN_CO_V0.0_FW_V0.0"
#endif // !CONTROLLER_DATA_STRING


/*
  *  BLE_PROPERTY             PROPERTY_LOCATION                PROPERTY_SETTINGS
  *   handle_val                controller                        read, notify
  *   power_mode                longboard                         read, notify
  *   is_lb_charging            longboard                         read, notify
  *   is_co_charging            controller                        read, notify
  *   lb_data                   longboard                         read
  *   co_data                   controller                        read
  */

static const char* co_data = CONTROLLER_DATA_STRING;

#define HANDLE_SERVICE_UUID                     "20000000-0001-11e0-ac36-0002a5d5c51b"
#define HANDLE_CHARACTERISTIC_UUID              "20000000-0001-11e1-ac36-0002a5d5c51b"
#define HANDLE_CHARACTERISTIC_PROP              (BLE_PROPERTY_READ | BLE_PROPERTY_NOTIFY)

#define CONTROLLER_STATE_SERVICE_UUID           "20000000-0001-11e1-ac36-0002a5d5c51b"
#define IS_CO_CHARGING_CHARACTERISTIC_UUID      "20000000-0002-11e1-ac36-0002a5d5c51b"
#define IS_CO_CHARGING_CHARACTERISTIC_PROP      (BLE_PROPERTY_READ | BLE_PROPERTY_NOTIFY)
#define CO_BATT_PERCENTAGE_CHARACTERISTIC_UUID  "20000000-0005-11e1-ac36-0002a5d5c51b"
#define CO_BATT_PERCENTAGE_CHARACTERISTIC_PROP  (BLE_PROPERTY_READ | BLE_PROPERTY_NOTIFY)

#define LONGBOARD_STATE_SERVICE_UUID            "20000000-0006-11e1-ac36-0002a5d5c51b"
#define IS_LB_CHARGING_CHARACTERISTIC_UUID      "20000000-0007-11e1-ac36-0002a5d5c51b"
#define IS_LB_CHARGING_CHARACTERISTIC_PROP      (BLE_PROPERTY_READ | BLE_PROPERTY_WRITE | BLE_PROPERTY_NOTIFY)
#define LB_BATT_PERCENTAGE_CHARACTERISTIC_UUID  "20000000-0007-11e1-ac36-0002a5d5c51b"
#define LB_BATT_PERCENTAGE_CHARACTERISTIC_PROP  (BLE_PROPERTY_READ | BLE_PROPERTY_WRITE | BLE_PROPERTY_NOTIFY)
#if !defined(DEBUG) || defined(FORCE_DEBUG_BLE_SECURE_PERM)
#define IS_LB_CHARGING_CHARACTERISTIC_PERM      (BLE_PERMISSION_WRITE_AUTHENTICATED_SECURE_CONNECTION)
#define LB_BATT_PERCENTAGE_CHARACTERISTIC_PERM  (BLE_PERMISSION_WRITE_AUTHENTICATED_SECURE_CONNECTION)
#else // !DEBUG || FORCE_DEBUG_BLE_SECURE_PERM
#define IS_LB_CHARGING_CHARACTERISTIC_PERM      (BLE_PERMISSION_READ_UNENCRYPTED)
#define LB_BATT_PERCENTAGE_CHARACTERISTIC_PERM  (BLE_PERMISSION_READ_UNENCRYPTED)
#endif // !DEBUG || FORCE_DEBUG_BLE_SECURE_PERM


#if defined(DEBUG) && !defined(NO_TEMP_THR)
#define CO_TEMPERATURE_CHARACTERISTIC_UUID      "20000000-0004-11e1-ac36-0002a5d5c51b"
#define CO_TEMPERATURE_CHARACTERISTIC_PROP      (BLE_PROPERTY_READ)
#endif // DEBUG && !NO_TEMP_THR

#define CO_DATA_SERVICE_UUID                    "20000000-0001-11e2-ac36-0002a5d5c51b"
#define CO_DATA_CHARACTERISTIC_UUID             "20000000-0003-11e1-ac36-0002a5d5c51b"
#define CO_DATA_CHARACTERISTIC_PROP             (BLE_PROPERTY_READ)


/*
  *           MANUFACTURER_DATA
  *
  *       (TODO)
  */

static const uint8_t manufacturer_data[6] = {
    0x01,
    0x00,
    (uint8_t)(0x20000000 >> 24),
    (uint8_t)(0x20000000 >> 16),
    (uint8_t)(0x20000000 >> 8),
    (uint8_t)(0x20000000 >> 0),
};

static osThreadId_t ble_thread_id;

void ble_thread(void*);

void begin_ble();

#endif // !BLE_HPP

