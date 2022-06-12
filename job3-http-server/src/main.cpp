// Web server using nodemcu ESP8266

#include <Arduino.h>
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

#include "index.h"

ESP8266WebServer server(80);

void handleOtherPath()
{
  server.send(404, "text / plain", "File NOT Found !");
}

void handleRootPath()
{
  server.send(200, "text/html", " SEMANGAT BELAJAR <b>INFORMATIKA UNY </b>!");
}

// LED Switch handler
void handleLedParams()
{
  String ledState = server.arg("led");

  if (ledState == "on")
  {
    digitalWrite(D6, HIGH);
  }
  else
  {
    digitalWrite(D6, LOW);
  }

  server.send(200, "text/html", "LED is <b>" + ledState + "</b>.");
}

void setup()
{
  Serial.begin(115200);
  pinMode(D6, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin("Pak_Dukuh", "Plotengan1234");

  while (WiFi.status() != WL_CONNECTED)
  { // Wait for connection
    delay(500);
    Serial.println("Waiting to connect...");
  }

  Serial.print("");
  Serial.print("WiFi Connected, IP address: ");
  Serial.println(WiFi.localIP()); // Print the local IP

  server.on("/other", handleOtherPath);
  server.on("/index.html", handleRootPath);
  server.on("/", handleRootPath);

  // Switch
  server.on("/sw", handleLedParams);

  server.begin(); // Start the server
  Serial.println("HTTP Server Started.");
}

void loop()
{
  server.handleClient(); // Handling of incoming requests
}