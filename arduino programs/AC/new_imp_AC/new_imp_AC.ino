
unsigned int d1[] = {192, 17868, 2960, 8900, 552, 444, 552, 1452, 520, 476, 516, 476, 460, 568, 512, 444, 556, 440, 548, 444, 488, 504, 556, 1432, 552, 472, 520, 444, 548, 1436, 556, 440, 552, 444, 544, 1468, 524, 1456, 520, 1516, 476, 1512, 504, 1428, 560, 432, 560, 432, 564, 432, 556, 472, 524, 436, 556, 468, 524, 440, 552, 472, 520, 444, 552, 440, 548, 444, 552, 500, 492, 464, 520, 472, 460, 536, 524, 468, 528, 464, 556, 436, 560, 468, 524, 432, 560, 436, 560, 436, 556, 436, 556, 436, 556, 436, 560, 436, 556, 468, 524, 440, 556, 468, 524, 460, 532, 464, 528, 496, 496, 1456, 556, 1428, 560, 1428, 556, 1428, 560, 2928, 3028, 8892, 560, 1424, 560, 436, 556, 440, 552, 436, 560, 468, 524, 444, 548, 496, 496, 464, 524, 468, 528, 1456, 560, 492, 500, 436, 560, 1460, 524, 432, 560, 1428, 560, 1424, 560, 1460, 524, 1436, 552, 1472, 516, 1452, 532, 460, 532, 464, 532, 460, 560, 488, 504, 436, 556, 436, 556, 468, 528, 432, 560, 432, 560, 432, 564, 432, 560, 432, 560, 468, 524, 440, 556, 440, 548, 444, 552, 444, 548, 464, 528, 464, 524, 468, 532, 460, 556, 472, 524, 440, 552, 436, 560, 488, 504, 420, 572, 468, 524, 436, 560, 432, 560, 436, 556, 436, 560, 436, 556, 440, 552, 440, 552, 444, 552, 512, 504, 2904, 3052, 8888, 536, 1452, 532, 496, 524, 484, 508, 436, 556, 436, 560, 432, 560, 436, 560, 468, 524, 432, 560, 1428, 556, 440, 556, 440, 552, 1452, 532, 464, 532, 1452, 532, 1492, 520, 436, 560, 1424, 560, 1428, 556, 1428, 560, 1476, 508, 1432, 556, 1436, 548, 1432, 556, 1452, 532, 464, 532, 460, 532, 460, 560, 1476, 512, 1424, 560, 1424, 560, 436, 560, 432, 560, 436, 556, 440, 556, 436, 556, 436, 556, 468, 528, 440, 552, 1452, 532, 1452, 536, 492, 500, 1452, 560, 1464, 520, 436, 560, 468, 524, 436, 556, 432, 564, 432, 560, 432, 560, 488, 504, 440, 556, 1432, 552, 1432, 552, 1452, 536, 1452, 560, };
int n1, n2, t1;
#define LEDPIN 13
#define maxLen 800
volatile  unsigned int irBuffer[maxLen]; 
volatile unsigned int x = 0;
void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, rxIR_Interrupt_Handler, CHANGE);  
}
void loop()
{
  
  delay(5000);
  unsigned int  d2[]={};    
      
 
if (x) 
   {                 
     digitalWrite(LEDPIN, HIGH);                               
     Serial.println();
     Serial.println("captured signal is:");
     detachInterrupt(0);                                       

     for (int i = 1; i < x; i++)
       { 
         d2[i]=(irBuffer[i] - irBuffer[i - 1]);
         Serial.print(d2[i]);
         Serial.print(",");
         t1=i;
         c[i]=d2[i];
        }
     compare();
   }
   
     x = 0;
     Serial.println();
     Serial.println();
     digitalWrite(LEDPIN, LOW);                                //end of visual indicator, for this time
      
     attachInterrupt(0, rxIR_Interrupt_Handler, CHANGE);       //re-enable ISR for receiving IR signal
    
    }

