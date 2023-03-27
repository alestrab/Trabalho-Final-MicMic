
//Teste de leitura da placa
int sol = 0; 

void setup() {
  Serial.begin(9600);           
}

void loop() {
  sol = analogRead(A2);  
  Serial.println(sol);
  delay(1000);          
}
