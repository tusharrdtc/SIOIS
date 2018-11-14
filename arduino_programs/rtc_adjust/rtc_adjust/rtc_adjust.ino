// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
int a;
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  while (!Serial); // for Leonardo/Micro/Zero

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
  rtc.adjust(DateTime(2018, 10, 24, 16, 20, 3));
}

void loop () {
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(),DEC);
    a=(now.hour());
    //a=Serial.read(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.println(now.second(), DEC);
    Serial.print("    ");
    f();
    Serial.println(a,DEC);
    Serial.println();
    delay(3000);
}
void f()
{
  if(12>a>15)
    {
      Serial.print("its afternoon");
    }
    
    else if(5>a>8)
    {
      Serial.print("its early morning");
    }
    else if(16>a>21)
    {
      Serial.print("its evening");
    }
    else if(21>a>24 && 1>a>5)
    {
      Serial.print("night");
    }
    else
    {
      Serial.print("its morning");
    }
}
