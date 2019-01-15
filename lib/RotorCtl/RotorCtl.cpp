#include "Arduino.h"
#include "RotorCtl.h"

RotorCtl::RotorCtl() {
    // Initialize to neutral
    _throtDir = "N";
    _throtVal = 0;
    _steerDir = "N";
    _steerVal = 0;
}

void RotorCtl::decodeCommand(String cmdStr) {
    _throtDir = cmdStr.substring(0, 0);
    String throtValString = cmdStr.substring(1, 3);
    _steerDir = cmdStr.substring(6, 6);
    String steerValString = cmdStr.substring(7, 9);

    _throtVal = throtValString.toInt();
    _steerVal = steerValString.toInt();
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