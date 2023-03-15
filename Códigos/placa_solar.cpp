#include <Arduino.h>
#include <Servo.h>

int sol = 0;

void setup()
{
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sol = analogRead(A2);
  Serial.print(sol);
  delay(1000); // Delay a little bit to improve simulation performance
}