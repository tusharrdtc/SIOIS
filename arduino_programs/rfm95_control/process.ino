void process()
{
  Serial.println("in process");
   /*-----(Soil Moisture sensor 1)------*/
  int x0 = buf[0] * 255;
  soilMoist = x0 + buf[1];

  /*-----(Air Temperature sensor)------*/
  int x1 = buf[2] * 255;
  temp = x1 + buf[3];

  /*-----(Humidity sensor)------*/
  int x2 = buf[4] * 255;
  hum = x2 + buf[5];

  /*-----(Soil Temperaure sensor 1)------*/
  int x3 = buf[6] * 255;
  soilTemp = x3 + buf[7];

  /*-----(Soil Moisture sensor 2)------*/
  int x4 = buf[8] * 255;
  soilMoist1 = x4 + buf[9];

  /*-----(Soil Moisture sensor 3)------*/
  int x5 = buf[10] * 255;
  soilMoist2 = x5 + buf[11];

  /*-----(Soil Temperature sensor 2)------*/
  int x6 = buf[12] * 255;
  soilTemp1 = x6 + buf[13];

  /*-----(Soil Temperature Sensor 3)------*/
  int x7 = buf[14] * 255;
  soilTemp2 = x6 + buf[15];

  /*-----(Sensor Battery Voltage)------*/
  double x8 = buf[16] * 255;
  batt = x8 + buf[17];
  battVolt = (batt / 1023) * 4.2; //converting analog readings to actual voltage

  /*------(Sending gy30reading)----*/
  int x9 = buf[18] * 255;
  light = x6 + buf[19];
  Serial.print("light is: ");
  Serial.println(light);

  /*-----(Node id)------*/
  int node_id = buf[20]; 
  Serial.print(F("current packet number is: "));
  Serial.println(node_id);

  
  Serial.print(F("Soil Moisture 1 is: "));
  Serial.println(soilMoist);
  Serial.print(F("Soil Moisture 2 is: "));
  Serial.println(soilMoist1);
  Serial.print(F("Soil Moisture 3 is: "));
  Serial.println(soilMoist2);
  Serial.print(F("Humidity: "));
  Serial.println(hum);
  
  //when sht20 is not connected &library throws a value of 998, display NA
  Serial.print(F("Temperature: "));
  Serial.println(temp);
  
  Serial.print(F("Soil Temperature1 is: "));
  Serial.println(soilTemp);
  Serial.print(F("Soil Temperature2 is: "));
  Serial.println(soilTemp1);
  Serial.print(F("Soil Temperature3 is: "));
  Serial.println(soilTemp2);

  Serial.print(F("Battery level "));
  Serial.println(battVolt);

  //Display SNR of last received signal
  int snr = rf95.lastSNR();
  Serial.print(F("SNR: "));
  Serial.println(snr);

  //Display rssi of last received signal
  int rssi = rf95.lastRssi();
  Serial.print(F("Rssi: "));
  Serial.println(rssi);

}
