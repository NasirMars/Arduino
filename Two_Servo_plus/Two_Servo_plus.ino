#include <Servo.h>

Servo EyeHori;
Servo EyeVerti;

int desiredPositionX = 85;
int desiredPositionY = 100;

void setup() {
  EyeHori.attach(2);
  EyeVerti.attach(3);
  Serial.begin(9600);
  EyeHori.write(desiredPositionX);
  EyeVerti.write(desiredPositionY);
}

void loop() {
  if (Serial.available()) {
    String inputString = Serial.readStringUntil('\n');
    inputString.trim();
    
    if (inputString == "0, 0") {
      // Stay in the current position
    }
    if (inputString == "1, 0") {
      desiredPositionX=desiredPositionX+4;
    }
    if (inputString == "-1, 0") {
      desiredPositionX=desiredPositionX-4;
    }
    if (inputString == "0, 1") {
      desiredPositionY=desiredPositionY-4;
    }
    if (inputString == "0, -1") {
      desiredPositionY=desiredPositionY+4;
    }
    if (inputString == "9, 9") {
      desiredPositionX=85;
      desiredPositionY=100;
    }
    
    // Limit the position ranges
    desiredPositionX = constrain(desiredPositionX, 20, 150);
    desiredPositionY = constrain(desiredPositionY, 60, 120);
    
    EyeHori.write(desiredPositionX);
    EyeVerti.write(desiredPositionY);
  }
}
