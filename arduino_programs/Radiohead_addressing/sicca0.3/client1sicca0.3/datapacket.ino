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
  digitalWrite(3, HIGH);
  analogReference(DEFAULT);
  int x0=average(A0);                 //soil moisture sensor
  int x1=int(sht20.readTemperature());   //temp sensor
  int x2=int(sht20.readHumidity());      //humidity sensor
  int x3=st();                           //soil temperature sensor 
  int y0=x0/255;           //lower byte of analog sensor 1
  int z0=x0%255;           //upper byte of analog sensor 1
  Serial.print(F("soil moisture is: "));
  Serial.println(x0);
  buf1[0]=byte(y0);        //storing lower byte of sensor 1 to array element
  buf1[1]=byte(z0);        //storing upper byte of sensor 1 to array element
  int y1=x1/255;           //lower byte of temp sensor
  int z1=x1%255;           //upper byte of temp sensor
  Serial.print(F("temp. is: "));
  Serial.println(x1);
  buf1[2]=byte(y1);        //storing lower byte of temp sensor to array element
  buf1[3]=byte(z1);        //storing upper byte of temp sensor to array element
  int y2=x2/255;           //lower byte of humidity sensor
  int z2=x2%255;           //upper byte of humidity sensor
  Serial.print(F("hum. is: "));
  Serial.println(x2);
  buf1[4]=byte(y2);        //storing lower byte of humidity sensor to array element
  buf1[5]=byte(z2);        //storing upper byte of humidity sensor to array element
  int y3=x3/255;           //lower byte of ST sensor
  int z3=x3%255;           //upper byte of ST sensor
  Serial.print(F("soil temp is: "));
  Serial.println(x3);
  buf1[6]=byte(y3);        //storing lower byte of ST sensor to array element
  buf1[7]=byte(z3);        //storing upper byte of ST sensor to array element

  analogReference(INTERNAL); 
  int x4=average(A1);   //battery analog reading
  Serial.print(F("battery voltage is: "));
  Serial.println(x4);
  int y4=x4/255;           //lower byte of analog sensor 2
  int z4=x4%255;           //upper byte of analog sensor 2
  buf1[8]=byte(y4);        //storing lower byte of sensor 2 to array element
  buf1[9]=byte(z4);        //storing upper byte of sensor 1 to array element
  buf1[10]=node_id;              //sending node id
  Serial.print(F("node_id is: "));
  Serial.println(node_id);
  Serial.println(F(""));
  node_id=node_id+1;
  if(node_id>254)
  {
    node_id=1;
  }
 
}
