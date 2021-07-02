#include <SPI.h>
#include <Ethernet.h>


byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};                                                    //Inizializza l'indirizzo fisico del server Arduino

IPAddress ip(192, 168, 1, 120);                                                                       //Inizializza il suo IP locale
IPAddress DNS(192, 168, 1, 1);                                                                        //Inizializza il suo DNS (in questo caso l'IP router)
IPAddress gateway(192, 168, 1, 1);                                                                    //Inizializza il gateway (IP del router)
IPAddress subnet(255, 255, 0, 0);                                                                     //Inizializza la maschera di rete                                            

EthernetServer server(23);                                                                            //Inizializza un server Telnet sulla porta 23
EthernetClient clients[4];                                                                            //Definisce la quantità di client che può gestire questo server (4)


void setup() {
  
  Ethernet.begin(mac, ip, DNS, gateway, subnet);                                                      //Viene inizializzata la shield Ethernet in base ai parametri specificati
  server.begin();                                                                                     //Inizializza il server                                          
  Serial.begin(9600);                                                                                 //Inizia la comunicazione seriale a 9600 baud
  Serial.print("Indirizzo del server: ");                                                             //Stampa sul monitor l'IP del server Arduino
  Serial.println(Ethernet.localIP());
}


void loop() {
  
  EthernetClient client = server.available();

  if (client) {                                                                                       //Se è presente un nuovo client...

    boolean newClient = true;
    
    for (byte i = 0; i < 4; i++)                                                                      //Controlla se questo client fa riferimento a uno dei client già esistenti
      if (clients[i] == client) {
        newClient = false;
        break;
      }


    if (newClient) {                                                                                  //Se il client è nuovo...                                          
                                                                  
      for (byte i = 0; i < 4; i++)                                                                    //Controlla quale dei clienti esistenti può essere sovrascritto
      
        if (!clients[i] && clients[i] != client) {
          
          clients[i] = client;                                                                                                                                     
          client.flush();                                                                             //Pulisci il buffer in input
          Serial.println("Abbiamo un nuovo client!");                                                 //"Abbiamo un nuovo client!"
          client.print("Ciao, client numero ");                                                       //"Ciao client numero ... "                    
          client.print(i+1);
          client.print("!");
          client.println();
          break;                                                                                      
        }
    }


    if (client.available() > 0) {                                                                     //Se il client è in linea...
      
      char thisChar = client.read();                                                                  //Leggi i byte provenienti dal client
      
      for (byte i = 0; i < 4; i++)                                                                    //Stampa i byte letti a tutti i client connessi
        if (clients[i] && (clients[i] != client)) 
          clients[i].write(thisChar);
      
      Serial.write(thisChar);                                                                         //Stampa i byte letti anche sul server tramite la seriale
    }
  }

  
  for (byte i = 0; i < 4; i++)                                                                        //Se uno dei client non è connesso, viene disconnesso dal server
    if (!clients[i].connected()) 
      clients[i].stop();
}
