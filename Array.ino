void setup()
{                
  Serial.begin(38400);
}

//Export the data in text file
//Calculate avergae of last 50
//Calculate MWSD of last 50

int val; // Analog Pin
float MyArray[50]; // Array which stores the values to find Standard Deviation
float sum; // Sum of all the elements inside the Array
float average; // Average of elements inside the Array
int numberOfSamples = 50; // Define the size of Moving window standard Deviation
int count = 0; // Used to find the time taken to execute the loop "n" number of times
unsigned startTime = millis(); // Finds the time before the start of the loop


void loop()                     
{
//  Serial.print("Time: ");
//  Serial.println(startTime);
  unsigned startTimeLoop = micros(); //Finds the time after the start of the loop
  
  count = count + 1; //Increase the count value by 1 with every loop run
  sum = 0;
  //Calculate the sum and store the values from analog pin in an array of size specified
  for (int i = 0; i < (numberOfSamples); i = i + 1) {
    val = analogRead(0);
    MyArray[i] = val;
    sum = sum + val;
    //Serial.println(MyArray[i]);
  }
  //Calculate the average
  average = sum/numberOfSamples;
  //Calculate the standard deviation
  float sqDevSum = 0.0;
  for(int i = 0; i < (numberOfSamples); i = i + 1) {
    sqDevSum = sqDevSum + pow((average - float(MyArray[i])), 2);
  }
  float stDev = sqrt(sqDevSum/(numberOfSamples));
  for (int i = 0; i < (numberOfSamples); i = i + 1) {
    Serial.println(MyArray[i]);
  }
  Serial.print("Average: ");
  Serial.println(average);
  Serial.print("Standard Deviation: ");
  Serial.println(stDev);
  
  
  //Serial.print("Analog Value: ");
  //Serial.println(val);
  unsigned timeNow = micros();
  //Print execution time of the loop
  Serial.print("Execution time for this loop in microseconds: ");
  Serial.println(float(timeNow - startTimeLoop)); 
  //Print the execution time of n number of loops
  if (count == 3){ //Specify number of loops
    unsigned timeNow = millis();
    //Serial.println(startTime);
    //Serial.println(timeNow);
    Serial.print("Execution time in milliseconds: ");
    Serial.println((float(timeNow - startTime)));
    //Serial.println("s");
    exit(0);
  }
  //exit(0);
  //delay(100);
}
