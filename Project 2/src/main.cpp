#include <Arduino.h>

#define BLYNK_TEMPLATE_ID "TMPLtyWkmL4t"
#define BLYNK_DEVICE_NAME "RELAY"
#define BLYNK_AUTH_TOKEN "NCmIINdxQUY4NlP47npjUKzmR9i0ECLX"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char SSID[] = "Pak_Dukuh";
char PASS[] = "Plotengan1234";

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASS);
}
void loop()
{
  Blynk.run();
}