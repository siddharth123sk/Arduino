int relayPin = 8;
int delayTime;
int LEDpin = 9;
int maxfrequency;
int timePerFrequency;

void setup() {

  Serial.begin(9600);
  Serial.println("Solid State Relay ");
  pinMode(relayPin, OUTPUT);
  digitalWrite(LEDpin, HIGH);

}


void loop() {
  maxfrequency = 1; ///////CHANGE MAX FREQUENCY HERE NOTHING ELSE TO BE CHANGED
  timePerFrequency = 1;
  for (int i = 1; i <=maxfrequency; i++) {
    for (int j = 1; j <= timePerFrequency * i; j++) {
      delayTime = 60;
      Serial.println(i);
      digitalWrite(relayPin, LOW);
      //Serial.println("Relay ON ");
      
      delay(delayTime);


      digitalWrite(relayPin, HIGH);
      //Serial.println("Relay OFF ");
      delay(delayTime);

       digitalWrite(relayPin, LOW);
      //Serial.println("Relay ON ");
      
      delay(delayTime*250);
    }
  }
}
