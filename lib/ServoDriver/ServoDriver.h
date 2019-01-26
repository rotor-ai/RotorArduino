#ifndef ServoDriver_h
#define ServoDriver_h

#include <Servo.h>
#include <Arduino.h>

class ServoDriver {
    public:
    ServoDriver();
    void servoRight(Servo servo);
    void servoLeft(Servo servo);
};

#endif