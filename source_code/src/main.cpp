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

void movingAverage() {

}

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(sensorRef, INPUT);
  int result = myFunction(2, 3);
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
    delay(15);
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}