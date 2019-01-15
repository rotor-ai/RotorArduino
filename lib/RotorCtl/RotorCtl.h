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
  String _steerDir;
  int _steerVal;

  public:
  RotorCtl();
  void decodeCommand(String cmd);
  String getThrotDir();
  int getThrotVal();
  String getSteerDir();
  int getSteerVal();
};

#endif