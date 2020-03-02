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
  maxfrequency = 30; ///////CHANGE MAX FREQUENCY HERE NOTHING ELSE TO BE CHANGED
  timePerFrequency = 2;
  for (int i = 1; i <=maxfrequency; i++) {
    for (int j = 1; j <= timePerFrequency * i; j++) {
      delayTime = 500/i;
      Serial.println(i);
      digitalWrite(relayPin, LOW);
      //Serial.println("Relay ON ");
      
      delay(delayTime);


      digitalWrite(relayPin, HIGH);
      //Serial.println("Relay OFF ");
      delay(delayTime);
    }
  }
}
