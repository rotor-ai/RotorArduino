# RotorArduino 0.1.0

The RotorArduino library provides the underlying control of motors and sensors on the Rotor System. 

### Prerequisites

The RotorArduino library has been tested on the Arduino Uno board.

Dependencies:
- Servo.h - licensed under GNU LGPL v2.1 - used with no modifications
    Copyright (c) 2009 Michael Margolis.  All right reserved.

- Arduino core library - licensed under GNU LGPL v2.1 - used with no modifications
    Copyright (c) 2005-2013 Arduino Team.  All right reserved.

Additional Hardware:
- Android Phone running the `RotorVehicle` app - https://github.com/rotor-ai/RotorVehicle
- Android or iOS device running the `RotorController` app - https://github.com/rotor-ai/mobileclient
- RC car with PWM speed control and servo for steering - a good starting point is the Exceed Short Course Desert Truck - [Amazon](https://www.amazon.com/Exceed-Racing-Desert-Course-2-4ghz/dp/9269802108/ref=sr_1_fkmrnull_1?keywords=Exceed+Racing+Desert+Short+Course+Truck&qid=1554669149&s=toys-and-games&sr=1-1-fkmrnull)

### Installing

Download the RotorVehicle library to your computer:

```
git clone https://github.com/rotor-ai/RotorArduino
```

Deployment can be made easier by using a plugin to VSCode called PlatformIO (https://platformio.org/). PIO allows for easy deployment of code to the arduino, as well as organization and control of dependencies.

## Authors

* **Robert Humphrey** - *RotorVehicle & RotorArduino*

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE.md](LICENSE.md) file for details
