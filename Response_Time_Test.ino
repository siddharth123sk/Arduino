int relayPin = 8;// set pin 8 for relay output
int LEDpin = 9;

void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Solid State Relay ");
  pinMode(relayPin, OUTPUT);
  digitalWrite(LEDpin, HIGH);

}

void loop() {

  digitalWrite(relayPin, LOW);// set relay pin to HIGH
  Serial.println("Started ");
  delay(5000);

  digitalWrite(relayPin, HIGH);// set relay pin to HIGH
  Serial.println("5 Seconds Done ");
  delay(20000);

  digitalWrite(relayPin, LOW);// set relay pin to HIGH
  Serial.println("35 Seconds Done ");
  delay(10000);
  Serial.println("55 Seconds Done ");
}

 
