
void co1() 
{
  /*int sensorPin = A0;
  int sensorPin1 = A1;
  int val; 
  int val1; */
   pinMode(sensorPin, INPUT);
   pinMode(sensorPin1, INPUT); 
   int sensorValue = 0;
   int sensorValue1 = 0;
  Serial.print("     ppm");
  Serial.println("        ppm1 ");    //1=inside
} 
void co2() 
{ 
  val = analogRead(A0);
  val1 = analogRead(A1); 
  float ppm = gasSensor.getPPM();
  float ppm1 = gasSensor1.getPPM();
  ppm=ppm-1536;
  //Serial.print("  ");
  Serial.print(ppm);
  Serial.print("      ");
  Serial.print(ppm1);
  Serial.println("      ");
  
} 
