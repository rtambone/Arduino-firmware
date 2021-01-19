//valve driver for letting air flow while valves are closed

#include <ArCOM.h>

// Module setup 
unsigned long FirmwareVersion = 1; 
char moduleName[] = "AirValveModule"; // name of the module for manual override UI and state machine assembler
ArCOM SerialCOM(Serial1); 

// Variables
byte opCode = 0;

void setup() 
{
  Serial1.begin(1312500);  // Set baud rate
  pinMode(5, OUTPUT); // Set the pin as output 
  digitalWrite(5, LOW); // Set pin to low (0V) that is set the valve close 
}

void loop() 
{
  if (Serial1.available()){ // if a byte arrived from the state maschine
     opCode= Serial1.readBytes();
     switch (opCode){
       case 'O':  // Open valve
         digitalWrite(5, HIGH);
       break;
       case 'C': // Close valve
         digitalWrite(5, LOW);
       break;
     } 
  }
}
