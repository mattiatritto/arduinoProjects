#include <Servo.h>                                                      //Libreria servomotore.

Servo Servomotore;                                                      //Istanza della classe servo in una variabile chiamata oggetto.

int const Potenziometro = A0;                                          
int Potenziometro_Valore;                                               
int Angolo;                                                             

void setup() 
{
  Servomotore.attach(9);                                                //Dichiarare il pin a cui è collegato il servomotore.
  Serial.begin(9600);                                                   //Apre una comunicazione seriale con il computer.
}

void loop() 
{
  Potenziometro_Valore = analogRead(Potenziometro);                     //Legge ed immagazzina il valore del pin del potenziometro.
  Serial.print("\t Valore Potenziometro: ");
  Serial.print(Potenziometro_Valore);
  Angolo = map(Potenziometro_Valore, 0, 1023, 0, 179);                  //Trasforma i valori da 0 a 1023 in valori da 0 a 179
  Serial.print("\n Angolo: ");
  Serial.print(Angolo);

  Servomotore.write(Angolo);                                            //Il comando Servomotore.write fa muovere il servomotore nella posizione desiderata.
  delay(15);
}

