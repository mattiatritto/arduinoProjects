#include <LiquidCrystal.h>                                                            //Importa la libreria LiquidCrystal.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                                                //Dichiarazione pin utilizzati dallo schermo LCD.

const int Pin_Interruttore = 6;                                                       //Pin 6 = Interruttore.
int Stato_Interruttore = 0;                                                           //Stato interruttore.
int Precedente_Stato_Interruttore = 0;                                                //Precedente stato interruttore.
int Risposta;                                                                         //Risposta della sfera.

void setup() 
{
  lcd.begin(16, 2);                                                                   //Specifica la larghezza dello schermo.
  pinMode(Pin_Interruttore, INPUT);                                                   //L'interruttore viene usato come input.
  lcd.print("Interroga");                                                             //Scrive sul display.                                                            
  lcd.setCursor(0, 1);                                                                //Posiziona il cursore in base alle coordinate.
  lcd.print("la sfera!");                                                             //Scrive sul display.
}

void loop()
{
  Stato_Interruttore = digitalRead(Pin_Interruttore);                                 //Lettura dello stato dell'interruttore.
  if (Stato_Interruttore != Precedente_Stato_Interruttore)                            //Se e' diverso il valore delle due variabili...
  {
    if (Stato_Interruttore == LOW)                                                    //Se e' LOW sceglie una risposta a caso.
    {
      Risposta = random(8);
      lcd.clear();                                                                    //Pulisce lo schermo.
      lcd.setCursor(0, 0);                                                            //Posiziona il cursore in base alle coordinate.
      lcd.print("La sfera dice:");                                                    //Scrive sul display.
      lcd.setCursor(0, 1);                                                            //Posiziona il cursore.
      switch(Risposta)                                                                //Esegue diversi pezzi di codice a seconda del parametro specificato.
    {
      case 0:
      lcd.print("Si.");
      break;
      case 1:
      lcd.print("Probabile.");
      break;
      case 2:
      lcd.print("Certo.");
      break;
      case 3:
      lcd.print("Bene.");
      break;
      case 4:
      lcd.print("Forse.");
      break;
      case 5:
      lcd.print("Chiedi ancora.");
      break;
      case 6:
      lcd.print("Improbabile.");
      break;
      case 7:
      lcd.print("No.");
      break;
    }
  }
}
Precedente_Stato_Interruttore = Stato_Interruttore;                                     //Assegna lo stesso valore alle due variabli per il loop successivo.
}
