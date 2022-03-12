#include <Arduino.h>
#include <ESP8266WiFi.h>

// Put your SSID and password here
const char* ssid = "ESP_WIFI";
const char* password = "password";

void setup() {
  
  // Begin serial connection
  Serial.begin(115200);

  // Change mode to access point
  WiFi.mode(WIFI_AP);

  // Create access point
  WiFi.softAP(ssid, password);

  // Print status
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());
  
}

void loop() {
  
}