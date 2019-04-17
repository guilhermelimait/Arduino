/*
.DEVELOPED BY
    Guilherme Lima
.PLATFORM
    Arduino Nano
.WEBSITE
    http://solucoesms.com.br
.LINKEDIN
    https://www.linkedin.com/in/guilhermelimait/
.DESCRIPTION
    Simple weather monitoring using DHT11 and Arduino Nano
*/


#include "DHT.h"
//biblioteca disponível em: https://github.com/adafruit/DHT-sensor-library

#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);

void setup() {
  Serial.begin (9600);
  dht.begin();
}

void loop() {
  float Umid = dht.readHumidity();
  float Temp = dht.readTemperature();

  Serial.print ("Umidade: ");
  Serial.print (Umid);
  Serial.print (" Temperatura: ");
  Serial.print (Temp);
  Serial.println ("C");
  delay (1000);
}

// -----------------------
// pin a1  - pin 2 dhtt11
// pin 5v  - pin 1 dhtt11
// pin gnd - pin 4 dhtt11
// arduino nano
// COM5 or whatever you're using
// ATmega328P (oldbootloader)
