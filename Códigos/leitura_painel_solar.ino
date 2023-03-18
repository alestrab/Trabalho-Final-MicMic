
//Teste de leitura da placa
int analogPin = A0; 
int sol = 0; 

void setup() {
  Serial.begin(9600);           
}

void loop() {
  sol = analogRead(analogPin);  
  Serial.println(sol);
  delay(100);          
}
