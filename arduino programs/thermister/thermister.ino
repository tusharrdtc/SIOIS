const int    SAMPLE_NUMBER      = 10;
const double BALANCE_RESISTOR   = 10000.0;
const double MAX_ADC            = 1023.0;
const double BETA               = 3974.0;
const double ROOM_TEMP          = 298.15;   // room temperature in Kelvin
const double RESISTOR_ROOM_TEMP = 10000.0;
double currentTemperature = 0;
int thermistorPin = 0;  // Where the ADC samples the resistor divider's output
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
  double adcAverage  = 0;            // Holds the average voltage measurement
  int a;
  int    adcSamples[SAMPLE_NUMBER];  // Array to hold each voltage measurement
  a=analogRead(thermistorPin);
  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcSamples[i] = analogRead(thermistorPin);  // read from pin and store
    delay(10);        // wait 10 milliseconds
  }

  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcAverage += adcSamples[i];      // add all samples up . . .
  }
  adcAverage /= SAMPLE_NUMBER;        // . . . average it w/ divide

  rThermistor = BALANCE_RESISTOR * ( (MAX_ADC / a) - 1);
  tKelvin = (BETA * ROOM_TEMP) / 
            (BETA + (ROOM_TEMP * log(rThermistor / RESISTOR_ROOM_TEMP)));

  tCelsius = tKelvin - 273.15;  // convert kelvin to celsius 

  return tCelsius;    // Return the temperature in Celsius
}

