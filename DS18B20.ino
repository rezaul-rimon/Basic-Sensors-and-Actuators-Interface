//#include <OneWire.h>
//#include <DallasTemperature.h>
#include "DHT.h"
#include <PZEM004Tv30.h>

//#define DS18 9
#define DHTPIN1 8
#define DHTPIN2 10

#define DHTTYPE DHT22

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

//OneWire oneWire(DS18); 
//DallasTemperature deep(&oneWire);

PZEM004Tv30 pzem(12, 11);

int sw=0;
int t=1;
int sc=0;
int loopc = 0;

void setup(void)
{
  Serial.begin(9600);
  //deep.begin();
  dht1.begin();
  dht2.begin();

  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

}

void loop(void)
{ 
  //deep.requestTemperatures();
  //float tempC = deep.getTempCByIndex(0);
  float t1 = dht1.readTemperature();
  float t2 = dht2.readTemperature();

  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float pf = pzem.pf();
  float frequency = pzem.frequency();

  if(digitalRead(5)==0)
  {
    sw = 1;
  }
  else if(digitalRead(5)==1) 
  { 
    sw = 0; 
    }

if((digitalRead(5)==0) && (t==1))
  {
    t=0;
    sc=1;
  }
  if(digitalRead(5)==1)
  {
   t=1;
  }
  
  Serial.print(t1);
  Serial.print(",");
  Serial.print(t2);
  Serial.print(",");

  Serial.print(voltage, 0);
  Serial.print(",");
  Serial.print(current);
  Serial.print(",");
  Serial.print(power);
  Serial.print(",");
  Serial.print(pf);
  Serial.print(",");
  Serial.print(frequency, 0);
  Serial.print(",");
  Serial.print(sw);
  Serial.print(",");
  Serial.println(sc);

  loopc++;
  if(loopc>=10)
  {
    loopc=0;
    sc=0;
  }
  delay(1000);
}
