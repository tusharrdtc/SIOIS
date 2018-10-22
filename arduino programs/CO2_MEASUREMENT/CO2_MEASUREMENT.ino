#define RLOAD 22.0
// Calibration resistance at atmospheric CO2 level
#define RZERO 30.94 
#include "MQ135.h" 
MQ135 gasSensor = MQ135(A0); 
int val; 
int sensorPin = A0; 
int sensorValue = 0;
int k=1,t=0;
void setup() {
  
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); 
  Serial.print("reading no.");
  Serial.print("   ppm");
  Serial.println("        time");
  
} 
 
void loop() { 
  val = analogRead(A0); 
  Serial.print ("raw = "); 
  Serial.println (val); 
  float zero = gasSensor.getRZero(); 
  Serial.print ("rzero: "); 
  Serial.println (zero); 
  float ppm = gasSensor.getPPM();
  
  //Serial.print(k);
  k=k+1;
  Serial.print ("ppm: "); 
  //Serial.print("          ");
  Serial.println(ppm);
  //Serial.print("      ");
  //Serial.println(t);
  t=t+1;
  //for(int i=1;i<2;i++)
  {
    //for(int j=0;j<60;j++)
    {
      
  delay(1000);
    }
  }
  
} 
