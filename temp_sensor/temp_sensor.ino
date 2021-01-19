const int sensorPin = A0;


void setup() 
{
 Serial.begin(9600); 

}

void loop() 
{
int sensorVal = analogRead(sensorPin);
Serial.print("Sensor value: ");
Serial.print(sensorVal);

float voltage = (sensorVal/1024.0)*5;
Serial.print("Volts: ");
Serial.print(voltage);

float temperature = (voltage - .5)*100;
Serial.print("degrees: ");
Serial.print(temperature);

delay(1000*30);
}
