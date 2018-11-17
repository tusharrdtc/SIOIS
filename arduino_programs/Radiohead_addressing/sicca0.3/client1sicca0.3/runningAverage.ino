//Function for calculating average
/*FUNCITON NAME: runningAverage
 * INPUT:   analog values 
 * OUTPUT:  average of analog values
 * LOGIC: Stores 10 readings in an array & calculates the average
 * EXAMPLE CALL:  average()
 */
int average(int pin) {

  burn8Readings(pin);
  int readings[10];      // the readings from the analog input
  int total = 0;                  // the running total

  for(int readIndex=0; readIndex<10; readIndex++)
  {
  // read from the sensor:
  readings[readIndex] = analogRead(pin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  delay(100); 
  }
  
   // calculate the average:
   avgVal = total / 10;

   return avgVal;
   
  }
