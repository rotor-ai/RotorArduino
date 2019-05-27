#include "Arduino.h"
#include "RotorCtl.h"
#include <Servo.h>

RotorCtl::RotorCtl(Servo steerServo, Servo esc) {
    // Initialize to neutral
    _throtDir = "N";
    _throtVal = 0;
    _steerDir = "N";
    _steerVal = 0;

    // Set trim values
    _THROT_PWM_MAX = 180;
    _THROT_PWM_MIN = 0;
    _throtPwmNeut = 90;
    _STEER_PWM_MAX = 180;
    _STEER_PWM_MIN = 0;
    _steerPwmNeut = 90;

    // Set IO pins
    _THROT_PIN = 10;
    _STEER_PIN = 11;
    _RELAY_PIN = 12;
    pinMode(_RELAY_PIN, OUTPUT);
    digitalWrite(_RELAY_PIN, LOW);

    // Bind servo library
    _steerServo = steerServo;
    _esc = esc;

    // Serial.begin(9600);
}

void RotorCtl::powerOnRotor() {
    digitalWrite(_RELAY_PIN, HIGH);
}

void RotorCtl::powerOffRotor() {
    digitalWrite(_RELAY_PIN, LOW);
}

void RotorCtl::stageNewCommand(String cmdStr) {
    if (cmdStr.length() == 9) {
        _throtDir = cmdStr.substring(0, 1);
        String throtValString = cmdStr.substring(1, 4);
        _steerDir = cmdStr.substring(5, 6);
        String steerValString = cmdStr.substring(6, 9);

        _throtVal = throtValString.toInt();
        _steerVal = steerValString.toInt();
    } else {
        if (cmdStr.charAt(1) == 'F') {
            _throtPwmNeut++;
        } else if (cmdStr.charAt(1) == 'B') {
            _throtPwmNeut--;
        } else if (cmdStr.charAt(1) == 'L') {
            _steerPwmNeut++;
        } else if (cmdStr.charAt(1) == 'R') {
            _steerPwmNeut--;
        }
    }

    // char cstr[16];
    // itoa(_steerVal, cstr, 10);
    // Serial.write("loaded value: ");
    // Serial.write(cstr);
    // Serial.write("\n\r");
}

void RotorCtl::writeToThrot() {
    // Calculate PWM
    int pwm;
    if (_throtDir == "F") {
        pwm = getPwmVal(_throtPwmNeut, _THROT_PWM_MAX, _throtVal);
    } else if(_throtDir == "B") {
        pwm = getPwmVal(_throtPwmNeut, _THROT_PWM_MIN, _throtVal);
    } else {
        pwm = _throtPwmNeut;
    }

    // Write to PWM
    _esc.write(pwm);

    // char cstr[16];
    // itoa(pwm, cstr, 10);
    // Serial.write("Throttle pwm: ");
    // Serial.println(cstr);
}

void RotorCtl::writeToSteer() {
    // Calculate PWM
    int pwm;
    if (_steerDir == "L") {
        pwm = getPwmVal(_steerPwmNeut, _STEER_PWM_MAX, _steerVal);
    } else if(_steerDir == "R") {
        pwm = getPwmVal(_steerPwmNeut, _STEER_PWM_MIN, _steerVal);
    } else {
        pwm = _steerPwmNeut;
    }

    // Write to PWM
    _steerServo.write(pwm);

    // char cstr[16];
    // itoa(pwm, cstr, 10);
    // Serial.write("Steering PWM: ");
    // Serial.println(cstr);
}

int RotorCtl::getPwmVal(int neut, int full, int val) {
    double pct = ((double) val / 100);
    int pwmOffset = (int) (pct * (full - neut));
    int pwm = pwmOffset + neut;
    return pwm;
}

int RotorCtl::getPwmFromDutyCycle(double dutyCycle) {
    int pwm = (int) (dutyCycle * 255);
    return pwm;
}

String RotorCtl::getThrotDir() {
    return _throtDir;
}

int RotorCtl::getThrotVal() {
    return _throtVal;
}

String RotorCtl::getSteerDir() {
    return _steerDir;
}

int RotorCtl::getSteerVal() {
    return _steerVal;
}