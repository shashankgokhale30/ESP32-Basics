// t0 turn on the on board led using the touch pin

int ledpin=2; 

void setup() {
  pinMode(ledpin,OUTPUT);
  Serial.begin(115200);

 

}

void loop() {
 
if(touchRead(T0)<50){ // T0=GPIOpin 4
  digitalWrite(ledpin,HIGH);
  }else{
    digitalWrite(ledpin,LOW);
 
  }
delay(200);
}
