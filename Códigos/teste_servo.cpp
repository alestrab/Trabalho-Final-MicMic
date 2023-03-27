#include <Arduino.h>
#include <Servo.h>
//Teste do servomotor
int servo = 0;  //Valor de ângulo do servo em graus

Servo servo_10; //Definição do servomotor

void setup()
{
  servo_10.attach(10, 500, 2500); //Servomotor conectado ao pino D10
  Serial.begin(9600);
}

void loop()
{
  servo = servo_10.read();
  Serial.println(servo);
  servo_10.write(90); //Coloca o servomotor na posição de 90°
  delay(1000);
}
