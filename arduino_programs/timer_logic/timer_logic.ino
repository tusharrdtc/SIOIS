#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 4);

double timer = 0;
bool j = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);                  //rawpin
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(1, 1);  //Set the cursor on 4th Col & 1st Row
  lcd.print("SENSE IT OUT");
  Serial.println("SENSE IT OUT");
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("SICCA");
  Serial.println("SICCA");
  delay(2000);
  lcd.clear();
}
void loop()
{
  keypad();
  //Serial.println("out of keypad");
  if (timer != 0)
  {
    lcd.setCursor(1, 1);
    lcd.print("TIMER STARTED FOR");
    lcd.setCursor(2, 1);
    lcd.print(timer);
  }
  else
  {
    lcd.setCursor(1, 1);
    lcd.print("ENTER TIME");
  }
  double val = timer * 3600;
  Serial.println(timer);
  for (double k = 0; k < val; k++)
  {
    Serial.print("remaining minutes are: ");
    int minutes = val - k;
    minutes = minutes / 60;
    Serial.println(minutes);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("REMAINING TIME:");
    lcd.setCursor(1, 2);
    lcd.print(minutes);
    int colm2 = digitalRead(11);
    if (colm2 == LOW)
    {
      k = val + 2;
    }
    if (k > val)
    {
      lcd.clear();
      lcd.setCursor(1, 2);
      lcd.print("TIMER END!");
    }
    delay(1000);
  }
}
void keypad()
{
  int colm1 = digitalRead(10);
  delay(500);
  if (colm1 == LOW)
  {
    Serial.println("enter time");
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("PRESS KEYS!");
    lcd.setCursor(1, 7);
    lcd.print(timer);
    while (j != 1)
    {
      menu();
    }

  }
}
void menu()
{
  int colm1 = digitalRead(10);
  delay(100);
  int colm2 = digitalRead(11);
  delay(100);
  int colm3 = digitalRead(12);
  delay(100);
  int colm4 = digitalRead(13);
  delay(100);
  if (colm2 == LOW || colm3 == LOW || colm4 == LOW)
  {
    if (colm2 == LOW)
    {
      timer = timer + 0.5;
      if (timer == 12)
      {
        timer = 0;
      }
      Serial.print("now timer value is: ");
      Serial.println(timer);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("TIMER");
      lcd.setCursor(7, 1);
      lcd.print(timer);
      lcd.setCursor(13, 1);
      lcd.print("HRS");
    }
    if (colm3 == LOW)
    {
      if (timer == 0)
      {
        timer = 12;
      }
      timer = timer - 0.5;
      Serial.print("now timer value is: ");
      Serial.println(timer);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("TIMER");
      lcd.setCursor(7, 1);
      lcd.print(timer);
      lcd.setCursor(13, 1);
      lcd.print("HRS");
    }
    if (colm4 == LOW)
    {
      Serial.print("final timer value is: ");
      Serial.println(timer);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print("TIMER ");
      lcd.setCursor(7, 1);
      lcd.print(timer);
      lcd.setCursor(13, 1);
      lcd.print("HRS");
      j = 1;
    }
  }
}
