#include <RTClib.h>

#define BUFFER_SIZE 250

RTC_DS1307 rtc;

char  GSM_string[250];
char  TIMER_string[250] = "JUST CHECKING";
int main_flag = 0;
char *ret;
bool check_reginumber_flag = 0;
char mynumber1[12] = "+918600502595";
char mynumber[12];

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.println("AT+CMGF=1");
  readStrings(1000);
}

void loop()
{
  Serial1.println("AT+CMGR=6");
  readStrings(1000);
  register_number();
  delay(1000);
  Serial1.println("AT+CMGD=1,3");
  readStrings(1000);
}

void  register_number()
{
  int flag_value = 0;
  if (check_reginumber_flag == 1)
  {
    const char needle[10] = "READ";
    ret = strstr(GSM_string, needle);
    Serial.print("ret is ");
    Serial.println(ret);
    char sub[200];

    int position = 8, length = 12, c = 0;
    while (c < length)
    {
      sub[c] = ret[position + c - 1];
      c++;
    }
    sub[c] = '\0';
    Serial.print("Number is: ");
    Serial.println(sub);
    Serial.println("my new number is: ");
    for(int i=0;i<12;i++)
    {
      mynumber[i]=sub[i];
      Serial.print(mynumber[i]);
    }
    Serial.println(" ");
//    int  new_number = atoi(sub);
//    mynumber = new_number;
//    Serial.print("my number is: ");
//    Serial.println(mynumber);
    Serial.println("We will sent you msg shortly");
    Serial1.print("AT+CMGS=\"");
    Serial1.print(mynumber1);
    Serial1.print("\"");  //Send SMS message
    readStrings(1000);
    Serial1.print("YOUR NUMBER HAS BEEN CHANGED!");
    readStrings(1000);
    Serial1.write(26);
    check_reginumber_flag = 0;
  }
}
int readStrings(int timeout)
{
  //Serial.println("inside readstring");
  int  index = 0;
  int  inByte = 0;
  char WS[3];

  //----- erase GSM_string
  memset(GSM_string, 0, BUFFER_SIZE);
  memset(WS, 0, 3);

  //----- clear Serial Line Buffer
  Serial1.flush();
  while (Serial1.available()) {
    Serial1.read();
  }

  //----- wait of the first character for "timeout" ms
  Serial1.setTimeout(timeout);
  inByte = Serial1.readBytes(WS, 1);
  GSM_string[index++] = WS[0];

  //----- wait of further characters until a pause of 30 ms occures
  while (inByte > 0)
  {
    Serial1.setTimeout(1000);
    inByte = Serial1.readBytes(WS, 1);
    GSM_string[index++] = WS[0];
  }
  Serial.println(GSM_string);

  if (strstr(GSM_string, "MYNUMBER") && strstr(GSM_string, "1234"))
  {
    Serial.println("Got REQUEST TO CHANGE MY NUMBER");
    //strcpy(GSM_string, TIMER_string);
    Serial.println("GSM_string is: ");
    Serial.println(GSM_string);
    //Serial.println("TIMER_string is: ");
    //Serial.println(TIMER_string);
    check_reginumber_flag = 1;
  }
  return 0;
}

//+CMGR: "REC UNREAD","+917066485916","","2018/10/31 18:16:17+22"
