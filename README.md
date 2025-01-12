# Smart Parking System

## Description
The Smart Parking System is an Arduino-based IoT project
that automates the process of detecting parking slot availability 
and controls a gate using IR sensors, an LCD display, and a servo motor.
It provides real-time updates about slot occupancy and opens the gate 
automatically when a vehicle is detected at the entrance,
provided there is an available slot.This will save the time of searching for a parking
slot in urban areas

## Features
- Real-time monitoring of parking slot availability.
- Automatic gate control based on slot occupancy.
- User-friendly LCD display showing the status of each parking slot.

## Components Required
- Arduino Uno
- LiquidCrystal I2C LCD (16x2)
- Servo Motor
- IR Sensors (4 units)
- Jumper Wires
- Breadboard
- USB Cable

Hardware Setup:
1. Connect the LiquidCrystal I2C LCD (16x2)
GND of LCD to GND on Arduino
VCC of LCD to 5V on Arduino
SDA of LCD to A4 on Arduino
SCL of LCD to A5 on Arduino

2. Connect the Servo Motor
GND of Servo to GND on Arduino
VCC of Servo to 5V on Arduino
Signal pin of Servo to Pin 9 on Arduino (or any other PWM pin)

3. Connect the IR Sensors
For each IR sensor, connect the VCC to 5V on Arduino.
Connect GND to GND on Arduino.
Connect the OUT (Signal) pin to digital pins on Arduino (e.g., Pin 2, Pin 3, Pin 4, Pin 5).

4. Power the System
Use the USB Cable to power the Arduino from your computer or a power adapter.

Software Setup:
Step 1: Install the Required Libraries in Arduino IDE
Open the Arduino IDE.
Go to Sketch > Include Library > Manage Libraries.

Install the following libraries:
   Servo library (for controlling the servo motor)
   LiquidCrystal I2C library (for the LCD)

## Code Explanation
The code initializes the components and continuously checks the status of the entrance and parking slots. If a vehicle is detected and slots are available, the gate opens automatically. When a vehicle is parkwd in a slot it will be displayed as "O" in the sense occupied 
else "F" in the sense Free. When all the slots are filled then even if the vehicle is detected the gate won't open.
The LCD displays the status of each slot: 
- "O" for Occupied 
- "F" for Free

**Key Variables:**
- `entranceSensorPin`: Pin connected to the entrance IR sensor.
- `slot1SensorPin`, `slot2SensorPin`, `slot3SensorPin`: Pins connected to the slot IR sensors.
- `gateServo`: Controls the gate's opening and closing.

**Main Functions:**
- `setup()`: Initializes the pins, servo, and LCD.
- `loop()`: Continuously checks sensor values and updates the servo and LCD display accordingly.


## Contributing
Contributions are welcome! Please fork this repository and submit a pull request for any improvements or new features.


