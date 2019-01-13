#include <Arduino.h>
#include <Wire.h>

void receiveEvent(int byteCount) {
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.print("\n\r");
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