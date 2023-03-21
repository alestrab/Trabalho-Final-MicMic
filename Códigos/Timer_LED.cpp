#define TIMER_INTERRUPT_DEBUG         2
#define _TIMERINTERRUPT_LOGLEVEL_     0

#define USE_TIMER_1     true
#define USE_TIMER_2     true

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "TimerInterrupt.h"

//#include <Arduino.h>
//#include <Servo.h>
//
//int servo = 0;       //graus do servomotor
//int sol0 = 0;        //iluminacao na posicao atual
//int sol1 = 0;        //iluminacao na posicao incrementada
//int sol2 = 0;        //iluminacao na posicao decrementada
//int servo0 = 0;      //posicao inicial do servo
//int sol[180];        //iluminacao em cada posicao
//int solmax = 0;      //iluminacao maxima
//int dif = 0;         //diferenca entre iluminacoes
//byte maxIndex = 0;   //indice da maior iluminacao

//Servo servo_10;      //servomotor

#if !defined(LED_BUILTIN)
  #define LED_BUILTIN     13
#endif

//////////////////////////////////////////////////////////////////////////
#if USE_TIMER_1
void TimerHandler1(unsigned int outputPin = LED_BUILTIN)
{
  static bool toggle1 = false;

#if (TIMER_INTERRUPT_DEBUG > 1)
  Serial.print("ITimer1 called, millis() = "); Serial.println(millis());
#endif

  //timer interrupt toggles pin LED_BUILTIN
  digitalWrite(outputPin, toggle1);
  toggle1 = !toggle1;
}
#endif
////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
#if USE_TIMER_2
void TimerHandler(unsigned int outputPin = LED_BUILTIN)
{
  static bool toggle = false;

#if (TIMER_INTERRUPT_DEBUG > 1)
  Serial.print("ITimer2 called, millis() = ");
  Serial.println(millis());
#endif

  //timer interrupt toggles outputPin
  digitalWrite(outputPin, toggle);
  toggle = !toggle;
}
#endif
///////////////////////////////////////////////////////////////////

unsigned int outputPin1 = LED_BUILTIN;
unsigned int outputPin  = A0;

#define TIMER1_INTERVAL_MS    1000
#define TIMER1_FREQUENCY      (float) (1000.0f / TIMER1_INTERVAL_MS)

#define TIMER_INTERVAL_MS     5000
#define TIMER_FREQUENCY       (float) (1000.0f / TIMER_INTERVAL_MS)

#define TIMER1_DURATION_MS    0
#define TIMER_DURATION_MS     0


void setup()
{ 
  //servo_10.attach(10, 500, 2500);
  //pinMode(A2, INPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin,  OUTPUT);
  
  Serial.begin(9600);
  while (!Serial);

  Serial.print(F("\nStarting TimerInterruptTest on "));
  Serial.println(BOARD_TYPE);
  Serial.println(TIMER_INTERRUPT_VERSION);
  Serial.print(F("CPU Frequency = ")); Serial.print(F_CPU / 1000000); Serial.println(F(" MHz"));

///////////////////////////////////////////////////////////////////
#if USE_TIMER_1
  ITimer1.init();
  // Using ATmega328 used in UNO => 16MHz CPU clock ,

  if (ITimer1.attachInterruptInterval(TIMER1_INTERVAL_MS, TimerHandler1, outputPin1, TIMER1_DURATION_MS))
  {
    Serial.print(F("Starting  ITimer1 OK, millis() = ")); Serial.println(millis());
  }
  else
    Serial.println(F("Can't set ITimer1. Select another freq. or timer"));
#endif
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
#if USE_TIMER_2 
  ITimer2.init();
  if (ITimer2.attachInterruptInterval(TIMER_INTERVAL_MS, TimerHandler, outputPin, TIMER_DURATION_MS))
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
  //servo_10.write(0);
  //servo = servo_10.read();
  //sol[servo] = analogRead(A2);
  //do
  //{
  //  servo_10.write(servo+1);
  //  servo = servo_10.read();
  //  sol[servo] = analogRead(A2);
  //  delay(10);
  //} while (servo<180);
//
  //solmax = sol[0];
//
  //for(byte i = 1; i < 180; i++)
  //{
  //    if(sol[i] > solmax) {
  //        solmax = sol[i];
  //        maxIndex = i;
  //    }
  //}
  //servo_10.write(maxIndex);
  //Serial.println(maxIndex);
  //Serial.println(solmax);
  //do
  //{
  //  servo = servo_10.read();
  //  servo0 = servo;
  //  sol0 = analogRead(A2);
  //  Serial.println(sol0);
  //  delay(100);
  //  servo_10.write(servo+1);
  //  sol1 = analogRead(A2);
  //  Serial.println(sol1);
  //  delay(100);
  //  servo_10.write(servo-2);
  //  sol2 = analogRead(A2);
  //  Serial.println(sol2);
  //  delay(100);
//
  //  if (sol1>max(sol0,sol2))
  //  {
  //    servo_10.write(servo+2);
  //  }
  //  if (sol0>max(sol1,sol2))
  //  {
  //    servo_10.write(servo0);
  //    delay(100);
  //  }
  //  Serial.println(servo);
  //  delay(100);
  //  dif = max(sol2-sol1,sol1-sol2);
  //} while (dif>20);
  //
//
//
//
  //delay(10000);
}