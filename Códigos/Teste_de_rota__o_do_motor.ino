void setup() {
  pinMode(22, OUTPUT);    // configura o pino digital 22 como saída
  pinMode(24, OUTPUT);    // configura o pino digital 24 como saída
  pinMode(26, OUTPUT);    // configura o pino digital 26 como saída
  pinMode(28, OUTPUT);    // configura o pino digital 28 como saída
}

void stepper() {
  digitalWrite(22, HIGH); 
  digitalWrite(24, LOW);
  digitalWrite(26, LOW);
  digitalWrite(28, HIGH);
  delay(20);            
  digitalWrite(22, LOW);  
  digitalWrite(24, LOW);
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
  delay(20);           
  digitalWrite(22, LOW);  
  digitalWrite(24, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(28, LOW);
  delay(20);
  digitalWrite(22, HIGH);  
  digitalWrite(24, HIGH);
  digitalWrite(26, LOW);
  digitalWrite(28, LOW);
  delay(20); 
}

void loop(){
  int passo;
  passo = 0;
  while(passo <= 64){
    stepper();
    passo +=1;
  }
  delay(10000);
}

//ANTI-HORÁRIO
//  digitalWrite(22, HIGH); 
//  digitalWrite(24, LOW);
//  digitalWrite(26, LOW);
//  digitalWrite(28, HIGH);
//  delay(20);            
//  digitalWrite(22, LOW);  
//  digitalWrite(24, LOW);
//  digitalWrite(26, HIGH);
//  digitalWrite(28, HIGH);
//  delay(20);           
//  digitalWrite(22, LOW);  
//  digitalWrite(24, HIGH);
//  digitalWrite(26, HIGH);
//  digitalWrite(28, LOW);
//  delay(20);
//  digitalWrite(22, HIGH);  
//  digitalWrite(24, HIGH);
//  digitalWrite(26, LOW);
//  digitalWrite(28, LOW);
//  delay(20); 



// HORÁRIO
//  digitalWrite(22, HIGH); 
//  digitalWrite(24, HIGH);
//  digitalWrite(26, LOW);
//  digitalWrite(28, LOW);
//  delay(20);            
//  digitalWrite(22, LOW);  
//  digitalWrite(24, HIGH);
//  digitalWrite(26, HIGH);
//  digitalWrite(28, LOW);
//  delay(20);           
//  digitalWrite(22, LOW);  
//  digitalWrite(24, LOW);
//  digitalWrite(26, HIGH);
//  digitalWrite(28, HIGH);
//  delay(20);
//  digitalWrite(22, HIGH);  
//  digitalWrite(24, LOW);
//  digitalWrite(26, LOW);
//  digitalWrite(28, HIGH);
//  delay(20); 
