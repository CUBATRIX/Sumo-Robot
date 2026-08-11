#include <Arduino.h>

#define sensorPin 13

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(sensorPin)) {
    Serial.println("Nível alto.");
    delay(100);
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}