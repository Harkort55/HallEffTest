#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  pinMode(25, OUTPUT);
  pinMode(26, INPUT_PULLUP);
  Serial.println("HallEffTest starting");
}

void loop() {
  static unsigned long lastToggle = 0;
  unsigned long currentTime = millis();
  
  int pin26 = digitalRead(26);
  unsigned long toggleInterval = (pin26 == LOW) ? 100 : 1000;  // 10x/sec if LOW, 1x/sec if HIGH
  
  // Toggle GPIO 25 based on pin 26 state
  if (currentTime - lastToggle >= toggleInterval) {
    digitalWrite(25, !digitalRead(25));
    lastToggle = currentTime;
  }
  
  int hall = hallRead();
  Serial.print("Hall sensor: ");
  Serial.println(hall);
  Serial.print("Pin 26: ");
  Serial.println(pin26);
  delay(50);
}
