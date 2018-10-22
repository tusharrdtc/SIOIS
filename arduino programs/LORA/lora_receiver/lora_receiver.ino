
//you can get lora library on the web https://github.com/sandeepmistry/arduino-LoRa. 
//written for inAIR9 module.you can also use the code for different lora module like RFM95.
//The code is for sender side
#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (LoRa.begin(915E6)) {
    //Serial.println("Starting LoRa failed!");
    Serial.println("Starting LoRa");
    //while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
      
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
