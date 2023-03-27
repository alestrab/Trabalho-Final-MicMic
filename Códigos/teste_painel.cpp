#include <Arduino.h>
#include <Servo.h>
//Teste de leitura da placa
int sol = 0; //Intensidade luminosa

void setup() {
  pinMode(A2, INPUT);  //Painel solar conectado em A2
  Serial.begin(9600);           
}

void loop() {
  sol = analogRead(A2);  
  Serial.println(sol);
  delay(1000);          
}
