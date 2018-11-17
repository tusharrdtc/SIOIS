/*

  Example of BH1750 library usage.

  This example initialises the BH1750 object using the default high resolution
  continuous mode and then makes a light level reading every second.

  Connection:

    VCC -> 3V3 or 5V
    GND -> GND
    SCL -> SCL (A5 on Arduino Uno, Leonardo, etc or 21 on Mega and Due, on esp8266 free selectable)
    SDA -> SDA (A4 on Arduino Uno, Leonardo, etc or 20 on Mega and Due, on esp8266 free selectable)
    ADD -> (not connected) or GND

  ADD pin is used to set sensor I2C address. If it has voltage greater or equal to
  0.7VCC voltage (e.g. you've connected it to VCC) the sensor address will be
  0x5C. In other case (if ADD voltage less than 0.7 * VCC) the sensor address will
  be 0x23 (by default).

*/


#include <Wire.h>
#include <BH1750.h>
#include "DFRobot_SHT20.h"

BH1750 lightMeter;
DFRobot_SHT20    sht20;


void setup() {

  Serial.begin(9600);

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);

  lightMeter.begin();
  sht20.initSHT20();                                  // Init SHT20 Sensor
  delay(100);
  sht20.checkSHT20();

  Serial.println(F("Test begin!"));

}


void loop() {
  float humd = sht20.readHumidity();                  // Read Humidity
  float temp = sht20.readTemperature();               // Read Temperature
  float lux = lightMeter.readLightLevel();
  Serial.print("Time:");
  Serial.print(millis());
  Serial.print("  Light: ");
  Serial.print(lux);
  Serial.print("lx");
  Serial.print("  Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print("  Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");
  Serial.println();
  delay(1000);

}
