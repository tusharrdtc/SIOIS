//Function to display battery status
/*
   Function Name: getData
   Input: none
   Output: Received data from sensor module
   Logic: Receives data using lora & sends ackowledgement
   Example Call: getData()
*/
void getData()
{
  //  dataString += String(millis());
  //  dataString += " getdata starts";
  //  sd();
  //  dataString = " ";
  int var_a = 0;

  //Checks whether data is available
  if (manager.available())
  {
    var_a = 1;
    flagGet = 0;
    lcd.setCursor(11, 0);
    lcd.print("L");

    // Wait for a message addressed to us from the client
    uint8_t len1 = sizeof(buf);
    uint8_t from, to, id, flags;

    //Read data
    if (manager.recvfromAck(buf, &len1, &from, &to, &id, &flags))
    {
      Serial.println(F(""));
      Serial.print(F("got request from : 0x"));
      Serial.print(from, HEX);
      Serial.print(F(": "));
      Serial.print(F("to"));
      Serial.print(to, HEX);
      Serial.print(F(" of id is:"));
      Serial.print(id, HEX);
      Serial.print(F(" "));
      Serial.print((char*)buf);
      Serial.print(F(": "));

      //Sending acknowledgement
      uint8_t data[] = "Your packet has reached, got ackno";
      if(!manager.sendtoWait(data, sizeof(data), from))
      {
        Serial.println(F("sendtoWait failed"));
      }
      flag = 1;
      var_b = 0;
    }
    else
      flag = 0;
    var_c = var_b;
  }
  else

    //Data not available
    if (!manager.available()  && (var_a == 0))
    {
      Serial.print(F("LoRa is not available:"));
      Serial.println(var_b);
      var_b = var_b + 1;
      int var_d = var_b - var_c;

      // wait for 7 minutes then turn off the pump automatically
      if (var_d > 420)
      {
        Serial.println(F("Pump is off, check lora"));
        //////LOGIC FOR 1 PHASE//////
        digitalWrite(relayPin1, HIGH);     //UNCOMMENT THE LINE WHEN YOU ARE USING 1 PHASE

        /*
            USE ONE OF THESE LOGIC. DONT USE BOTH SIMULTANEOUS.
            COMMENT BELOW IF YOU ARE USING 1 PHASE
        */

        //////LOGIC FOR 3 PHASE //////
        //      digitalWrite(relayPin2, LOW);    //UNCOMMENT THE SECTION WHEN YOU ARE USING 3 PHASE
        //      for (int i = 0; i < 1; i++)
        //    {
        //      Serial.println(i);
        //      delay(1000);
        //    }
        //    digitalWrite(relayPin1, HIGH);
        //    digitalWrite(relayPin2, HIGH);
        lcd.setCursor(0, 3);
        lcd.print(F("NO DATA AVAILABLE"));
        if (flagGet == 0)
        {
          flagGetData = 1;
          Serial.println(flagGetData);
        }
        Serial.println(F("Your sensor module is not responding!"));
        var_a = 0;
        var_b = 0;
        var_c = 0;
        lcd.setCursor(11, 0);
        lcd.print(" ");
        lcd.setCursor(7, 0);
        lcd.print(" ");
        delay(1000);
      }
      delay(1000);
    }
  //  dataString += String(millis());
  //  dataString += " getdata end";
  //  sd();
  //  dataString = " ";

}
