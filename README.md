

## About the Project

This project is a simple **Automatic Room Light Controller with 2 Digit Counter** that keeps track of the number of students inside a classroom. It uses two IR sensors to detect when someone enters or exits, updates the count automatically, and shows the current number of students on a **16×2 I2C LCD**. An LED is also used to indicate whether the classroom is occupied.

This project is a great way to learn about sensor interfacing, LCD communication, and basic automation using Arduino.

## Features

* Automatically counts students entering and leaving the classroom
* Displays the current student count on a 16×2 I2C LCD
* Shows **"No student"** when the classroom is empty
* Turns the LED ON when students are present and OFF when the room is empty
* Easy to build and beginner-friendly

## Components Used

* Arduino Uno
* 16×2 LCD with I2C module
* 2 IR Sensors
* LED
* 220Ω Resistor
* Breadboard
* Jumper Wires

## Circuit Connections

| Component       | Arduino Pin |
| --------------- | ----------- |
| Entry IR Sensor | D8          |
| Exit IR Sensor  | D9          |
| LED             | D10         |
| LCD (I2C)       | SDA, SCL    |

## Libraries Required

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

Make sure the **LiquidCrystal_I2C** library is installed before uploading the code.

## How It Works

* The first IR sensor detects a student entering the classroom.
* The second IR sensor detects a student leaving.
* Whenever an entry is detected, the counter increases by one.
* Whenever an exit is detected, the counter decreases.
* The LCD continuously displays the number of students currently inside.
* If the count becomes zero, the display changes to **"No student"**, and the LED turns off.

## Getting Started

1. Clone or download this repository.
2. Open the project in the Arduino IDE.
3. Install the required libraries.
4. Connect all components as shown in the circuit.
5. Upload the code to your Arduino board.
6. Power the circuit and test the system.

## Future Improvements

Some ideas for improving this project include:

* Better direction detection to avoid false counts
* Saving attendance data to an SD card
* Sending attendance data over Wi-Fi or Bluetooth
* Adding a buzzer for notifications
* Creating a web or mobile dashboard to monitor classroom occupancy

## License

This project is open-source and created for learning and educational purposes. Feel free to use it, modify it, and improve it.
