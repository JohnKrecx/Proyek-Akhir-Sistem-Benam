#include "MQ7.h"

MQ7 mq7 (A0, 5.0);
const int AOUTpin = 0;
const int DOUTpin = 8;
const int ledPin = 13;

int limit;

void setup(){
  Serial.begin(9600);
  pinMode(DOUTpin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  limit = digitalRead(DOUTpin);
  Serial.print("Karbon Monoksida : ");
  Serial.println(mq7.getPPM());
  Serial.print("Limit : ");
  Serial.print(limit);
  delay(1000);

  if (limit == HIGH){
    Serial.println("Warning !");
    digitalWrite(ledPin, HIGH);
  }
  else{
    Serial.println("OK");
    digitalWrite(ledPin, LOW);
  }
}
