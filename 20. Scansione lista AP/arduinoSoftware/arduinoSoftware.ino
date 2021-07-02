#include "ESP8266WiFi.h"


void setup() {
  
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);                                                                    //Setta il Wi-Fi su "station mode"
  WiFi.disconnect();                                                                      //Si disconnette da un AP collegato in precedenza
  
  delay(100);
  Serial.println("SETUP DONE!");
}


void loop() {

  int n = WiFi.scanNetworks();                                                            //Il metodo scanNetworks restituisce il numero di reti trovate
  Serial.println("SCAN DONE!");
  
  if (n == 0)                                                                             //Se il numero di reti è uguale a 0 non è stata trovata nessuna rete
    Serial.println("NO NETWORKS FOUND!");
    
  else
  {
    Serial.print(n);
    Serial.println(" NETWORKS FOUND:");
    
    for (int i = 0; i < n; i++)
    {
                                      
      Serial.print(i+1);                                                              
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));                                                         //Stampa il SSID (nome) dell'AP
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));                                                         //Stampa la potenza del segnale in decibel
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");                  //Se l'AP è protetto da password stampa "*"
      delay(10);
    }
  }
  
  Serial.println("");

  delay(5000);                                                                            //Aspetta 5 secondi per la prossima scansione
}
