#include <Arduino.h>
#include <Wire.h>
#include <RotorCtl.h>

// Function declarations
void receiveEvent(int byteCount);

// Globals
RotorCtl rotorCtl;

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  delay(500);
}

void receiveEvent(int byteCount) {
  String commandStr = "";
  while (Wire.available()) {
    char c = Wire.read();
    commandStr += c;
  }

  rotorCtl.stageNewCommand(commandStr);
  rotorCtl.writeToSteer();
  rotorCtl.writeToThrot();
}