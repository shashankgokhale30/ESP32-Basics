// Relay connected to GPIO 2
const int relayPin = 2;

void setup() {
  pinMode(relayPin, OUTPUT);

  // Most relay modules are ACTIVE LOW
  digitalWrite(relayPin, HIGH);
  Serial.begin(115200);   // Relay OFF at startup
}

void loop() {
  // Turn relay ON
  if (Serial.available()){
    String cmd=Serial.readString();
    if(cmd=="on"){
      digitalWrite(relayPin, HIGH);
      } else if(cmd=="off"){
        digitalWrite(relayPin, LOW) ;
      }
  }
}
 

  
  
