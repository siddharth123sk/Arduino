void setup() {

  //Initialized the serial port for data upload
  // put your setup code here, to run once:
  Serial.begin(9600);
  }

  void loop() {
  // put your main code here, to run repeatedly:
  int variable1 = int(random(100));

  Serial.println(variable1);
}
