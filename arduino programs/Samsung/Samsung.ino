/*
This program reads data from a samsung remote
and save that in EEPROM
*/
#include <EEPROM.h>
#define tsop_pin 2
#define led_pin 13
boolean button[10][32]; // for storing 10 buttons each having data of 32 bit
int b = 0;
int data_previous = 9999; // taking random value except 0
unsigned long int t1;
unsigned long int t2;
int eaddr = 0;          // EEPROM starting address
boolean add_flag = 1;   // This flag is used to read and store the address only once.
void setup()
{
  Serial.begin(9600);
  pinMode(tsop_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop()
{
again:                                // for repeating this program when same button is pressed twice
  boolean bin[32];                    //boolean consumes less space
  int addr = 0, data = 0;             // address and data variabels

  while (pulseIn(tsop_pin,LOW) < 4000); // wait until start bit is received.

  digitalWrite(led_pin, HIGH);      //turn on an led

  for (int i = 0; i < 32; i++)
  {

    if (pulseIn(tsop_pin, HIGH) > 1000) //store binary values
      bin[i] = 1;
    else
      bin[i] = 0;
  }

  Serial.print("Bit Stream = ");
  for (int i = 0; i < 32; i++)     //print bit stream
  {
    Serial.print(bin[i]);
  }
  Serial.println();

  Serial.print("Address = ");
  for (int i = 0; i < 8; i++)     //extract addr bits
  {

    if (bin[i] == 1)
      addr += 1 << i;

  }
  Serial.print("   ");
  Serial.println(addr);
  if (add_flag == 1)     // for storing address of the signal at position 0 only once.
  {
    EEPROM.write(eaddr, addr);  // storing address to EEPROM
    eaddr = eaddr + 1;          // incrementing address.
    add_flag = 0; 
  }
  Serial.print("Data = ");
  for (int i = 0; i < 8; i++)     //extract data bits
  {

    if (bin[i + 16] == 1)
      data += 1 << i;
  }

  Serial.print("   ");
  Serial.println(data);
  Serial.println();

  if (data_previous == data)    // If same data is recieved than don't store rather repeat the process
  {
    Serial.println("JUMP");      
    goto again;
  }

  else
  {
    if (EEPROM.read(0) != addr)   // if address of the present signal doesn't matches with that of first signal, than different remote id detected. So again repeat the process.
    {
      Serial.println("//*********************************Different Remote****************************************//");
      goto again;
    }
    b++;
    data_previous = data;
    EEPROM.write(eaddr, data); // storing data in EEPROM.
    eaddr = eaddr + 1;
    Serial.println("Stored");
  }



  for (int f = 0; f < 32; f++) // Storing 10 buttons' data in this array.
  {

    button[b][f] = bin[f];   
  }


  Serial.println("    ");
  for (int j = 1; j <= b; j++)
  {
    Serial.print("Button ");
    Serial.print(j);
    Serial.println(" ");

    for (int i = 0; i < 32; i++)     //extract addr bits
    {

      Serial.print(button[j][i]);
    }
    Serial.println("\n");
  }
  delay(50);                      
  digitalWrite(led_pin, LOW); //turn off the led

}



