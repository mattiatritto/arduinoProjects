#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


char ssid[] = "Home Wi-Fi Tritto";
char pass[] = "3FvEpNUr0f3G";


unsigned int localPort = 2390;                                                                //Porta locale per ricevere pacchetti UDP


/*IPAddress timeServer(129, 6, 15, 28);                                                       //time.nist.gov NTP server*/
IPAddress timeServerIP;                                                                       //time.nist.gov NTP server address
const char* ntpServerName = "time.nist.gov";


const int NTP_PACKET_SIZE = 48;                                                               //L'orario NTP è nei primi 48 byte del messaggio
byte packetBuffer[NTP_PACKET_SIZE];                                                           //Buffer contenente i pacchetti inviati e ricevuti


WiFiUDP udp;                                                                                  //Un'istanza UDP per permetterci di mandare e ricevere pacchetti UDP


void setup()
{
  
  Serial.begin(9600);
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);                                                                     //Si collega alla rete Wi-Fi specificata
  
  while (WiFi.status() != WL_CONNECTED) {                                                     //Finchè non si connette ad una rete Wi-Fi...
    
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println("IP address: ");                                                             //Stampa l'indirizzo IP locale
  Serial.println(WiFi.localIP());

  Serial.println("\nStarting UDP comunication");                                              //Inizializza la comunicazione UDP
  udp.begin(localPort);
  Serial.print("Local port: ");                                                               //Stampa la porta locale utilizzata
  Serial.println(udp.localPort());
}


void loop()
{
  
  WiFi.hostByName(ntpServerName, timeServerIP);                                               
  sendNTPpacket(timeServerIP);                                                                //Trasmetti un pacchetto NTP all'indirizzo IP specificato
  
  delay(1000);                                                                                //Aspetta un secondo per vedere se risponde
  
  int cb = udp.parsePacket();                                                                 //Memorizza in una variabile la lunghezza del pacchetto inviato
  
  if (!cb)                                                                                    //Se non è arrivato nessun pacchetto stampa il seguente messaggio:
    Serial.println("No packet yet!\n");                                                         
  
  else {                                                                                      //Altrimenti abbiamo ricevuto un pacchetto, ora leggi i dati da esso
    
    Serial.print("Packet received, length = ");
    Serial.println(cb);
    
    udp.read(packetBuffer, NTP_PACKET_SIZE);                                                  //Leggi il pacchetto sul buffer

    //Il tempo inizia dal byte numero 40 ed è lungo 4 byte

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);                        //Estraiamo le due word
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    
    unsigned long secsSince1900 = highWord << 16 | lowWord;                                   //Combina le due word in un intero (i secondi trascorsi dal 1 Gennaio 1900) e lo stampa
    Serial.print("\nSeconds since Jan 1 1900 = " );
    Serial.println(secsSince1900);

    
    Serial.print("\nUnix time = ");                                                           //Ora calcoliamo Unix time
    
    const unsigned long seventyYears = 2208988800UL;                                          //Unix time inizia il 1 Gennaio 1970. In secondi è 2208988800
    unsigned long epoch = secsSince1900 - seventyYears;                                       //Sottraiamo 70 anni
    Serial.println(epoch);                                                                    //Stampa Unix time

    //Stampiamo l'ora, i minuti e i secondi
    
    Serial.print("\nThe UTC time is ");                                                       //UTC è l'orario al meridiano di Greenwich (GMT)
    Serial.print((epoch % 86400L) / 3600);                                                    //Stampa l'ora (86400 sono i secondi contenuti in un giorno)
    Serial.print(':');
    
    if (((epoch % 3600) / 60) < 10)                                                           //Nei primi 10 minuti di ogni ora vogliamo prima lo 0
      Serial.print('0');
    Serial.print((epoch % 3600) / 60);                                                        //Stampa i minuti (3600 sono i secondi contenuti in un'ora)
    Serial.print(':');
    
    if ((epoch % 60) < 10)                                                                    //Nei primi 10 secondi di ogni minuto vogliamo prima lo 0
      Serial.print('0');
    Serial.println(epoch % 60);                                                               //Stampa i secondi (60 sono i secondi contenuti in un minuto)
  }
                                                                                              //Aspetta 10 secondi prima di richiedere l'orario
  delay(10000);
}


unsigned long sendNTPpacket(IPAddress & address)                                              //Manda una richiesta NTP al time server all'indirizzo passato come parametro
{
  
  Serial.println("\nSending NTP packet...");
  
  memset(packetBuffer, 0, NTP_PACKET_SIZE);                                                   //Setta tutti i byte del buffer a 0
  
  //Inizializza i valori richiesti per formare una richiesta NTP
  
  packetBuffer[0] = 0b11100011;                                                               
  packetBuffer[1] = 0;                                                                        
  packetBuffer[2] = 6;                                                                        
  packetBuffer[3] = 0xEC;                                                                     
  
                                                                                              //8 byte a 0
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  //Tutti i campi NTP sono stati settati, ora possiamo inviare una richiesta al time server
  
  udp.beginPacket(address, 123);                                                              //Le richieste NTP devono essere effettuate sulla porta 123
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}
