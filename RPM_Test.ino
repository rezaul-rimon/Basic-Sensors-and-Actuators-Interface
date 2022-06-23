
#define sensor A3
int count=0, rmp=0, tt=1;

void Rpm()
{
  count=0;
  unsigned long pre=millis();
  while((millis()-pre) < 1000)
  {
    if((digitalRead(sensor)==0) && tt == 1)
      {
        count++;
        tt=0;
      }
      if(digitalRead(sensor)==1)
      {
        tt=1;
      }
      delay(1);
  }
  rmp=(count/3)*60;
}

void setup()

{
Serial.begin(9600);
pinMode(sensor, INPUT);

}

void loop()
{


  Rpm();
  Serial.println(rmp);
  
}
