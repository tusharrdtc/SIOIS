#include <LowPower.h>
#include <SPI.h>
#include <RH_RF95.h>    //Library for LoRa
#include "DFRobot_SHT20.h"  //Library for soil moisture sensor
#include<Wire.h>  //Library for I2C sensors
#include<OneWire.h> //Library for soil temp sensor
#include <DallasTemperature.h>
#include <BH1750.h>


#define RF95_FREQ 868.00
/*-----( Declare Constants and Pin Numbers )-----*/
#define ONE_WIRE_BUS_PIN 9

//Creating required instances
RH_RF95 rf95(10, 2);


/*-----(setup for light sensor)------*/
BH1750 lightMeter;
//Sleep sleep;
DFRobot_SHT20 sht20;
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS_PIN);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
/*-----( Declare Variables )-----*/
// Assign the addresses of your 1-Wire temp sensors.
// See the tutorial on how to obtain these addresses:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html

DeviceAddress Probe01 = { 0x28, 0xAA, 0X56, 0X4B, 0X1B, 0X13, 0X02, 0X7E};
DeviceAddress Probe02 = { 0x28, 0xAA, 0x09, 0x37, 0x1B, 0x13, 0x02, 0x3E  };
DeviceAddress Probe03 = { 0x28, 0xAA, 0x9A, 0x44, 0x1B, 0x13, 0x02, 0xE7  };


//Global Variables
byte buf1[22];                ////array to store data of sensor side
byte present = 0;
byte type_s;
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
long int sleepTime = 10000;
int node_id = 1;
int avgVal=0;
void setup()
{
  Serial.begin(9600);

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  lightMeter.begin();
  while (!Serial) ; // Wait for serial port to be available

  //Initialising rf95
  if (!rf95.init())
    Serial.println(F("init failed"));

  //Setting frequency to 868 MHz
  if (!rf95.setFrequency(RF95_FREQ))
  {
    Serial.print(F("Frequency is not set"));
  }

  if(!rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128))
  {
    Serial.println(F("config failed"));
  }
  //Set Trasnmit power
  rf95.setTxPower(15, false);
  sht20.initSHT20();                                  // Init SHT20 Sensor
  sht20.checkSHT20();                                 //SHT20 checksum

  // Initialize the Temperature measurement library
  sensors.begin();
  // set the resolution to 10 bit (Can be 9 to 12 bits .. lower is faster)
  sensors.setResolution(Probe01, 10);
  sensors.setResolution(Probe02, 10);
  sensors.setResolution(Probe03, 10);
  

  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  
}

void loop()
{
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  delay(500);
  datapacket();
  delay(100);
  transmit();
  delay(500);
  gotosleep();
 }
