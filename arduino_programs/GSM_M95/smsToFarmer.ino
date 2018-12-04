//Function to check is connected or not
/*
   Function Name: check_sensor
   Input: none
   Output: sending sms to sms farmer
   Logic: checking inbox of SIM and compare it with given keyword and if matches then send sms to farmer
   Example Call: sms_to_farmer()
*/

void sms_to_farmer()
{
//  dataString += String(millis());
//  dataString += " sms_to_farmer starts";
//  sd();
//  dataString = " ";
  Serial1.println("AT+CMGF=1");
  delay(10);
  for (int loop_flag =1; loop_flag < 6; loop_flag++)
  {
//    Serial.print("loop flag is: ");
//    Serial.println(loop_flag);
    Serial1.print("AT+CMGR=");
    Serial1.println(loop_flag);
    readSms(1000);
    if (loop_flag == 5 || (check_status_flag == 1 && check_net_flag == 1 &&  check_sms_flag == 1 && check_timer_flag == 1))
    {
      Serial1.println("AT+CMGD=1,3");      //delete all read sms
    }
    delay(100);
  }
  if (check_sms_flag == 1  &&  check_number_flag == 1)   //for send sms balance sms to user
  {
    Serial1.println("AT+CUSD=1,*141*23#");
    readSms(500);
    readSms(120000);
    //Serial1.println("AT+CMGS=\"+917066485916\"\r");
    Serial1.print("AT+CMGS=\"");
    Serial1.print(mynumber);
    Serial1.println("\"");  //Send SMS message
    Serial1.println(GSM_string);
    Serial1.println(char(26));
    readSms(1000);
  }
  if (check_net_flag == 1  &&   check_number_flag == 1)   //for send net balance sms to user
  {
    Serial1.println("AT+CUSD=1,*121*2#");
    readSms(500);
    readSms(120000);
    //Serial1.println("AT+CMGS=\"+917066485916\"\r");
    Serial1.print("AT+CMGS=\"");
    Serial1.print(mynumber);
    Serial1.println("\"");  //Send SMS message
    Serial1.println(GSM_string);
    Serial1.println(char(26));
    readSms(1000);
  }
  if (check_status_flag == 1  && check_number_flag == 1)   //for send status sms to user
  {
    //Serial1.print("AT+CMGS=\"7066485916\"\r\n");
    Serial1.print("AT+CMGS=\"");
    Serial1.print(mynumber);
    Serial1.println("\"");  //Send SMS message
    readSms(1000);
    Serial1.print(F("SM= "));
    Serial1.print(soilMoist);
    Serial1.print(F(" ST= "));
    Serial1.print(soilTemp);
    Serial1.print(F(" HUM= "));
    Serial1.print(hum);
    Serial1.print(F(" TEMP= "));
    Serial1.print(temp);
    Serial1.print(F(" PUMP STATUS= "));
    for (int x = 0; x < 6; x++)
    {
      Serial1.print(pump[x]);
    }
    Serial1.write(26);
  }
  check_sms_flag = 0;
  check_net_flag = 0;
  check_status_flag = 0;
  check_number_flag = 0;
}

int readSms(int timeout)
{
  int  index = 0;
  int  inByte = 0;
  int timer_var;
  char WS[3];

  //----- erase GSM_string
  memset(GSM_string, 0, BUFFER_SIZE);
  memset(WS, 0, 3);

  //----- clear Serial Line Buffer
  Serial1.flush();
  while (Serial1.available()) {
    Serial1.read();
  }

  //----- wait of the first character for "timeout" ms
  Serial1.setTimeout(timeout);
  inByte = Serial1.readBytes(WS, 1);
  GSM_string[index++] = WS[0];

  //----- wait of further characters until a pause of 30 ms occures
  while (inByte > 0)
  {
    Serial1.setTimeout(1000);
    inByte = Serial1.readBytes(WS, 1);
    GSM_string[index++] = WS[0];
    timer_var = index;
  }
  Serial.println(GSM_string);

  if (strstr(GSM_string, "SMS"))
  {
    check_sms_flag = 1;
  }
  if (strstr(GSM_string, "NET"))
  {
    check_net_flag = 1;
  }
  if (strstr(GSM_string, "STATUS"))
  {
    check_status_flag = 1;
  }
  if (strstr(GSM_string, mynumber))
  {
    check_number_flag = 1;
  }
  if (strstr(GSM_string, "TIMER"))
  {
    check_timer_flag = 1;       //to check SMS for timer mode
    timer_flag = 1;             //to switch between timer to auto or manual mode
    strcpy(TIMER_string, GSM_string);
  }
  if (strstr(GSM_string, "MYNUMBER") && strstr(GSM_string, "1234"))
  {
    Serial.println("GOT REQUEST TO CHANGE MY NUMBER");
    strcpy(NUMBER_string, GSM_string);
    Serial.println("GSM_string is: ");
    Serial.println(GSM_string);
    check_newnumber_flag = 1;
  }
  return 0;
}
