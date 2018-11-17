//Function to display battery status
/*
   Function Name: gsm
   Input: none
   Output: Sends message to user
   Logic: Sends battery low & check sensor module messages in case no data is received
   Example Call: gsm()
*/

int gsm()
{
//  dataString += String(millis());
//  dataString += " gsm starts";
//  sd();
//  dataString = " ";
  int flagGSM = 0;
  int statusCode;

  if (battVolt < 3.3 && (batt_flag == 0  || batt_flag == 21 ||  batt_flag == 41))
  {
    if (flagGSM == 0)
    {
      Serial1.print("AT\r\n");  //Test command
      if (readStrings(1000) == 1)  {
        flagGSM++;
      }
      else {
        statusCode == 1000;
      }
    }

    if (flagGSM == 1)
    {
      Serial1.print("AT+CMGF=1\r\n"); //to select SMS message format (PDU or text)
      if (readStrings(1000) == 1)  {
        flagGSM++;
      }
      else {
        statusCode == 1000;
      }
    }

    if (flagGSM == 2)
    {
      //      Serial1.print("AT+CMGS=\"7066485916\"\r\n");  //Send SMS message
      //      readStrings(1000);
      Serial1.print("AT+CMGS=\"");
      Serial1.print(mynumber);
      Serial1.println("\"");  //Send SMS message
      Serial1.print("BATTERY LOW!");
      Serial1.write(26);
      if (readStrings(1000) == 1)  {
        flagGSM++;
      }
      else {
        statusCode == 1000;
      }
    }

    if (flagGSM == 3)
    {
      Serial.print(F("Msg sent successfully!"));
      batt_flag = batt_flag + 1;
      if(batt_flag >= 41)
      {
        batt_flag == 1;
        batt_flag == 2*batt_flag;
      }
      flagGSM = 0;
    }

    if (statusCode == 1000)
    {
      Serial1.print("Sending Failed!");
      flagGSM = 0;
    }
  }
  if(battVolt <=3.3)
  {
    batt_flag == 1;
  }

  if (flagGetData == 1)       //to send sms when no data comes
  {
    if (flagGSM == 0)
    {
      Serial1.print("AT\r\n");
      if (readStrings(1000) == 1)  {
        flagGSM++;
      }
      else {
        statusCode == 1000;
      }
    }

    if (flagGSM == 1)
    {
      Serial1.print("AT+CMGF=1\r\n");
      if (readStrings(1000) == 1)  {
        flagGSM++;
      }
      else {
        statusCode == 1000;
      }
    }

    if (flagGSM == 2)
    {
      Serial1.print("AT+CMGS=\"7066485916\"\r\n");
      readStrings(1000);
      Serial1.print("CHECK SENSOR MODULE!");
      Serial1.write(26);
      if (readStrings(1000) == 1)  {
        flagGSM++;
      }
      else {
        statusCode == 1000;
      }
    }

    if (flagGSM == 3)
    {
      Serial.print(F("Msg sent successfully!"));
    }

    if (statusCode == 1000)
    {
      Serial1.print("Message Sending Failed!");
    }
    flagGetData = 0;
    flagGet = 1;
  }

  return 0;
//  dataString += String(millis());
//  dataString += "gsm end";
//  sd();
//  dataString = " ";
}
