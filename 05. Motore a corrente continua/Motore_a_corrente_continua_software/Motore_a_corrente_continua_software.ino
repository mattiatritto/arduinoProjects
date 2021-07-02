const int Pin_Pulsante = 2;                     //Dichiarazione pin del pulsante.
const int Pin_Motore = 9;                       //Dichiarazione pin del motore.
int Stato_Pulsante = 0;                         //Variabile per memorizzare il valore del pulsante.

void setup()
{
  pinMode(Pin_Motore, OUTPUT);                  //Pin motore OUTPUT.
  pinMode(Pin_Pulsante, INPUT);                 //Pin pulsante INPUT.
}

void loop()
{
  Stato_Pulsante = digitalRead(Pin_Pulsante);   //Controlla lo stato del pulsante.

  if (Stato_Pulsante == HIGH) 
  {                                             //Se il pulsante e' premuto, il pin viene impostato come HIGH.
    digitalWrite(Pin_Motore, HIGH);       
  }
  else 
  {
    digitalWrite(Pin_Motore, LOW);              //Se il pulsante non e' premuto, il pin viene impostato come LOW.
  } 
}

