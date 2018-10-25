#include <RHReliableDatagram.h>
#include <RH_RF95.h>
#include <SPI.h>
#include <RHDatagram.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2
#define freq 868.0

RH_RF95 driver(10, 2);     //for arduino Mega

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, SERVER_ADDRESS);

void setup()
{
  Serial.begin(9600);
  //SPI.setClockDivider(SPI_CLOCK_DIV2);
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
  driver.setTxPower(15, false);
}

uint8_t buf1[5]; 
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
void loop()
{
  buf1[0]=208;
  buf1[1]=35;
  buf1[2]=26;
  buf1[3]=27;
  buf1[4]=28;
 // buf1[5]=29;
//  buf1[6]=30;
//  buf1[7]=21;
//  buf1[8]=22;
//  buf1[9]=23;
//  buf1[10]=24;
//  buf1[11]=25;
//  buf1[12]=31;
//  buf1[13]=32;
//  buf1[14]=33;
  Serial.println("Sending to rf95_reliable_datagram_server");
   //delay(2000);
   if (manager.sendtoWait(buf1, sizeof(buf1), SERVER_ADDRESS))
   {
    Serial.println("inside the manager loop");
    // Now wait for a reply from the server
    uint8_t len = sizeof(buf);
    uint8_t from;
         if (manager.recvfromAckTimeout(buf, &len, 2000, &from))
         {
           Serial.print("got reply from : 0x");
           Serial.println(from, HEX);
           Serial.print(": ");
           //delay(2000);
           Serial.println((char*)buf);
           //delay(2000);
           }
       else
        {
          Serial.println("No reply, is rf95_reliable_datagram_server running?");
        }      
    }
   else
      {
          Serial.println("sendtoWait failed");
       }
       delay(1000);
}
