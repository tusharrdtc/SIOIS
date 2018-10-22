#include <AFMotor.h>        // Headerfile for the L293D sheild 

AF_DCMotor motor(1);       // DC Gear Motor is connected to motor port 1 

void setup() 
{
  motor.setSpeed(200);    // DC Gear Motor speed is set within range of (0 - 255)
  motor.run(RELEASE);     // DC Gear Motor is set in STOP action 
}

void loop() 
{

  motor.run(FORWARD);     // DC Gear Motor is set for Forward Motion
  
 }
