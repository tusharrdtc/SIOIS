#include <RTClib.h>

#define BUFFER_SIZE 250 //Size of array in readStrings function
#define input_time 30
#define relayPin1 29

RTC_DS1307 rtc;

bool manual_val=0;
char url[200];
int soilMoist = 550;
int hum = 65;
int temp = 28;
int soilTemp = 26;
double battVolt = 3.7;
char  GSM_string[250];
char buff[50];
bool pumpStat = 1;
bool check_sms_flag = 0;
bool check_net_flag = 0;
bool check_status_flag = 0;
bool check_number_flag = 0;
bool check_timer_flag = 0;
bool check_newnumber_flag = 0;
bool timer_flag = 0;
int sms_flag = 0;
char pump[5] = {'O', 'F', 'F'};
const long interval = 1000;
char TIMER_string[250];
char NUMBER_string[250];
char mynumber[12] = "7066485916";
char *ret;
int mn = 0;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("hello");
}
void loop()
{
  if (sms_flag > 10)
  {
    sms_to_farmer();
    sms_flag = 0;
  }
  sms_flag = sms_flag + 1;
//  Serial.print(F("sms_flag is: "));
//  Serial.println(sms_flag);
    newnumber();
      if (timer_flag == 1)
      {
        timerMode();
      }
  if (mn > 300)
  {
    gprs();
    mn = 0;
  }
  //    gsm();
  //Serial.print("value of mn is: ");
  Serial.println(mn);
  mn = mn + 1;
  delay(1000);
}
