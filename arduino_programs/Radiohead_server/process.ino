//Function for processing the received data
/*
 * Function Name: process
 * Input: none
 * Output: none
 * Logic: converts data from bytes to integers 
 * Example Call: process()
 */
void process()
{
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
      
      //To print 3 digit analog values
      if(soilMoist<1000)
      {
        lcd.setCursor(6, 1);
        lcd.print(" ");
        lcd.setCursor(3, 1);
        lcd.print(soilMoist);
      }

      //To print 4 digit analog values
      else 
      {
        lcd.setCursor(3, 1);
        lcd.print(soilMoist);
        
      }
       
      Serial.print("Humidity: ");
      Serial.println(hum);

      //when sht20 is not connected &library throws a value of 998, display NA
      if (hum > 99)
      {
        lcd.setCursor(16, 2);
        lcd.print("NA");
      }
      else
      {
        lcd.setCursor(16, 2);
        lcd.print(hum);
      }

      //when sht20 is not connected &library throws a value of 998, display NA
      Serial.print("Temperature: ");
      Serial.println(temp);
      if (temp > 99)
      {
        lcd.setCursor(16, 1);
        lcd.print("NA");
      }
      else
      {
        lcd.setCursor(16, 1);
        lcd.print(temp);
      }
      Serial.print("Soil Temperature: ");
      Serial.println(soilTemp);

      //when sht20 is not connected &library throws a value of 998, display NA
      if (soilTemp > 99 || soilTemp == 0)
      {
        lcd.setCursor(3, 2);
        lcd.print("NA");
      }
      else
      {
        lcd.setCursor(3, 2);
        lcd.print(soilTemp);
      }
      Serial.print("batt");
      Serial.println(batt);
      Serial.print("Battery level ");
      Serial.println(battVolt);

      //Display SNR of last received signal
      int snr = driver.lastSNR();
      Serial.print("SNR: ");
      Serial.println(snr);

      //Display rssi of last received signal
      int rssi = driver.lastRssi();
      rssiPos = -rssi;

      Serial.print("Rssi: ");
      Serial.println(rssi);
          
}
