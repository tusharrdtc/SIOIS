int menuDisp() {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("FC IS: ");
      lcd.setCursor(10,0);
      lcd.print(fc);
      lcd.setCursor(1, 2);
      lcd.print("WP IS:");
      lcd.setCursor(10,2);
      lcd.print(wp);
      for(int i=0;i<6;i++)  
      {
       
       int colm3 = digitalRead(setPin);
       delay(1000);
       if(colm3==LOW)
       {
        return 1;
       }
       
      }
      lcd.clear();
   return 0;

}

void fieldCap()  {
  
  int colm1 = digitalRead(upPin);
  int colm2 = digitalRead(downPin);
  int colm3 = digitalRead(setPin);
  int colm4 = digitalRead(backPin);
  delay(500);
      //lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("FC IS:");
      lcd.setCursor(1,2);
      lcd.print(fc);

      //To increase threshold value
      if (colm1 == LOW)
      {
        
        fc = fc - 10;
        if(fc < 100)
        {fc = 100;}
        lcd.setCursor(1, 2);
        lcd.print(fc);
        Serial.println(fc);
        
       
      }

      //To decrease threshold value
      if (colm2 == LOW)
      {
        
        fc = fc + 10;
        if(fc>999)
        {fc = 999;}
        lcd.setCursor(1, 2);
        lcd.print(fc);
        Serial.println(fc);
    
      }

    //To set the threshold & update the EEPROM
    if (colm3 == LOW)
    {
      lcd.setCursor(0, 1);
      lcd.print("FC VALUE SET");
      delay(1000);
      Serial.println("back");
      lcd.clear();
      j = 1;
      
     }

    if(colm4 == LOW) {
    lcd.clear();
    j=1;
    k=1;
    
   }
    
  }

void wiltPoint()  {

  
  int colm1 = digitalRead(upPin);
  int colm2 = digitalRead(downPin);
  int colm3 = digitalRead(setPin);
  int colm4 = digitalRead(backPin);
  delay(500);
      //lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("WP IS:");
      lcd.setCursor(1,2);
      lcd.print(wp);

      //To increase threshold value
      if (colm1 == LOW)
      {
        wp = wp - 10;
        if(wp < 100)
        {wp = 100;}
        Serial.println(wp);
        lcd.setCursor(1, 2);
        lcd.print(wp);
        Serial.println(wp);
       
      }

      //To decrease threshold value
      if (colm2 == LOW)
      {
        wp = wp + 10;
        if(wp > 999)
        {wp = 999;}
        lcd.setCursor(1, 2);
        lcd.print(wp);
        Serial.println(wp);
        
      }

    //To set the threshold & update the EEPROM
    if (colm3 == LOW)
    {
      lcd.setCursor(0, 1);
      lcd.print("WP VALUE SET");
      delay(1000);
      Serial.println("back");
      lcd.clear();
      k = 1;
      
     }
     if(colm4 == LOW) {
    lcd.clear();
    k=1;
    
   }
  }
