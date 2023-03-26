#include <Arduino.h>
#include <Servo.h>
#define TIMER_INTERRUPT_DEBUG         2
#define _TIMERINTERRUPT_LOGLEVEL_     0

#define USE_TIMER_1     false   //Timer utilizado na biblioteca do servomotor
#define USE_TIMER_2     true    //Timer utilizado para interrupção neste programa

#include "TimerInterrupt.h"

int passo = 5;                //passo para scan
int servo = 0;                //graus do servomotor
unsigned int sol0 = 0;        //iluminação na posição atual
unsigned int sol1 = 0;        //iluminação na posição incrementada
unsigned int sol2 = 0;        //iluminação na posição decrementada
int servo0 = 0;               //posição inicial do servo
unsigned int sol[180];        //iluminação em cada posicao
int solmax = 0;               //iluminação máxima
int dif = 0;                  //diferença entre iluminações
byte maxIndex = 0;            //índice da maior iluminação
Servo servo_10;               //servomotor
int aux = 0;                  //variável auxiliar utilizada para alternar entre os modos de scan e ajuste local
int N = 50;

#if !defined(LED_BUILTIN)      //LED do arduino
  #define LED_BUILTIN     13
#endif

////////////////////////////////////////////////////////////////
#if USE_TIMER_2
void TimerHandler(unsigned int outputPin1 = LED_BUILTIN)
{
  static bool toggle = false;

#if (TIMER_INTERRUPT_DEBUG > 1)
  Serial.print("ITimer2 called, millis() = ");
  Serial.println(millis());
#endif

  digitalWrite(outputPin1, toggle); //Escreve o valor de toggle no LED da placa
  aux = !aux;                       //Troca o valor da variável auxiliar entre 0 e 1
  toggle = !toggle;                 //Troca o valor de toggle entre 0 e 1

 }
#endif
///////////////////////////////////////////////////////////////////

unsigned int outputPin1 = LED_BUILTIN;

#define TIMER_INTERVAL_MS     120000  //Intervalo de tempo em ms em que o sistema fará o scan
#define TIMER_FREQUENCY       (float) (1000.0f / TIMER_INTERVAL_MS)

#define TIMER1_DURATION_MS    0
#define TIMER_DURATION_MS     0


void setup()
{ 
  servo_10.attach(10, 500, 2500);       //Associa o servomotor ao pino 10
  pinMode(A2, INPUT);                   //Pino A2 referente à saída do painel solar
  pinMode(outputPin1, OUTPUT);          //LED da placa como output
  servo_10.write(90);                   //Configuração inicial do servomotor em 90°, que deve corresponder à posição horizontal
  
  Serial.begin(9600);
  while (!Serial);

  Serial.print(F("\nStarting TimerInterruptTest on "));
  Serial.println(BOARD_TYPE);
  Serial.println(TIMER_INTERRUPT_VERSION);
  Serial.print(F("CPU Frequency = ")); Serial.print(F_CPU / 1000000); Serial.println(F(" MHz"));

///////////////////////////////////////////////////////////////////
#if USE_TIMER_2 
  ITimer2.init();
  if (ITimer2.attachInterruptInterval(TIMER_INTERVAL_MS, TimerHandler, outputPin1, TIMER_DURATION_MS))
  {
    Serial.print(F("Starting  ITimer2 OK, millis() = ")); Serial.println(millis());
  }
  else
    Serial.println(F("Can't set ITimer2. Select another freq. or timer"));
    
#endif
}
///////////////////////////////////////////////////////////////////

