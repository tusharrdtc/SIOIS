#include <MD5.h>
char s[300] = {0};
int i,k;
#define LEDPIN 13
#define maxLen 400
volatile  unsigned int irBuffer[maxLen]; 
volatile unsigned int x = 0;
void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, rxIR_Interrupt_Handler, CHANGE);  
   //md5();
}
void loop()
{
   
  int n = 0;
  //int bin[233];
  int  data[]={};
  int a=0;
  delay(5000);
  if(x)
  {
    digitalWrite(LEDPIN, HIGH);
    detachInterrupt(0);
    for(i=1;i<x;i++)
    {
      /*data[i]=(irBuffer[i]-irBuffer[i-1]);
      Serial.print(data[i]);
      Serial.print(",");*/
      a=(irBuffer[i]-irBuffer[i-1]);
      /*Serial.print(a);
      Serial.print(",");*/
    if(a>700)
    {
     /* Serial.print("1");
      Serial.print(",");*/
      //bin[i]=1;
      //Serial.print(bin[i]);
      //Serial.print("|");
      k=1;
      n += sprintf (&s[n], "%d", k);
      }
    else
    {
     /* Serial.print("0");
      Serial.print(",");*/
      //bin[i]=0;
      //Serial.print(bin[i]);
      //Serial.print("|");
      k=0;
      n += sprintf (&s[n], "%d", k);
      }
    }
    //Serial.println(s);
    md5();
   }
   

  x=0;
  digitalWrite(LEDPIN, LOW);
  attachInterrupt(0,rxIR_Interrupt_Handler, CHANGE);
   
  }

void rxIR_Interrupt_Handler() 
  {
    if (x > maxLen) return;                                    //ignore if irBuffer is already full
    irBuffer[x++] = micros();                                  //just continually record the time-stamp of signal transitions

   }

