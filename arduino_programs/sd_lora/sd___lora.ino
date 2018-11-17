#include <RH_RF95.h>
#include <SPI.h>
#include <SD.h>
#define BUFFER_SIZE 250

#define freq 868.0
#define sdcs 3
#define input_time 30

RH_RF95 rf95(53, 2);

uint8_t buf[22];
char url[200];
char  GSM_string[250];
int hum;
int temp;
int soilTemp;
int soilMoist;
double batt;
char buff[50];
uint8_t from;
uint8_t rssi;
int fc=325;
int wp=500;
int address = 0;
int value;
double battStat;
double battVolt;
bool pumpStat;
int rssiPos;
bool flag = 0;
String dataString = "";

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial);
  if(!rf95.init())
    Serial.println("init failed");

  if(!rf95.setFrequency(freq))
    Serial.println("Set frequency bfailed");

  if(!rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128))
    Serial.print("config failed!");

   rf95.setTxPower(15, false);

   Serial1.begin(9600);
   sd_init();

   pinMode(OUTPUT, 4);
   pinMode(OUTPUT, 6);
   digitalWrite(6, HIGH);
   //pinMode(OUTPUT, 53);
   //digitalWrite(4, HIGH);
   //digitalWrite(53, HIGH);
   String dataString = "";
}

void loop()
{
  dataString += String(millis());
  //Serial.println("sd function");
  dataString += " loop start";
  sd();
  dataString=" ";
  // put your main code here, to run repeatedly:
  battVolt = 4.2;
  getData();
  if(flag == 1)
  {
  process();
  //gprs();
  flag = 0;
  }
  dataString += String(millis());
  //Serial.println("sd function");
  dataString += " loop end";
  sd();
  dataString=" ";
  delay(1000);
}
