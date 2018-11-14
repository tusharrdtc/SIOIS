#include <Wire.h>
void setup() 
{
  pinMode(6,OUTPUT);
  Wire.begin();                // join i2c bus (address optional for master)
  Serial.begin(9600);          // start serial communication at 9600bps
}
int reading = 0;
void loop() {
  analogWrite(6,153);
  const int I2C_address = 0x28;  // I2C write address 
  const byte DAT[4] = {0x10,0x20,0x40,0x80};
   byte Adval_High, Adval_Low;    // Store A/D value (high byte, low byte)
  byte i;                        // Counter

  delay(1000);
  
  for (i=0; i<=3; i++)
  {
    Wire.beginTransmission(I2C_address);
    Wire.write(byte (DAT[i])); // Configure the device to read each CH  
    Wire.endTransmission(); 
    delay(1);
    
    // Read A/D value
    Wire.requestFrom(I2C_address, 2);
    while(Wire.available())          // Checkf for data from slave
    { 
      Adval_High = Wire.read();   // Receive A/D high byte
      Adval_Low = Wire.read();    // Receive A/D low byte
    } 
    
    Serial.print("A/D value CH");
    Serial.print(i);
    Serial.print(" is ");
    Serial.print(Adval_High, HEX);
    
    
    if (Adval_Low <= 8)
      Serial.print("0");
    Serial.println(Adval_Low, HEX);
   
  }  
  Serial.println();
  delay(1000);
}
/*
//FOR 1 CHANNEL CODE
#include <Wire.h>
void setup() 
{
  pinMode(6,OUTPUT);
  Wire.begin();                // join i2c bus (address optional for master)
  Serial.begin(9600);          // start serial communication at 9600bps
}

int reading = 0;

void loop() {
  analogWrite(6,153);
  // step 1: instruct sensor to read echoes
  Wire.beginTransmission(0x28); // transmit to device #112 (0x70)
  // the address specified in the datasheet is 224 (0xE0)
  // but i2c adressing uses the high 7 bits so it's 112
  Wire.write(byte(0x18));      // sets register pointer to the command register (0x00)
  //Wire.write(byte(0x18));      // command sensor to measure in "inches" (0x50)
  // use 0x51 for centimeters
  // use 0x52 for ping microseconds
  Wire.endTransmission();      // stop transmitting

  // step 2: wait for readings to happen
  delay(70);                   // datasheet suggests at least 65 milliseconds

  // step 3: instruct sensor to return a particular echo reading
  //Wire.beginTransmission(112); // transmit to device #112
  //Wire.write(byte(0x18));      // sets register pointer to echo #1 register (0x02)
  //Wire.endTransmission();      // stop transmitting

  // step 4: request reading from sensor
  Wire.requestFrom(0x28, 8);    // request 2 bytes from slave device #112

  // step 5: receive reading from sensor
  if (8 <= Wire.available()) { // if two bytes were received
    reading = Wire.read();  // receive high byte (overwrites previous reading)
    reading = reading << 8;    // shift high byte to be high 8 bits
    reading |= Wire.read(); // receive low byte as lower 8 bits
    Serial.println(reading);   // print the reading
    
  }

  delay(250);                  // wait a bit since people have to read the output :)
}
/*
#include <Wire.h> // call library
#define AD7991_Adresse 0x28 // I2C adress of the Pmod AD2 module
int MSB;
int LSB;
int valeur;

void setup()
{
 Serial.begin(9600); // initialization of serial communication
 Wire.begin(); // initialization of I2C communication
 }

void loop()
{
 Wire.beginTransmission(AD7991_Adresse); // Launch of the measure
 Wire.endTransmission();
 delay(10);
 Wire.requestFrom(AD7991_Adresse, 2); // Recovery of the two bytes MSB and LSB
 if(Wire.available() <=2)
 {
  MSB = Wire.read();
  LSB = Wire.read();
 }
 valeur=MSB<< 8 |LSB ;
 Serial.print("MSB="); // display in serial monitor
 Serial.println(MSB);
 Serial.print("LSB=");
 Serial.println(LSB);
 Serial.print("Valeur=");
 Serial.println(valeur);
 delay(4000);
}

void Init_AD7991(void)
{
 Wire.beginTransmission(AD7991_Adresse);
 Wire.write(0x08); // configuration of the I2C communication in HIGH SPEED Mode
 Wire.write(0xF0); // configuration of Pmod AD2 (read of V0)
 Wire.endTransmission();
}*/

/*
//THE CODE IS FOR PMODAD2 (AD7991)
#include <Wire.h> 
void setup() 
{ 
  Serial.begin(9600);
  Wire.begin();             // join i2c bus (address optional for master) 
  delay(1000);
} 
 void loop() 
{
  const int I2C_address = 0x28;  // I2C write address 
  const byte DAT[4] = {0x10,0x20,0x40,0x80};
                                 // Constant configuration data
  
  byte Adval_High, Adval_Low;    // Store A/D value (high byte, low byte)
  byte i;                        // Counter

  delay(1000);
  
  for (i=0; i<=3; i++)
  {
    Wire.beginTransmission(I2C_address);
    Wire.write(DAT[i]);        // Configure the device to read each CH  
    Wire.endTransmission(); 
    delay(1);
    
    // Read A/D value
    Wire.requestFrom(I2C_address, 2);
    while(Wire.available())          // Checkf for data from slave
    { 
      Adval_High = Wire.read();   // Receive A/D high byte
      Adval_Low = Wire.read();    // Receive A/D low byte
    } 
    
    Serial.print("A/D value CH");
    Serial.print(i, DEC);
    Serial.print(" is ");
    Serial.print(Adval_High,DEC);
    
    if (Adval_Low <= 0x0F)
      Serial.print("0");
    Serial.println(Adval_Low,DEC);
  }  
  Serial.println();
  delay(1000);
}
*/
