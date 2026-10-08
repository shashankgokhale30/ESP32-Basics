#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define GPIO pins for HC-SR04 Ultrasonic Sensor
#define TRIG_PIN 5
#define ECHO_PIN 18

// Speed of sound in cm/us
#define SOUND_SPEED 0.0343

// Initialize the LCD display (I2C address 0x27 or 0x3F, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize Serial monitor
  Serial.begin(115200);

  // Configure HC-SR04 pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize LCD display
  lcd.init();
  lcd.backlight();
  
  // Display initial message
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop() {
  // Clear the TRIG pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Trigger the sensor with a 10us HIGH pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read travel time of pulse in microseconds
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in centimeters
  float distanceCm = (duration * SOUND_SPEED) / 2.0;

  // Print to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // Display distance on LCD (Line 2)
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear second line
  lcd.setCursor(0, 1);
  lcd.print(distanceCm, 2);     // Print value with 2 decimal places
  lcd.print(" cm");

  delay(500); // Update every half second
}