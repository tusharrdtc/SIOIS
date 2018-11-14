#include <AltSoftSerial.h>

AltSoftSerial altSerial;

#define data  150;
String url = "https://api.thingspeak.com/";
int input_time = 30;
char buf[50];
int len;
String pvt_key = "79IABQSK9NDB39BH";
void setup()
{
Serial.begin(9600);
delay(1000);
altSerial.begin(9600);
delay(1000);
url+="update?api_key=";
url+=pvt_key;
url+="&field1=";
url+=data;

len = url.length();
Serial.println(url);
Serial.println(len);
}



void loop()
{
String c;

if (Serial.available()) {
    c = Serial.readString();
    
    altSerial.print(c);
  }

if (altSerial.available()) 
  {
    c = altSerial.readString();
    Serial.print(c);
  }

altSerial.println("AT");
delay(1000);
//Serial.println("Setting up URL");
sprintf(buf,"AT+QHTTPURL=%d,%d",len,input_time);
altSerial.println(buf);
delay(1000);
altSerial.print(url);
delay(2000);
altSerial.println("AT+QHTTPGET=60");
delay(1000);

//altSerial.println(url);

//delay(2000);
altSerial.flush();
}

