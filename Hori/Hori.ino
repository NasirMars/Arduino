#include <Servo.h>

Servo EyeHori;
int desiredPosition;

void setup(){
  EyeHori.attach(2);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int newPosition = Serial.parseInt(); // Read the incoming data as an integer
    if (newPosition >= 35 && newPosition <= 135) { // Central 85
      desiredPosition = newPosition;
      EyeHori.write(desiredPosition); // Set the servo position
    }
  }
}
