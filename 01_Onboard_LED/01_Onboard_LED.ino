int ledpin=2;
void setup() {
    pinMode(ledpin,OUTPUT);}
void loop() {
 
  digitalWrite(ledpin,HIGH);
  delay(100);
  digitalWrite(ledpin,LOW);
  delay(100);
}
