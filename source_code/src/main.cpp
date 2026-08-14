#include <Arduino.h>

#define sensorPin 13
#define sensorRef 15

const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
long total = 0;
int average = 0;

// put function declarations here:
int myFunction(int, int);

void movingAverage(uint8_t sensor_reading) {
  total = total - readings[readIndex];
  readings[readIndex] = sensor_reading;
  total = total + readings[readIndex];
  readIndex = (readIndex + 1) % numReadings;
  average = total / numReadings;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(sensorRef, INPUT);
  for(int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(sensorPin)) {
    Serial.println("Nível alto.");
    delay(100);
  }

  // Leitura do sensor de refletância
  if (digitalRead(sensorRef)) {
    Serial.println("Sensor de refletância em nível alto.");
    movingAverage(analogRead(sensorRef));
    delay(15);
  }

  Serial.println("oi")

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}