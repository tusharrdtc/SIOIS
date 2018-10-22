const double BALANCE_RESISTOR   = 10000.0;
const double BETA               = 3974.0;
const double ROOM_TEMP          = 298.15;   // room temperature in Kelvin
const double RESISTOR_ROOM_TEMP = 10000.0;
double currentTemperature = 0;
void setup() 
{ 
  Serial.begin(9600);
}
void loop() 
{
  currentTemperature = readThermistor();
  delay(3000);
  
    Serial.println(currentTemperature);
    
}

double readThermistor() 
{
  // variables that live in this function
  double rThermistor = 0;            // Holds thermistor resistance value
  double tKelvin     = 0;            // Holds calculated temperature
  double tCelsius    = 0;            // Hold temperature in celsius
  double a;
  a=analogRead(A0);
  rThermistor = BALANCE_RESISTOR * ( (1023 / a) - 1);
  tKelvin = (BETA * ROOM_TEMP) / 
            (BETA + (ROOM_TEMP * log(rThermistor / RESISTOR_ROOM_TEMP)));

  tCelsius = tKelvin - 273.15;  // convert kelvin to celsius 

  return tCelsius;    // Return the temperature in Celsius
}

