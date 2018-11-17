//Function for burning a few analog readings
/*FUNCITON NAME: transmit
   INPUT:   NONE
   OUTPUT:  NONE
   LOGIC: Transmits data & checks for acknowledgement
   EXAMPLE CALL:  transmit()
*/
void transmit()
{

  Serial.println(F("Sending to rf95_reliable_datagram_server"));
  // Send a message to rf95_server
  if (manager.sendtoWait(buf1, sizeof(buf1), SERVER_ADDRESS))
  {
    // Now wait for a reply
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    uint8_t from;

    if (manager.recvfromAckTimeout(buf, &len, 2000, &from))
    {
        Serial.print(F("got reply from : 0x"));
        Serial.println(from, DEC);
        Serial.print(F(": "));
        Serial.println((char*)buf);
        Serial.print(F("RSSI: "));
        Serial.println(driver.lastRssi(), DEC);
      }
      else
      {
        Serial.println(F("No reply, is rf95_reliable_datagram_server running?"));
      }
    }
    else
    {
      Serial.println(F("sendtoWait failed"));
    }

  }
