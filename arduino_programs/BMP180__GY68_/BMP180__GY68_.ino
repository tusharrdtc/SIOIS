#include <Adafruit_BMP085.h>
#include <Wire.h>


char PRESSURESHOW[4];                          // initializing a character of size 4 for showing the  result
char TEMPARATURESHOW[4];                       // initializing a character of size 4 for showing the temparature result

Adafruit_BMP085 bmp;
void setup() 
      {
           Serial.begin(9600);
           if (!bmp.begin())
              {
                 Serial.println("ERROR");     //if there is an error in communication
                 while(1);
               }

}
void loop()
      {
         Serial.println("Pressure= ");          
         String PRESSUREVALUE = String(bmp.readPressure());
         // convert the reading to a char array
         PRESSUREVALUE.toCharArray(PRESSURESHOW, 4);
         Serial.print(PRESSURESHOW);
         Serial.println("hPa");
         Serial.print("Tempr. = ");
         String TEMPARATUREVALUE = String(bmp.readTemperature());
         // convert the reading to a char array
         TEMPARATUREVALUE.toCharArray(TEMPARATURESHOW, 4);
         Serial.println(TEMPARATURESHOW);
         Serial.print("c  ");
         delay(1000);

}
