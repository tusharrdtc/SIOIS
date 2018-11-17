void m()
{
  //Serial.println("inside the m");
  int colm1 = digitalRead(9);
  int colm2 = digitalRead(10);
  int colm3 = digitalRead(11);
  int colm4 = digitalRead(12);
  if (colm1 == LOW || colm2 == LOW || colm3 == LOW || colm4 == LOW)
  {
    if (colm1 == LOW || colm2 == LOW || colm3 == LOW)
    {
      lcd.clear();
      lcd.setCursor(-4, 1);
      lcd.print("Hours: ");
      lcd.setCursor(8, 1);
      lcd.print("Min: ");
      Serial.println("set minutes");
      if (colm1 == LOW)
      {
        minutes = minutes - 30;
        
        if (minutes < 0)
          minutes = 0;
          Serial.println(minutes);
        val = minutes / 2;
        if (val < 0)  {
          val = 0;
          lcd.setCursor(6, 1);
          lcd.print(hours);
          lcd.setCursor(12, 1);
          lcd.print("00");
        }
        
        if (val % 2 == 0) {
          Serial.print("val = ");
          Serial.println(val);
          hours = hours - 1;
          if (hours < 0 || hours > 12)
            hours = 0;
          lcd.setCursor(6, 1);
          lcd.print(hours);
          lcd.setCursor(12, 1);
          lcd.print("30");
        }

        else  {
          lcd.setCursor(6, 1);
          lcd.print(hours);
          lcd.setCursor(12, 1);
          lcd.print("00");

        }
        
        delay(500);

      }
      if (colm2 == LOW)
      {
        minutes = minutes + 30;
        if (minutes >= 720)
          minutes = 720;
        val = minutes / 2;
        if (val % 2 == 0) {
          hours = hours + 1;
          if (hours > 12)
            hours = 12;
          lcd.setCursor(6, 1);
          lcd.print(hours);
          lcd.setCursor(12, 1);
          lcd.print("00");
        }
        else  {
          lcd.setCursor(6, 1);
          lcd.print(hours);
          lcd.setCursor(12, 1);
          lcd.print("30");
        }

        Serial.println(minutes);
        delay(500);
      }

    }
    if (colm4 == LOW)
    {

      lcd.clear();
      lcd.setCursor(1, 2);
      lcd.print("Timer Set");
      Serial.println("back");
      timerMin.setTimeout(minutes * 60 * 1000); // 4 hours in ms
      timerMin.restart();
      digitalWrite(13, HIGH);
      k = 60;
    }

  }
}
