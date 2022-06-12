#include <Arduino.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

#define SENSOR_PIN 5 // D1
#define LED_PIN 16   // D0

const char *ssid = "Pak_Dukuh";
const char *password = "Plotengan1234";

const char *host = "maker.ifttt.com";
const char *eventName = "door_openned";
const char *key = "gJRj8RzkQlyB6qLDlYKGZpsR-WChvLIbvLa2jmbC8NK";

int doorClosed = 1;

int get_http()
{
  WiFiClient client;
  const int httpPort = 80;

  if (!client.connect(host, httpPort))
  {
    Serial.println("connection failed");
    return client.available();
    ;
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
      return client.available();
    }
  }

  while (client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  return client.available();
}

void setup()
{
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  Serial.print("Connecting to : ");
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
  if ((digitalRead(SENSOR_PIN) == HIGH) && (doorClosed == 1))
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("DOOR OPEN!!");
    while (get_http() != 0)
      ;

    doorClosed = 0;
  }
  else if ((digitalRead(SENSOR_PIN) == LOW) && (doorClosed == 0))
  {
    digitalWrite(LED_PIN, LOW);
    doorClosed = 1;
  }
  delay(10);
}
