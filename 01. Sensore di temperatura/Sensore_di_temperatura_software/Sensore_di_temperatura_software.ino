const int Sensore_Pin = A0;                               //Ingresso analogico.
const float Temperatura_di_base = 20.0;                   //Temperatura di riferimento.

void setup()
{
  Serial.begin(9600);                                     //Apri il monitor seriale alla velocita' di 9600 bit al secondo.
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {                                                       //Utilizziamo il ciclo for per impostare i pin velocemente.
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop()
{
  int Valore_sensore = analogRead(Sensore_Pin);           //Lettura ingresso analogico.
  Serial.print("Valore sensore: ");
  Serial.print(Valore_sensore);

  float Voltaggio =(Valore_sensore/1024.0) * 5.0;         //Conversione della lettura ADC in voltaggio.
  Serial.print("   Volts:  ");
  Serial.print(Voltaggio);
  Serial.print("   Gradi Celsius:  ");
  float Temperatura = (Voltaggio - .5)*100;               //Conversione del voltaggio in temperatura.
  Serial.println(Temperatura);

  if(Temperatura < Temperatura_di_base) 
  {                                                       //Accensione dei led in base alla temperatura.
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(Temperatura >= Temperatura_di_base+2 && Temperatura < Temperatura_di_base+4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(Temperatura >= Temperatura_di_base+4 && Temperatura < Temperatura_di_base+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(Temperatura >= Temperatura_di_base+6 && Temperatura < Temperatura_di_base+8)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}

