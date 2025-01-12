#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Initialize the LCD, servo, and IR sensor pins
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address to 0x27 for a 16 chars and 2 line display
Servo gateServo;

// IR sensor pins
const int entranceSensorPin = 2;
const int slot1SensorPin = 3;
const int slot2SensorPin = 4;
const int slot3SensorPin = 5;

void setup() {
  // Set up the pins for input
  pinMode(entranceSensorPin, INPUT);
  pinMode(slot1SensorPin, INPUT);
  pinMode(slot2SensorPin, INPUT);
  pinMode(slot3SensorPin, INPUT);

  // Initialize the servo motor
  gateServo.attach(9);
  gateServo.write(90); // Start with the gate closed

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("SMART PARKING");

  delay(3000); // Wait a moment for everything to start up
}

void loop() {
  // Read the sensor values
  int entranceDetected = digitalRead(entranceSensorPin);
  int slot1Status = digitalRead(slot1SensorPin);
  int slot2Status = digitalRead(slot2SensorPin);
  int slot3Status = digitalRead(slot3SensorPin);

  // Check if all slots are full
  bool allSlotsFull = (slot1Status == LOW) && (slot2Status == LOW) && (slot3Status == LOW);

  // Entrance sensor logic
  if (entranceDetected == LOW && !allSlotsFull) { // Vehicle detected and at least one slot is free
    gateServo.write(0); // Open the gate
  } else {
    gateServo.write(90); // Close the gate
  }

  // Display parking slot status
  lcd.setCursor(0, 1);
  if (allSlotsFull) {
    lcd.print("PARKING FULL  ");
  } else {
    lcd.print("S1:");
    lcd.print(slot1Status == LOW ? "O " : "F ");

    lcd.print("S2:");
    lcd.print(slot2Status == LOW ? "O " : "F ");

    lcd.print("S3:");
    lcd.print(slot3Status == LOW ? "O " : "F ");
  }

  delay(1000); // Update the display every second
}
