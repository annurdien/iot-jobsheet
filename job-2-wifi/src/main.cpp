#include <Arduino.h>
#include <ESP8266WiFi.h>

// Put your SSID and password here
const char *ssid = "ESP_WIFI";
const char *password = "password";

void setup()
{

  // Begin serial connection
  Serial.begin(115200);

  // Change mode to access point
  WiFi.mode(WIFI_AP);

  // Create access point
  WiFi.softAP(ssid, password);

  // Print status
  Serial.print("AP SSID: ");
  Serial.println(ssid);
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop()
{
}

// // Set the SSID and password of your WiFi network
// const char *ssid = "Pak_Dukuh";
// const char *password = "Plotengan1234";

// void setup()
// {
//   // begin serial connection
//   Serial.begin(115200);

//   // connect to WiFi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }

//   // print the IP address
//   Serial.println("");
//   Serial.print("Connected to ");
//   Serial.println(ssid);
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop()
// {
// }
