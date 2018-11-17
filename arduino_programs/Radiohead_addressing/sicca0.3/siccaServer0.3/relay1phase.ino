//Function for turning ON the single phase motor
/*
   Function Name: relay1phase
   Input: none
   Output: none
   Logic: if soil is dry, switch ON the relay
   Example Call: relay1phase()
*/
void relay1phase()
{
  //  dataString += String(millis());
  //  dataString += " relay1phase starts";
  //  sd();
  //  dataString=" ";
  if ((soilMoist11 >= wp || soilMoist21 >= wp)  && manual_val == 0 && timer_flag != 1)
  {
    Serial.println(F("PUMP IS ON"));
    digitalWrite(relayPin1, LOW);
    lcd.setCursor(0, 3);
    lcd.print(F("PUMP STATUS: "));
    lcd.setCursor(13, 3);
    lcd.print(F("ON(A)  "));
    pumpStat = 1;
    pump[0] = 'O';
    pump[1] = 'N';
    pump[2] = ' ';
    pump[3] = ' ';
    pump[4] = ' ';
    pump[5] = ' ';
    if (soilMoist11 == soilMoist21)
    {
      if (soilMoist11 < fc)
      {
        Serial.println(F("NODE 1 IS ON"));
        digitalWrite(relayPin3, LOW);
      }
      else
      {
        Serial.println(F("NODE 2 IS ON"));
        digitalWrite(relayPin4, LOW);
      }
    }
    else if (soilMoist11 > soilMoist21)
    {
      Serial.println(F("NODE 2 IS ON"));
      digitalWrite(relayPin4, LOW);
    }
    else
    {
      Serial.println(F("NODE 1 IS ON"));
      digitalWrite(relayPin3, LOW);
    }
  }
  if (soilMoist11 <= fc && soilMoist21 <= fc  && manual_val == 0 && timer_flag == 0)
  {
    Serial.println(F("PUMP IS OFF"));
    digitalWrite(relayPin1, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("OFF(A) ");
    pumpStat = 0;
    pump[0] = 'O';
    pump[1] = 'F';
    pump[2] = 'F';
    pump[3] = ' ';
    pump[4] = ' ';
    pump[5] = ' ';
  }
  //  dataString += String(millis());
  //  dataString += " relay1phase end";
  //  sd();
  //  dataString=" ";
}
