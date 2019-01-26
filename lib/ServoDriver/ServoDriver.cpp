#include <Servo.h>
#include <Arduino.h>
#include <ServoDriver.h>

ServoDriver::ServoDriver() {
    // Initialize
}

void ServoDriver::servoRight(Servo servo) {
    servo.write(60);
}

void ServoDriver::servoLeft(Servo servo) {
    servo.write(120);
}