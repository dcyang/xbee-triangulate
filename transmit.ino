#include <SoftwareSerial.h>

#define rxPin 3
#define txPin 2
#define ledPin 13
SoftwareSerial xbee = SoftwareSerial(rxPin, txPin);
unsigned long state = HIGH;

void setup() {
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    xbee.begin(9600);
}

void loop() {
    xbee.print('B');
    state = HIGH - state;
    digitalWrite(ledPin, state);
    Serial.println(state);
    delay(1000);
    //Serial.println(millis());
    //delay(1000);
}
