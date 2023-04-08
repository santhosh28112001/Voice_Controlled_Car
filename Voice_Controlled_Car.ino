/*****************************************************
Project Title: Voice Controlled Car
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*******************************************************/
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1);  //RX = 10, TX=11 of Arduino and Tx and Rx of Bluetooth
String readvoice;
int k=0;
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  while (Serial.available())
  {
    delay(3);
    char c = Serial.read();
    readvoice += c;
    }

    if(readvoice.length() > 0)
    {
      Serial.println(readvoice);

      if(readvoice == "LED 1")
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        k=1;
      }

      if(readvoice == "LED 2")
      {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        k=2;
      }

      if(readvoice == "LED 3")
      {
        if (k==2)
        {
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          delay(1000);
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
        }
      }

      if(readvoice == "LED 4")
      {
        if (k==2)
        {
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          delay(1000);
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
        }
      }

      if(readvoice == "stop")
      {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
      }
    }
  readvoice="";
}
