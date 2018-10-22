#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define rowPin  9 //keypad pins
#define upPin  10
#define downPin 11
#define setPin  12
#define backPin 13

int threshold = 500, j,k,i, colm1, colm2, colm3, colm4;
int fc = 325;
int wp = 500;
LiquidCrystal_I2C lcd(0x3F, 20, 4);

void setup() 
{
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
}

void loop()
{
  i=0;
  j=0;
  k=0;
  
  if(i==0)
  {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("SM  420");
  lcd.setCursor(11, 1);
  lcd.print("ST 26");
  lcd.setCursor(0, 2);
  lcd.print("TEMP  28");
  lcd.setCursor(11, 2);
  lcd.print("HUM  64");
  }
  colm3 = digitalRead(setPin);
  if (colm3 == LOW)
  {
    i=1; j=0, k=1;
    while (j != 1)
    {
      FC();
    }
    while (k != 1 )
    {
      WP();
      Serial.println("outside the wp");
    }
  }
  Serial.println("Outside the if loop");
}
void FC()
{
  bool flagKey = 1;
  int colm1 = digitalRead(upPin);
  int colm2 = digitalRead(downPin);
  int colm3 = digitalRead(setPin);
  int colm4 = digitalRead(backPin);
  if (colm1 == LOW || colm2 == LOW || colm3 == LOW || colm4 == LOW)
  {
    if (colm1 == LOW || colm2 == LOW || colm3 == LOW)
    {
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("FC IS:");
      lcd.setCursor(15,1);
      lcd.print(fc);
      delay(1000);
      //To increase threshold value
      if (colm1 == LOW && flagKey == 1)
      {
        fc = fc - 10;
        lcd.setCursor(1, 2);
        lcd.print(fc);
        Serial.println(fc);
       
      }

      //To decrease threshold value
      if (colm2 == LOW && flagKey == 1)
      {
        fc = fc + 10;
        lcd.setCursor(1, 2);
        lcd.print(fc);
        Serial.println(fc);
      }
    }

    //To set the threshold & update the EEPROM
    if (colm4 == LOW)
    {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("FC VALUE SET");
      Serial.println("back");
      flagKey=0;
      j=1, k=0;
     }
   }
}

void WP()
{
  bool flagKey = 1;
  int colm1 = digitalRead(upPin);
  int colm2 = digitalRead(downPin);
  int colm3 = digitalRead(setPin);
  int colm4 = digitalRead(backPin);
  if (colm1 == LOW || colm2 == LOW || colm3 == LOW || colm4 == LOW)
  {
    if (colm1 == LOW || colm2 == LOW || colm3 == LOW)
    {
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("WP IS:");
      lcd.setCursor(15,1);
      lcd.print(wp);

      //To increase threshold value
      if (colm1 == LOW && flagKey == 1)
      {
        wp = wp - 10;
        Serial.println(wp);
        lcd.setCursor(1, 2);
        lcd.print(wp);
        Serial.println(wp);
       
      }

      //To decrease threshold value
      if (colm2 == LOW && flagKey == 1)
      {
        wp = wp + 10;
        lcd.setCursor(1, 2);
        lcd.print(wp);
        Serial.println(wp);
      }
    }

    //To set the threshold & update the EEPROM
    if (colm4 == LOW)
    {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("WP VALUE SET");
      Serial.println("back");
      flagKey=0;
      i=0;
      k=0;
     }
   }
}
