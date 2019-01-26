#include <Arduino.h>

#define ledpin 13
int lowerBound = 50;
int upperBound = 1000;
bool rampUp = true;
int delayTime = lowerBound;

void setup() { pinMode(ledpin, OUTPUT); }

void loop() {
  digitalWrite(ledpin, HIGH);
  delay(delayTime);
  digitalWrite(ledpin, LOW);
  delay(delayTime);
  if (rampUp) {
    delayTime *= 2;
    Serial.print("delayTime"); Serial.print(" : "); Serial.println(delayTime);
    if (delayTime > upperBound) {
      rampUp = false;
    }
  } else {
    delayTime /= 2;
    Serial.print("delayTime"); Serial.print(" : "); Serial.println(delayTime);
    if (delayTime < lowerBound) {
      rampUp = true;
    }
  }
}