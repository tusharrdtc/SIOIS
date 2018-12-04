//Function to switch to timer mode
/*
 * Function Name: timer_mode
 * Input: none
 * Output: ONs motor for specified time
 * Logic: Receives time input & turns ON the pump for that period of time 
 * Example Call: timer_mode()
 */

void  timerMode()
{

  int current_hour = 0, farmer_hour;
  int current_min = 0, farmer_min;
  int current_sec = 0, farmer_sec;
  int flag_value = 0;
  if (check_timer_flag == 1)
  {
    const char needle[10] = "TIMER";
    ret = strstr(TIMER_string, needle);
    Serial.print("ret is ");
    Serial.println(ret);
    char sub1[10], sub2[10], sub3[10];
    DateTime now = rtc.now();
    current_hour = now.hour();
    current_min = now.minute();
    current_sec = now.second();

    //////////for hour///////
    if (flag_value == 0)
    {
      int position = 6, length = 2, c = 0;
      while (c < length)
      {
        sub1[c] = ret[position + c - 1];
        c++;
      }
      sub1[c] = '\0';
      Serial.print("sub1 is: ");
      Serial.println(sub1);
      farmer_hour = atoi(sub1);
      if ((current_hour + farmer_hour <= 23) && farmer_hour != 0)
      {
        farmer_hour = current_hour + farmer_hour;
      }

      else if ((current_hour + farmer_hour) > 23)
      {
        farmer_hour = current_hour + farmer_hour;
        farmer_hour = farmer_hour - 24;
      }
      else {
        farmer_hour = current_hour;
      }
      flag_value = flag_value + 1;
    }

    /////farmer minutes/////
    if (flag_value == 1)
    {
      int position = 9; int length = 2; int c = 0;
      while (c < length)
      {
        sub2[c] = ret[position + c - 1];
        c++;
      }
      sub2[c] = '\0';
      Serial.print("sub2 is: ");
      Serial.println(sub2);
      farmer_min = atoi(sub2);
      if ((current_min + farmer_min <= 59) && farmer_min != 0)
      {
        farmer_min = current_min + farmer_min;
      }
      else if ((current_min + farmer_min) > 59)
      {
        farmer_min = current_min + farmer_min;
        farmer_min = farmer_min - 60;
        farmer_hour = farmer_hour + 1;
      }
      else {
        farmer_min = current_min;
      }
      flag_value = flag_value + 1;
    }

    /////farmer seconds/////
    if (flag_value == 2)
    {
      int position = 12; int length = 2; int c = 0;
      while (c < length)
      {
        sub3[c] = ret[position + c - 1];
        c++;
      }
      sub3[c] = '\0';
      Serial.print("sub3 is: ");
      Serial.println(sub3);
      farmer_sec = atoi(sub3);
      if ((current_sec + farmer_sec <= 59) && farmer_sec != 0)
      {
        farmer_sec = current_sec + farmer_sec;
      }
      else if ((current_sec + farmer_sec) > 59)
      {
        farmer_sec = current_sec + farmer_sec;
        farmer_sec = farmer_sec - 60;
        farmer_sec = farmer_sec + 1;
      }
      else    {
        farmer_sec = current_sec;
      }
      flag_value == 0;
    }
    if (manual_val == 0)
    {
      Serial.print("Your pump will TURN OFF on: ");
      Serial.print(farmer_hour);
      Serial.print(":");
      Serial.print(farmer_min);
      Serial.print(":");
      Serial.print(farmer_sec);
      Serial.println("hrs");
      digitalWrite(relayPin1, LOW);
      pumpStat = 1;
      pump[0] = 'T';
      pump[1] = 'I';
      pump[2] = 'M';
      pump[3] = 'E';
      pump[4] = 'R';
      pump[5] = ' ';
    }
    if (manual_val == 1)
    {
      Serial.println("YOUR PUMP IS ON MANUAL MODE. PUMP CAN NOT START");
      //Serial1.print("AT+CMGS=\"7066485916\"\r\n");  //Send SMS message
      Serial1.print("AT+CMGS=\"");
      Serial1.print(mynumber);
      Serial1.println("\"");  //Send SMS message
      Serial1.print("PUMP IS IN MANUAL MODE! CHANGE IT FIRST.");
      Serial1.write(26);
    }

  }
  check_timer_flag = 0;
  DateTime now = rtc.now();
  Serial.print("Current time is: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());
  if ((now.hour() == farmer_hour) && (now.minute() == farmer_min) && (now.second() >= farmer_sec))
  {
    Serial.println("TIME FINISHED!");
    digitalWrite(relayPin1, HIGH);
    timer_flag = 0;
  }

}
