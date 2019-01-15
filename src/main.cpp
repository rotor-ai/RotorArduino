#include <Arduino.h>
#include <Wire.h>
#include <RotorCtl.h>

// Function declarations
void receiveEvent(int byteCount);

// Globals
RotorCtl rotorCtl;
String startupCmd = "N000, N000";

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

  // startup Sequence
  rotorCtl.stageNewCommand(startupCmd);
  rotorCtl.writeToSteer();
  rotorCtl.writeToThrot();
  rotorCtl.powerOnRotor();
  delay(2000);
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