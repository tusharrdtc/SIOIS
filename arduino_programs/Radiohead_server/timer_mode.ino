//
//void timer_mode()
//{
//  //  Serial1.println("AT");
//  //  readStrings(1000);
//  Serial1.println("AT+QLTS");
//  readStrings(1000);
//  if (strstr(GSM_string, "+QLTS:"))
//  {
//    const char needle[10] = "+QLTS:";
//    ret = strstr(GSM_string, needle);
//    Serial.println("array is");
//    Serial.println(ret);
//    Serial.println("length of the array is:");
//    Serial.println(strlen(ret));
//    char sub1[10], sub2[10], sub3[10];
//
//    int position = 18, length = 2, c = 0;
//    while (c < length)
//    {
//      sub1[c] = ret[position + c - 1];
//      c++;
//    }
//    sub1[c] = '\0';
////    Serial.println("Hour ");
////    Serial.println(sub1);
//    hour_time = atoi(sub1);
////    Serial.println("hour in integer format: ");
////    Serial.println(m1);
//
//    position = 21, length = 2, c = 0;
//    while (c < length)
//    {
//      sub2[c] = ret[position + c - 1];
//      c++;
//    }
//    sub2[c] = '\0';
////    Serial.println("Minute ");
////    Serial.println(sub2);
//    
//    minute_time = atoi(sub2);
////    Serial.println("minutes in integer ");
////    Serial.println(m2);
//
//    position = 24, length = 2, c = 0;
//    while (c < length)
//    {
//      sub3[c] = ret[position + c - 1];
//      c++;
//    }
//    sub3[c] = '\0';
////    Serial.println("Seconds ");
////    Serial.println(sub3);
//   
//    seconds_time = atoi(sub3);
////    Serial.println("seconds in integer");
////    Serial.println(m3);
//  }
//}
