void setup() {
  //analogReference(EXTERNAL);
  
  
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
}
void loop() 
           {  int i;
              int j;
              int val;
  
              val = analogRead(A0); //connect sensor to Analog 0
              Serial.println(val); //print the value to serial port
              for(i=0;i<1;i++)
              {
              for(j=0;j<1;j++)
              {
              delay(1000);
               }
 
             }
           }
           
