#include <RHReliableDatagram.h>
#include <RH_RF95.h>
#include <SPI.h>
#include "DFRobot_SHT20.h"

#define RF95_FREQ 868.00
#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Singleton instance of the radio driver
RH_RF95 driver(10, 2);
//RH_RF95 driver(5, 2); // Rocket Scream Mini Ultra Pro with the RFM95W

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, CLIENT_ADDRESS);

// Need this on Arduino Zero with SerialUSB port (eg RocketScream Mini Ultra Pro)
//#define Serial SerialUSB
DFRobot_SHT20 sht20;
uint8_t z[RH_RF95_MAX_MESSAGE_LEN];
byte buf1[3];
int reading=0;
//byte i;
byte present = 0;
byte type_s;
byte data[12];
byte addr[8];
float celsius, fahrenheit;


void setup() 
{
  Serial.begin(9600);
  while (!Serial) ; // Wait for serial port to be available
  if (!manager.init())
  {
    Serial.println("init failed");
  }
  if(!driver.setFrequency(RF95_FREQ))
  {
    Serial.print("Frequency is not set");
    Serial.println("Set the frequency");
    driver.setFrequency(RF95_FREQ);
  }
    driver.setTxPower(20, false);
    driver.setModemConfig(RH_RF95::Bw125Cr45Sf128);
    sht20.initSHT20();                                  // Init SHT20 Sensor
    delay(100);
    sht20.checkSHT20(); 
    //Serial.println("all set");
}

//uint8_t data[] = "Hello World!";
//uint8_t data[] = "Hello World!";
// Dont put this on the stack:
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];

void loop()
{
  datapacket();
  Serial.println("Sending to rf95_reliable_datagram_server");
  // Send a message to manager_server
  if (manager.sendtoWait(buf1, sizeof(buf1), SERVER_ADDRESS))
  {
    // Now wait for a reply from the server
    uint8_t len = sizeof(z);
    uint8_t from;  
//    int snr=driver.lastSNR();
//    Serial.print("snr @ client =");
//    Serial.println(snr);
//    int16_t rssi=driver.lastRssi();
//    Serial.print("rssi @ client =");
//    Serial.println(rssi);
     
    if (manager.recvfromAckTimeout(buf, &len, 2000, &from))
    {
      Serial.print("got reply from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
    }
    else
    {
      Serial.println("No reply, is rf95_reliable_datagram_server running?");
    }
  }
  else
    Serial.println("sendtoWait failed");
  delay(500);
  //for(int i=0;i<1;i++)
  {
    for(int j=0;j<10;j++)
    {
      delay(1000);
    }
}
}

void datapacket()
{ 
  digitalWrite(3,HIGH);
  delay(2000);
  int x1=int(sht20.readTemperature());
  int x2=int(sht20.readHumidity());
  Serial.print(" Temperature:");
    Serial.print(x1, 1);
    Serial.println("C");
    Serial.print(" Humidity:");
    Serial.print(x2, 1);
    Serial.println("%");
  digitalWrite(3,LOW);
  int y1=x1/255;
  int z1=x1%255;
  buf1[0]=byte(y1);
  buf1[1]=byte(z1);
  int y2=x2/255;
  int z2=x2%255;
  buf1[2]=byte(y2); 
  buf1[3]=byte(z2);
  Serial.println(y1);
  Serial.println(z1);
  Serial.println(y2);
  Serial.println(z2);
}