void loop()
{
  //AJUSTE LOCAL
  //Executado em loop quando aux = 0
  //As medições de sol0, sol1 e sol2 foram feitas tomando-se a média de 50 medições consecutivas em intervalos e 1ms
  if ((aux == 0)){
  servo = servo_10.read();
  //Leitura de sol0
  for (byte i = 0; i < N; i++)
      {
        sol0 = sol0 + analogRead(A2);
        delay(1);
      }
      sol0 = sol0/N;

  //Caso fora das bordas
  if ((servo>=passo)&(servo<=180-passo)){
      //Posição incrementada
      servo_10.write(servo+passo);
      delay(50);
      //Leitura de sol1
      for (byte i = 0; i < N; i++)
      {
        sol1 = sol1 + analogRead(A2);
        delay(1);
      }
      sol1 = sol1/N;

      //Posição decrementada
      servo_10.write(servo-passo);
      delay(50);
      //Leitura de sol2
      for (byte i = 0; i < N; i++)
      {
        sol2 = sol2 + analogRead(A2);
        delay(1);
      }
      sol2 = sol2/N;

      //Movimentação do servomotor para a posição de maior intensidade entre sol0, sol1 e sol2
      if (sol1>max(sol0,sol2)){
        servo_10.write(servo+passo);
      }
      if (sol0>=max(sol1,sol2)){
        servo_10.write(servo);
        delay(1000);  //Delay maior quando o servomotor se mantém na mesma posição
      }
      if (sol2>max(sol0,sol1)){
        servo_10.write(servo-passo);
      }
    }

    //Caso próximo do limite inferior
    if (servo<passo){
      //Posição incrementada
      servo_10.write(servo+passo);
      delay(50);
      //Leitura de sol1
      for (byte i = 0; i < N; i++)
      {
        sol1 = sol1 + analogRead(A2);
        delay(1);
      }
      sol1 = sol1/N;

      //Movimentação do servomotor para a posição de maior intensidade entre sol0 e sol1
      if (sol1>sol0){
        servo_10.write(servo-passo);
      }
      if (sol0>=sol1){
        servo_10.write(servo);
        delay(1000);  //Delay maior quando o servomotor se mantém na mesma posição
      }
    }

    //Caso próximo do limite superior
    if (servo>180-passo){
      servo_10.write(servo-passo);
      delay(50);
      //Leitura de sol2
      for (byte i = 0; i < N; i++)
      {
        sol2 = sol2 + analogRead(A2);
        delay(1);
      }
      sol2 = sol2/N;

      //Movimentação do servomotor para a posição de maior intensidade entre sol0 e sol2
      if (sol2>sol0){
        servo_10.write(servo-passo);
      }
      if (sol0>=sol2){
        servo_10.write(servo);
        delay(1000); //Delay maior quando o servomotor se mantém na mesma posição
      }
    }
    servo = servo_10.read();
      Serial.print(F("sol0 = "));Serial.print(sol0);
      Serial.print(F("  sol1 = "));Serial.print(sol1);
      Serial.print(F("  sol2 = "));Serial.println(sol2);
      Serial.print(F("Servo = "));Serial.println(servo);
    delay(500);
  }


  //SCAN
  //Executado uma vez quando aux = 1
  //As medições de sol[] também foram feitas tomando-se a média de 50 medições consecutivas em intervalos e 1ms
  if ((aux == 1)){
    servo_10.write(0);
    servo = servo_10.read();
    delay(500);
    //Leitura de sol[0]
    for (byte i = 0; i < N; i++)
      {
        sol[servo] = sol[servo] + analogRead(A2);
        delay(1);
      }
      sol[servo] = sol[servo]/N;
    
    //Varredura e leitura dos demais valores de intensidade luminosa
    do
    {
      servo_10.write(servo+1);
      delay(20);
      servo = servo_10.read();
      for (byte i = 0; i < N; i++)
      {
        sol[servo] = sol[servo] + analogRead(A2);
        delay(1);
      }
      sol[servo] = sol[servo]/N;
      
      

      Serial.print(F("servo = "));Serial.print(servo);Serial.print(F("      sol = "));Serial.println(sol[servo]);
    } while (servo<180);

    //Determinação de solmax, a iluminação máxima, junto com o ângulo de rotação do servomotor dessa medição
    solmax = sol[0];
    for(byte i = 1; i < 180; i++)
    {
        if(sol[i] > solmax) {
            solmax = sol[i];
            maxIndex = i;
        }
    }
    servo_10.write(maxIndex);
    Serial.println(maxIndex);
    Serial.println(solmax);
    aux = !aux;  //Faz aux = 0, retornando ao modo de ajuste local até a próxima interrupção
    delay(1000);
  }
  
}
