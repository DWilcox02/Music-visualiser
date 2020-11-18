//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1

//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7];
int i;
String values[7];

/********************Setup Loop*************************/
void setup() {
  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);

  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  digitalWrite(RESET, LOW);
  delay(5);
  values[0] = "0";
  values[1] = "1";
  values[2] = "2";
  values[3] = "3";
  values[4] = "4";
  values[5] = "5";
  values[6] = "6";
  Serial.begin(9600);
}

/****************Main Function Loop***************************/
void loop() {

  Read_Frequencies();
  Graph_Frequencies();
  delay(50);

}

/*************Pull frquencies from Spectrum Shield****************/
void Read_Frequencies() {
  digitalWrite(RESET, HIGH);
  delayMicroseconds(200);
  digitalWrite(RESET, LOW);
  delayMicroseconds(200);

  //Read frequencies for each band
  for (freq_amp = 0; freq_amp < 7; freq_amp++)
  {
    digitalWrite(STROBE, HIGH);
    delayMicroseconds(50);
    digitalWrite(STROBE, LOW);
    delayMicroseconds(50);

    Frequencies_One[freq_amp] = analogRead(DC_One);
    Frequencies_Two[freq_amp] = analogRead(DC_Two);
  }
}

/*****************Print Out Band Values for Serial Plotter*****************/
void Graph_Frequencies() {
  for (i = 0; i < 7; i++)
  {
//    Serial.print(Frequencies_One[i]);
//    Serial.print(" ");
//    Serial.print(Frequencies_Two[i]);
//    Serial.print(" ");
    String tempVal = values[i];
    Serial.print("Value " + tempVal + ":");
    Serial.print((((Frequencies_One[i] + Frequencies_Two[i]) / 2 )*30));
    Serial.println("        ");
  }
  
}
