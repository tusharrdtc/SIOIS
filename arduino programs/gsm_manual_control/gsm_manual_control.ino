#define BUFFER_SIZE 250
char  GSM_string[250];
//char pump[4];
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600); 
}

void loop()
{
  manual();
}

int readStrings(int timeout)
{
  
  int  index = 0;
  int  inByte = 0;
  char WS[3];
  int i=0, j=0, k=0, l=0;
  char pump[4]={'O','F','F'};
  
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
  if(strstr(GSM_string, "+917066485916"))            
  { 
    Serial.println("Number Matched");
    i=1;
  }
  if(strstr(GSM_string, "ON"))  
  {
    Serial.println("Keyword Matched for ON condition");
    j=1; 
   }
  if(strstr(GSM_string, "OFF"))    
  {
    Serial.println("Keyword Matched for OFF condition");
    k=1;
  }

  if(strstr(GSM_string, "STATUS"))    
  {
    Serial.println("Your status of SICCA will be sent on registerd mobile number");
    l=1;
  }
  if(i==1 && j==1)
  {
    Serial.println("PUMP ON");
    pump[4]='O','N',' ';
  }
  if(i==1 && k==1)
  {
    Serial.println("PUMP OFF");
    pump[4]='O','F','F';
  }

//    if(l == 1)
//    {
//      Serial1.print("AT+CMGF=1\r\n");
//      readStrings(1000);
//      Serial1.print("AT+CMGS=\"7066485916\"\r\n");
//      readStrings(1000);
//      Serial1.print("SM=450, ST=26, HUM= 56, TEMP=28, Pump status=");
//      for(int x=0; x<3;x++)
//      {
//       Serial1.print(pump[x]);
//      }
//      Serial1.write(26);
//      Serial.println("pump");
//      Serial.println("Your SMS has been sent on your registered mobile number.");
//    }
  return 0;
}
void manual()
{
//  Serial1.println("AT+CMGD=1,4");       //delete all SMS
//  readStrings(1000);
//  Serial.println("Your all SMS has been deleted"); 
//  delay(1000);
  Serial.println("START");
  Serial1.println("AT+CMGF=1");            //set GSM in text mode
  readStrings(1000);
  Serial1.println("AT+CMGR=1");            //read SMS with index 1 
  readStrings(1000);
  Serial1.println("AT+CMGR=2");            //read SMS with index 2 
  readStrings(1000);
  Serial1.println("AT+CMGR=3");            //read SMS with index 3 
  readStrings(1000);
  delay(100);
  Serial1.println("AT+CMGR=4");            //read SMS with index 4 
  readStrings(1000);
  delay(100);
  Serial1.println("AT+CMGR=5");            //read SMS with index 4 
  readStrings(1000);
  delay(100);
  Serial.println("END");
  delay(5000);
}

