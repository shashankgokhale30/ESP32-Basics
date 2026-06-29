#include "BluetoothSerial.h"

BluetoothSerial serial_BT;

char cmd;


void setup() {
  // put your setup code here, to run once:
serial_BT.begin("esp32");
pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(serial_BT.available()){
    cmd=serial_BT.read();

}
  if (cmd==1){
   digitalWrite(2,HIGH);
}
  if (cmd==0){
    digitalWrite(2,LOW);
    delay(20);
}
} 

