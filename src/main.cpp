#include <Arduino.h>
#include <RotorCtl.h>
#include <Servo.h>

// Globals
String startupCmd = "N000 N000";
String bufferedString = "";
Servo steerServo;
Servo esc;
RotorCtl rotorCtl(steerServo, esc);
int _THROT_PIN = 10;
int _STEER_PIN = 11;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);

  // Set indicator LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Attach servos
  steerServo.attach(_STEER_PIN);
  esc.attach(_THROT_PIN);

  // startup Sequence
  rotorCtl.stageNewCommand(startupCmd);
  rotorCtl.writeToSteer();
  rotorCtl.writeToThrot();
  rotorCtl.powerOnRotor();
  delay(1000);

}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    String message = Serial.readString();

    // Loop over message and parse
    for (unsigned int j = 0; j < message.length(); j++) {
      char c = message.charAt(j);
      
      if (c == '\n') {

        // Stage received command to vehicle
        rotorCtl.stageNewCommand(bufferedString);
        rotorCtl.writeToSteer();
        rotorCtl.writeToThrot();

        // Respond with current command
        bufferedString += c;
        Serial.println("'" + bufferedString + "'");
        bufferedString = "";
      }
      else {//very critical else
        bufferedString += c;
      }

    }
  }
}
