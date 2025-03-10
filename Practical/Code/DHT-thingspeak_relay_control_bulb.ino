#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
 
//const char *ssid =  "PAAL_LAB";  
//const char *pass =  "ncbc@paal";

const char *ssid =  "FarmBot";  
const char *pass =  "ncbc@farmbot";

DHT dht(D5, DHT22);
 
WiFiClient client;
 
long myChannelNumber = 1833602;
const char myWriteAPIKey[] = "4LKWZZ9ECV2ABWKU";
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
  pinMode(D1 , OUTPUT);
  
  /*int moistPin = 0;
  int moistVal = 0;
  pinMode(A0 , OUTPUT);8*/
}
 
void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(t>23)
  {digitalWrite(D1,LOW);}// if the sensor value is below 50% led on your nano will glow else it is off
  
  else
  {digitalWrite(D1,HIGH);}
  
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(5000);
}
