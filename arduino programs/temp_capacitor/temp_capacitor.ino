void setup() {
  Serial.begin(9600);
  f1();
}

void loop() {
  double v1;
  double v2;
  double v3;
  double s1;
  double s2;
  double s3;
  int i, j, k;
  double sm1;
  double sm2;
  double sm3;
  i = analogRead(A0);
  j = analogRead(A1);
  //k = analogRead(A2);
  v1 = (0.0049)*i;
  v2 = (0.0049)*j;
  //v3 = (0.0049)*k;
  sm1 = (0.09765)*i;
  sm2 = (0.09765)*j;
  //sm3 = (0.09765)*k;
  Serial.print("voltage1=");
  Serial.print(v1);
  Serial.print("  ");
  Serial.print("sm1=");
  Serial.print(sm1);
  Serial.print("%");
  Serial.println("     ");
  //Serial.println(i);
  delay(2000);
  /*Serial.print("voltage 2=");
  Serial.print(v2);
  Serial.print("  ");
  Serial.print("sm2=");
  Serial.print(sm2);
  Serial.print("%");
  Serial.println("     ");
  //Serial.println(j);
  delay(2000);
  Serial.print("voltage 3=");
  Serial.print(v3);
  Serial.print("  ");
  Serial.print("sm3=");
  Serial.print(sm3);
  Serial.print("%");
  Serial.println("     ");
  //Serial.println(k);
  delay(1000);*/

}
void f1()
{
  pinMode(5, OUTPUT);
  pinMode(6,OUTPUT);
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
