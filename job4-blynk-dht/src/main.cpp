#include <Arduino.h>

#define BLYNK_TEMPLATE_ID "TMPL42-2f1Vf"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "XEANohQlOdSgInFfIm8vV7yKEglbU4P2"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Pak_Dukuh";
char pass[] = "Plotengan1234";

WidgetLED led1(V1);

BlynkTimer timer;

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue())
  {
    BLYNK_PRINT.print("LED1 off");
  }
  else
  {
    BLYNK_PRINT.print("LED1 off");
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  // Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  // Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(100L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
}
