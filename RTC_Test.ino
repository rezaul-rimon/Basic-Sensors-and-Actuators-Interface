
#include <Wire.h>
#include <RTC.h>

static DS3231 RTC;

void setup()
{
	Serial.begin(9600);
	RTC.begin();
  
//    RTC.setHourMode(CLOCK_H24);
//    RTC.setDateTime(__DATE__, __TIME__);
//    RTC.startClock();	

  //RTC.setYear(2022);
  
}

void loop()
{
  int dt=RTC.getDay();
  int mt=RTC.getMonth();
  int yr=RTC.getYear()-2000;
  int hr=RTC.getHours();
  int mn=RTC.getMinutes();
  int sc=RTC.getSeconds();

    String d,t;
    d=String(dt)+"/"+String(mt)+"/"+String(yr);
    t=String(hr)+":"+String(mn)+":"+String(sc);
    Serial.print(d);
    Serial.print(",");
    Serial.println(t);

    delay(1000);

}
