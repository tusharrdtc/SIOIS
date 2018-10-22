int a=500;
int q=1;
int colm1,colm2,colm3,colm4;

void setup()
{
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(22,INPUT);
  Serial.begin(9600);
  digitalWrite(13,HIGH);
  digitalWrite(14,HIGH);
  digitalWrite(15,HIGH);
  digitalWrite(22,HIGH);
  Serial.print("initial values is");
  Serial.println(a);
}
void loop()
{
  digitalWrite(9,LOW);
  colm1=digitalRead(13);
  colm2=digitalRead(14);
  colm3=digitalRead(15);
  colm4=digitalRead(22);

   if(colm1==LOW || colm2==LOW || colm3==LOW  || colm4==LOW)
   {
   if(colm1==LOW || colm2==LOW || colm3==LOW)
       {
          if(colm1==LOW && q==1)
          {
            a=a-5;
            Serial.println(a);
            q=1;
            delay(200);
          
            Serial.println(a);
          }
          if(colm2==LOW && q==1)
          {
            a=a+5;
            q=1;
            Serial.println(a);
          
            delay(200);  
          }
        if(colm3==LOW)
        {
          q=0;
          Serial.println(a);
          
          delay(200);
         }
      }
   }
   if(colm4==LOW)
   {
    Serial.println("exit");
   }
}


