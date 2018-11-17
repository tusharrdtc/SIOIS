void process()
{
  dataString += String(millis());
  //Serial.println("sd function");
  dataString += " process starts";
  sd();
  dataString=" ";
  int x0 = buf[0] * 255;
  soilMoist = x0 + buf[1]; //Soil Moisture
  int x1 = buf[2] * 255;
  temp = x1 + buf[3]; //Air Humidity
  int x2 = buf[4] * 255;
  hum = x2 + buf[5]; //Temperature
  int x3 = buf[6] * 255;
  soilTemp = x3 + buf[7]; //Soil Temperature
  double x4 = buf[8] * 255;
  batt = x4 + buf[9]; //Battery level

  battVolt = (batt / 1023) * 4.2; //converting analog readings to actual voltage
  int node_id = buf[10];  //packet number
  Serial.print("current packet number is: ");
  Serial.println(node_id);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoist);

  Serial.print("Humidity: ");
  Serial.println(hum);

  Serial.print("Temperature: ");
  Serial.println(temp);

  Serial.print("Soil Temperature: ");
  Serial.println(soilTemp);

  Serial.print("batt");
  Serial.println(batt);
  Serial.print("Battery level ");
  Serial.println(battVolt);

  //Display SNR of last received signal
  int snr = rf95.lastSNR();
  Serial.print("SNR: ");
  Serial.println(snr);

  //Display rssi of last received signal
  int rssi = rf95.lastRssi();
  rssiPos = -rssi;

  Serial.print("Rssi: ");
  Serial.println(rssi);
  dataString += String(millis());
  //Serial.println("sd function");
  dataString += " process end";
  sd();
  dataString=" ";
}
