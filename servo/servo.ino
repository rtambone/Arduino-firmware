//servo 
#include <Servo.h>

Servo servo1; 

void setup() 
{
  servo1.attach(5);
  servo1.write(90);
}

void loop() 
{
  int angle= analogRead(0); 
  angle= map(angle, 0, 1023, 0, 180);
  servo1.write(angle);
  delay(15);
}
