#define BUFFER_SIZE 250
char  GSM_string[250];
int timer_flag = 0;
char *ret;
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop()
{
  timer_flag = 0;

  timer_mode();
  delay(2000);

}

void  timer_mode()
{
  Serial1.println("AT+CMGF=1");
  readStrings(1000);
  Serial1.println("AT+CMGR=1");
  readStrings(1000);
  if (timer_flag == 1)
  {
//    const char needle[10] = "TIMER";
//    ret = strstr(GSM_string, needle);
//    Serial.println(ret);
    char sub[10];
    int position = 6, length = 2, c = 0;
    int i;
    while (c < length)
    {
      sub[c] = ret[position + c - 1];
      c++;
    }
    sub[c] = '\0';
    int m;
    m = atoi(sub);
    Serial.println(m);
  }
  //   Serial1.println("AT+CMGD=1,3");
  //   readStrings(1000);
  delay(3000);
}
int readStrings(int timeout)
{

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

  if (strstr(GSM_string, "TIMER"))
  {
    timer_flag = 1;
  }
  return 0;
}

