#include "DHT.h"

#define DHTPIN D3     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)


DHT dht(DHTPIN, DHTTYPE);

#include <Adafruit_NeoPixel.h>      //Adiciona a biblioteca Adafruit NeoPixel
#define D_in D4       //Nomeia o pino 6 do Arduino
#define qtdeLeds 1    //Informa a quantidade de LEDs que serão ligados em cascata
Adafruit_NeoPixel pixels(qtdeLeds, D_in);     //Instancia o objeto "pixels", informando a quantidade e o pino de sinal

void setup() {
  // put your setup code here, to run once:
  pinMode(D_in, OUTPUT); 
  Serial.begin(9600);
  dht.begin();
  pixels.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float t = dht.readTemperature();
  int ldr= analogRead(A0);

  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  Serial.print("Nivel de luz= ");
  Serial.println(ldr);

  int mapldrpixels= map(ldr, 0, 4095, 0, 254);
  //pixels.clear();      //desliga todos os LEDs
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));     //liga o led correspondente ao número da variável i na cor vermelha
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));     //liga o led correspondente ao número da variável i na cor vermelha
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));     //liga o led correspondente ao número da variável i na cor vermelha
  pixels.show();
  delay(1000);
  pixels.clear();

}
