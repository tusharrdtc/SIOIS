#define relayPin1 2
#define relayPin2 3
#define relayPin3 4
#define relayPin4 5

/*----(Variable declaration)-----*/
int soilMoist11;
int soilMoist21;
int wp = 700;
int fc = 325;
bool node1LockFlag = 0;
bool node2LockFlag = 0;
bool pumpOnFlag = 0;
bool pumpOffFlag = 0;
bool manualPin = 1; 

void setup() 
{
  Serial.begin(9600);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  digitalWrite(relayPin3, HIGH);
  digitalWrite(relayPin4, HIGH);
}

void loop()
{
  for(int i=0; i<8; i++)
  {
    analogRead(0);
  }
  soilMoist11 = analogRead(0);
  Serial.print("soilMoist11 is:");
  Serial.println(soilMoist11);
  for(int i=0; i<8; i++)
  {
    analogRead(1);
  }
  soilMoist21 = analogRead(1);
  Serial.print("soilMoist21 is : ");
  Serial.println(soilMoist21);
  pumpOnOff3phase();
  delay(1000);
}
void pumpOnOff3phase()
{
  if(soilMoist11 > wp || soilMoist21 > wp)
  {
    pumpOn();
    digitalWrite(relayPin1, LOW);
    if(soilMoist11 > wp && node1LockFlag == 0)
    {
      Serial.println("node 1 is on");
      digitalWrite(relayPin3, LOW);
      node2LockFlag = 1;
    }
    if(soilMoist21 > wp && node2LockFlag == 0)
    {
      Serial.println("node 2 is on");
      digitalWrite(relayPin4, LOW);
      node1LockFlag = 1;
    }
  }
  if(soilMoist11 < fc || soilMoist21 < fc)
  {
    if(soilMoist11 <fc)
    {
      Serial.print("soilMoist11 is turn off");
      digitalWrite(relayPin3, HIGH);
      node2LockFlag = 0;
    }
    if(soilMoist21 < fc)
    {
      Serial.println("soilMoist21 is turn off");
      digitalWrite(relayPin4, HIGH);
      node1LockFlag = 0;
    }
    if(soilMoist11 < fc && soilMoist21 < fc)
    {
      pumpOff();
      digitalWrite(relayPin1, HIGH);
    }
  }
}
void pumpOn()
{
  if (soilMoist11 >= wp  && manualPin==1)
  {
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("ON  ");
    pump[0]='O';
    pump[1]='N';
    pump[2]=' ';
    pump[3]=' ';
    pump[4]=' ';
    pump[5]=' ';
    pumpStat = 1;
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, HIGH);
    Serial.println(F("PULSE TO TURN ON PUMP"));
    for (int i = 0; i < 2; i++)
    {
      Serial.println(i);
      delay(1000);
    }
    digitalWrite(relayPin1, HIGH);
  }
}
void pumpOff()
 {
  //LOGIC TO TURN OFF THE PUMP
    lcd.setCursor(0, 3);
    lcd.print("PUMP STATUS: ");
    lcd.setCursor(13, 3);
    lcd.print("OFF ");
    pump[0]='O';
    pump[1]='F';
    pump[2]='F';
    pump[3]=' ';
    pump[4]=' ';
    pump[5]=' ';
    pumpStat = 0;
    Serial.println(F("PULSE TO TURN OFF PUMP"));
    digitalWrite(relayPin2, LOW);
    for (int i = 0; i < 2; i++)
    {
      Serial.println(i);
      delay(1000);
    }
    digitalWrite(relayPin1, HIGH);
    digitalWrite(relayPin2, HIGH);
  }
 }
}
