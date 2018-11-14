void f1()
{
  pinMode(3, OUTPUT);
  pinMode(11,OUTPUT);
  TCCR2A=0;//reset the register
  TCCR2B=0;//reset the register
  TCCR2A=0b01010011;// fast pwm mode
  TCCR2B=0b00001001;// no prescaler and WGM02 is 1
  OCR2A=50;//control value
}

