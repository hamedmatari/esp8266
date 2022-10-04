#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <webPage.h>

/* Put your SSID & Password */
const char* ssid = "NodeMCU";       
const char* password = "123456789"; 

ESP8266WebServer server(80);

bool LED = false;


void setup() {
  Serial.begin(9600);
  pinMode(D4, OUTPUT); 

  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.println("Access Point IP:");
  Serial.println(myIP);

  LED = false;
  digitalWrite(D4, LED);

  
  server.on("/", webContent);
  server.on("/led", ProcessButton);

  
  server.begin();
  //Serial.println("HTTP Server Started");
}

void loop() {
  server.handleClient();
}

void webContent() {
  Serial.println("sending web page");
  server.send(200, "text/html", PAGE_MAIN);

}


void ProcessButton() {
  LED = !LED;
  digitalWrite(D4, LED);
  Serial.println("Button :"); Serial.println(LED);
  server.send(200, "text/plain", "done"); //Send web page

  /*
    if (LED) {
    server.send(200, "text/plain", "1"); //Send web page
    }
    else {
    server.send(200, "text/plain", "0"); //Send web page
    }
  */

}