#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT); // Set GPIO2 as output (built-in LED)
}

void loop() {
  digitalWrite(2, HIGH); // LED ON
  delay(500);             // Wait 500ms
  digitalWrite(2, LOW);  // LED OFF
  delay(500);             // Wait 500ms
}