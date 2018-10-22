#include<SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);     //RX, TX

char temp[2]="OK";
char temp1[50];
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  while(!Serial)
  {
    ;
  }
  mySerial.println("AT");
  delay(1000);
  timeplease();
  delay(1000);
  timeplease();
  for(int i=0; i<2; i++)
  {
    Serial.print("Your ");
    Serial.print(i);
    Serial.print(" th element is ");
    Serial.println(temp[i]);
  }
}

void loop()
{
  
}
 void timeplease()
 {
  for(int i=0; i<50; i++)
  {
    if(mySerial.available()>0)
    {
      temp1[i]=mySerial.read();
      Serial.print("AT command ");
      Serial.print(i);
      Serial.print(" th element is ");
      Serial.write(temp1[i]);
      
      Serial.println("");
    }
  }
 }

