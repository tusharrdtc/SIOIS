//Function to display battery status
/*
 * Function Name: gsm
 * Input: none
 * Output: Sends message to user
 * Logic: Sends battery low & check sensor module messages in case no data is received
 * Example Call: gsm()
 */
 
int gsm()
{ 
  int flagGSM = 0;
  int statusCode;
  
  if(battVolt < 3.3)
  { 
    
    
    if(flagGSM == 0)
    {
      Serial1.print("AT\r\n");  //Test command
      if(readStrings(1000) == 1)  {flagGSM++;}
      else {statusCode == 1000;}
    }

    if(flagGSM == 1)
    {
      Serial1.print("AT+CMGF=1\r\n"); //to select SMS message format (PDU or text)
      if(readStrings(1000) == 1)  {flagGSM++;}
      else {statusCode == 1000;}
    }

    if(flagGSM == 2)
    {
      Serial1.print("AT+CMGS=\"7066485916\"\r\n");  //Send SMS message
      readStrings(1000);
      Serial1.print("BATTERY LOW!");
      Serial1.write(26);
      if(readStrings(1000) == 1)  {flagGSM++;}
      else {statusCode == 1000;}
    }

    if(flagGSM == 3)
    {
      Serial.print("Msg sent successfully!");
    }

    if(statusCode == 1000)
    {
      Serial1.print("Sending Failed!");
    }
  }

  if(flagGetData == 1)        //to send sms when no data comes
  {
     if(flagGSM == 0)          
    {
      Serial1.print("AT\r\n");
      if(readStrings(1000) == 1)  {flagGSM++;}
      else {statusCode == 1000;}
    }

    if(flagGSM == 1)
    {
      Serial1.print("AT+CMGF=1\r\n");
      if(readStrings(1000) == 1)  {flagGSM++;}
      else {statusCode == 1000;}
    }

    if(flagGSM == 2)
    {
      Serial1.print("AT+CMGS=\"7066485916\"\r\n");
      readStrings(1000);
      Serial1.print("CHECK SENSOR MODULE!");
      Serial1.write(26);
      if(readStrings(1000) == 1)  {flagGSM++;}
      else {statusCode == 1000;}
    }

    if(flagGSM == 3)
    {
      Serial.print("Msg sent successfully!");
    }

    if(statusCode == 1000)
    {
      Serial1.print("Message Sending Failed!");
    }
    flagGetData=0;
    flagGet=1;
  }

  return 0;
}
