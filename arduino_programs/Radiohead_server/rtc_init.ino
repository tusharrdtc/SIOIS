//Function for storing & displaying time using RTC
/*
 * Function Name: rtc
 * Input: none
 * Output: none
 * Logic: Once set, the function uses an rtc module to store & display time 
 * Example Call: process()
 */

void rtc_init()
{
  DateTime now = rtc.now();
  rtcHour = now.hour();
  rtcMin = now.minute();
}

void rtcDisp()
{
  rtc_init();
  if (rtcHour < 10)
  {
    lcd.setCursor(15, 0);
    lcd.print("0");
    lcd.setCursor(16, 0);
    lcd.print(rtcHour, DEC);
  }
  else if(rtcHour == 165)
  {
    lcd.setCursor(15, 0);
    lcd.print("--");
  }
  else
  {
    lcd.setCursor(15, 0);
    lcd.print(rtcHour, DEC);
  }
  lcd.setCursor(17, 0);
  lcd.print(":");
  if (rtcMin < 10)
  {
    lcd.setCursor(18, 0);
    lcd.print("0");
    lcd.setCursor(19, 0);
    lcd.print(rtcMin, DEC);
  }
    else if(rtcMin == 165)
  {
    lcd.setCursor(18, 0);
    lcd.print("--");
  }
  else
  {
    lcd.setCursor(18, 0);
    lcd.print(rtcMin, DEC);
  }
  
}
