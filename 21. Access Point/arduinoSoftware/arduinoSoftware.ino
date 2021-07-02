#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>


const char *ssid = "Access Point";
const char *password = "12345678";

ESP8266WebServer server(80);


void handleRoot() {
  
	server.send(200, "text/html", "<h1>You are connected!</h1>");
}


void setup() {
  
	delay(1000);
	Serial.begin(9600);
	Serial.println();
 
	Serial.print("Configuring AP...");
	WiFi.softAP(ssid, password);                                                              //Se si vuole un AP senza password basta togliere il parametro "password"

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("Access Point IP address: ");
	Serial.println(myIP);
 
	server.on("/", handleRoot);
	server.begin();
	Serial.println("HTTP server started!");
}


void loop() {
  
	server.handleClient();
}
