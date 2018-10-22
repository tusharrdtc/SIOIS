#include<avr/io.h>
#include<util/delay.h>
void setup() {
 f1(); 

}

void loop() {
 

}
void f1()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  
 TCCR2A= bit(COM2A1) | bit(COM2B1) | bit (WGM21) | bit (WGM20);
  TCCR2B= bit(WGM22) | bit(CS20);
  OCR2A = 100;
  OCR2B = 50;
  TCCR0A= bit(COM0A1) | bit(COM0B1) | bit (WGM01) | bit (WGM00);
  TCCR0B= bit(WGM02) | bit(CS00);
  OCR0A = 100;
  OCR0B = 50;
}

