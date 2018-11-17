//Function to display battery status
/*
 * Function Name: newNumber
 * Input: gsmString
 * Output: New number
 * Logic: finds the appropraite kyeword in the string
 * Example Call: newNumber()
 */

void newNumber()
{
  if (check_newnumber_flag == 1)
  {
    const char needle[10] = "READ";
    ret = strstr(NUMBER_string, needle);
    Serial.print(F("ret is "));
    Serial.println(ret);
    char sub[200];

    int position = 11, length = 13, c = 0;
    while (c < length)
    {
      sub[c] = ret[position + c - 1];
      c++;
    }
    sub[c] = '\0';
    Serial.print(F("Number is: "));
    Serial.println(sub);
    Serial.println(F("my new number is: "));
    for (int i = 0; i < 10; i++)
    {
      mynumber[i] = sub[i];
      Serial.print(mynumber[i]);
    }
    Serial.println(F(" "));
        Serial.println(F("We will sent you msg shortly"));
        Serial1.print("AT+CMGS=\"");
        Serial1.print(mynumber);
        Serial1.println("\"");  //Send SMS message
        readStrings(1000);
        Serial1.println("YOUR NUMBER HAS BEEN CHANGED!");
        readStrings(1000);
        Serial1.write(26);
    check_newnumber_flag = 0;
  }
}
