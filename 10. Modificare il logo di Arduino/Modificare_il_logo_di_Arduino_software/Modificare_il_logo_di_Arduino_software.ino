void setup()
{
  Serial.begin(9600);                                             //Apre il monitor seriale.
}

void loop()
{
  Serial.write(analogRead(A0)/4);                                 //Scrive sul monitor seriale il valore del potenziometro.
  delay(1);                                                       //Pausa di un millesimo di secondo.
}


//Sul monitor seriale appaiono caratteri strani perche' Arduino invia byte "grezzi" e non caratteri ASCII.
