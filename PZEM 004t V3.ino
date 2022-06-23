#include <PZEM004Tv30.h>
PZEM004Tv30 pzem(9, 8);
//Tx Rx
void setup() {
Serial.begin(9600);
}
void loop() {
float voltage = pzem.voltage();
Serial.print("Votage: ");
Serial.print(voltage); 
Serial.println(" V");

float current = pzem.current();
Serial.print("Current: ");
Serial.print(current); 
Serial.println(" A");

float power = pzem.power();
Serial.print("Power: ");
Serial.print(power); 
Serial.println(" W");


float frequency = pzem.frequency();
Serial.print("Frequency: "); 
Serial.print(frequency, 1);
Serial.println(" Hz");

float pf = pzem.pf();
Serial.print("PF: ");
Serial.println(pf);
Serial.println();

delay(2000);
}
