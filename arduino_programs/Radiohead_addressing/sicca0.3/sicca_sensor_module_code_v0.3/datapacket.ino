//Function for reading & processing data
/*FUNCITON NAME: datapacket
 * INPUT:   NONE
 * OUTPUT:  Data in bytes
 * LOGIC: Reads data & stores them in byte form
 * EXAMPLE CALL:  datapacket()
 */

void datapacket()
{
  //Serial.println("In datapacket loop");
  //digitalWrite(3, HIGH);
  // Command all devices on bus to read temperature  
  sensors.requestTemperatures();
  delay(1000);
  analogReference(DEFAULT);
  int x0=average(A0);                          //soil moisture sensor
  int x1=  int(sht20.readTemperature());       //temp sensor
  int x2=  int(sht20.readHumidity());         //humidity sensor
  int x3=  printTemperature(Probe01);         //soil temperature sensor
  int x4 = average(A1);
  int x5 = average(A2);
  int x6 = printTemperature(Probe02);
  int x7 = printTemperature(Probe03);
  int x9 = lightMeter.readLightLevel();       //gy30sensor data

  /*-----(Soil Moisture sensor 1)------*/
  int y0=x0/255;           //lower byte of analog sensor 1
  int z0=x0%255;           //upper byte of analog sensor 1
  Serial.print(F("soil moisture of Sensor 1 is: "));
  Serial.println(x0);
  buf1[0]=byte(y0);        //storing lower byte of sensor 1 to array element
  buf1[1]=byte(z0);        //storing upper byte of sensor 1 to array element
  
  /*-----(Temperature sensor)----*/
  int y1=x1/255;           //lower byte of temp sensor
  int z1=x1%255;           //upper byte of temp sensor
  Serial.print(F("temp. is: "));
  Serial.println(x1);
  buf1[2]=byte(y1);        //storing lower byte of temp sensor to array element
  buf1[3]=byte(z1);        //storing upper byte of temp sensor to array element
  
  /*-----(Humidity sensor)------*/
  int y2=x2/255;           //lower byte of humidity sensor
  int z2=x2%255;           //upper byte of humidity sensor
  Serial.print(F("hum. is: "));
  Serial.println(x2);
  buf1[4]=byte(y2);        //storing lower byte of humidity sensor to array element
  buf1[5]=byte(z2);        //storing upper byte of humidity sensor to array element
  
  /*-----(Soil Tempereature sensor 1)----*/
  int y3=x3/255;           //lower byte of ST sensor
  int z3=x3%255;           //upper byte of ST sensor
  Serial.print(F("soil temp1 is: "));
  Serial.println(x3);
  buf1[6]=byte(y3);        //storing lower byte of ST sensor to array element
  buf1[7]=byte(z3);        //storing upper byte of ST sensor to array element

  /*-----(Sensor Battery)------*/
  analogReference(INTERNAL);
  int x8=average(A3);   //battery analog reading
  Serial.print(F("battery voltage is: "));
  Serial.println(x8);
  int y8=x8/255;           //lower byte of analog sensor 2
  int z8=x8%255;           //upper byte of analog sensor 2
  buf1[8]=byte(y8);        //storing lower byte of sensor 2 to array elementy
  buf1[9]=byte(z8);        //storing upper byte of sensor 1 to array element

  /*-----(Soil Moisture sensor 2)----*/
  int y4=x4/255;           //lower byte of analog sensor 1
  int z4=x4%255;           //upper byte of analog sensor 1
  Serial.print(F("soil moisture of Sensor 2 is: "));
  Serial.println(x4);
  buf1[10]=byte(y4);        //storing lower byte of sensor 1 to array element
  buf1[11]=byte(z4);        //storing upper byte of sensor 1 to array element

 /*-----(Soil Moisture sensor 3)------*/
  int y5=x5/255;           //lower byte of analog sensor 1
  int z5=x5%255;           //upper byte of analog sensor 1
  Serial.print(F("soil moisture of Sensor 3 is: "));
  Serial.println(x5);
  buf1[12]=byte(y5);        //storing lower byte of sensor 1 to array element
  buf1[13]=byte(z5);        //storing upper byte of sensor 1 to array element

  /*-----(Soil Temoperature sensor 2)----*/
  int y6=x6/255;           //lower byte of ST sensor
  int z6=x6%255;           //upper byte of ST sensor
  Serial.print(F("soil temp2 is: "));
  Serial.println(x6);
  buf1[14]=byte(y6);        //storing lower byte of ST sensor to array element
  buf1[15]=byte(z6);        //storing upper byte of ST sensor to array element

 /*-----(Soil Temoperature sensor 3)----*/
  int y7=x7/255;           //lower byte of ST sensor
  int z7=x7%255;           //upper byte of ST sensor
  Serial.print(F("soil temp3 is: "));
  Serial.println(x7);
  buf1[16]=byte(y7);        //storing lower byte of ST sensor to array element
  buf1[17]=byte(z7);        //storing upper byte of ST sensor to array element

  /*----(Sending Node id)------*/
  buf1[18]=node_id;              
  Serial.print(F("node_id is: "));
  Serial.println(node_id);
  Serial.println("");
  node_id=node_id+1;
  if(node_id>254)
  {
    node_id=1;
  }

  /*------(Sending gy30reading)----*/
  int y9 = x9/255;
  int z9 = x9%255;
  buf1[19]=byte(y9);
  buf1[20]=byte(z9);
  Serial.print(F("Light is: "));
  Serial.print(x9);
  Serial.println(" lux");

}
