/*Kamil Borkowski
stan poczatkowy to zapalona dioda
stany:
x1  x2  Q
1   0   1
1   1   0
0   0   0
0   1   1
*/
int ButtonPin =12;//Przycisk
int DiodaPin=5;//Control of Diode
boolean Q1 = 1;
boolean M1 = 1;
boolean M2 = 0;
boolean M1p = 0;
boolean M2p = 0;
boolean I1 = 1;

void setup() {
  pinMode(ButtonPin, INPUT);
  pinMode(DiodaPin, OUTPUT);
  char *hej="Setup passed";
  Serial.begin(9600);
  Serial.println(hej);
  }

void loop() {
  char *cykl="Next loop passed  ";
  char *drukP="Odczyt przycisku    ";
  char *drukW="Ustawienie wyjscia  ";
  
  Serial.println();
  Serial.print(drukP);
  I1 = digitalRead(ButtonPin);
  Serial.print(I1);
  Serial.println();

 
  M1p = I1&M1 | M1&!M2  | !I1&!M1&M2;
  M2p = I1; 



  M1 = M1p;
  M2 = M2p;
  
  Q1 = M1&!M2 | !M1&M2;

  Serial.print(M1);
  Serial.print(M2);
  Serial.println();
  digitalWrite(DiodaPin,Q1);
  Serial.print(drukW);
  Serial.print(Q1);
  Serial.println();
  Serial.println(cykl);
  delay(100);

}
