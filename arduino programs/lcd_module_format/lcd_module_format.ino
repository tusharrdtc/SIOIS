#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int a=500;
int colm1,colm2,colm3,colm4;
int q=1;
uint8_t gsm[8]  = {0x1f, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x1f};      //gsm range character
uint8_t range1[8]  = {0x0, 0x0, 0x0, 0x0, 0x1f, 0x1f, 0x1f};          //creating character range 1
uint8_t range2[8]  = {0x0, 0x0, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};         //creating character range 2
uint8_t range3[8]  = {0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};      //creating character range 3
uint8_t extra4[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uint8_t extra5[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uint8_t battery[8]  = {0x04, 0x1f, 0x11, 0x11, 0x1f, 0x1f, 0x1f};      //battery character
//uint8_t extra8[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
//uint8_t extra9[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
//uint8_t extra10[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
//uint8_t local[8]  = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f};      //local range character
//uint8_t extra12[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
//uint8_t extra13[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
//uint8_t extra14[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

// Set the LCD address to 0x27 for a 16 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup()
{ 
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  Serial.begin(9600);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  lcd.begin();
  lcd.backlight();
  lcd.createChar(0, gsm);  
  lcd.createChar(1, range1);
  lcd.createChar(2, range2);
  lcd.createChar(3, range3);
  lcd.createChar(4, extra4);
  lcd.createChar(5, extra5);
  lcd.createChar(6, battery);
    lcd.home();
    lcd.write(0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(3);
    lcd.write(4);
    lcd.write(5);
    lcd.write(6);
    lcd.setCursor(9,0);
  lcd.print("L");
  lcd.setCursor(11,0);
  lcd.print("TIME:");
	lcd.setCursor(0,1);
  lcd.print("SM");
  lcd.setCursor(3,1);
  lcd.print("455");
  lcd.setCursor(7,1);
  lcd.print("HUM.");
  lcd.setCursor(12,1);
  lcd.print("78");
  lcd.setCursor(-4,2);
  lcd.print("ST");
  lcd.setCursor(-1,2);
  lcd.print("28");
  lcd.setCursor(3,2);
  lcd.print("TEMP");
  lcd.setCursor(8,2);
  lcd.print("32");
  lcd.setCursor(-4,3);
  lcd.print("PUMP_STAT:"); 
  lcd.setCursor(6,3);
  lcd.print("ON");  
}
  void loop()
  {
    //nothing to do;
 }
