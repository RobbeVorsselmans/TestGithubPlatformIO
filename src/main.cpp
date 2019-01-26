#include <Arduino.h>

#define ledpin 13
int lowerBound = 50;
int upperBound = 500;
bool rampUp = true;
int delayTime = lowerBound;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  Serial.println("Start!");
  }

void loop() {
  digitalWrite(ledpin, HIGH);
  delay(delayTime);
  digitalWrite(ledpin, LOW);
  delay(delayTime);
  if (rampUp) {
    delayTime *= 2;
    Serial.print("delayTime"); Serial.print(" : "); Serial.println(delayTime);
    if (delayTime >= upperBound) {
      rampUp = false;
    }
  } else {
    delayTime /= 2;
    Serial.print("delayTime"); Serial.print(" : "); Serial.println(delayTime);
    if (delayTime <= lowerBound) {
      rampUp = true;
    }
  }
}