//int gsm()
//{
//
//  int flagGSM = 0;
//  int statusCode;
//
//  if (battVolt < 3.3 && batt_flag == 0)
//  {
//    if (flagGSM == 0)
//    {
//      Serial1.print("AT\r\n");  //Test command
//      if (readStrings(1000) == 1)  {
//        flagGSM++;
//      }
//      else {
//        statusCode == 1000;
//      }
//    }
//
//    if (flagGSM == 1)
//    {
//      Serial1.print("AT+CMGF=1\r\n"); //to select SMS message format (PDU or text)
//      if (readStrings(1000) == 1)  {
//        flagGSM++;
//      }
//      else {
//        statusCode == 1000;
//      }
//    }
//
//    if (flagGSM == 2)
//    {
//      //      Serial1.print("AT+CMGS=\"7066485916\"\r\n");  //Send SMS message
//      //      readStrings(1000);
//      Serial1.print("AT+CMGS=\"");
//      Serial1.print(mynumber);
//      Serial1.println("\"");  //Send SMS message
//      Serial1.print("BATTERY LOW!");
//      Serial1.write(26);
//      if (readStrings(1000) == 1)  
//      {
//        flagGSM++;
//      }
//      else 
//      {
//        statusCode == 1000;
//      }
//    }
//
//    if (flagGSM == 3)
//    {
//      Serial.print("Msg sent successfully!");
//      batt_flag = 1;
//      flagGSM = 0;
//    }
//
//    if (statusCode == 1000)
//    {
//      Serial.print("Sending Failed!");
//      flagGSM = 0;
//    }
//  }
//
//
