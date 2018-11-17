//Function for turning ON the three phase motor
/*
   Function Name: relay3phase
   Input: none
   Output: none
   Logic: if soil is dry switch ON the relay
   Example Call: relay3phase()
*/

void relay3phase()
{
  if (soilMoist >= wp  && manualPin==1)
  {
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("ON  ");
    pump[0]='O';
    pump[1]='N';
    pump[2]=' ';
    pump[3]=' ';
    pump[4]=' ';
    pump[5]=' ';
    pumpStat = 1;
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, HIGH);
    Serial.println(F("PULSE TO TURN ON PUMP"));
    for (int i = 0; i < 2; i++)
    {
      Serial.println(i);
      delay(1000);
    }
    digitalWrite(relayPin1, HIGH);
  }

  if (soilMoist <= fc  && manualPin==1)
  {
    //LOGIC TO TURN OFF THE PUMP
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("OFF ");
    pump[0]='O';
    pump[1]='F';
    pump[2]='F';
    pump[3]=' ';
    pump[4]=' ';
    pump[5]=' ';
    pumpStat = 0;
    Serial.println(F("PULSE TO TURN OFF PUMP"));
    digitalWrite(relayPin2, LOW);
    for (int i = 0; i < 2; i++)
    {
      Serial.println(i);
      delay(1000);
    }
    digitalWrite(relayPin1, HIGH);
    digitalWrite(relayPin2, HIGH);
  }
}
