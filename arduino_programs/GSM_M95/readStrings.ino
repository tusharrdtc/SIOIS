int readStrings(int timeout)
{

  int  index = 0;
  int  inByte = 0;
  char WS[3];

  //----- erase GSM_string
  memset(GSM_string, 0, BUFFER_SIZE);
  memset(WS, 0, 3);

  //----- clear Serial Line Buffer
  Serial1.flush();
  while (Serial1.available()) {
    Serial1.read();
  }

  //----- wait of the first character for "timeout" ms
  Serial1.setTimeout(timeout);
  inByte = Serial1.readBytes(WS, 1);
  GSM_string[index++] = WS[0];

  //----- wait of further characters until a pause of 30 ms occures
  while (inByte > 0)
  {
    Serial1.setTimeout(1000);
    inByte = Serial1.readBytes(WS, 1);
    GSM_string[index++] = WS[0];
  }
  Serial.println(GSM_string);
  //Serial.println("test");

  if (strstr(GSM_string, "OK\r\n"))            {
    return 1;
  }
  if (strstr(GSM_string, "CONNECT\r\n"))      {
    return 4;
  }

  return 0;
}
