const int Interruttore_Pin = 8;                                                                       //Pin interruttore di inclinazione.
unsigned long Tempo_Ultimo_Led = 0;                                                                   //Variabile che memorizza il momento in cui e' stato modificato l'ultimo led.
int Stato_Interruttore = 0;                                                                           //Memorizza lo stato dell'interruttore.
int Precedente_Stato_Interruttore = 0;                                                                //Memorizza il precedente stato dell'interruttore.

int Led = 2;                                                                                          //Variabile usata per verificare quale led e' il prossimo ad accendersi.
long Intervallo_Di_Tempo = 3000;                                                                      //Intervallo di accensione di ogni led.

void setup()
{
  for(int x = 2;x<8;x++)                                                                               //Dichiara i pin OUTPUT con un ciclo for.
  {
    pinMode(x, OUTPUT);
  }
  pinMode(Interruttore_Pin, INPUT);
}

void loop()
{
  unsigned long Tempo_Attuale = millis();                                                               //Cronometra il tempo da quando Arduino si e' acceso o resettato.
  if(Tempo_Attuale - Tempo_Ultimo_Led > Intervallo_Di_Tempo)                                            //Controlla se e' passato abbastanza tempo per accendere il led successivo. 
  {
    Tempo_Ultimo_Led = Tempo_Attuale;                                                                   //Se si' imposta la prima variabile al valore della seconda.
    digitalWrite(Led, HIGH);
    Led++;                                                                                              //Incrementa la variabile Led.
    
  if(Led == 7)                                                                                          //Controlla se il led sul pin 7 e' acceso.
  {
    }
  }
  Stato_Interruttore = digitalRead(Interruttore_Pin);                                                   //Memorizza lo stato attuale dell'interruttore.
    

  if(Stato_Interruttore != Precedente_Stato_Interruttore)                                               //Se lo stato dell'interruttore e' diverso dal precedente: 
  {
    for(int x = 2; x<8;x++){                                                                            //Spegni tutti i led.
      digitalWrite(x, LOW);
    }
    Led = 2;
    Tempo_Ultimo_Led = Tempo_Attuale;
  }
  Precedente_Stato_Interruttore = Stato_Interruttore;
}




