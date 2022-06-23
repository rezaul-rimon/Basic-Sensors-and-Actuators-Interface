unsigned long int sum=0;
int arr[100];

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  sum=0;
  for(int i=0; i<100; i++)
  {
    int value = analogRead(A0);
    sum=sum+value;
    arr[i]=value;
    delay(5);
  }

////sorting
  for(int i=0; i<100; i++)
  {
    for(int j=0; j<100; j++)
    {
     if(arr[j]>arr[j+1])
     {
      int tmp = arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=tmp;
     }
  }
  }
////

  float ave=sum/100;
  float ph=(ave/73.0);
  
  if(ph < 6.5) ph=14.0-ph;
  else if(ph > 7.7) ph=ph-7.0;

  float median=arr[50];
  float phmedian = median/73.0;

  if(phmedian < 6.5) phmedian=14.0-phmedian;
  else if(phmedian > 7.7) phmedian=phmedian-7.0;

  Serial.print(ave);
  Serial.print(" ");
  Serial.println(ph);
  Serial.print(median);
  Serial.print(" ");
  Serial.println(phmedian);
  Serial.println();
  
}
