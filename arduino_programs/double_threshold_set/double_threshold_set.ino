#include <SPI.h>
#include <LiquidCrystal_I2C.h>  //Library for LCD
#include <EEPROM.h> //Library for EEPROM

#define rowPin  9 //keypad pins
#define upPin  10
#define downPin 11
#define setPin  12
#define backPin 13

LiquidCrystal_I2C lcd(0x3F, 20, 4);

int valFc;
int valWp;
int fc;
int wp;
int addFc = 0;
int addWp = 1;
int j = 0,k=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  
  lcd.begin();
  lcd.backlight();  //Turn on backlight
  
  valFc = EEPROM.read(addFc);
  fc = valFc*4;
  valWp = EEPROM.read(addWp);
  wp = valWp*4;
}

void loop() {
  // put your main code here, to run repeatedly:
  j=0,k=0;
  lcdDisp();
  menu();
  
}

void menu() {
  int colm3 = digitalRead(setPin);  //Read user input
  if (colm3 == LOW)
    {
    lcd.clear();
    //Read keypad function until back button is pressed
    while(j!= 1)
    {
      fieldCap();
      
    }
    valFc = fc/4;
    EEPROM.update(addFc,valFc); //Update EEPROM with new threshold
    while(k!= 1)
    {
      wiltPoint();
      delay(500);
    }
    valWp = wp/4;
      EEPROM.update(addWp,valWp); //Update EEPROM with new threshold

    }
    
}

void lcdDisp()
{ 
  lcd.setCursor(0,0);
  lcd.print("E");
  lcd.setCursor(0, 1);
  lcd.print("SM");
  lcd.setCursor(10, 1);
  lcd.print("TEMP");
  lcd.setCursor(10, 2);
  lcd.print("HUM");
  lcd.setCursor(0, 2);
  lcd.print("ST");
}


void fieldCap()  {

  bool flagKey = 1;
  int colm1 = digitalRead(upPin);
  int colm2 = digitalRead(downPin);
  int colm3 = digitalRead(setPin);
  int colm4 = digitalRead(backPin);
      //lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("FC IS:");
      lcd.setCursor(1,2);
      lcd.print(fc);

      //To increase threshold value
      if (colm1 == LOW && flagKey == 1)
      {
        
        fc = fc - 10;
        if(fc < 100)
        {fc = 100;}
        lcd.setCursor(1, 2);
        lcd.print(fc);
        Serial.println(fc);
        delay(500);
        
       
      }

      //To decrease threshold value
      if (colm2 == LOW && flagKey == 1)
      {
        
        fc = fc + 10;
        if(fc>999)
        {fc = 999;}
        lcd.setCursor(1, 2);
        lcd.print(fc);
        Serial.println(fc);
        delay(500);
      }

    //To set the threshold & update the EEPROM
    if (colm4 == LOW)
    {
      lcd.setCursor(0, 1);
      lcd.print("FC VALUE SET");
      delay(1000);
      Serial.println("back");
      lcd.clear();
      j = 1;
      delay(500);
     }
  }

void wiltPoint()  {

  bool flagKey = 1;
  int colm1 = digitalRead(upPin);
  int colm2 = digitalRead(downPin);
  int colm3 = digitalRead(setPin);
  int colm4 = digitalRead(backPin);
      //lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("WP IS:");
      lcd.setCursor(1,2);
      lcd.print(wp);

      //To increase threshold value
      if (colm1 == LOW && flagKey == 1)
      {
        wp = wp - 10;
        if(wp < 100)
        {wp = 100;}
        Serial.println(wp);
        lcd.setCursor(1, 2);
        lcd.print(wp);
        Serial.println(wp);
        delay(500);
       
      }

      //To decrease threshold value
      if (colm2 == LOW && flagKey == 1)
      {
        wp = wp + 10;
        if(wp > 999)
        {wp = 999;}
        lcd.setCursor(1, 2);
        lcd.print(wp);
        Serial.println(wp);
        delay(500);
      }

    //To set the threshold & update the EEPROM
    if (colm4 == LOW)
    {
      lcd.setCursor(0, 1);
      lcd.print("WP VALUE SET");
      delay(1000);
      Serial.println("back");
      lcd.clear();
      k = 1;
      delay(500);
     }
  }

