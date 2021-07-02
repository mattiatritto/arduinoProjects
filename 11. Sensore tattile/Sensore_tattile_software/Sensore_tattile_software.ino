#include <CapacitiveSensor.h>                                                                           //Importa la libreria CapacitiveSensor.
CapacitiveSensor Sensore_Tattile = CapacitiveSensor(4, 2);                                              //Crea un'istanza della libreria e dice i pin necessari.

int Soglia_Accensione_Led = 30;                                                                         //Soglia accensione led.
const int Pin_Led = 12;                                                                                 //Pin del led.

void setup() 
{
  Serial.begin(9600);                                                                                   //Apre il monitor seriale.
  pinMode(Pin_Led, OUTPUT);                                                                             //Definisce il pin del led come OUTPUT.
}

void loop() 
{
  long Valore_Sensore = Sensore_Tattile.capacitiveSensor(30);
  Serial.print("Valore sensore: ")                                                                      //Immagazzina nella variabile "Valore_Sensore" il valore del sensore. Legge 30 campioni.
  Serial.println(Valore_Sensore);                                                                       //Stampa sul monitor seriale il valore del sensore.
  if(Valore_Sensore > Soglia_Accensione_Led)
  {
    digitalWrite(Pin_Led, HIGH);
  }
else
{
  digitalWrite(Pin_Led, LOW);
}
delay(10);
}
