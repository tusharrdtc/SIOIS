/*
LED ON and OFF program */



int ledPin= 13;
int i;
void setup() {
   Serial.begin(9600);
 pinMode(ledPin, OUTPUT); 
 for(i=0;i<10;i++)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("hi");
    delay(1000);
    digitalWrite(ledPin, LOW);
     Serial.println("hi");
     delay(1000);
     }

}
 void loop()
{
  
 
} 



