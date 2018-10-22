void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  general_gsm();
  Serial1.println("AT+CSCA?");                //SMS service center address 
  delay(5000);
  timeplease();
  Serial1.println("AT+CPMS=?");              //To check SMS storage location
  delay(5000);
  timeplease();
  Serial.println("");
  delay(1000);
//  Serial1.println("AT+CMGD=1, 2");                  //Delete all read SMS
//  delay(5000);
//  timeplease();
//  Serial1.println("AT+CMGL=ALL");              //To List all SMS
//  delay(5000);
//  timeplease();
//  Serial1.println("AT+CMGL=ALL");
//  delay(200);
//  timeplease();
  Serial1.println("AT+CMGR=1");
  timeplease();
  Serial1.println("AT+CMGR=2");
  timeplease();
  Serial1.println("AT+CMGR=3");
  timeplease();
  Serial1.println("AT+CMGR=4");
  timeplease();
  Serial1.println("AT+CMGR=5");
  timeplease();
  Serial1.println("AT+CMGR=6");
  timeplease();
  Serial1.println("AT+CMGR=7");
  timeplease();
  Serial1.println("AT+CMGR=8");
  timeplease();
  Serial1.println("AT+CMGR=9");
  timeplease();
  Serial1.println("AT+CMGR=10");
  timeplease();
  Serial1.println("AT+CMGR=11");
  timeplease();
  Serial1.println("AT+CMGR=12");
  timeplease();
  Serial1.println("AT+CMGR=13");
  timeplease();
  Serial1.println("AT+CMGR=14");
  timeplease();
  Serial1.println("AT+CMGR=15");
  timeplease();
  Serial1.println("AT+CMGR=16");
  timeplease();
  
//  Serial1.println("AT+CPMS='SM','SM','SM'");   //To set SIM storage for upcoming MSG
//  delay(5000);
//  timeplease();
//send_sms();
}
void loop()
{
   if (Serial1.available() > 0)
    {
      Serial.write(Serial1.read());
      //delay(1000);
    }
}
void timeplease()
{
  for (int i = 0; i < 20000; i++)
  {
    if (Serial1.available() > 0)
    {
      Serial.write(Serial1.read());
      //delay(1000);
    }
  }
}
void send_sms()
{
  Serial1.println("AT+CMGS=\"+917066485916\"\r");       //enter your mobile number
  delay(1000);
  timeplease();
  Serial1.println("Baattery Low");        //content of SMS
  delay(1000);
  timeplease();
  Serial1.println(char(26));           //end character Z
  delay(1000);
  timeplease();
}

void general_gsm()
{
  Serial1.println("AT");         //Test command
  delay(1000);
  timeplease();
  Serial1.println("AT+CMGF=1");      //to anable GSM in Text mode
  delay(1000);
  timeplease();
}
void receive_sms()
{

}

