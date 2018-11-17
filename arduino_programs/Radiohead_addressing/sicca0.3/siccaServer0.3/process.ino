//Function for processing the received data
/*
   Function Name: process
   Input: none
   Output: none
   Logic: converts data from bytes to integers
   Example Call: process()
*/
void process()
{
  //  dataString += String(millis());
  //  dataString += " process starts";
  //  sd();
  //  dataString = " ";
  if (from == 1)
  {
    int x0 = buf[0] * 255;
    soilMoist11 = x0 + buf[1]; //Soil Moisture
    int x1 = buf[2] * 255;
    temp1 = x1 + buf[3]; //Air Humidity
    int x2 = buf[4] * 255;
    hum1 = x2 + buf[5]; //Temperature
    int x3 = buf[6] * 255;
    soilTemp11 = x3 + buf[7]; //Soil Temperature
    double x4 = buf[8] * 255;
    batt = x4 + buf[9]; //Battery level

    battVolt1 = (batt / 1023) * 4.2; //converting analog readings to actual voltage
    int node_id = buf[10];  //packet number
    Serial.print(F("current packet number is: "));
    Serial.println(node_id);
    Serial.print(F("Soil Moisture: "));
    Serial.println(soilMoist11);
  }
  if (from == 2)
  {
    int x0 = buf[0] * 255;
    soilMoist21 = x0 + buf[1]; //Soil Moisture
    int x1 = buf[2] * 255;
    temp2 = x1 + buf[3]; //Air Humidity
    int x2 = buf[4] * 255;
    hum2 = x2 + buf[5]; //Temperature
    int x3 = buf[6] * 255;
    soilTemp21 = x3 + buf[7]; //Soil Temperature
    double x4 = buf[8] * 255;
    batt = x4 + buf[9]; //Battery level

    battVolt2 = (batt / 1023) * 4.2; //converting analog readings to actual voltage
    int node_id = buf[10];  //packet number
    Serial.print(F("current packet number is: "));
    Serial.println(node_id);
    Serial.print(F("Soil Moisture: "));
    Serial.println(soilMoist21);
  }

    //To print 3 digit analog values
    if (soilMoist11 < 1000)
    {
      lcd.setCursor(6, 1);
      lcd.print(" ");
      lcd.setCursor(3, 1);
      lcd.print(soilMoist11);
    }

    //To print 4 digit analog values
    else
    {
      lcd.setCursor(3, 1);
      lcd.print(soilMoist11);

    }

    Serial.print(F("Humidity: "));
    Serial.println(hum1);

    //when sht20 is not connected &library throws a value of 998, display NA
    if (hum1 > 99)
    {
      lcd.setCursor(16, 2);
      lcd.print("NA");
    }
    else
    {
      lcd.setCursor(16, 2);
      lcd.print(hum1);
    }

    //when sht20 is not connected &library throws a value of 998, display NA
    Serial.print(F("Temperature: "));
    Serial.println(temp1);
    if (temp > 99)
    {
      lcd.setCursor(16, 1);
      lcd.print("NA");
    }
    else
    {
      lcd.setCursor(16, 1);
      lcd.print(temp1);
    }
    Serial.print(F("Soil Temperature: "));
    Serial.println(soilTemp11);

    //when sht20 is not connected &library throws a value of 998, display NA
    if (soilTemp > 99 || soilTemp == 0)
    {
      lcd.setCursor(3, 2);
      lcd.print("NA");
    }
    else
    {
      lcd.setCursor(3, 2);
      lcd.print(soilTemp11);
    }
    Serial.print("batt");
    Serial.println(batt);
    Serial.print(F("Battery level "));
    Serial.println(battVolt1);

    //Display SNR of last received signal
    int snr = driver.lastSNR();
    Serial.print(F("SNR: "));
    Serial.println(snr);

    //Display rssi of last received signal
    int rssi = driver.lastRssi();
    rssiPos = -rssi;

    Serial.print(F("Rssi: "));
    Serial.println(rssi);
    //  dataString += String(millis());
    //  dataString += " process end";
    //  sd();
    //  dataString=" ";
  }
