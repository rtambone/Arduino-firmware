//servo 

#include <Servo.h>
#include <ArCOM.h>

// Module setup 
unsigned long FirmwareVersion = 1; 
char moduleName[] = "ServoModule"; // name of the module for manual override UI and state machine assembler
ArCOM SerialCOM(Serial); 

// Variables
byte opCode = 0;
Servo servo1; 


void setup() 
{
  Serial.begin(115200);  // Set baud rate
  pinMode(5, OUTPUT); 
  servo1.attach(5); 
  servo1.write(90); // Set starting position 
}

void loop() 
{
  byte angle= SerialCOM.readByte(); // Read incoming byte
  angle= map(angle, 0, 255, 0, 180);
  servo1.write(angle); 
  delay(10);  // Wait 10 ms to allow servo moving 
}
