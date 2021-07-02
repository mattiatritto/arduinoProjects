int Valore_Fotoresistenza;                                                            //Variabile utilizzata per immagazzinare il valore della fotoresistenza.
int Valore_Basso_Sensore = 1023;                                                      //Valore basso.
int Valore_Alto_Sensore = 0;                                                          //Valore alto.

const int Pin_Led = 13;                                                               //Pin per il led.

void setup() 
{
  pinMode(Pin_Led, OUTPUT);                                                           //Imposta il pin 13 come OUTPUT.
  digitalWrite(Pin_Led, OUTPUT);                                                      //Accende il led.
  while (millis() < 5000)                                                             //Il ciclo while termina dopo 5 secondi dall'attivazione o resettaggio di Arduino.
  {
    Valore_Fotoresistenza = analogRead(A0);                                           //Legge ed immagazzina il valore della fotoresistenza nella variabile "Valore_Fotoresistenza".
    if (Valore_Fotoresistenza > Valore_Alto_Sensore)     
    {
      Valore_Alto_Sensore = Valore_Fotoresistenza;
      
    } if (Valore_Fotoresistenza < Valore_Basso_Sensore) 
    {
      Valore_Basso_Sensore = Valore_Fotoresistenza;
     
    }
  }
  digitalWrite(Pin_Led, LOW);                                                         //Dopo la calibrazione di 5 secondi il led si spegne.
}
 void loop() 
 {
  Valore_Fotoresistenza = analogRead(A0);                                             //Legge ed immagazzina il valore della fotoresistenza.
  int pitch =                                                                         //Il valore di pitch e' calcolato a partire dalla variabile "Valore_Fotoresistenza".
  map(Valore_Fotoresistenza,Valore_Basso_Sensore,Valore_Alto_Sensore, 50, 4000);      //Intervallo di frequenze generate da Arduino.
  Serial.print ("Valore Fotoresistenza: ");                   
  Serial.print (Valore_Fotoresistenza);                                               //Invio del valore della fotoresistenza al monitor seriale.

  tone(8,pitch,20);                                                                   //(Pin utilizzato, Variabile utilizzata, Tempo utilizzato).
  delay(10);                                                                          //La funzione delay e' usata per creare un po' di stacco tra le note.
  }
  
