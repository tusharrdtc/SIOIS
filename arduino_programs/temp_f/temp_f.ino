void setup() 
{
  //Serial.begin(9600);
  f1();
}
 void loop()
{
 
}
 void f1()
{
  /*pinMode(5, OUTPUT);
  pinMode(6,OUTPUT);*/
  pinMode(3, OUTPUT);
  pinMode(11,OUTPUT);
  // pinMode(9, OUTPUT);
  //pinMode(11,OUTPUT);
  
        /*TCCR0A=0;//reset the register
        TCCR0B=0;//reset tthe register
        TCCR0A=0b01010011;// fast pwm mode
        TCCR0B=0b00001001;// no prescaler and WGM02 is 1
        OCR0A=50;//control value

        TCCR1A=0;//reset the register
        TCCR1B=0;//reset tthe register
        TCCR1A=0b01010001;// fast pwm mode
        TCCR1B=0b00001001;// no prescaler and WGM02 is 1
        OCR1A=50;//control value*/

         TCCR2A=0;//reset the register
         TCCR2B=0;//reset the register
         TCCR2A=0b01010011;// fast pwm mode
         TCCR2B=0b00001001;// no prescaler and WGM02 is 1
         OCR2A=50;//control value
        
    
}

