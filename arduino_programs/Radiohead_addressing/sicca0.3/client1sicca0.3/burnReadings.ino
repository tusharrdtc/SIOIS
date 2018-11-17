//Function for burning a few analog readings
/*FUNCITON NAME: burnReadings
 * INPUT:   NONE 
 * OUTPUT:  NONE
 * LOGIC: Read 8 readings without taking any action
 * EXAMPLE CALL:  burnReadings()
 */

void burn8Readings(int pin)
{
  
  //Serial.println(F("In burn loop"));
  for (int i = 0; i < 8; i++)
  {
    analogRead(pin);
    delay(50);
  }
}
