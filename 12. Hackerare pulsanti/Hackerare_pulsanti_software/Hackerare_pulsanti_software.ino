const int Fotoaccoppiatore = 2; 

void setup() 
{
  pinMode(Fotoaccoppiatore, OUTPUT);
}

void loop() 
{
  digitalWrite(Fotoaccoppiatore, HIGH);  
  delay(15);
  digitalWrite(Fotoaccoppiatore, LOW);  
  delay(21000);                
}


