const int PIN_ANALOG_INPUT_L = 2;
const int PIN_ANALOG_INPUT_R = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 115200 );
    pinMode(4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 int r = analogRead( PIN_ANALOG_INPUT_R );
 int l = analogRead( PIN_ANALOG_INPUT_L );
  float fr = r * 1.0; // / 1023.0;
  float fl = l * 5.0 / 1023.0;
  // Serial.println( fr);
  for(int i=0; i<((fr-400)/3); i++) {
    Serial.print("*");    
  }
  Serial.println(" ");
  if (fr>500) {
    Serial.println("*** over 500 ***");
  digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
  }
  if (fr<400) {
    Serial.println("under 400");
    digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  }

}
