//Function to display battery status
/*
 * Function Name: battery
 * Input: none
 * Output: Battery percentage
 * Logic: Comapres battery voltage & prints the result
 * Example Call: battery()
 */
void battery()
{
  if (battVolt < 4.8 && battVolt >= 4.1)
  {
    lcd.createChar(7, battery_100);
    Serial.println("battery=100%");
    lcd.setCursor(6, 0);
    lcd.print(" ");
    lcd.setCursor(7, 0);
    lcd.write(7);

  }
  else if (battVolt < 4.2 && battVolt >= 4.0)
  {
    lcd.createChar(7, battery_75);
    lcd.setCursor(6, 0);
    lcd.print(" ");
    Serial.println("battery=75%");
    lcd.setCursor(7, 0);
    lcd.write(7);
   
  }
  else if (battVolt < 4.0 && battVolt >= 3.8)
  {
    lcd.createChar(7, battery_50);
    lcd.setCursor(6, 0);
    lcd.print(" ");
    Serial.println("battery=50%");
    lcd.setCursor(7, 0);
    lcd.write(7);
  }
  else if (battVolt < 3.8 && battVolt >= 3.5)
  {
    lcd.createChar(7, battery_25);
    lcd.setCursor(6, 0);
    lcd.print(" ");
    Serial.println("battery=25%");
    lcd.setCursor(7, 0);
    lcd.write(7);

  }
  else if (battVolt < 3.5 && battVolt > 3.2)
  {
    lcd.createChar(7, battery_0);
    lcd.setCursor(6, 0);
    lcd.print(" ");
    Serial.println("battery=0%");
    lcd.setCursor(7, 0);
    lcd.write(7);
  }
  else if (battVolt <= 3.2)
  {
    lcd.createChar(7, battery_x);
    lcd.setCursor(6, 0);
    lcd.print(" ");
    Serial.println("Battery is discharged");
    lcd.setCursor(7, 0);
    lcd.write(7);
  }
}
    
