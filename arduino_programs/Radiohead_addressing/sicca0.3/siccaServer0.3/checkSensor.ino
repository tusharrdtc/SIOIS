//Function to check is connected or not
/*
   Function Name: check_sensor
   Input: none
   Output: sending sms to sms farmer
   Logic: called by relay() function when soil moisture sensor is disconnected
   Example Call: check_sensor()
*/

void checkSensor()
{
  Serial1.println("AT");                                    //ping command to gsm module
  readStrings(1000);
  Serial1.println("AT+CMGF=1");                            //text mode
  readStrings(1000);
  //Serial1.print("AT+CMGS=\"7066485916\"\r\n");             //enter number
  Serial1.print("AT+CMGS=\"");
  Serial1.print(mynumber);
  Serial1.println("\"");  //Send SMS message
  Serial1.println("Their is a issue of soil moisture sensor of the farmer! ");     //content of sms
  readStrings(1000);
  Serial1.write(26);
  readStrings(1000);
}
