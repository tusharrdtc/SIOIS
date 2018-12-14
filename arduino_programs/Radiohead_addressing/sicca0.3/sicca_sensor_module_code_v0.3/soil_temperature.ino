
/*-----( Declare User-written Functions )-----*/
int printTemperature(DeviceAddress deviceAddress)
{

int tempC = sensors.getTempC(deviceAddress);

   if (tempC == -127.00)
   {
   Serial.print(F("Error getting temperature  "));
   }
//   else
//   {
//   Serial.print("C: ");
//   Serial.print(tempC);
//   Serial.print(" F: ");
//   Serial.print(DallasTemperature::toFahrenheit(tempC));
//   }
return tempC;
}// End printTemperature
//*********( THE END )*****
