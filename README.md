# RotorArduino

The RotorArduino library provides the underlying control of motors and sensors on the Rotor System. 

## Getting Started

### Prerequisites

The RotorArduino library has been tested on the Arduino Uno board.

Dependencies:
- Arduino Servo.h library

Additional Hardware:
- Raspberry Pi running the `RotorVehicle` library - https://github.com/rotor-ai/RotorVehicle
- Android or iOS device running the Rotor `mobileclient` library - https://github.com/rotor-ai/mobileclient
- RC car with PWM speed control and servo for steering - a good starting point is the Exceed Short Course Desert Truck - [Amazon](https://www.amazon.com/Exceed-Racing-Desert-Course-2-4ghz/dp/9269802108/ref=sr_1_fkmrnull_1?keywords=Exceed+Racing+Desert+Short+Course+Truck&qid=1554669149&s=toys-and-games&sr=1-1-fkmrnull)
- (Optional) A Raspberry Pi LCD screen can be used for logging and debugging - [Amazon](https://www.amazon.com/gp/product/B0153R2A9I/ref=ppx_od_dt_b_asin_title_s01?ie=UTF8&psc=1)

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
