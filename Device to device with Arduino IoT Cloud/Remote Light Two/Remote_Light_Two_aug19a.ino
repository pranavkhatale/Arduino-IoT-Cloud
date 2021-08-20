#include "arduino_secrets.h"
#include "thingProperties.h"

int buttonPin = D1;
int ledPin = D0;

void setup() {
  // Initialize serial and wait for port to open:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

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
  
  int buttonState = digitalRead(buttonPin);
  
  if(buttonState == LOW) {
    switch_2 = !switch_2;
    delay(500);
  }
  
  
}

void onSwitch2Change() {
  // Do something
  
}

void onSwitch1Change() {
  // Do something
    if(switch_1) {
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
