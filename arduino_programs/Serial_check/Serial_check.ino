void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
  while(!Serial)
  {
    ;
  }

}

void loop()
{
  if(Serial.available()>0)
  {
    Serial1.write(Serial.read());
  }
 
 timeplease();

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
}

