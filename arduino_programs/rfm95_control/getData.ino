void getData()
{
  if(rf95.available())
  {
    uint8_t len1 = sizeof(buf);
    if(rf95.recv(buf, &len1))
    {
      Serial.println("");
      Serial.print(F("got request from : "));
      Serial.print((char*)buf);
      Serial.print(": ");

      uint8_t data[] = "got packets";
      rf95.send(data, sizeof(data));
      rf95.waitPacketSent();
      flag = 1;
    }
  }
  else
  {
    Serial.println("Lora is not available");
  }
  delay(1000);
}
