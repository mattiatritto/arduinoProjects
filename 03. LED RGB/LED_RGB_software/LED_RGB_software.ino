const int Pin_Led_Verde = 9;
const int Pin_Led_Rosso = 11;
const int Pin_Led_Blu = 10;

const int Pin_Sensore_Rosso = A0;
const int Pin_Sensore_Verde = A1;
const int Pin_Sensore_Blu = A2;

int Valore_Rosso = 0;
int Valore_Verde = 0;
int Valore_Blu = 0;

int Valore_Sensore_Rosso = 0;
int Valore_Sensore_Verde = 0;
int Valore_Sensore_Blu = 0;

void setup()
{
  Serial.begin(9600);                                                     //Apre la comunicazione seriale con il computer.
  pinMode(Pin_Led_Verde, OUTPUT);
  pinMode(Pin_Led_Rosso, OUTPUT);
  pinMode(Pin_Led_Blu, OUTPUT);
}

void loop()
{
  Valore_Sensore_Rosso = analogRead(Pin_Sensore_Rosso);
  delay(5);
  Valore_Sensore_Verde = analogRead(Pin_Sensore_Verde);
  delay(5);
  Valore_Sensore_Blu = analogRead(Pin_Sensore_Blu);

  Valore_Rosso = Valore_Sensore_Rosso/4;                                  //Divide per quattro la lettura dei sensori.
  Valore_Verde = Valore_Sensore_Verde/4;
  Valore_Blu = Valore_Sensore_Blu/4;

  Serial.print("\n Valori\t Rosso: ");
  Serial.print(Valore_Rosso);
  Serial.print("\t Verde: ");
  Serial.print(Valore_Verde);
  Serial.print("\t Blu: ");
  Serial.print(Valore_Blu);

  analogWrite(Pin_Led_Rosso, Valore_Rosso);
  analogWrite(Pin_Led_Verde, Valore_Verde);
  analogWrite(Pin_Led_Blu, Valore_Blu);
  }

