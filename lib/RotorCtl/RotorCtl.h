/*
    RotorCtl class allows for control over the rotor vehicle
*/

#ifndef RotorCtl_h
#define RotorCtl_h

#include <Arduino.h>

class RotorCtl {
  private:
  String _throtDir;
  int _throtVal;
  int _THROT_PWM_MAX, _THROT_PWM_MIN, _throtPwmNeut;
  String _steerDir;
  int _steerVal;
  int _STEER_PWM_MAX, _STEER_PWM_MIN, _steerPwmNeut;
  int _THROT_PIN;
  int _STEER_PIN;
  int _RELAY_PIN;
  int getPwmVal(int neut, int full, int val);
  int getPwmFromDutyCycle(double dutyCycle);

  public:
  RotorCtl();
  void powerOnRotor();
  void powerOffRotor();
  void stageNewCommand(String cmd);
  void writeToThrot();
  void writeToSteer();
  void incSteerTrim(bool up);
  void incThrotTrim(bool up);
  String getThrotDir();
  int getThrotVal();
  String getSteerDir();
  int getSteerVal();
};

#endif