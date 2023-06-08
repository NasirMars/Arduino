#include <Servo.h>

Servo EyeHori;
Servo EyeVerti;

int desiredPositionX=85;
int desiredPositionY=100;

void setup() {
  EyeHori.attach(2);
  EyeVerti.attach(3);
  Serial.begin(9600);
  EyeHori.write(desiredPositionX);
  EyeVerti.write(desiredPositionY);
}

void loop() {
  if (Serial.available()) {
    String inputString = Serial.readStringUntil('\n'); // Read the incoming data as a string
    inputString.trim(); // Remove leading and trailing whitespace
    
    // Split the input string into two values
    int separatorIndex = inputString.indexOf(' ');
    if (separatorIndex != -1) {
      String posXString = inputString.substring(0, separatorIndex);
      String posYString = inputString.substring(separatorIndex + 1);
      
      desiredPositionX = posXString.toInt(); // Convert the string to an integer
      desiredPositionY = posYString.toInt(); // Convert the string to an integer
      
      // Limit the position ranges
      if (desiredPositionX >= 20 && desiredPositionX <= 150) {
        EyeHori.write(desiredPositionX-5); // Set the horizontal servo position
      }
      if (desiredPositionY >= 60 && desiredPositionY <= 120) {
        EyeVerti.write(190-desiredPositionY); // Set the vertical servo position
      }
    }
  }
}
