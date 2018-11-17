void getData()
{
  dataString += String(millis());
  //Serial.println("sd function");
  dataString += " inside getdata";
  sd();
  dataString=" ";
  if (rf95.available())
  {
//    digitalWrite(5, LOW);
//    delay(1000);
    uint8_t len1 = sizeof(buf);
    if (rf95.recv(buf, &len1))
    {
      Serial.println("got request from : ");
      Serial.print((char*)buf);
      Serial.print(":");

      uint8_t data[] = "GOT PACKETES";
      rf95.send(data, sizeof(data));
      rf95.waitPacketSent();
      flag = 1;
      //digitalWrite(5, HIGH);
    }
  }
  else
  {
    Serial.println("LoRa is not available");
    //delay(1000);
  }
  //digitalWrite(53, HIGH);
  dataString += String(millis());
  //Serial.println("sd function");
  dataString += " getdata end";
  sd();
  dataString=" ";
}
