//Function to upload data on the internet
/*
 * Function Name: gprs
 * Input: none
 * Output: uploads data on the web server
 * Logic: 
 * Example Call: gprs()
 */
int gprs()
{ 
  int flagGprs = 1;
  int statusCode = 0;
  char batvalue[5]; //variable to store battery voltage value
  unsigned int interval = 5000; //one minute in ms
  
  dtostrf(battVolt , 4 , 2 , batvalue); //convert float into string
 
  if(flagGprs == 1)
  {
    Serial1.print("AT\r\n");  //Test command
    if(readStrings(1000) == 1)
    {
    flagGprs++;}
    else  {statusCode = 1000;}

  }
  if(flagGprs == 2)
  {
    Serial1.print("AT+QIFGCNT=0\r\n");  //Select a Context as Foreground Context
    if(readStrings(1000) == 1)
    {
    flagGprs = flagGprs + 2;}
    else  {statusCode = 1000;}
    
  }

  if(flagGprs == 4)
  {
    int len = sprintf(url, "https://www.senseitout.com/write_data_test.php?&data3=%d&data4=%d&data5=%d&data6=%d&data7=%d&data9=%d&data10=%d&data11=%s", from, rssiPos, soilMoist, temp, hum, soilTemp, pumpStat, batvalue);    
    //int len  = sprintf(url,"https://api.thingspeak.com/update?api_key=79IABQSK9NDB39BH&field1=%d&field2=%d&field3=%d&field4=%d&field5=%d",soilMoist,hum,temp,soilTemp,battVolt);  //sends formatted output to a char array url
    sprintf(buff,"AT+QHTTPURL=%d,%d\r\n",len,input_time);  //Send HTTP server url
    Serial1.print(buff);
    if(readStrings(2000) == 4)
    {
    flagGprs++;}
    else  {statusCode = 1000;}

  }

  if(flagGprs == 5)
  {
    Serial1.print(url);
    if(readStrings(60000) == 1)
    {
    flagGprs = flagGprs + 2;}
    else  {statusCode = 1000;}

  }

  if(flagGprs == 7)
  {  Serial1.print("AT+QHTTPGET=60\r\n"); //send HTTP GET request
    readStrings(500);
    if(readStrings(10000) == 1)
      {flagGprs++;}
    else  {statusCode = 1000;}
   }
 
  if(flagGprs == 8)
  {
    Serial.println("DATA UPLOADED!");
    return 1;
    
  }

  if(statusCode == 1000)
 {
 Serial1.print("AT+QIDEACT\r\n"); //Deactivate GPRS/CSD PDP Context
 readStrings(5000);
 readStrings(10000);
 }
 Serial.print("Moving out");
 return 0;
}
