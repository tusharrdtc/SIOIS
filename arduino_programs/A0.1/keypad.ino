//void h()
//{
//
//  int colm1 = digitalRead(9);
//  int colm2 = digitalRead(10);
//  int colm3 = digitalRead(11);
//  int colm4 = digitalRead(12);
//  if (colm1 == LOW || colm2 == LOW || colm3 == LOW || colm4 == LOW)
//  {
//    if (colm1 == LOW || colm2 == LOW || colm3 == LOW)
//    {
//      lcd.clear();
//      lcd.setCursor(1, 1);
//      lcd.print("Set Hours:");
//      Serial.println("set hours");
//      if (colm1 == LOW)
//      {
//        hours = hours - 1;
//        if(hours <= 0)
//        hours = 0;
//        val=(float)hours/2.0;
//        if(val%2 == 0)
//        lcd.setCursor(15, 1);
//        lcd.print(val);
//        Serial.println(val);
//        delay(500);
//
//      }
//      if (colm2 == LOW)
//      {
//        hours = hours + 1;
//        if(hours>=24)
//        hours = 24;
//        val = (float)hours/2.0;
//        lcd.setCursor(15, 1);
//        lcd.print(val);
//        Serial.println(val);
//        delay(500);
//      }
//
//    }
//    if (colm4 == LOW)
//    {
//      Serial.println("back");
//      digitalWrite(13, HIGH);
//      timerHour.setTimeout(hours*30*60 * 1000); // 4 hours in ms
//      timerHour.restart();
//      j = 60;
//      delay(500);
//    }
//
//  }
//}
