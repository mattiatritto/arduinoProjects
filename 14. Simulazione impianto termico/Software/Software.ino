#include <LiquidCrystal.h>                                                            
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);                                                

const int Pin_LED_Rosso = 9; 
const int Pin_LED_Verde = 8;
const int Pin_Temperatura = A0;                                                           
byte GradoCentigrado[8] = 
{
   B01110,
   B01010,
   B01110,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000
};

void setup() 
{
  Serial.begin(9600);                                                                  
  pinMode(Pin_LED_Rosso, OUTPUT);
  pinMode(Pin_LED_Verde, OUTPUT);
  pinMode(Pin_Temperatura, INPUT);
  lcd.begin(16, 2);
  lcd.createChar(0, GradoCentigrado);
  lcd.setCursor(0, 0);
  lcd.print("Inizializzazione");                                                                                                                         
  lcd.setCursor(0, 1);                                                                
  lcd.print("   termostato   ");  
  delay(4000);
  lcd.clear();
}

void loop()
{
  int Valore_sensore = analogRead(Pin_Temperatura);          
  Serial.print("Valore sensore: ");
  Serial.print(Valore_sensore);
  float Voltaggio =(Valore_sensore / 1024.0) * 5.0;         
  Serial.print("   Volt:  ");
  Serial.print(Voltaggio);
  Serial.print("   Gradi Celsius:  ");
  float Temperatura = (Voltaggio - .5)*100;               
  Serial.println(Temperatura);
  lcd.setCursor(0, 0);
  lcd.print("  T = ");
  lcd.print(Temperatura);
  lcd.print(" ");
  lcd.write((byte)0);
  lcd.print("C  ");
  lcd.setCursor(0, 1);
  lcd.print("  Caldaia: ");
  
  if (Temperatura < 18.0)                            
    {
      digitalWrite(Pin_LED_Rosso, LOW);
      digitalWrite(Pin_LED_Verde, HIGH);
      lcd.print(" ON");
    }
  else 
    {
      digitalWrite(Pin_LED_Rosso, HIGH);
      digitalWrite(Pin_LED_Verde, LOW);
      lcd.print("OFF");
    }
  delay(1500);                    
}
