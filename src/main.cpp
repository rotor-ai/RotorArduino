#include <Arduino.h>
#include <Wire.h>

void decodeCommand(String command) {
  // TODO
}

void receiveEvent(int byteCount) {
  String commandStr = "";
  while (Wire.available()) {
    char c = Wire.read();
    commandStr += c;
  }
  // Serial.print((commandStr + "\n\r"));
  // Serial.print("\n\r");
  decodeCommand(commandStr);
}

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