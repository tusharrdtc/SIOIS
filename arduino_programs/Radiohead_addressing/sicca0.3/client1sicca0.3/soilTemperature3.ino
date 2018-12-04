//Function for burning a few analog readings
/*FUNCITON NAME: soilTemperature
 * INPUT:   NONE 
 * OUTPUT:  NONE
 * LOGIC: 
 * EXAMPLE CALL:  st()
 */

int st2()
{
  if(!ds2.search(addr)) 
  {
    ds2.reset_search();
    delay(250);
    //
    //return;
  }
  if (OneWire::crc8(addr, 7) != addr[7]) 
  {
      Serial.println("CRC is not valid!");
      //return;
  }
  ds2.reset();
  ds2.select(addr);
  ds2.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  present = ds2.reset();
  ds2.select(addr);    
  ds2.write(0xBE);         // Read Scratchpad
  for (byte i = 0; i < 9; i++)  //We need 9 bytes
  {           
    data[i] = ds2.read();
  }
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) 
  {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) 
    {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } 
  else 
  {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  return int(celsius);
  delay(500);
}
