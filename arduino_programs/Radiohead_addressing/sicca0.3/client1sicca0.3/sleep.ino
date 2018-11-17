//Function for burning a few analog readings
/*FUNCITON NAME: sleep
 * INPUT:   NONE 
 * OUTPUT:  NONE
 * LOGIC: uses sleep library to put MCU to sleep
 * EXAMPLE CALL:  gotosleep()
 */
void gotosleep()
{
  Serial.print(F("sleeping for 3 min "));
  delay(100);
  if(!driver.sleep())
    Serial.println(F("LoRa cant sleep"));
  
  for(int i = 0; i< 24; i++)
  {
  //LowPower.powerDown(SLEEP_8S,ADC_OFF,BOD_OFF);
  }
}
