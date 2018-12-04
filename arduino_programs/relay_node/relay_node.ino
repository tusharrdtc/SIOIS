#define relayPin1 2
#define relayPin2 3
#define relayPin3 4
#define relayPin4 5

/*----(Variable declaration)-----*/
int soilMoist1;
int soilMoist2;
int wp = 700;
int fc = 325;
bool node1LockFlag = 0;
bool node2LockFlag = 0;
bool pumpOnFlag = 0;
bool pumpOffFlag = 0;

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
  for (int i = 0; i < 8; i++)
  {
    analogRead(0);
    delay(50);
  }
  soilMoist1 = analogRead(0);
  for (int i = 0; i < 8; i++)
  {
    analogRead(1);
    delay(50);
  }
  soilMoist2 = analogRead(1);
  Serial.print("soilMoist1 is: ");
  Serial.println(soilMoist1);
  Serial.print("soilMoist2 is: ");
  Serial.println(soilMoist2);
  nodeOnOff();
  Serial.println(" ");
  delay(1000);
}
void nodeOnOff()
{
  if (soilMoist1 > wp || soilMoist2 > wp)
  {
    Serial.println("inside the irrigation mode");
    if (pumpOnFlag == 0)
    {
      Serial.println("Pump is TURN ON");
      pumpOn();
      pumpOnFlag = 1;
      pumpOffFlag = 0;
    }
    if (soilMoist1 > soilMoist2 || node1LockFlag == 1)
    {
      Serial.println("inside the case 1");
      if (soilMoist1 > wp)
      {
        digitalWrite(relayPin3, LOW);
        node2LockFlag = 1;
        node1LockFlag = 1;
        Serial.println("node1 is ON");
      }
    }
    if ((soilMoist2 > soilMoist1) || node2LockFlag == 1)
    {
      Serial.println("inside the case 2");
      if (soilMoist2 > wp)
      {
        Serial.println("node2 is ON");
        digitalWrite(relayPin4, LOW);
        node2LockFlag = 1;
        node1LockFlag = 1;
      }
    }

  }
  if ((soilMoist1 < fc) || (soilMoist2 < fc))
  {
    if (soilMoist1 < fc)
    {
      Serial.println("node1 is OFF");
      digitalWrite(relayPin3, HIGH);
      node2LockFlag = 0;
    }
    if (soilMoist2 < fc)
    {
      Serial.println("node1 is OFF");
      digitalWrite(relayPin4, HIGH);
      node1LockFlag = 0;
      node2LockFlag = 0;
    }

    if (pumpOffFlag == 0 && soilMoist1 <fc && soilMoist2 <fc)
    {
      pumpOff();
      pumpOffFlag = 1;
      Serial.println("Pump is OFF");
    }
    node1LockFlag = 0;
    node2LockFlag = 0;
    pumpOnFlag = 0;
  }
}
void pumpOn()
{
  /*-----(LOGIC TO TURN OFF THE 1 PHASE PUMP)-----*/
  Serial.println("TURN ON THE 1 PHASE PUMP");
  digitalWrite(relayPin1, LOW);

  /*----(TURN ON PUMP FIRST)----*/
  /* Serial.println(F("PULSE TO TURN ON PUMP"));
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, HIGH);
    for (int i = 0; i < 2; i++)
    {
     //Serial.println(i);
     delay(1000);
    }
    digitalWrite(relayPin1, HIGH);*/
}
void pumpOff()
{
  /*-----(LOGIC TO TURN OFF THE 1 PHASE PUMP)-----*/
  Serial.println("TURN OFF THE 1 PHASE PUMP");
  digitalWrite(relayPin1, HIGH);

  /*-----(LOGIC TO TURN OFF THE 3 PHASE PUMP)-----*/
  /*Serial.println(F("PULSE TO TURN OFF 3 PHASE PUMP"));
    digitalWrite(relayPin2, LOW);
    for (int i = 0; i < 2; i++)
    {
    //Serial.println(i);
    delay(1000);
    }
    digitalWrite(relayPin1, HIGH);
    digitalWrite(relayPin2, HIGH);*/
}
