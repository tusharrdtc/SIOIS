int timesTosend=1;
int count=0;
char phone_no[]="7066485916";  //phone number
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.print("\r");
  delay(2000);
  Serial1.write("AT+CSMS=0");
  delay(200);
  while(1)
  {
  if(Serial1.available()>0)
  {
  Serial.write(Serial1.read());
  }
  delay(1000);
  }
  //Serial.write("AT+CMGF=1");
  //delay(200);
  
  /*Serial.write("AT+CMGF=1");
  delay(200);
  Serial.write("AT+CMGR=1");
  while(1)
  {
  if(Serial.available()>0)
  {
    Serial.write(Serial.read());
  }
  }
  delay(5000);*/
}
void loop()
{
  while(count<timesTosend)
   {
    delay(1500);
    Serial1.write("AT+CMGL=ALL");
    delay(200);
    Serial1.write("AT+CMGR=1");
    delay(200);
    ////////THE PART IS FOR SEND SMS///////
    /*
    Serial.print("AT+CMGS=\"");
    Serial.print(phone_no);
    Serial.println("\"");
    while(Serial.read()!='>');
    {
      Serial.print("Test Message from Arduino GSM….HELLO..!!!");  //SMS body
      delay(500);
      Serial.write(0x1A);  // sends ctrl+z end of message
      Serial.write(0x0D);  // Carriage Return in Hex
      Serial.write(0x0A);  // Line feed in Hex
      //The 0D0A pair of characters is the signal for the end of a line and beginning of another.
      delay(5000);
    }
    count++;
   */}
}

