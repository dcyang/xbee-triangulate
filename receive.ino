#include <SoftwareSerial.h>
#define rxPin 3
#define txPin 2
#define ledPin 13
SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);
//int count = 0;

void setup(){
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  xbee.begin(9600);
  Serial.begin(9600);
  Serial.println("Starting XBee Communication");
}

int count = 0;

void loop(){
  //Serial.println("Waiting for XBe");
  //if (x != -1)
  //if (count % 10 == 0) Serial.println();
  if (xbee.available()) {
    char x = xbee.read();
    Serial.println(x);

    if (x=='5'){
      Serial.println("Replying 6");
      xbee.print('6');
      count++;
    }
    else{
      Serial.println("Replying 9");
      xbee.print('9');
      count++;
    }
    Serial.print("counter = ");
    Serial.println(count);
  }
  //++count;
  //Serial.println(rec);
  //delay(1500);
}
