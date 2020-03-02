void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}
//unsigned long total = 0;
//float val1 = 0; // Analog Pin
//float val2 = 0;
////float analogInPinA = A0;
////float analogInPinB = A1;
//float voltage1;
//float voltage2;
float starttime = millis();
float endtime = starttime;
//int p = 0;
void loop()
{
 // p = p + 1;
  float x = analogRead(A0);  // make an initial reading to set up the ADC
  //delay(20);                // let the ADC stabilize
  x = analogRead(A0);      // toss the first reading and take one we will keep
  //delay(20);                // delay again to be friendly to future readings

  float y = analogRead(A1);  // make an initial reading to set up the ADC
  //delay(20);                // let the ADC stabilize
  y = analogRead(A1);      // toss the first reading and take one we will keep
  //delay(20);                // delay again to be friendly to future readings


  //val1 = analogRead(A0);
  //val2 = analogRead(A1);
  //total = total + val1;

  //val = total / 32;
  //Serial.println(y*(3.3 / 1023.00));
  //Serial.println(x*(3.3 / 1023.00));
  Serial.println((x - y) * (3.3 / 1023.00));
  //Serial.println(y);
  //Serial.println(val*5/1023);
  //  voltage1 = x * (5 / 1023.00);
  //voltage2 = val2 * (3.3 / 1023.00);
  //Serial.println((y-x)*3.3/1023);
  //Serial.print(',');
  //Serial.println(val2*100);
  //Serial.print("Analog difference is: ");
  //Serial.println((analogRead(analogInPinA) - analogRead(analogInPinB))*5/1023);
  //Serial.println((y - x));
  //delay(20);
//  if (p = 10) {
//    Serial.println(millis() - starttime);
//    Serial.println("100 Datapoints Printed!");
//
//  }
  delay(5);
  //endtime = millis();
}
