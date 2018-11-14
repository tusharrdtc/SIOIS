int flag=0;
void setup() 
{
Serial.begin(9600);  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}

void loop()
{
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      Serial.println("PULSE TO TURN ON PUMP");
      for(int i=0; i<2; i++)
   {
      Serial.println(i);
      delay(1000);
   }
  digitalWrite(2, HIGH);
  delay(10000);
  //LOGIC TO TURN OFF THE PUMP
  Serial.println("PULSE TO TURN OFF PUMP");
  digitalWrite(3, LOW); 
  for(int i=0; i<2; i++)
  {
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH); 
  
  
   delay(10000);
}
