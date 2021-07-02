char character;
const int LED = 13;


void setup() {
  
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  
  if(Serial.available()){
    
    character = Serial.read();
    Serial.print(character);
  }
  
  if(character == 'H' || character == 'h')
    digitalWrite(LED, HIGH);
  else if(character == 'L' || character == 'l')
    digitalWrite(LED, LOW);

  delay(10);
}
