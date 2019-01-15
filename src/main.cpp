#include <Arduino.h>
#include <Wire.h>
#include <RotorCtl.h>

// Function declarations
void receiveEvent(int byteCount);

// Globals
RotorCtl rotorCtl;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
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
  // Serial.print((commandStr + "\n\r"));
  rotorCtl.decodeCommand(commandStr);
}