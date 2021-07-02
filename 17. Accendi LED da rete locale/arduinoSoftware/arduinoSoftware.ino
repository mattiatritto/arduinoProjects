#include <Ethernet.h>
#include <SPI.h>
#include <String.h>


byte mac[] = {0xDE, 0xAD, 0xBE, 0xFE, 0xED, 0x34};
byte ip[] = {192, 168, 1, 120};
byte subnet[] = {255, 255, 255, 0};
byte gateway[] = {192, 168, 1, 1};


EthernetServer server(80);


int led = 7;
String listener;


void setup() {
  
  Ethernet.begin(mac, ip, gateway, subnet);
  pinMode(led, OUTPUT);
  listener = "";
}


void loop() {

 EthernetClient client = server.available();

 if(client) {

  while(client.connected()) {
    if(client.available()) {
      
      char character = client.read();
      listener.concat(character);

      if(character == '\n'){
        if(listener.indexOf("led=1") > 0)
          digitalWrite(led, HIGH);
        else
          digitalWrite(led, LOW);
    
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
      client.println("<html>");
      client.println("<head> <title>Controlla LED in rete</title> <link rel = 'shortcut icon' type = 'image/x-icon' href = 'https://cdn.pixabay.com/photo/2017/01/31/13/22/green-2023982_960_720.png'/> </head>");
      client.println("<body> <a href = '/?led=1'>Accendi</a> - <a href = '/?led=0'>Spegni</a> </body");
      client.println("</html");
      client.stop();
      listener = "";
      }
    }
  }
 }
}
