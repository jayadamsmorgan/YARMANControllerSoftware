#include "Arduino.h"
#include "BLE.hpp"
#include "BLE.h"
#include "Indication.hpp"
#include "RTOS2.h"
#include "Power.hpp"
#include "STM32WB.h"

BLEService handle_service(HANDLE_SERVICE_UUID);
BLECharacteristic handle_characteristic(
  HANDLE_CHARACTERISTIC_UUID, HANDLE_CHARACTERISTIC_PROP, handle_val);

BLEService controller_state_service(CONTROLLER_STATE_SERVICE_UUID);
BLECharacteristic is_co_charging_characteristic(
  IS_CO_CHARGING_CHARACTERISTIC_UUID, IS_CO_CHARGING_CHARACTERISTIC_PROP, is_co_charging());
#if defined(DEBUG) && !defined(NO_TEMP_THR)
BLECharacteristic co_temperature_characteristic(
  CO_TEMPERATURE_CHARACTERISTIC_UUID, CO_TEMPERATURE_CHARACTERISTIC_PROP, STM32WB.readTemperature());
#endif // DEBUG && NO_TEMP_THR

BLEService co_data_service(CO_DATA_SERVICE_UUID);
BLECharacteristic co_data_characteristic(
  CO_DATA_CHARACTERISTIC_UUID, CO_DATA_CHARACTERISTIC_PROP, co_data);


void on_connect() {
}

void ble_thread(void *) {
  int old_handle_val = 0;
  bool old_charging_val = false;
  float old_temperature = 0.0f;
  LOG("BLE_THREAD: Started.");
  while (true) {
    if (!BLE.advertising() && !BLE.connected()) {
      BLE.advertise();
    }
    if (handle_val != old_handle_val) {
      handle_characteristic.writeValue(handle_val);
      old_handle_val = handle_val;
    }
    bool is_chrgn = is_co_charging();
    if (is_chrgn != old_charging_val) {
      is_co_charging_characteristic.writeValue(is_chrgn);
      old_charging_val = is_chrgn;
    }
    #if defined(DEBUG) && !defined(NO_TEMP_THR)
    if (co_temperature != old_temperature) {
      co_temperature_characteristic.writeValue(co_temperature);
      old_temperature = co_temperature;
    }
    #endif // DEBUG && NO_TEMP_THR
    // TODO: Go to sleep once values dont change over some period of time.
    osDelay(1);
  }
}


void begin_ble() {
  if (!BLE.begin()) {
    LOGERR("BLE_SETUP: Cannot initiate BLE.");
    ERR_BLE_INIT();
    STOP();
    return;
  }
  BLE.setTxPowerLevel(2);
  LOG("BLE_SETUP: BLE initiated successfully.");
  BLE.setIncludeTxPowerLevel(true);
  BLE.setDeviceName(BLE_LOCAL_NAME);
  BLE.setLocalName(BLE_LOCAL_NAME);
  BLE.setManufacturerData(manufacturer_data, sizeof(manufacturer_data));
  BLE.onConnect(on_connect);
  //BLE.setSecurity(BLE_SECURITY_AUTHENTICATED_SECURE_CONNECTION);
  LOGCAT("BLE_SETUP: BLE Local name:", BLE_LOCAL_NAME);
  //LOGCAT("BLE_SETUP: BLE Address:", BLE.address());
  handle_service.addCharacteristic(handle_characteristic);
  co_data_service.addCharacteristic(co_data_characteristic);
  LOGCAT("BLE_SETUP: Controller Data String: ", CONTROLLER_DATA_STRING);
  controller_state_service.addCharacteristic(is_co_charging_characteristic);
  #if defined(DEBUG) && !defined(NO_TEMP_THR)
  controller_state_service.addCharacteristic(co_temperature_characteristic);
  #endif // DEBUG && NO_TEMP_THR
  BLE.addService(handle_service);
  BLE.addService(co_data_service);
  BLE.addService(controller_state_service);
  BLE.advertise();
  ble_thread_id = osThreadNew(ble_thread, NULL, NULL);
  if (ble_thread_id == NULL) {
    LOGERR("BLE_SETUP: Cannot start BLE thread.");
    ERR_BLE_THR_START();
    STOP();
  }
  LOG("BLE_SETUP: BLE setted up successfully.");
}
