#include <Servo.h>

const int sensorPin = 2;   // PIR sensor connected to pin 2
const int doorPin = 9;    // Door motor driver connected to pin 9
Servo doorServo;           // Create a Servo object for the door motor

int openAngle = 90;       // Angle to which the door opens (adjust as needed)
int closeAngle = 0;        // Angle to which the door closes
int holdTime = 5000;       // Time the door stays open (adjust as needed)

void setup() {
  Serial.begin(9600);
  Serial.println("Automatic Door Control System Started");
  doorServo.attach(doorPin);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  if (sensorValue == LOW) { // Object detected
    Serial.println("Object Detected, Opening Door");
    doorServo.write(openAngle);  // Open the door
    delay(holdTime);            // Hold the door open for a while
  } else {  // No object detected
    Serial.println("No Object Detected, Closing Door");
    doorServo.write(closeAngle); // Close the door
  }

  delay(100); // Adjust delay based on sensor sensitivity (optional)
}