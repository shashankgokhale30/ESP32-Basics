#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128,64,&Wire,-1);

void setup() {
display.begin(SSD1306_SWITCHCAPVCC,0X3C);
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("shashank gokhale");
display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}
