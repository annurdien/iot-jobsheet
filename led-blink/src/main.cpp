#include <Arduino.h>

void setup() {

  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

}

void loop() {
  
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  delay(1000);
  
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  delay(1000);

}