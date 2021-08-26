#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdio.h>

#define LED D5
#define RXPIN D7

SoftwareSerial MYSERIAL(RXPIN,D8);

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(RXPIN, INPUT);
  
  Serial.begin(115200);
  MYSERIAL.begin(57600);
  Serial.println("Program Started");

  
  digitalWrite(LED, HIGH);
}

void loop()
{
  while (MYSERIAL.available())
  {                               // If anything comes in Serial1 (pins 0 & 1)
    Serial.print(MYSERIAL.read(), HEX); // read it and send it out Serial (USB)
    Serial.print(" ");
  }
}