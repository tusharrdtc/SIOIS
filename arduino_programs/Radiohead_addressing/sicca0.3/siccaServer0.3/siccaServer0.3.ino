/* Library Section*/
#include <RHReliableDatagram.h>
#include <RH_RF95.h>  //Library for rfm95
#include <SPI.h>
#include <LiquidCrystal_I2C.h>  //Library for LCD
#include <RTClib.h> //Library for RTC
#include <elapsedMillis.h>
#include <EEPROM.h> //Library for EEPROM
#include <SD.h>

elapsedMillis timeElapsed;
#define CLIENT_ADDRESS 2                   //1
#define CLIENT_ADDRESS 1                   //2
#define SERVER_ADDRESS 1                   //2


/* Definitions*/
#define freq 868.0  //rfm95 frequency
#define input_time 30 //Timeout for AT+QHTTPURL command
#define rowPin  9 //keypad pins
#define upPin  10
#define downPin 11
#define setPin  12
#define backPin 13
#define relayPin1 5  //Relay pin 1 for turn ON/OFFF the pump
#define relayPin2 6  //Relay pin 2 for turn ON/OFF the pump
#define relayPin3 7  //Relay pin 3 for turn ON/OFF the node 1
#define relayPin4 8  //Relay pin 4 for turn ON/OFF the node 2
#define manualPin 22  //Manual mode pin for input
#define manualOut 28  //Manual mode pin for output 
#define BUFFER_SIZE 250 //Size of array in readStrings function
#define sdcs 53           //chipselect for sd card
/*Creating Instances*/

LiquidCrystal_I2C lcd(0x3F, 20, 4);
RTC_DS1307 rtc;


// Singleton instance of the radio driver
RH_RF95 driver(53, 2);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, SERVER_ADDRESS);


/* Variable Section*/
uint8_t buf[22];
char url[200];
char timer_arr[250];
int soilMoist11;
int soilMoist21;
int hum1;
int temp1;
int soilTemp11;
int soilTemp21;
double batt1;
double batt2;
char buff[50];
bool flag = 0;
bool flagKey = 0;
bool flagGetData;
bool flagGet = 0;
bool check_sms_flag = 0;
bool check_net_flag = 0;
bool check_status_flag = 0;
bool check_number_flag = 0;
bool check_timer_flag = 0;
bool check_newnumber_flag = 0;
bool timer_flag = 0;
uint8_t gsm_E[8]  = {0x1f, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x1f};      //gsm range character
uint8_t range1[8]  = {0x0, 0x0, 0x0, 0x0, 0x1f, 0x1f, 0x1f};          //creating character range 1
uint8_t range2[8]  = {0x0, 0x0, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};         //creating character range 2
uint8_t range3[8]  = {0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};      //creating character range 3
uint8_t range_x[8]  = {0x11, 0xb, 0x4, 0xb, 0x11, 0x0, 0x0};      //creating character no range
uint8_t extra4[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uint8_t extra5[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uint8_t battery_100[8]  = {0x04, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};      //battery full
uint8_t battery_75[8]  = {0x04, 0x1f, 0x11, 0x1f, 0x1f, 0x1f, 0x1f};      //battery at 75%
uint8_t battery_50[8]  = {0x04, 0x1f, 0x11, 0x11, 0x1f, 0x1f, 0x1f};      //battery at 50%
uint8_t battery_25[8]  = {0x04, 0x1f, 0x11, 0x11, 0x11, 0x1f, 0x1f};      //battery at 25%
uint8_t battery_0[8]  = {0x04, 0x1f, 0x11, 0x11, 0x11, 0x11, 0x1f};      //battery down
uint8_t battery_x[8]  = {0x04, 0x1f, 0x1B, 0x15, 0x1B, 0x11, 0x1f};      //battery down
uint8_t from;
int16_t rssi;
int valFc;
int valWp;
int fc=325;          //lower threshold
int wp=500;          //upper threshold
int addFc = 0;   //upper threshold stored in eeprom
int addWp = 1;   //upper threshold stored in eeprom
int j = 0, k = 0; //used in keypad Function
int address = 0;
int value;
int rtcHour, rtcMin;  //
double battVolt1;
double battVolt2;
bool pumpStat;
char pump[5] = {'O', 'N'};
int rssiPos;
int sms_flag = 0;
//unsigned long previousMillis = 0;   /////not used
const long interval = 1000;
//const int node_id;                  ////not used
int var_b = 1;  //a flag used in getData function
int var_c = 0;;  //a flag used in getData function
char  GSM_string[250];
char TIMER_string[250];
char NUMBER_string[250];
char mynumber[12] = "8600502595";
char *ret;
bool manual_val;
//int menuCounter = 0;             ////not used
int batt_flag = 0;
String dataString = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  /* RFM95 setup section */
  while (!Serial) ; // Wait for serial port to be available
  if (!manager.init())
    Serial.println(F("init failed"));

  //Set Frequency & Configuration.Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  if (!driver.setFrequency(freq))
    Serial.print(F("Set frequency failed!"));

  if (!driver.setModemConfig(RH_RF95::Bw125Cr45Sf128 ))
    Serial.print(F("config failed!"));

  // you can set transmitter powers from 5 to 23 dBm:
  driver.setTxPower(15, false);
  /*GSM setup*/
  Serial1.begin(9600);



  /*LCD setup*/
  lcdSetup();

  /*Keypad setup*/
  pinMode(rowPin, OUTPUT);   //KP1
  pinMode(upPin, INPUT);    //KP2
  pinMode(downPin, INPUT);    //KP3
  pinMode(setPin, INPUT);    //KP4
  pinMode(backPin, INPUT);    //KP5
  digitalWrite(rowPin, LOW);
  digitalWrite(upPin, HIGH);
  digitalWrite(downPin, HIGH);
  digitalWrite(setPin, HIGH);
  digitalWrite(backPin, HIGH);
  pinMode(manualPin, INPUT);
  pinMode(manualOut, OUTPUT);
  //pinMode(44, OUTPUT);


  /*Initialise RTC Module*/
  rtc_init();
  
  /*Initialise SD Module*/
  //sd_init();
  
  /*Relay Setup
     NOTE: This relay works when its signal pin is LOW*/
  pinMode(relayPin1, OUTPUT);    //FOR RELAY
  pinMode(relayPin2, OUTPUT);    //FOR RELAY
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  digitalWrite(manualOut, HIGH);

  
  /*Threshold Setup*/
//  valFc = EEPROM.read(addFc);
//  fc = valFc * 4;
//  valWp = EEPROM.read(addWp);
//  wp = valWp * 4;
  lcd.setCursor(0, 3);
  lcd.print("PUMP STATUS: ");
  lcd.setCursor(13, 3);
  lcd.print("      ");
}


void loop()
{
  // put your main code here, to run repeatedly:
  j = 0, k = 0;
  lcdDisp();
  //menu();
  gsmRssi();
  battVolt = 4.2;
  rtcDisp();
  manualMode();
  if (sms_flag > 10)
  {
    smsToFarmer();
    sms_flag = 0;
  }
  sms_flag = sms_flag + 1;
  Serial.print(F("sms_flag is: "));
  Serial.println(sms_flag);
  newNumber();
  if (timer_flag == 1)
  {
    timerMode();
  }
  getData();
  if (flag == 1)
  {
    process();
    relay1phase();
    battery();
    gprs();
    flag = 0;

  }
  gsm();

}
