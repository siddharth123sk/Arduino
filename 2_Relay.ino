#include <Scheduler.h>
int relayPin1 = 7;
int relayPin2 = 8;
int delayTime;
int LEDpin = 9;

void setup() {

  Serial.begin(9600);
  //Serial.println("Solid State Relay ");
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(LEDpin, HIGH);
  Scheduler.startLoop(loop2);
}



void loop() {
  for (int i = 1; i <=40; i++) {
    for (int j = 1; j <= 2 * i; j++) {
      delayTime = 500/i;
      Serial.println(i);
      digitalWrite(relayPin1, LOW);
      //Serial.println("Relay ON ");
      
      delay(delayTime);


      digitalWrite(relayPin1, HIGH);
      //Serial.println("Relay OFF ");
      delay(delayTime);
    }
  }
}
void loop2(){
  for (int i = 1; i <=40; i++) {
    for (int j = 1; j <= 2 * i; j++) {
      delayTime = 500/i;
      Serial.println(i);
      digitalWrite(relayPin2, LOW);
      //Serial.println("Relay ON ");
      
      delay(delayTime);


      digitalWrite(relayPin2, HIGH);
      //Serial.println("Relay OFF ");
      delay(delayTime);
    }
  }
}
