#include "Arduino.h"
#include "RotorCtl.h"

RotorCtl::RotorCtl() {
    // Initialize to neutral
    _throtDir = "N";
    _throtVal = 0;
    _steerDir = "N";
    _steerVal = 0;

    // Set trim values
    _THROT_PWM_MAX = getPwmFromDutyCycle(.07);
    _THROT_PWM_MIN = getPwmFromDutyCycle(.056);
    _throtPwmNeut = getPwmFromDutyCycle(.06);
    _STEER_PWM_MAX = getPwmFromDutyCycle(.11);
    _STEER_PWM_MIN = getPwmFromDutyCycle(.068);
    _steerPwmNeut = getPwmFromDutyCycle(.1);

    // Set IO pins
    _THROT_PIN = 10;
    _STEER_PIN = 11;
    _RELAY_PIN = 12;
    pinMode(_RELAY_PIN, OUTPUT);
    digitalWrite(_RELAY_PIN, LOW);

    // DEBUG: Serial.begin(9600)
}

void RotorCtl::powerOnRotor() {
    digitalWrite(_RELAY_PIN, HIGH);
}

void RotorCtl::powerOffRotor() {
    digitalWrite(_RELAY_PIN, LOW);
}

void RotorCtl::stageNewCommand(String cmdStr) {
    _throtDir = cmdStr.substring(0, 1);
    String throtValString = cmdStr.substring(1, 4);
    _steerDir = cmdStr.substring(6, 7);
    String steerValString = cmdStr.substring(7, 10);

    _throtVal = throtValString.toInt();
    _steerVal = steerValString.toInt();
}

void RotorCtl::writeToThrot() {
    // Calculate PWM
    int pwm;
    if (_throtDir == "F") {
        pwm = getPwmVal(_throtPwmNeut, _THROT_PWM_MAX, _throtVal);
    } else if(_throtDir == "V") {
        pwm = getPwmVal(_throtPwmNeut, _THROT_PWM_MIN, _throtVal);
    } else {
        pwm = _throtPwmNeut;
    }

    // Write to PWM
    analogWrite(_THROT_PIN, pwm);
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
    analogWrite(_STEER_PIN, pwm);

    // DEBUG: char cstr[16];
    // itoa(_throtVal, cstr, 10);
    // Serial.write(cstr);
}

int RotorCtl::getPwmVal(int neut, int full, int val) {
    double pct = ((double) val / 100);
    int pwmOffset = (int) (pct * (full - neut));
    int pwm = pwmOffset + neut;
    return pwm;
}

int RotorCtl::getPwmFromDutyCycle(double dutyCycle) {
    int pwm = (int) dutyCycle * 255;
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

void RotorCtl::incSteerTrim(bool up) {
    up ? _steerPwmNeut++ : _steerPwmNeut--;
}

void RotorCtl::incThrotTrim(bool up) {
    up ? _throtPwmNeut++ : _throtPwmNeut--;
}