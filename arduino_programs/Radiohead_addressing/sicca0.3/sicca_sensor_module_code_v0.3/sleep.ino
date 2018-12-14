//Function for burning a few analog readings
/*FUNCITON NAME: sleep
   INPUT:   NONE
   OUTPUT:  NONE
   LOGIC: uses sleep library to put MCU to sleep
   EXAMPLE CALL:  gotosleep()
*/
void gotosleep()
{
  Serial.print(F("sleeping for 8 sec "));
  if (!rf95.sleep())
    Serial.println(F("LoRa cant sleep"));
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(500);
  for(int i = 0; i< ; i++)
  {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
}
