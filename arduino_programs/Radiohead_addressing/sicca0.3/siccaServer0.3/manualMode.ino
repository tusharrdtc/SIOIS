//Function to display battery status
/*
 * Function Name: manualMode
 * Input: manual switch
 * Output: status of pump
 * Logic: check digital logic and gives result
 * Example Call: manualMode()
 */

void manualMode()
{
  //  dataString += String(millis());
  //  dataString += " manual mode starts";
  //  sd();
  //  dataString=" ";
  manual_val = digitalRead(manualPin);
  Serial.print(F("mode of sicca is: "));
  Serial.println(manual_val);
  //manual_val = 1;             //temporary adjustment
  if (manual_val == 1)
  {
    Serial.println(F("Pump is in Manual Mode"));
    lcd.setCursor(0, 3);
    lcd.print(F("PUMP STATUS: "));
    lcd.setCursor(13, 3);
    lcd.print(F("MANUAL"));
    pump[0] = 'M';
    pump[1] = 'A';
    pump[2] = 'N';
    pump[3] = 'U';
    pump[4] = 'A';
    pump[5] = 'L';
  }
  if (manual_val == 0  && timer_flag==0)
  {
    //Serial.println("Pump is in AUTO Mode");
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    Serial.print(F("wp is: "));
    Serial.println(wp);
    Serial.print(F("fc is: "));
    Serial.println(fc);
    if (soilMoist >= wp)
    {
      Serial.println(F("PUMP IS ON (A)"));
      Serial.print(F("wp is: "));
      Serial.println(soilMoist);
      lcd.setCursor(13, 3);
      lcd.print("ON(A)  ");
    }
    if (soilMoist <= fc)
    {
      Serial.println(F("PUMP IS OFF(A)"));
      Serial.print(F("fc is: "));
      Serial.println(soilMoist);
      lcd.setCursor(13, 3);
      lcd.print(F("OFF(A) "));
    }
    //    lcd.setCursor(13, 3);
    //    lcd.print("      ");
  }
  //  dataString += String(millis());
  //  dataString += " manual end";
  //  sd();
  //  dataString=" ";
}
