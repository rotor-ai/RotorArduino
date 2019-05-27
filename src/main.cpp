#include <Arduino.h>
#include <Wire.h>
#include <RotorCtl.h>
#include <Servo.h>

// Function declarations
void receiveEvent(int byteCount);

// Globals
String startupCmd = "N000, N000";
String bufferedString = "";
Servo steerServo;
Servo esc;
RotorCtl rotorCtl(steerServo, esc);

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.setTimeout(50);

  // Set indicator LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Serial.println("Starting up...");

  // startup Sequence
  rotorCtl.stageNewCommand(startupCmd);
  rotorCtl.writeToSteer();
  rotorCtl.writeToThrot();
  rotorCtl.powerOnRotor();
  delay(1000);

  steerServo.attach(11);
  esc.attach(10);

  // Serial.println("Started up...");
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    String message = Serial.readString();

    // Loop over message and parse
    for (unsigned int j = 0; j < message.length(); j++) {
      char c = message.charAt(j);
      bufferedString += c;
      if (c == '\n') {
        Serial.print(bufferedString);
        bufferedString = "";
      }
    }
  }
}

void receiveEvent(int byteCount) {
  String commandStr = "";
  while (Wire.available()) {
    char c = Wire.read();
    commandStr += c;
  }

  Serial.println("Received msg");

  // Serial.println(commandStr);
  // rotorCtl.stageNewCommand(commandStr);
  // rotorCtl.writeToSteer();
  // rotorCtl.writeToThrot();

}