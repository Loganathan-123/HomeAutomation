#include <Servo.h>

const int potentiometerPin = A0;
int potValue = 0;
const int numLEDs = 12;
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 10, 11, 12};

Servo myServo;
void setup() {
  
  for (int i = 0; i < numLEDs; i++) {
    if(i == 9) continue;
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(9, OUTPUT);
  myServo.attach(9);
}

void loop() {
  potValue = analogRead(potentiometerPin);  
  int ledThreshold = map(potValue, 0, 1023, 0, numLEDs);  
  for (int i = 0; i < numLEDs; i++) {
    if(i==9) continue;
    if (i < ledThreshold) {
      digitalWrite(ledPins[i], HIGH);  
    } else {
      digitalWrite(ledPins[i], LOW); 
    }
  }

  if(potValue < 512) {
    myServo.write(0);
  }
  else {
    myServo.write(90);
  }

  delay(500);
}
