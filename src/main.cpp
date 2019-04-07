#include <Arduino.h>
#include <Wire.h>
#include <RotorCtl.h>
#include <Servo.h>

// Function declarations
void receiveEvent(int byteCount);

// Globals
String startupCmd = "N000, N000";
Servo steerServo;
Servo esc;
RotorCtl rotorCtl(steerServo, esc);

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

  Serial.println("Starting up...");

  // startup Sequence
  rotorCtl.stageNewCommand(startupCmd);
  rotorCtl.writeToSteer();
  rotorCtl.writeToThrot();
  rotorCtl.powerOnRotor();
  delay(1000);

  steerServo.attach(11);
  esc.attach(10);

  Serial.println("Started up...");
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

  // Serial.println(commandStr);
  rotorCtl.stageNewCommand(commandStr);
  rotorCtl.writeToSteer();
  rotorCtl.writeToThrot();

}