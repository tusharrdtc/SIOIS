#include <Wire.h>
#include "RTClib.h"
int a;
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void rtc1() {
  while (!Serial); 

  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
     
  }
  //rtc.adjust(DateTime(2018, 7, 4, 19, 48, 33));
}
void rtc2 () {
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    //Serial.print(" (");
    Serial.print("        ");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    //Serial.print(") ");
    Serial.print("       ");
    Serial.print(now.hour(),DEC);
    a=(now.hour());
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print("       ");
    if(a>=12 && a<16)
              {
                Serial.print("Afternoon");
              }
    else if(a>=5 && a<8)
              {
                Serial.print("Early morning");
              }
     else if(a>=16 && a<21)
              {
               Serial.print("Evening");
              }
     else if(a>=21 && a<24 || (a>=0 && a<5))
              {
               Serial.print("Night");
              }
      else /*(8>=a && a>12)*/
              {
               Serial.print("Morning");
              }
              Serial.print("     ");
}

