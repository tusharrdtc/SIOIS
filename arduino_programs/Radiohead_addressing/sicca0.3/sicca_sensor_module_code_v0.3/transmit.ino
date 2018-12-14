  //Function for burning a few analog readings
/*FUNCITON NAME: transmit
 * INPUT:   NONE
 * OUTPUT:  NONE
 * LOGIC: Transmits data & checks for acknowledgement
 * EXAMPLE CALL:  transmit()
 */
  void transmit()
  {
    Serial.println(F("Sending to rf95_reliable_datagram_server"));
  rf95.send(buf1, sizeof(buf1));
  
  rf95.waitPacketSent();
  // Now wait for a reply
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  if (rf95.waitAvailableTimeout(3000))
  { 
    // Should be a reply message for us now   
    if (rf95.recv(buf, &len))
   {
      Serial.print("got reply: ");
      Serial.println((char*)buf);
//      Serial.print("RSSI: ");
//      Serial.println(rf95.lastRssi(), DEC);    
    }
    else
    {
      Serial.println(F("recv failed"));
    }
  }
  else
  {
    Serial.println(F("No reply, is rf95_server running?"));
  }
  delay(400);

  }
