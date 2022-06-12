#include <Arduino.h>
#include <ESP8266WiFi.h>

#define LED_Pin 4
#define BUTTON_Pin 16

const char *ssid = "Pak_Dukuh";
const char *password = "Plotengan1234";
const char *host = "maker.ifttt.com";
const char *eventName = "update_tweet";
const char *key = "gJRj8RzkQlyB6qLDlYKGZpsR-WChvLIbvLa2jmbC8NK";

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  int timeout = 10 * 4;
  while (WiFi.status() != WL_CONNECTED && (timeout-- > 0))

  {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Failed to connect, going back to sleep");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  WiFiClient client;
  const int httpPort = 80;

  if (!client.connect(host, httpPort))
  {
    Serial.println("connection failed");
    return;
  }

  String url = "/trigger/";

  url += eventName;
  url += "/with/key/";
  url += key;

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +

               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  int timeout = millis() + 5000;

  while (client.available() == 0)
  {
    if (timeout - millis() < 0)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  while (client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  pinMode(LED_Pin, OUTPUT);
  digitalWrite(LED_Pin, HIGH);

  delay(2000);

  digitalWrite(LED_Pin, LOW);
  ESP.deepSleep(BUTTON_Pin);

  delay(60000);
}