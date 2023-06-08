#include<Servo.h>
#define numOfValsRec 5
#define digitsPerValRec 1

Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRing;
Servo servoPinky;


int valsRec[numOfValsRec];
//$00000
int stringLength = numOfValsRec * digitsPerValRec + 1;
int counter = 0;
bool counterStart = false;
String receivedString;
void setup() {
  Serial.begin(9600);
  servoThumb.attach(2);
  servoIndex.attach(3);
  servoMiddle.attach(4);
  servoRing.attach(5);
  servoPinky.attach(6);
  
}

void receieveData() {
  while (Serial.available())
  {
    char c = Serial.read();

    if (c == '$') {
      counterStart = true;
    }
    if (counterStart) {
      if (counter < stringLength) {
        receivedString = String(receivedString + c);
        counter++;
      }
      if (counter >= stringLength) {
        for (int i = 0; i < numOfValsRec; i++) {
          int num = (i * digitsPerValRec) + 1;
          valsRec[i] = receivedString.substring(num, num + digitsPerValRec).toInt();
        }
        receivedString = "";
        counter = 0;
        counterStart = false;
      }
    }
  }
}
void loop() {
  receieveData();
  if (valsRec[0] == 0) {
    servoThumb.write(90);
  } else {
    servoThumb.write(90);
  }
  if (valsRec[1] == 0) {
    servoIndex.write(90);
  } else {
    servoIndex.write(90);
  }
  if (valsRec[2] == 0) {
    servoMiddle.write(90);
  } else {
    servoMiddle.write(90);
  }
  if (valsRec[3] == 0) {
    servoRing.write(90);
  } else {
    servoRing.write(90);
  }
  if (valsRec[4] == 0) {
    servoPinky.write(90);
  } else {
    servoPinky.write(90);
  }
}
