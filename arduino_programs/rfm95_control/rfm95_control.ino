#include <RH_RF95.h>  //Library for rfm95
#include <SPI.h>

#define freq 868.0  //rfm95 frequency

// Singleton instance of the radio driver
RH_RF95 rf95(53, 2);

uint8_t buf[22];
int soilMoist;
int soilMoist1;
int soilMoist2;
int hum;
int temp;
int soilTemp;
int soilTemp1;
int soilTemp2;
unsigned int light;
double batt;
char buff[50];
bool flag = 0;
bool flagKey = 0;
bool flagGetData;
bool flagGet = 0;
uint8_t from;
int16_t rssi;
int fc=325;          //lower threshold
int wp=500;          //upper threshold
double battVolt;

void setup() 
{
  Serial.begin(9600);

  while(!Serial);
  if (!rf95.init())
    Serial.println(F("init failed"));

  //Set Frequency & Configuration.Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  if (!rf95.setFrequency(freq))
    Serial.print(F("Set frequency failed!"));

  if (!rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128 ))
    Serial.print(F("config failed!"));

  // you can set transmitter powers from 5 to 23 dBm:
  rf95.setTxPower(15, false);
}

void loop() 
{
 getData();
 if(flag == 1)
 {
  process();
  flag = 0;
 }
}
