//Function for displaying GSM signal strength
/*
 * Function Name: gsmRssi()
 * Input: none
 * Output: none
 * Logic: Calculates signal strength & displays on the LCD
 * Example Call: gsmRssi()
 */

void gsmRssi()
{
//  dataString += String(millis());
//  dataString += " menu gsmRssi()";
//  sd();
//  dataString=" ";
  char sub[50];
  int position=16, length=2, c = 0;
  char temp[50];
  int i;
  Serial1.println("AT+CSQ");                //AT command to get rssi value varies from 0 to 30
  if(Serial1.available()>0)
  {
    for(i=0; i<30; i++)
    {
      temp[i]=Serial1.read();
      //Serial.print(temp);
    }
  }
  while (c < length) 
  {
      sub[c] = temp[position+c-1];         //logic to take substring from main string
      c++;
   }
   sub[c] = '\0';
//   Serial.print("Char value is ");
//   Serial.println(sub);
   int m;
   m=atoi(sub);                         //function to convert char to decimal
   if(m>=20 && m<30)
   {
    lcd.setCursor(1,0);
    lcd.print(" ");
    lcd.createChar(1, range1);
    lcd.setCursor(1,0);
    lcd.write(1);
    lcd.createChar(2, range2);
    lcd.setCursor(2,0);
    lcd.write(2);
    lcd.createChar(3, range3);
    lcd.setCursor(3,0);
    lcd.write(3);
    Serial.println(F("Excellent"));
   }
   else if(m>=15 && m<20)
   {
    lcd.setCursor(1,0);
    lcd.print(" ");
    lcd.createChar(1, range1);
    lcd.setCursor(1,0);
    lcd.write(1);
    lcd.createChar(2, range2);
    lcd.setCursor(2,0);
    lcd.write(2);
    lcd.setCursor(3,0);
    lcd.print(" ");
    Serial.println(F("Good"));
   }
   else if(m>=10 && m<15)
   {
    lcd.setCursor(1,0);
    lcd.print(" ");
    lcd.createChar(1, range1);
    lcd.setCursor(1,0);
    lcd.write(1);
    Serial.println(F("OK"));
    lcd.setCursor(2,0);
    lcd.print(" ");
    lcd.setCursor(3,0);
    lcd.print(" ");
   }
   else if(m>=9 && m<10)
   {
    lcd.setCursor(1,0);
    lcd.print(" ");
    lcd.setCursor(2,0);
    lcd.print(" ");
    lcd.setCursor(3,0);
    lcd.print(" ");
    Serial.println(F("Marginal"));
   }
   else
   {
    lcd.createChar(1,range_x);
    lcd.setCursor(1,0);
    lcd.write(1);
    lcd.setCursor(2,0);
    lcd.print(" ");
    lcd.setCursor(3,0);
    lcd.print(" ");
    Serial.println(F("no network"));
   }
//   dataString += String(millis());
//  dataString += " menu rssi_N end";
//  sd();
//  dataString=" ";
}
