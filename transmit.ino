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

unsigned long sendTime= 0;
unsigned long recTime= 0;
char sendSymbol= '0';
char recSymbol= '0';
int flag= 0;


void loop() {
  //start the clock, send the message

  sendTime= millis();

  //if(Serial.read()== '5'){
  //  xbee.print('5');
  //}

  sendSymbol= Serial.read();
  if(sendSymbol== '5'){
    xbee.print('5');
    flag= 1;
    while(flag==1){
      recSymbol=xbee.read();
      if(recSymbol=='6'){
        recTime= millis();
        Serial.println("signal acknowledged");
        Serial.println(recTime-sendTime);
        recSymbol= '0';
        recTime= 0;
        flag=0;
      }
    }
  }
  else if(sendSymbol== '6'){
    xbee.print('6');
  }


  state = HIGH - state;
  digitalWrite(ledPin, state);
  //Serial.println(state);



  //delay(1000);
  //Serial.println(millis());
  //delay(1000);
}
