#define BUFFER_SIZE 250 //Size of array in readStrings function
char  GSM_string[250];  
char pump[3]={'O','O','F'};
bool check_sms_flag=0;
bool check_net_flag=0;
bool check_status_flag=0;
bool check_number_flag=0;
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop()
{
  Serial1.println("AT+CMGF=1");
  for (int m=1; m<21; m++)
    {
       Serial1.print("AT+CMGR=");
       Serial1.println(m);
       readStrings(1000);
       if(m==20 || (check_status_flag==1 && check_net_flag==1 &&  check_sms_flag==1))
       {
        Serial1.println("AT+CMGD=1,3");      //delete all unread sms 
       }
       delay(10);
    }
  if(check_sms_flag==1  &&  check_number_flag==1)        //for send sms balance sms to user
     {
      Serial1.println("AT+CUSD=1,*141*23#");
      readStrings(500);
      readStrings(120000);
      Serial1.println("AT+CMGS=\"+917066485916\"\r");
      Serial1.println(GSM_string);
      Serial1.println(char(26));
      readStrings(1000);
     }
  if(check_net_flag==1  && check_number_flag==1)        //for send net balance sms to user
     { 
      Serial1.println("AT+CUSD=1,*111*2*2#");
      readStrings(500);
      readStrings(120000);
      Serial1.println("AT+CMGS=\"+917066485916\"\r");
      Serial1.println(GSM_string);
      Serial1.println(char(26));
      readStrings(1000);
     }
    if(check_status_flag==1  &&  check_number_flag==1)        //for send status sms to user
     {
      Serial1.print("AT+CMGS=\"7066485916\"\r\n");
      readStrings(1000);
      Serial1.print("SM=450, ST=26, HUM= 56, TEMP=28, Pump status=");
      for(int x=0; x<3; x++)
       {
         Serial1.print(pump[x]);
       }  
       Serial1.write(26);
     }
   check_sms_flag=0;
   check_net_flag=0;
   check_status_flag=0;
   check_number_flag=0;
   delay(10000);
}

int readStrings(int timeout)
{
  int  index = 0;
  int  inByte = 0;
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
  }
  Serial.println(GSM_string);
  //Serial.println("test");
  
  //if(strstr(GSM_string, "OK\r\n"))             { return 1; }
  if(strstr(GSM_string, "SMS"))          
  {
    check_sms_flag=1;
   }
  if(strstr(GSM_string, "NET"))            
  {
    check_net_flag=1;
   }
  //if(strstr(GSM_string, "CONNECT\r\n"))        { return 4; }
  if(strstr(GSM_string, "STATUS"))         
  {
    check_status_flag=1;
   }
   if(strstr(GSM_string, "+917066485916"))         
  {
    check_number_flag=1;
   }

  return 0;
}
