//Function for turning ON the single phase motor
/*
   Function Name: relay1phase
   Input: none
   Output: none
   Logic: if soil is dry switch ON the relay
   Example Call: relay1phase()
*/
void relay1phase()
{
  if (soilMoist >= wp  && manual_val==1)
  {
    digitalWrite(relayPin1, LOW);
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("ON  ");
    pumpStat = 1;
    pump[0]='O';
    pump[1]='N';
    pump[2]=' ';
    pump[3]=' ';
    pump[4]=' ';
    pump[5]=' ';
  }
  if (soilMoist <= fc  && manual_val==1)
  {
    digitalWrite(relayPin1, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("OFF ");
    pumpStat = 0;
    pump[0]='O';
    pump[1]='F';
    pump[2]='F';
    pump[3]=' ';
    pump[4]=' ';
    pump[5]=' ';
  }
}
