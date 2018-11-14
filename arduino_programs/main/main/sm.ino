/*void sm()
{
  double volt=0;
  double temp=0;
  double sm=0;
  temp=analogRead(1);
  volt=(temp/1024)*5;
  Serial.println(volt);
  
}*/


void temp() {
 
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  h=h+10;
  h1=h1-10;
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from outside DHT sensor!");
  }
    if (isnan(h1) || isnan(t1)) {
    Serial.println("Failed to read from inside DHT sensor!");
    return;
  }
  //Serial.println("");
  Serial.print(h);
  Serial.print("               ");
  Serial.print(t);
  Serial.print("              ");
  
  /*for(int i=0; i<1;i++)
  {
    for(int j=0;i<60;j++)
    {
    delay(1000);
    }
  }*/
  
  Serial.print(h1);
  Serial.print("               ");
  Serial.print(t1);
  Serial.print("              ");
  //for(int i=0; i<1;i++)
  {
    //for(int j=0;j<60;j++)
    {
    //delay(1000);
    }
  }
  }
