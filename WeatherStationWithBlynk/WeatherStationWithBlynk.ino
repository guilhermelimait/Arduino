#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "********";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "********";
char pass[] = "********";

#define DHTPIN D4          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  Serial.println("temp=" );
  Serial.print(t);
  Serial.println("umid= ");
  Serial.print(h);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V6, h);
  Blynk.virtualWrite(V5, t);
}

void setup()
{
  Serial.begin(115200); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
  Blynk.tweet("Hey, my tweet works! #iot #arduino #nodemcu #blynk");
}
