
double water;
unsigned long pulse_freq;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
  attachInterrupt(0, pulse, RISING); // Setup Interrupt
  
}

void loop ()
{
    water = .00225 * pulse_freq;
    Serial.print(water);
    Serial.println("L");
    delay(500);
  
}
void pulse() // Interrupt function

{
  pulse_freq++;
}
