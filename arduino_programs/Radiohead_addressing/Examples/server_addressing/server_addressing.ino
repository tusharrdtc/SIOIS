#include <RHReliableDatagram.h>
#include <RH_RF95.h>
#include <SPI.h>

#define CLIENT_ADDRESS 2                   //1
#define CLIENT_ADDRESS 1                   //2
#define SERVER_ADDRESS 1                   //2
#define freq 868.0

RH_RF95 driver(53, 2);     //for arduino Mega

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, SERVER_ADDRESS);

void setup()
{
  Serial.begin(9600);
   /* RFM95 setup section */
  while (!Serial) ; // Wait for serial port to be available
  if (!manager.init())
    Serial.println("init failed");
  
  //Set Frequency & Configuration.Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  if(!driver.setFrequency(freq))
    Serial.print("Set frequency failed!");
  
  if(!driver.setModemConfig(RH_RF95::Bw125Cr45Sf128 ))
    Serial.print("config failed!");
  
  // you can set transmitter powers from 5 to 23 dBm:
  driver.setTxPower(20, false);
}

uint8_t data[] = "And hello back to you";
// Dont put this on the stack:
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];

void loop()
{
  Serial.println("inside loop");
  if(manager.available())
  {
    //Serial.println("inside manager function");
    uint8_t len1=sizeof(buf);
    uint8_t from, to, id, flags;
    if(manager.recvfromAck(buf, &len1, &from, &to, &id, &flags))
    {
      Serial.print("got request from : 0x");
      Serial.print(from,HEX);
      Serial.print(": ");
      Serial.print("to");
      Serial.print(to, HEX);
      Serial.print(" of id is:");
      Serial.print(id, HEX);
      Serial.println(" ");
      Serial.println((char*)buf);

      if(!manager.sendtoWait(data, sizeof(data), from))
        Serial.println("sendtoWait failed");
   }
  }
  delay(1000);
}
