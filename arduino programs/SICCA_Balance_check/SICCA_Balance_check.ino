#define BUFFER_SIZE 250
char  GSM_string[250];
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.println("AT+CMGF=1");            //set GSM in text mode
  readStrings(1000);
}

void loop()
{
   Serial.println("START");
   for(int i=1;i<21;i++)
   {
   Serial1.print("AT+CMGR=");
   Serial1.println(i);            
   readStrings(1000);
   balance();
   delay(1000);
   if(i==21)
   {
    Serial1.println("AT+CMGD=1,4");       //delete all SMS
    readStrings(1000);
    Serial.println("Your all SMS has been deleted"); 
    delay(1000);
   }
   }
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
    Serial1.setTimeout(10000);
    inByte = Serial1.readBytes(WS, 1);
    GSM_string[index++] = WS[0];
  }
  Serial.println(GSM_string);
  //Serial.println("test");
  return 0;
}
void timeplease()
{
  for(int i=0; i<20;i++)
  {
    if(Serial1.available()>0)
    {
      Serial.write(Serial1.read());
    }
  }
  delay(100);
}
void balance()
{
  int i=0, j=0, k=0, l=0;
   if(strstr(GSM_string, "+917066485916"))      
  {
     i=1;
     Serial.println("number matched"); 
  }
  if(strstr(GSM_string, "BAL")) 
  { 
    j=1;
    Serial.println("keyword matched for balance check");
   }
   if(i==1  && j==1)
   {
    Serial.println("Please wait, we will send balance SMS to you!");
//    Serial1.println("AT+CMGF=1");
//    readStrings(1000);
    Serial1.println("AT+CUSD=1,*141*23#");
    readStrings(120000);
    //Serial1.println("AT+CMGS=\"+917066485916\"\r");
//    delay(1000);
//    timeplease();
    Serial1.println(GSM_string);
//    delay(1000);
//    timeplease();
    Serial1.println(char(26));
    Serial.println("END");
//    timeplease();
    delay(3000);
    Serial.println("next iteration starts");
    Serial1.println("AT+CUSD=1, *111*2*2#");
    readStrings(120000);
    //Serial1.println("AT+CMGS=\"+917066485916\"\r");
//    delay(1000);
//    timeplease();
    Serial1.println(GSM_string);
//    delay(1000);
//    timeplease();
    Serial1.println(char(26));
    delay(1000);
    timeplease();
    Serial.println("Your SMS has been sent");
   }
//  if(strstr(GSM_string, "+QPING:"))           { return 12; }

}

