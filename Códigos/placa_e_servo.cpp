#include <Arduino.h>
#include <Servo.h>

int servo = 0;
int servo0 = 0;
int sol0 = 0;
int aux = 0;
int sol1 = 0;
int sol2 = 0;

Servo servo_10;

void setup()
{
  servo_10.attach(10, 500, 2500);
  Serial.begin(9600);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  servo = servo_10.read();
  servo0 = servo;
  sol0 = analogRead(A2);
  Serial.println(sol0);
  delay(100);
  servo_10.write(servo+1);
  sol1 = analogRead(A2);
  Serial.println(sol1);
  delay(100);
  servo_10.write(servo-2);
  sol2 = analogRead(A2);
  Serial.println(sol2);
  delay(100);

  if (sol1>max(sol0,sol2))
  {
    servo_10.write(servo+2);
  }
  if (sol0>max(sol1,sol2))
  {
    servo_10.write(servo0);
    delay(0);
  }
  Serial.println(servo);
  delay(100);
}