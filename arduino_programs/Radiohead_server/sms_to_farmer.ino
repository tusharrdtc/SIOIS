//Function to check is connected or not 
/*
 * Function Name: check_sensor
 * Input: none
 * Output: sending sms to sms farmer 
 * Logic: checking inbox of SIM and compare it with given keyword and if matches then send sms to farmer
 * Example Call: sms_to_farmer()
 */

void sms_to_farmer()
{
  Serial1.println("AT+CMGF=1");
  for (int loop_flag=1; loop_flag<6; loop_flag++)
    {
       Serial1.print("AT+CMGR=");
       Serial1.println(loop_flag);
       readSms(1000);
       if(loop_flag==5 || (check_status_flag==1 && check_net_flag==1 &&  check_sms_flag==1 && check_timer_flag==1))
       {
        Serial1.println("AT+CMGD=1,3");      //delete all unread sms 
       }
       delay(10);
    }
  if(check_sms_flag==1  &&  check_number_flag==1)        //for send sms balance sms to user
     {
      Serial1.println("AT+CUSD=1,*141*23#");
      readSms(500);
      readSms(120000);
      Serial1.println("AT+CMGS=\"+917066485916\"\r");
      Serial1.println(GSM_string);
      Serial1.println(char(26));
      readSms(1000);
     }
  if(check_net_flag==1  &&   check_number_flag==1)        //for send net balance sms to user
     { 
      Serial1.println("AT+CUSD=1,*111*2*2#");
      readSms(500);
      readSms(120000);
      Serial1.println("AT+CMGS=\"+917066485916\"\r");
      Serial1.println(GSM_string);
      Serial1.println(char(26));
      readSms(1000);
     }
    if(check_status_flag==1  && check_number_flag==1)        //for send status sms to user
     {
      Serial1.print("AT+CMGS=\"7066485916\"\r\n");
      readSms(1000);
      Serial1.print("SM= ");
      Serial1.print(soilMoist);
      Serial1.print(" ST= ");
      Serial1.print(soilTemp);
      Serial1.print(" HUM= "); 
      Serial1.print(hum);
      Serial1.print(" TEMP= ");
      Serial1.print(temp);
      Serial1.print(" PUMP STATUS= ");
      for(int x=0; x<6; x++)
       {
         Serial1.print(pump[x]);
       }  
       Serial1.write(26);
     }
   check_sms_flag=0;
   check_net_flag=0;
   check_status_flag=0;
   check_number_flag=0;
   //delay(10000);
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
  while(Serial1.available()) { Serial1.read(); }
  
  //----- wait of the first character for "timeout" ms
  Serial1.setTimeout(timeout);
  inByte = Serial1.readBytes(WS, 1);
  GSM_string[index++] = WS[0];
  
  //----- wait of further characters until a pause of 30 ms occures
  while(inByte > 0)
  {
    Serial1.setTimeout(1000);
    inByte = Serial1.readBytes(WS, 1);
    GSM_string[index++] = WS[0];
    timer_var=index;
  }
  Serial.println(GSM_string);
  
  if(strstr(GSM_string, "SMS"))          
  {
    check_sms_flag=1;
   }
  if(strstr(GSM_string, "NET"))            
  {
    check_net_flag=1;
  }
  if(strstr(GSM_string, "STATUS"))         
  {
    check_status_flag=1;
   }
   if(strstr(GSM_string, "+917066485916"))         
  {
    check_number_flag=1;
   }
   if(strstr(GSM_string, "TIMER"))         
  {
    check_timer_flag=1;
  }

  return 0;
}
