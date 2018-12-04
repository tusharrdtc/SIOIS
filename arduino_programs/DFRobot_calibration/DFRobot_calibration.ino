int avgVal = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Give time to settle the sensor");
  for(int i = 8; i>0; i--)
  {
    for(int j = 60; j > 0; j--)
    {
      Serial.print("Remaining time is: ");
      Serial.print(i);
      Serial.print(" MINUTES ");
      Serial.print(j);
      Serial.println(" SECONDS");
      delay(1000);
    }
}
  Serial.print("A008");
//  Serial.print("   A009");
//  Serial.println("   A010");
}

void loop()
{
  int x0 = average(0);
//  int x1 = average(1);
//  int x2 = average(2);
  //int x3 = average(3);
  Serial.println(x0);
//  Serial.print("    ");
//  Serial.print(x1);
//  Serial.print("    ");
//  Serial.println(x2);
  delay(5000);
}
int average(int pin) {

  burn8Readings(pin);
  int readings[10];      // the readings from the analog input
  int total = 0;                  // the running total

  for(int readIndex=0; readIndex<10; readIndex++)
  {
  // read from the sensor:
  readings[readIndex] = analogRead(pin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  delay(100); 
  }
  
   // calculate the average:
   avgVal = total / 10;

   return avgVal;
   
}
void burn8Readings(int pin)
{
  
  //Serial.println("In burn loop");
  for (int i = 0; i < 8; i++)
  {
    analogRead(pin);
    delay(50);
  }
}
