void manual_mode()
{
  manual_val=digitalRead(manualPin); 
  if(manual_val==0)
  {
    Serial.println("Pump is in Manual Mode");
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("MANUAL");
    pump[0]='M';
    pump[1]='A';
    pump[2]='N';
    pump[3]='U';
    pump[4]='A';
    pump[5]='L';
  }
  if(manual_val==1)
  {
    Serial.println("Pump is in AUTO Mode");
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("AUTO  ");
  }
}
