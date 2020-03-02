
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  Serial.begin(9600);
}
float starttime = millis();
float time11[2];
float time12[100];
float time21[100];
float time22[100];


float endtime = starttime;

float NaturalFrequency11 = 10;
float NaturalFrequency12 = 10;
float NaturalFrequency21 = 10;
float NaturalFrequency22 = 10;

float NatualTimePeriod11 = 1;
float NatualTimePeriod12 = 1;
float NatualTimePeriod21 = 1;
float NatualTimePeriod22 = 1;


float deltaNatualTimePeriod11 = 0.2;
float deltaNatualTimePeriod12 = 0.2;
float deltaNatualTimePeriod21 = 0.2;
float deltaNatualTimePeriod22 = 0.2;

float Amplitude = 2;

float deltaAmplitude = 0.5;

float array11[100];
float array12[100];
float array21[100];
float array22[100];

int chances11 = 0;
int chances12 = 0;
int chances21 = 0;
int chances22 = 0;

int storecoordinatesOfProbableResonance11[50];
float storetimeOfProbableResonance11[50];

int maybeinResonance11;

int runLoopsThisManyTimes = 10;

float frequencythreshold = 0.5;
int m = 0;
int n = 0;
int o =0;

float timePeriod11;
float timePeriod12;
float timePeriod21;
float timePeriod22;


void loop()
{

  for (int i = 0; i < (runLoopsThisManyTimes + 1) ; i++) {
    array11[i] = ((analogRead(A0) - analogRead(A1)) * (3.3 / 1024));
    if (i == 0 or i == runLoopsThisManyTimes) {
      time11[i] = millis();
    }

    array12[i] = ((analogRead(A2) - analogRead(A3)) * (3.3 / 1024));
    time12[i] = millis();
    array21[i] = ((analogRead(A4) - analogRead(A5)) * (3.3 / 1024));
    time21[i] = millis();
    array22[i] = ((analogRead(A6) - analogRead(A7)) * (3.3 / 1024));
    time22[i] = millis();

    //STORING THE COORDINATES OF VALUES WHICH ARE NEAR MAX AMPLITUDE
    if (((array11[i] > (Amplitude - deltaAmplitude))) && ((array11[i] < (Amplitude + deltaAmplitude)))) {
      chances11 = chances11 + 1;
      storecoordinatesOfProbableResonance11[m] = i;
      m = m + 1;
    }

    //STORING TIME AT WHICH THE AMPLITUDE IS NEAR TO ZERO
    if (((array11[i] > (-1 * frequencythreshold))) && ((array11[i] < frequencythreshold))) {
      //chances11 = chances11 + 1;
      storetimeOfProbableResonance11[n] = time11[i];
      n = n + 1;
    }

  }
  //IF A GIVEN NUMBER OF POINTS ARE NEAR MAX AMPLITUDE IT MEANS VERIFYING THE TIMEPERIOD WILL SHOW IF THE WAVE IS OF RESONANCE OR NOT
  if (m > 33) {
    timePeriod11 = abs( 2 * (storetimeOfProbableResonance[1] - storetimeOfProbableResonance[2]));
    if ((timePeriod11 > (NatualTimePeriod11 - deltaNatualTimePeriod11)) && (timePeriod11 < (NatualTimePeriod11 + deltaNatualTimePeriod11)) ) {
      o = o + 1;
    }
  }

  if( o > 1){
    Serial.println("Resonance Found!");
    }


  //  for(int i =0; i < (sizeof(storetimeOfProbableResonance) + 1); i++ ){
  //
  //    }

  //  if (((array12[i] > (Amplitude - deltaAmplitude))) && ((array12[i] < (Amplitude + deltaAmplitude)))) {
  //    chances12 = chances12 + 1;
  //  }
  //
  //  if (((array21[i] > (Amplitude - deltaAmplitude))) && ((array21[i] < (Amplitude + deltaAmplitude)))) {
  //    chances21 = chances21 + 1;
  //  }
  //
  //  if (((array22[i] > (Amplitude - deltaAmplitude))) && ((array22[i] < (Amplitude + deltaAmplitude)))) {
  //    chances22 = chances22 + 1;
  //  }



  //  Serial.print("Value11 is: ");
  //  Serial.println(Value11);
  //  Serial.print("Value12 is: ");
  //  Serial.println(Value12);
  //  Serial.print("Value21 is: ");
  //  Serial.println(Value21);
  //  Serial.print("Value22 is: ");
  //  Serial.println(Value22);
  delay(10);
  //endtime = millis();
}
