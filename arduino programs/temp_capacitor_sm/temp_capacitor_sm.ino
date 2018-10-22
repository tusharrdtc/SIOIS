void setup() {
  Serial.begin(9600);
  f1();
}

void loop() {
  double v1;
  double v2;
  double s1;
  double s2;
  int i, j;
  double sm1;
  double sm2;
  i = analogRead(A0);
  j = analogRead(A1);
  /*sm1 = i/12.78;
  sm2 = j/12.78;*/
  Serial.print(i);
  /*Serial.print("sm1=");
  Serial.print(sm1);
  Serial.print("%");*/
  Serial.print("     ");
  delay(1000);
  //Serial.print(j);
  /*Serial.print("sm2=");
  Serial.print(sm2);
  Serial.print("%");*/
  Serial.println("     ");
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
  OCR2A=50;                     //control value
}
