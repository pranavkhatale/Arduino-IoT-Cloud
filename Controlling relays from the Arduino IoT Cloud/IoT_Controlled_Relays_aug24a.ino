#include "arduino_secrets.h"
#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
}

void onRelay1Change() {
  // Do something
  if(relay_1){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
}

void onRelay2Change() {
  // Do something
    if(relay_2){
    digitalWrite(0, HIGH);
  }
  else{
    digitalWrite(0, LOW);
  }
}
