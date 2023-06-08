#include <Servo.h>

Servo sg92r;  // Create a servo object

void setup() {
  pinMode(2, OUTPUT);  // Set pin 2 as OUTPUT for GND
  pinMode(3, OUTPUT);  // Set pin 3 as OUTPUT for 5V
  digitalWrite(2, LOW);  // Set pin 2 LOW for GND
  digitalWrite(3, HIGH);  // Set pin 3 HIGH for 5V

  sg92r.attach(4);  // Attach the servo to pin 4
}

void loop() {
//  sg92r.write(80);
//  delay(1000);
//  sg92r.write(60);
//  delay(1000);
  sg92r.write(85);
  delay(1000);
//  sg92r.write(120);
//  delay(1000);
}
