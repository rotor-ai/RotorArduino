#include <Arduino.h>
#include <Wire.h>

void receiveEvent(int byteCount) {
  while (Wire.available()) {
    char c = Wire.read();
    digitalWrite(LED_BUILTIN, c);
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
}

void loop() {
  delay(1000);
}
