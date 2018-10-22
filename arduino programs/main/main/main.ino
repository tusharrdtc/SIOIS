#include "DHT.h"
#define RLOAD 1.0
// Calibration resistance at atmospheric CO2 level
#define RZERO 55.73 
//#define RZERO1 44.43
#include "MQ135.h" 
   int sensorPin = A0;
   int sensorPin1 = A1;
   int val; 
   int val1; 
MQ135 gasSensor = MQ135(A0);
MQ135 gasSensor1 = MQ135(A1); 
#define DHTPIN 2
#define DHTPINA 3     
#define DHTTYPE DHT22  // DHT 22  (AM2302), AM2321
#define DHTTYPE1 DHT11  // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
DHT dht1(DHTPINA , DHTTYPE1);

void setup()
{
 
   Serial.begin(9600);
  //Serial.println("DHTxx test!");

  dht.begin();
  rtc1();
  Serial.print("Humidity(%) out ");
  Serial.print("    ");
  Serial.print("Temp out(*c)");
  Serial.print("     ");
  Serial.print("Humidity(%) in ");
  Serial.print("    ");
  Serial.print("Temp(*c) in");
  Serial.print("           ");
  Serial.print("Date");
  Serial.print("            ");
  Serial.print("Day");
  Serial.print("              ");
  Serial.print("Time");
  Serial.print("        ");
  Serial.print("Daytime");
  co1();
}
void loop()
{
  temp();
  rtc2();
  co2();
  for(int i=0; i<5;i++)
  {
    for(int j=0;j<60;j++)
    {
    delay(1000);
    }
  }
}

