
#include <ESP32Servo.h>
Servo myServo;
int servoPin=18;
void setup() {
  // put your setup code here, to run once:
myServo.attach(servoPin);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  int angle=Serial.parseInt(); //to read a value of a number we use parseInt and let it store in a variable 
  myServo.write(angle);
}
delay(1000);
}

