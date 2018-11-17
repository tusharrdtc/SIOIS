//Function for storing & displaying time using RTC
/*
   Function Name: rtc
   Input: none
   Output: none
   Logic: Once set, the function uses an rtc module to store & display time
   Example Call: process()
*/

void rtc_init()
{
//  dataString += String(millis());
//  dataString += " rtc_init starts";
//  sd();
//  dataString = " ";
  if (! rtc.begin())
  {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println(F("RTC is NOT running!"));
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:

  }
  //rtc.adjust(DateTime(2018, 10, 31, 15, 24, 3));

  DateTime now = rtc.now();
  rtcHour = now.hour();
  rtcMin = now.minute();
  //  Serial.print("time is: ");
  //  Serial.println(rtcHour);
//  dataString += String(millis());
//  dataString += " rtc_init end";
//  sd();
//  dataString = " ";
}

void rtcDisp()
{
  rtc_init();
//  dataString += String(millis());
//  dataString += " rtcDisp starts";
//  sd();
//  dataString=" ";
  if (rtcHour < 10)
  {
    lcd.setCursor(15, 0);
    lcd.print("0");
    lcd.setCursor(16, 0);
    lcd.print(rtcHour, DEC);
  }
  else if (rtcHour == 165)
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
  else if (rtcMin == 165)
  {
    lcd.setCursor(18, 0);
    lcd.print("--");
  }
  else
  {
    lcd.setCursor(18, 0);
    lcd.print(rtcMin, DEC);
  }
//  dataString += String(millis());
//  dataString += " rtcDisp end";
//  sd();
//  dataString=" ";
}
