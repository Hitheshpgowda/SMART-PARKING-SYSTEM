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

## Circuit Diagram
![Circuit Diagram Placeholder](#)

## Setup Instructions
1. Connect the components as per the circuit diagram.
2. Upload the provided Arduino code to the Arduino Uno board.
3. Ensure that the servo motor is correctly calibrated to open and close the gate.
4. Power the system and observe the LCD display for slot status updates.

## Code Explanation
The code initializes the components and continuously checks the status of the entrance and parking slots. If a vehicle is detected and slots are available, the gate opens automatically. The LCD displays the status of each slot: 
- "O" for Occupied 
- "F" for Free

**Key Variables:**
- `entranceSensorPin`: Pin connected to the entrance IR sensor.
- `slot1SensorPin`, `slot2SensorPin`, `slot3SensorPin`: Pins connected to the slot IR sensors.
- `gateServo`: Controls the gate's opening and closing.

**Main Functions:**
- `setup()`: Initializes the pins, servo, and LCD.
- `loop()`: Continuously checks sensor values and updates the servo and LCD display accordingly.

## Video Demonstration
Watch the project in action [here](). *(Replace with the actual link to your video on YouTube or another platform)*

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request for any improvements or new features.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
