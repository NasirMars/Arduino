#include "Keyboard.h"

  int  shift1 = 0;
  int  shift2 = 0;
  int  lastShift = 0;
  int  lastDot = 0;
  int  lastDash = 0;
  int  typeGap = 200;
  int  charGap = 200;
  int  dotD = 40;
  int  dotF = 2000;
  int  dashD = 3*dotD;
  int  dashF = 2000;
  int  shiftD = 150;
  int  shiftF = 3000;
  int  symbol[]={0, 0, 0, 0, 0, 0};
  int  count = 0;
  
void setup() {
  pinMode(A3,INPUT);  //Shift
  pinMode(A2,INPUT);  //Dot
  pinMode(A1,INPUT);  //Dash
  pinMode(A0,INPUT);  //Space
  pinMode(15,INPUT);  //Backspace
  pinMode(14,INPUT);  //Enter
  pinMode(16,OUTPUT);  //Buzzer
  Serial.begin(9600);
  Serial.println("ready");
}

void loop() {
  Keyboard.begin();
  int  dot = digitalRead(A2);
  int  dash = digitalRead(A1);
  int  space = digitalRead(A0);
  int  backSpace = digitalRead(15);
  int  enter = digitalRead(14);
  int  shift1 = digitalRead(A3);
  int  shift2 = digitalRead(A3);
  if(shift1 != lastShift){
        if(shift1 == 1){
          tone(16,shiftF,shiftD);
          symbol[0]=1;
          }
          else{
            symbol[0]=0;
          }
        }
     delay(10);
  lastShift = shift1;
  if(shift2 == 1){  //***************************************SHIFT
    if(dot != lastDot){
      if(dot == 1){
        tone(16,dotF,dotD);
      }
    }
    if(dash != lastDash){
      if(dash == 1){
        tone(16,dashF,dashD);
      }
    }
  }
  if(shift2 ==0){  //***************************************NO SHIFT
    if(dot != lastDot){
      if(dot == 1 && dash == 0){
        tone(16,dotF,dotD);
        delay(200);
        if(dot == 0 && dash == 0){
          Keyboard.write('e');
        }
      }
    }
    if(dash != lastDash){
      if(dash == 1 && dot == 0){
        tone(16,dashF,dashD);
        delay(200);
        if(dot == 0 && dash == 0){
          Keyboard.write('e');
      }
    }
  }
  }
  if(symbol[0]==1){
     Serial.println("Yes");
  }
  else if(symbol[0]==0){
    Serial.println("Noo");
  }
  Keyboard.end();
}
