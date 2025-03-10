int ledPin = 12;
int delayTime = 2000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(ledPin,HIGH);
 delay(delayTime);
 digitalWrite(ledPin,LOW);
 delay(delayTime);

}
