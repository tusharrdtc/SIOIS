#include <RBD_Timer.h> // https://github.com/alextaujenis/RBD_Timer
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

RBD::Timer timerHour;
RBD::Timer timerMin;
LiquidCrystal_I2C lcd(0x3F, 16, 4);

unsigned long hours = 0;
unsigned long minutes = 0;
int val = 0.00;
int j,k = 0;
bool foo = 0;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
  //digitalWrite(13, LOW);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print(F("SENSE IT OUT"));
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print(F("Please Set Timer"));

}

void loop() {

//  if (digitalRead(11) == LOW)  {
//    digitalWrite(13, HIGH);
//    timer4.setTimeout(hours * 1000); // 4 hours in ms
//    timer4.restart();
//  }

  j = 0;
  k=0;
  menu();
//  Serial.println("Out of menu");
//  if (timerHour.onExpired()) {
//      timerMin.setTimeout(minutes*60 * 1000); // 4 minutes in ms
//      timerMin.restart();
//  }
  if(timerMin.onExpired()) {
    //digitalWrite(13,LOW);
    Serial.println("change");
  }

}
