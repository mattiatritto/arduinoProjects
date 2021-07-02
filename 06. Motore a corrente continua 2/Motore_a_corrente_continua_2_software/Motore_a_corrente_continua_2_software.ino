const int Pin_1 = 2; 
const int Pin_2 = 3; 
const int Pin_Motore = 9;   
const int Pin_Interruttore_Direzione = 4;  
const int Stato_Interruttore_Accensione/Spegnimento = 5; 
const int Pin_Potenziometro = A0;  

int Stato_Interruttore_Accensione/Spegnimento = 0;  
int Previsione_Stato_Interruttore_Accensione/Spegnimento = 0; 
int Stato_Interruttore_Direzione = 0;  
int Previsione_Stato_Interruttore_Direzione = 0;  
int Stato_Motore = 0; 
int Velocità_Motore = 0; 
int Direzione_Motore = 1; 

void setup() 
{
  pinMode(Pin_Interruttore_Direzione, INPUT);
  pinMode(Stato_Interruttore_Accensione/Spegnimento, INPUT);
  pinMode(Pin_1, OUTPUT);
  pinMode(Pin_2, OUTPUT);
  pinMode(Pin_Motore, OUTPUT);
  digitalWrite(Pin_Motore, LOW);
}

void loop() 
{
  Stato_Interruttore_Accensione/Spegnimento = digitalRead(Stato_Interruttore_Accensione/Spegnimento);
  delay(1);
  Stato_Interruttore_Direzione = digitalRead(Pin_Interruttore_Direzione);
  Velocità_Motore = analogRead(Pin_Potenziometro) / 4;
  if (Stato_Interruttore_Accensione/Spegnimento != Previsione_ Stato_Interruttore_Accensione/Spegnimento) 
  {
    if (Stato_Interruttore_Accensione/Spegnimento == HIGH) 
    {
      Stato_Motore = !Stato_Motore;
    }
  }
  if (Stato_Interruttore_Direzione != Previsione_ Stato_Interruttore_Direzione) 
  {
   if (Stato_Interruttore_Direzione == HIGH) 
   {
      Direzione_Motore = !Direzione_Motore;
    }
  }
  if (Direzione_Motore == 1) 
  {
    digitalWrite(Pin_1, HIGH);
    digitalWrite(Pin_2, LOW);
  } 
  else 
  {
    digitalWrite(Pin_1, LOW);
    digitalWrite(Pin_2, HIGH);
  }
  if (Stato_Motore == 1) 
  {
    analogWrite(Pin_Motore, Velocità_Motore);
  } 
  else 
  {
    analogWrite(Pin_Motore, 0);
  }
  Previsione_Stato_Interruttore_Direzione = Stato_Interruttore_Direzione;
  Previsione_Stato_Interruttore_Accensione/Spegnimento = Stato_Interruttore_Accensione/Spegnimento;
}




