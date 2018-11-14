const int    SAMPLE_NUMBER      = 100;
void setup() 
{ 
  Serial.begin(9600);
}
void loop() 
{
  readThermistor();
  Serial.print("   ");
  delay(1000);
  readThermistor1();
  Serial.print("   ");
  delay(1000);
  readThermistor2();
  Serial.println("   ");
  delay(1000);
  f1();
}

double readThermistor() 
{
  // variables that live in this function
  double adcAverage  = 0;            // Holds the average voltage measurement
  int    adcSamples[SAMPLE_NUMBER];  // Array to hold each voltage measurement
  double v;
  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcSamples[i] = analogRead(A0);  // read from pin and store
    delay(10);        // wait 10 milliseconds
  }

  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcAverage += adcSamples[i];      // add all samples up . . .
  }
  adcAverage /= SAMPLE_NUMBER;        // . . . average it w/ divide
  Serial.print("A1 is = ");
  Serial.print(adcAverage);
  v = (adcAverage/1024)*5;
  Serial.print("    ");
  Serial.print("v @ ckt = ");
  Serial.print(v);
  delay(1000);
}
double readThermistor1() 
{
  // variables that live in this function
  double adcAverage  = 0;            // Holds the average voltage measurement
  int    adcSamples[SAMPLE_NUMBER];  // Array to hold each voltage measurement
  double v;
  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcSamples[i] = analogRead(A1);  // read from pin and store
    delay(10);        // wait 10 milliseconds
  }

  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcAverage += adcSamples[i];      // add all samples up . . .
  }
  adcAverage /= SAMPLE_NUMBER;        // . . . average it w/ divide
  Serial.print("A2 is = ");
  Serial.print(adcAverage);
  v = (adcAverage/1024)*5;
  Serial.print("    ");
  Serial.print("v @ resistive is = ");
  Serial.print(v);
  delay(1000);

  
}
double readThermistor2() 
{
  // variables that live in this function
  double adcAverage  = 0;            // Holds the average voltage measurement
  int    adcSamples[SAMPLE_NUMBER];  // Array to hold each voltage measurement
  double v;
  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcSamples[i] = analogRead(A2);  // read from pin and store
    delay(10);        // wait 10 milliseconds
  }

  for (int i = 0; i < SAMPLE_NUMBER; i++) 
  {
    adcAverage += adcSamples[i];      // add all samples up . . .
  }
  adcAverage /= SAMPLE_NUMBER;        // . . . average it w/ divide
  Serial.print("A3 is = ");
  Serial.print(adcAverage);
  v = (adcAverage/1024)*5;
  Serial.print("    ");
  Serial.print("v @ w/o ckt = ");
  Serial.print(v);
  delay(1000);

  
}
void f1()
{
  pinMode(5, OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(11,OUTPUT);

  TCCR2A=0;                     //reset the register
  TCCR2B=0;                     //reset the register
  TCCR2A=0b01010011;            // fast pwm mode
  TCCR2B=0b00001001;            // no prescaler and WGM02 is 1
  OCR2A=15;                     //control value
}

