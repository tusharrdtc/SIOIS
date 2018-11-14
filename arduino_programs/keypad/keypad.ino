void keypad(){
  int c1, c2, c3, c4;
  pinMode(6,OUTPUT);
  pinMode(7, INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(6,LOW);
  c1=digitalRead(7);
  c2=digitalRead(8);
  c3=digitalRead(9);
  c4=digitalRead(10);
  if(c1==LOW || c2==LOW || c3==LOW || c4==LOW)
  {
    
    if(c1==LOW)
    { 
       lcd.clear();
       lcd.print("pressed key is: ");
       lcd.setCursor(0, 1);
       lcd.print("2");
       delay(2000);
    }
    if(c2==LOW)
    {
      lcd.clear();
      lcd.print("pressed key is: ");
      lcd.setCursor(0, 1);
      lcd.print("1"); 
      delay(2000); 
    }
    if(c3==LOW)
    {
       lcd.clear();
       lcd.print("pressed key is: ");
       lcd.setCursor(0, 1);
       lcd.print("4");
       delay(2000);
    }
    if(c4==LOW)
    {
      lcd.clear();
      lcd.print("pressed key is: ");
      lcd.setCursor(0, 1);
      lcd.println("3");
      delay(2000);
    }
  }
}

