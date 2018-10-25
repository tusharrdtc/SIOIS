//Function to access menu
/*
 * Function Name: menu
 * Input: none
 * Output: Displays menu
 * Logic: Reads the input from user & displays the menu
 * Example Call: menu()
 */

void menu()
{
  int colm3 = digitalRead(setPin);  //Read user input
  delay(500);
  if(colm3 == LOW) 
  {
     int r = menuDisp();
  
  if (r == 1)
    {
    lcd.clear();
   
    //Read keypad function until back button is pressed
    while(j!= 1)
    {
      fieldCap();
      
    }
    valFc = fc/4;
    EEPROM.update(addFc,valFc); //Update EEPROM with new threshold
    while(k!= 1)
    {
      wiltPoint();
    }
    valWp = wp/4;
      EEPROM.update(addWp,valWp); //Update EEPROM with new threshold

    }
  }
}
