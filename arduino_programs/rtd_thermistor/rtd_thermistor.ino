const double BALANCE_RESISTOR   = 10000.0;
const double BETA               = 3974.0;
const double ROOM_TEMP          = 298.15;   // room temperature in Kelvin
const double RESISTOR_ROOM_TEMP = 10000.0;
double currentTemperature = 0;
void setup() 
{ 
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12, HIGH);
  
  
}
void loop() 
{
    //f1();
    //delay(1000);
    //readThermistor();
    //delay(1000);
    rtd();
    delay(1000);
    
}

double readThermistor() 
{
  double rThermistor = 0;            // Holds thermistor resistance value
  double tKelvin     = 0;            // Holds calculated temperature
  double tCelsius    = 0;            // Hold temperature in celsius
  double a;
  a=analogRead(1);
  rThermistor = BALANCE_RESISTOR * ( (1023 / a) - 1);
  tKelvin = (BETA * ROOM_TEMP) / 
            (BETA + (ROOM_TEMP * log(rThermistor / RESISTOR_ROOM_TEMP)));

  tCelsius = tKelvin - 273.15;      // convert kelvin to celsius 
  Serial.print(tCelsius);
  Serial.print("     ");
  }
int rtd(){
  double r2=91.2;
  double b;                           //analog output
  double r;                           //rtd resistance at t degree celsius
  double r0 = 107.79;                 //resistance of PT100 at 274 degree kelvin 
  double t0 = 20;                     // 0 degree celsius
  float alpha = 0.00375;              //temp coefficient at 0 degree celsius of PT100
  double t;                           //current temperature
  b=analogRead(0);
  r = r2 * ( b / (1024 - b));
  t = ((r-r0)/(r0*alpha )) + t0 ;
  Serial.println(t);
  Serial.println("");
  delay(1000);
}
void f1()
{
  
  /*TCCR0A=0;              //reset the register
  TCCR0B=0;              //reset tthe register
  TCCR0A=0b01010011;     // fast pwm mode
  TCCR0B=0b00001001;     // no prescaler and WGM02 is 1
  OCR0A=50;              //control value*/
  TCCR2A=0;              //reset the register
  TCCR2B=0;              //reset the register
  TCCR2A=0b01010011;     // fast pwm mode
  TCCR2B=0b00001001;     // no prescaler and WGM02 is 1
  OCR2A=50;              //control value
}


