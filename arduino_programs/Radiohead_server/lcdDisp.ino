//Function to display Constant charaacters on LCD
/*
 * Function Name: lcdDisp
 * Input: none
 * Output: Prints characters on LCD
 * Logic: 
 * Example Call: lcdDisp()
 */

void lcdDisp()
{
  lcd.setCursor(0,0);
  lcd.print("E");
  lcd.setCursor(0, 1);
  lcd.print("SM");
  lcd.setCursor(10, 1);
  lcd.print("TEMP");
  lcd.setCursor(10, 2);
  lcd.print("HUM");
  lcd.setCursor(0, 2);
  lcd.print("ST");
}
