#include <Arduino.h>
#include <Servo.h>

int servo = 0;

Servo servo_10;

void setup()
{
  servo_10.attach(10, 500, 2500);
  Serial.begin(9600);
}

void loop()
{
  servo = servo_10.read();
  Serial.println(servo);
  servo_10.write(90);
  delay(1000);
  servo_10.write(0);
  delay(1000);
}