#include <Wire.h>
#define Addr 0x48       // ADS7828 I2C address is 0x48(72)

void setup()
    {
      Wire.begin();
      Serial.begin(9600);
      delay(300);
    }

void loop()
   {
      byte data[2];
      Wire.beginTransmission(Addr);       // Start I2C Transmission
        // Send command byte
        // channel-0 selected,  A/D Converter ON
      Wire.write(0x04);
        // Stop I2C transmission
      Wire.endTransmission();
  
        // Request 2 bytes of data
      Wire.requestFrom(Addr, 2);
  
        // Read 2 bytes of data
        // raw_adc msb, raw_adc lsb
      if(Wire.available() == 2)
           {
              data[0] = Wire.read();
              data[1] = Wire.read();
              delay(300);
    
              int raw_adc = ((data[0] & 0x0F) * 256) + data[1];           // Converting the data to 12 bits
              Serial.print("Digital value of analog input : ");
              Serial.println(raw_adc);
           }
    }
