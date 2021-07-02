int Pulsanti[6] = {2};                        //Array di 6 numeri interi.       //Ad un numero intero assegno il valore 2.

int Note[] = {262,294,330,349};               //Array di quattro note musicali che corrispondono alle frequenze del DO, RE, MI, FA.

void setup()
{                         
  Serial.begin(9600);                         //Inizia comunicazione seriale con il computer.
}

void loop() 
{
  int Valore_Pin_A0 = analogRead(A0);         //Dichiarazione variabile locale per memorizzare il valore del pin A0.
  
  Serial.println(Valore_Pin_A0);              //Invio dei valori al computer.

  if(Valore_Pin_A0 == 1023)                   //Assegnamento dei valori a toni diversi.
  {                                           
    tone(8, Note[0]);
  }
  else if(Valore_Pin_A0 >= 990 && Valore_Pin_A0 <= 1010)
  {
    tone(8, Note[1]);
  }
  else if(Valore_Pin_A0 >= 505 && Valore_Pin_A0 <= 515)
  {
    tone(8, Note[2]);
  }
  else if(Valore_Pin_A0 >= 5 && Valore_Pin_A0 <= 10)
  {
    tone(8, Note[3]);
  }
  else
  {
    noTone(8);                              	//La funzione noTone e' usata quando nessun pulsante viene premuto e quindi il piezo non suoner�.
  }
}

