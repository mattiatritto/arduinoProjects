int value;


void setup() {
  
  for (int i = 3; i < 7; i++)             //Inizializza i pin dal 3 al 6 come INPUT
    pinMode(i, INPUT);

  for (int i = 8; i < 12; i++)            //Inizializza i pin dal 8 al 11 come OUTPUT
    pinMode(i, OUTPUT);

  Serial.begin(9600);                     //Inizia la comunicazione seriale a 9600 baud
}


void loop() {
  
  for (int i = 3; i < 7; i++){            //Dal pin 3 al pin 6...
    
    value = digitalRead(i);               //Leggi il valore e salvalo nella variabile

    if (value == 1)                       //Se il valore è uguale a 1...
      digitalWrite(i+5, HIGH);            //Manda 5V al LED corrispondente
    else 
      digitalWrite(i+5, LOW);             //Manda 0V al LED corrispondente
  
    Serial.println(value);                //Scrive sulla seriale il valore
  }

  Serial.println(char(10));               //Vai a capo

  delay(1000);                            //Aspetta 1 millisecondo
}
