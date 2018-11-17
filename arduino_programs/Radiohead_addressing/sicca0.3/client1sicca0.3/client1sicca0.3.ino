//#include <LowPower.h>
#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF95.h>    //Library for LoRa
#include "DFRobot_SHT20.h"  //Library for soil moisture sensor
#include<Wire.h>  //Library for I2C sensors
#include<OneWire.h> //Library for soil temp sensor
//#include <Sleep_n0m1.h> //Library for sleeping MCU

#define ONE_WIRE_BUS 6
#define CLIENT_ADDRESS 1                   //1
#define SERVER_ADDRESS 1                  //2
#define RF95_FREQ 868.00

//Creating required instances
RH_RF95 driver(10, 2);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, CLIENT_ADDRESS);
//Sleep sleep;
DFRobot_SHT20 sht20;
OneWire ds(ONE_WIRE_BUS);

//Global Variables
byte buf1[12];                ////array to store data of sensor side
byte present = 0;
byte type_s;
byte data[12];
byte addr[8];
float celsius, fahrenheit;
unsigned long sleepTime = 10000;
int node_id = 1;
int avgVal = 0;
void setup()
{
  Serial.begin(9600);
  while (!Serial) ; // Wait for serial port to be available

  pinMode(3, OUTPUT);  //Power Pin for sensors

  //Initialising rf95
  if (!manager.init())
    Serial.println(F("init failed"));

  //Setting frequency to 868 MHz
  if (!driver.setFrequency(RF95_FREQ))
  {
    Serial.print(F("Frequency is not set"));
    Serial.println(F("Set the frequency"));
    driver.setFrequency(RF95_FREQ);
  }

  //setting modem configuration
  if (!driver.setModemConfig(RH_RF95::Bw125Cr45Sf128 ))
    Serial.print(F("config failed!"));
    
  //Set Trasnmit power
  driver.setTxPower(15, false);

  sht20.initSHT20();                                  // Init SHT20 Sensor
  sht20.checkSHT20();                                 //SHT20 checksum
}

void loop()
{

  datapacket();
  delay(100);
  transmit();
  //delay(500);
  //gotosleep();
  //delay(500);
  for(int i=0; i<2;i++)
  {
    for (int j = 0; j < 60; j++)
    {
      Serial.println(j);
      delay(1000);
    }
  }

}
