#include "Wire.h"
#include <Arduino.h>
#include "button.h"

#define PIN_BUTTON 5
#define WAIT_TIME_S 3

Button button_make(PIN_BUTTON);
const int address = 10;

void setup() {
  Wire.begin();
}

void loop() {
    if (button_make.wasPressed()){
      Wire.beginTransmission(address);
      Wire.write(WAIT_TIME_S);
      Wire.endTransmission();
    }
}
