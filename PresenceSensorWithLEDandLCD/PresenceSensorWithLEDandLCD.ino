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
    Simple solution to interact with the presence sensor and showing the results on a display and LEDs    
.DESCRIPTION PORTUGUESE VERSION
    As bibliotecas utilizadas aqui tem necessidades ou atividades diferentes para seu funcionamento, siga exatamente como informado:
    Abaixo o local para download das bibliotecas:
    DHT: https://github.com/adafruit/DHT-sensor-library salvar a pasta nas libraries do arduino
    LCD COM I2C: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/NewliquidCrystal_1.3.4.zip renomear a pasta para LiquidCrystalI2C e salvar nas libraries do Arduino
    Informações sobre o Wire: https://www.arduino.cc/en/reference/wire
.PIN MAPPING
    Arduino nano -> Presence Sensor (PIR DYP-ME003)
    pin d3  - Data (middle pin)
    pin 5v  - 5v (right pin)
    pin gnd - gnd (left pin)

    LED
    Green LED
      - negative - 10kOm - gnd
      - positive - d5

    Red LED
      - negative - 10kOm - gnd
      - positive - d6
      
    Arduino nano -> PC
    COM5 or whatever you're using
    ATmega328P (oldbootloader)
    
    Arduino nano -> LCD 16x2 I2C
    pin a4  - pin sda
    pin a5  - pin scl
    pin 5v  - pin vcc
    pin gnd - pin gnd
*/

#include <LiquidCrystal_I2C.h>

int AlvoEncontrado = 6;
int AlvoLivre = 5;
int DataSensor = 3;
int Momento;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //informação padrão para funcionamento do LCD 16X2 I2C

void setup() {
  pinMode (AlvoEncontrado, OUTPUT);
  pinMode (AlvoLivre, OUTPUT);
  pinMode (DataSensor, INPUT);
  Serial.begin (9600);
  lcd.begin(16,2);
  lcd.setBacklight(HIGH);
}

void loop() {
  Momento = digitalRead(DataSensor);
  if (Momento == LOW){
    digitalWrite (AlvoEncontrado, LOW);
    digitalWrite (AlvoLivre, HIGH);
    lcd.setCursor(0,0);
    lcd.print("SensorDesativado");
    Serial.println ("SensorDesativado");
  }
  else{
    digitalWrite (AlvoEncontrado, HIGH);
    digitalWrite (AlvoLivre, LOW);
    lcd.setCursor(0,0);
    lcd.print("SensorAtivado   ");
    Serial.println ("SensorAtivado   ");
  }
  delay (100);
}
