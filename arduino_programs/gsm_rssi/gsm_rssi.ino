void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop()
{
  rssi();
  delay(1000);
}

void rssi()
{
  char sub[50];
  int position=16, length=2, c = 0;
  char temp[50];
  int i;
  Serial1.println("AT+CSQ");
  if(Serial1.available()>0)
  {
    for(i=0; i<30; i++)
    {
      temp[i]=Serial1.read();
      //Serial.print(temp);
    }
  }
  while (c < length) 
  {
      sub[c] = temp[position+c-1];
      c++;
   }
   sub[c] = '\0';
//   Serial.print("Char value is ");
//   Serial.println(sub);
   int m;
   m=atoi(sub);
   if(m>=20 && m<30)
   {
    Serial.println("Excellent");
   }
   else if(m>=15 && m<20)
   {
    Serial.println("Good");
   }
   else if(m>=10 && m<15)
   {
    Serial.println("OK");
   }
   else if(m>=9 && m<10)
   {
    Serial.println("Marginal");
   }
   else
   {
    Serial.println("no network");
   }
}
/*
 *  
AT+CSQ?
+CSQ:18,99

AT+CSQ

+CSQ: 4,0

OK

Value RSSI dBm  Condition
2 -109  Marginal
3 -107  Marginal
4 -105  Marginal
5 -103  Marginal
6 -101  Marginal
7 -99 Marginal
8 -97 Marginal
9 -95 Marginal
10  -93 OK
11  -91 OK
12  -89 OK
13  -87 OK
14  -85 OK
15  -83 Good
16  -81 Good
17  -79 Good
18  -77 Good
19  -75 Good
20  -73 Excellent
21  -71 Excellent
22  -69 Excellent
23  -67 Excellent
24  -65 Excellent
25  -63 Excellent
26  -61 Excellent
27  -59 Excellent
28  -57 Excellent
29  -55 Excellent
30  -53 Excellent*/
 
