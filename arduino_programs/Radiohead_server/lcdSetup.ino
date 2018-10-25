//Function to display characters & strings once
/*
 * Function Name: lcdSetup
 * Input: none
 * Output: Prints on LCD
 * Logic: 
 * Example Call: lcdSetup()
 */
void lcdSetup()
{
  lcd.begin();
  lcd.backlight();  //Turn on backlight
  
  //Create battery symbol
  lcd.createChar(4, extra4);
  lcd.createChar(5, extra5);
  
  //lcd.home();
  lcd.setCursor(4, 1);  //Set the cursor on 4th Col & 1st Row
  lcd.print("SENSE IT OUT");
  Serial.println("SENSE IT OUT");
  delay(2000);
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("SICCA");
  Serial.println("SICCA");
  delay(2000);
  lcd.clear();
}
