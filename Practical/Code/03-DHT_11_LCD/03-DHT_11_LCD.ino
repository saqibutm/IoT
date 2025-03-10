#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


#define DHTPIN 3     // Digital pin connected to the DHT sensor

//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 4);


void setup() {
  //pinMode(D2 , Input);
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("A Project of");
  //lcd.print("");
  lcd.setCursor(0,2);
  lcd.print("NCBC-PAAL");
  //lcd.print("");
  //lcd.print("");
  delay(5000);
  lcd.clear(); 
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));


  lcd.setCursor(1,0);
  lcd.print("Welcome BS-IoT");
  
  lcd.setCursor(0,1);
  lcd.print(h);
  lcd.print("% Humidity");
  
  lcd.setCursor(0,2);
  lcd.print(t);
  lcd.print((char)223); // print ° character
  lcd.print("C Temp");
  
  lcd.setCursor(-4,3);
  lcd.print(hic);
  lcd.print("C HeatIndex");

  delay(2000);
  //lcd.clear();
}
