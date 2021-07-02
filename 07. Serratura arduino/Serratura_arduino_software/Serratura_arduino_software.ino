#include <Servo.h>                                                                              //Importa la libreria Servo.
Servo Servomotore;                                                                              //Crea un'istanza per utilizzare il motore.

const int Piezo = A0;                                                                           //Pin piezo.
const int Pin_Interruttore = 2;                                                                 //Pin interruttore.
const int Led_Giallo = 3;                                                                       //Led giallo.
const int Led_Verde = 4;                                                                        //Led verde.
const int Led_Rosso = 5;                                                                        //Led rosso.

int Valore_Vibrazione;                                                                          //Valore vibrazione.
int Valore_Pulsante;                                                                            //Valore pulsante.

const int Vibrazione_Bassa = 10;                                                                //Vibrazione bassa.
const int Vibrazione_Alta = 100;                                                                //Vibrazione alta.

boolean Blocco = false;                                                                         //Blocco.
int Numero_Di_Vibrazioni = 0;                                                                   //Numero di vibrazioni.

void setup()
{
  Servomotore.attach(9);                                                                        //Attacca il servomotore al pin 9.
  pinMode(Led_Giallo, OUTPUT);
  pinMode(Led_Rosso, OUTPUT);
  pinMode(Led_Verde, OUTPUT);
  pinMode(Pin_Interruttore, INPUT);
  Serial.begin(9600);                                                                           //Apre il monitor seriale.
  digitalWrite(Led_Verde, HIGH);
  Servomotore.write(0);                                                                         //Muove il servomotore a 0°.
  Serial.println("La serratura e' sbloccata!");
}

void loop()
{
  if(Blocco == false) 
  {
    Valore_Pulsante = digitalRead(Pin_Interruttore);                                            //Immagazzina il valore dell'interruttore nella variabile.
    if(Valore_Pulsante == HIGH)
    {
      Blocco = true;
      digitalWrite(Led_Verde, LOW);
      digitalWrite(Led_Rosso, HIGH);
      Servomotore.write(180);
      Serial.println("La serratura e' bloccata!");
      delay (1000);
    }
  }
  if(Blocco == true)
  {
    Valore_Vibrazione = analogRead(Piezo);
    if(Numero_Di_Vibrazioni < 3 && Valore_Vibrazione >0)
    {
      if(checkForKnock(Valore_Vibrazione) == true)
      {
        Numero_Di_Vibrazioni++;
      }
      Serial.print(3-Numero_Di_Vibrazioni);
      Serial.println(" vibrazioni per sbloccare!");
    }
    if(Numero_Di_Vibrazioni >= 3)
    {
      Blocco = false;
      Servomotore.write(0);
      delay(20);
      digitalWrite(Led_Verde, HIGH);
      digitalWrite(Led_Rosso, LOW);
      Serial.println("La serratura e' sbloccata!");
    }
  }
}
boolean checkForKnock(int Valore)
{
  if(Valore > Vibrazione_Bassa && Valore < Vibrazione_Alta)
  {
    digitalWrite(Led_Giallo, HIGH);
    delay(50);
    digitalWrite(Led_Giallo, LOW);
    Serial.print("Vibrazione valida ");
    Serial.println(Valore);
    return true;
  }
  else
  {
    Serial.print("Vibrazione non valida ");
    Serial.println(Valore);
    return false;
  }
}