void rxIR_Interrupt_Handler() 
  {
    if (x > maxLen) return;                                    //ignore if irBuffer is already full
    irBuffer[x++] = micros();                                  //just continually record the time-stamp of signal transitions

   }
   void compare()
   {
    
    Serial.println("Signal captured");
     Serial.print("Size of the stored array is:");
    size_t n1 = sizeof(d1) / sizeof(int);
    Serial.println(n1);
    Serial.print("Size of the captured array is:");
    //size_t n2 = sizeof(d2) / sizeof(int);
    Serial.println(t1);
    for(int i=0;i<10;i++)
    {
      if(c[i]==d1[i]+100 )
      {
        Serial.println("matched");
      }
      else
      {
        Serial.println("unmatched");
      }
      /*if(17000<c[i] && c[i]<18000)
      {
        Serial.println("got the digit");
        Serial.print("position is");
        Serial.println(i);
      }*/
    }
   }
    
   
/*unsigned int d1[] = {192, 17868, 2960, 8900, 552, 444, 552, 1452, 520, 476, 516, 476, 460, 568, 512, 444, 556, 440, 548, 444, 488, 504, 556, 1432, 552, 472, 520, 444, 548, 1436, 556, 440, 552, 444, 544, 1468, 524, 1456, 520, 1516, 476, 1512, 504, 1428, 560, 432, 560, 432, 564, 432, 556, 472, 524, 436, 556, 468, 524, 440, 552, 472, 520, 444, 552, 440, 548, 444, 552, 500, 492, 464, 520, 472, 460, 536, 524, 468, 528, 464, 556, 436, 560, 468, 524, 432, 560, 436, 560, 436, 556, 436, 556, 436, 556, 436, 560, 436, 556, 468, 524, 440, 556, 468, 524, 460, 532, 464, 528, 496, 496, 1456, 556, 1428, 560, 1428, 556, 1428, 560, 2928, 3028, 8892, 560, 1424, 560, 436, 556, 440, 552, 436, 560, 468, 524, 444, 548, 496, 496, 464, 524, 468, 528, 1456, 560, 492, 500, 436, 560, 1460, 524, 432, 560, 1428, 560, 1424, 560, 1460, 524, 1436, 552, 1472, 516, 1452, 532, 460, 532, 464, 532, 460, 560, 488, 504, 436, 556, 436, 556, 468, 528, 432, 560, 432, 560, 432, 564, 432, 560, 432, 560, 468, 524, 440, 556, 440, 548, 444, 552, 444, 548, 464, 528, 464, 524, 468, 532, 460, 556, 472, 524, 440, 552, 436, 560, 488, 504, 420, 572, 468, 524, 436, 560, 432, 560, 436, 556, 436, 560, 436, 556, 440, 552, 440, 552, 444, 552, 512, 504, 2904, 3052, 8888, 536, 1452, 532, 496, 524, 484, 508, 436, 556, 436, 560, 432, 560, 436, 560, 468, 524, 432, 560, 1428, 556, 440, 556, 440, 552, 1452, 532, 464, 532, 1452, 532, 1492, 520, 436, 560, 1424, 560, 1428, 556, 1428, 560, 1476, 508, 1432, 556, 1436, 548, 1432, 556, 1452, 532, 464, 532, 460, 532, 460, 560, 1476, 512, 1424, 560, 1424, 560, 436, 560, 432, 560, 436, 556, 440, 556, 436, 556, 436, 556, 468, 528, 440, 552, 1452, 532, 1452, 536, 492, 500, 1452, 560, 1464, 520, 436, 560, 468, 524, 436, 556, 432, 564, 432, 560, 432, 560, 488, 504, 440, 556, 1432, 552, 1432, 552, 1452, 536, 1452, 560, };
unsigned int d2[]={}; 
int i,j,k;
void setup()
{
  size_t j = sizeof(d1) / sizeof(int);
  Serial.begin(9600);
  for(i=0;i<j;i++)
  {
    if(d1[i]<700)
    {
      Serial.print("0");
      Serial.print(",");
    }
    else
    {
    Serial.print("1");
    Serial.print(",");
    }
  }
}
void loop()
{
  
}
*/
