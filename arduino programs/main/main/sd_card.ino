/*int rtd(){
  double r2=94;
  double b;                           //analog output
  double r;                           //rtd resistance at t degree celsius
  double r0 = 109;                 //resistance of PT100 at 274 degree kelvin 
  double t0 = 20;                     // 0 degree celsius
  float alpha = 0.00375;              //temp coefficient at 0 degree celsius of PT100
  double t;                           //current temperature
  b=analogRead(0);
  r = r2 * ( b / (1024 - b));
  t = ((r-r0)/(r0*alpha )) + t0 ;
  Serial.print(t);
  Serial.print("        ");
}*/
