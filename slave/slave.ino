#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

const int address = 10;
const int wait_time_beetwen = 100;
Servo servo1;
bool make_turn;

void setup() {
  servo1.attach(9);
  servo1.write(0);
  Wire.begin(address);
  Wire.onReceive(handle_receive);
  make_turn = false;
}

void loop() {
  if(make_turn){
    int time_wait_ms = Wire.read()*1000;
    turn(1, 0, 180);
    delay(time_wait_ms);
    turn(-1, 180, 0);
    make_turn = false;
  }
}

void handle_receive(){
  if (Wire.available())
    make_turn = true;
}

void turn(int step, int begin, int end){
  for (int i=begin; (step > 0 && i < end) || (step < 0 && i > end); i+=step){
    servo1.write(i);
    delay(wait_time_beetwen);
  }
}
