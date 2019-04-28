/*
.DEVELOPED BY
    Guilherme Lima
.PLATFORM
    Arduino Nano
.WEBSITE
    http://solucoesms.com.br
.LINKEDIN
    https://www.linkedin.com/in/guilhermelimait/
    https://github.com/guilhermelimait/Arduino/tree/master/WeatherStationWithLCD  
.DESCRIPTION ENGLISH VERSION
    Simple weather monitoring using DHT11 and Arduino Nano showing results on LCD 16X2 with I2C
.DESCRIPTION PORTUGUESE VERSION
    As bibliotecas utilizadas aqui tem necessidades ou atividades diferentes para seu funcionamento, siga exatamente como informado:
    Abaixo o local para download das bibliotecas:
    DHT: https://github.com/adafruit/DHT-sensor-library salvar a pasta nas libraries do arduino
    LCD COM I2C: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/NewliquidCrystal_1.3.4.zip renomear a pasta para LiquidCrystalI2C e salvar nas libraries do Arduino
    Informações sobre o Wire: https://www.arduino.cc/en/reference/wire
.PIN MAPPING
    Arduino nano -> DHT 11
    pin a1  - pin 2 dhtt11
    pin 5v  - pin 1 dhtt11
    pin gnd - pin 4 dhtt11
    
    Arduino nano -> PC
    COM5 or whatever you're using
    ATmega328P (oldbootloader)
    
    Arduino nano -> LCD 16x2 I2C
    pin a4  - pin sda
    pin a5  - pin scl
    pin 5v  - pin vcc
    pin gnd - pin gnd
*/

#include "DHT.h"                          //biblioteca obrigatória do sensor DHT11
#include <Wire.h>                         //biblioteca obrigatória do arduino nano para comunicação pinos a4/a5
#include <LiquidCrystal_I2C.h>            //biblioteca obrigatória do LCD 16x2 com I2C

#define DHTPIN A1                         //definição de variáveis
#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);                
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //informação padrão para funcionamento do LCD 16X2 I2C

void setup() {
  lcd.begin (16,2);                       //inicializacao e tamanho do lcd
  dht.begin();                            //inicializacao do dht
}

void loop() {
  float Umid = dht.readHumidity();        //lê a umidade atual
  float Temp = dht.readTemperature();     //lê a temperatura atual

  lcd.setBacklight(HIGH);                  //desliga led de fundo do lcd
  lcd.setCursor(0,0);                     //linha 1
  lcd.print ("Umid: ");
  lcd.print (Umid);
  lcd.setCursor(0,1);                     //linha 2
  lcd.print ("Temp: ");
  lcd.print (Temp);
  lcd.print (" \337C");                    //caractere ° (grau celcius)
  delay (5000);
  lcd.setCursor(0,0);
  lcd.print ("github.com/     ");
  lcd.setCursor(0,1);
  lcd.print ("guilhermelima   ");
  delay (2000);
}
