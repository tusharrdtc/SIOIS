void sd_init()
{
  //digitalWrite(4, LOW);
  if (!SD.begin(sdcs)) {
    Serial.println("Card failed, or not present");
  }
  else
  {
  Serial.println("card initialized.");
  }
}
void sd()
{ 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) 
  {  
      dataFile.println(dataString);
      dataFile.close();
      // print to the serial port too:
      Serial.println(dataString);
    }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
      }
      //digitalWrite(4, HIGH);
}
