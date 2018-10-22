#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int a=500;
int colm1,colm2,colm3,colm4;
int q=1;

uint8_t range1[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};          //creating character range 1
uint8_t range2[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};         //creating character range 2
uint8_t range3[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};        //creating character range 3
uint8_t range4[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range5[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range6[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range7[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range8[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range9[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range10[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range11[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range12[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range13[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range14[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range15[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t range16[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
//uint8_t range17[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
//uint8_t range18[8]  = {0x1f, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};

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
  lcd.createChar(0, range1);
  lcd.createChar(1, range2);
  lcd.createChar(2, range3);
  lcd.createChar(3, range4);
  lcd.createChar(4, range5);
  lcd.createChar(5, range6);
  lcd.createChar(6, range7);
  lcd.createChar(7, range8);
  lcd.createChar(8, range9);
  lcd.createChar(9, range10);
  lcd.createChar(10, range11);
  lcd.createChar(11, range12);
  lcd.createChar(12, range13);
  lcd.createChar(13, range14);
  lcd.createChar(14, range15);
  lcd.createChar(15, range16);
  //lcd.createChar(16, range17);
  
  lcd.home();
  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
  lcd.write(8);
  lcd.write(9);
  lcd.write(10);
  lcd.write(11);
  lcd.write(12);
  lcd.write(13);
  lcd.write(14);
  lcd.write(15);
  lcd.write(16);
  //lcd.write(17);
  
 }
  
void loop() 
{
  /*lcd.setCursor(-2, 9);
  // print from 0 to 9:
  for (int thisChar = 1; thisChar < 9; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }

  // set the cursor to (16,1):*/
  /*lcd.setCursor(16, 1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
    /*for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  // clear screen for the next loop:
  lcd.clear();*/
}



