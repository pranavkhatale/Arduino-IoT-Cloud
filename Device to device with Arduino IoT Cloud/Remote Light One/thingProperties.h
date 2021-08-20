// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[]           = "";
const char DEVICE_LOGIN_NAME[]  = "";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onSwitch2Change();
void onSwitch1Change();

bool switch_2;
int switch_1;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(switch_2, READWRITE, ON_CHANGE, onSwitch2Change);
  ArduinoCloud.addProperty(switch_1, READWRITE, ON_CHANGE, onSwitch1Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
