#include "Keyboard.h"

  int  shift1 = 0;
  int  shift2 = 0;
  int  lastShift = 0;
  int  lastSpace = 0;
  int  lastBackSpace = 0;
  int  lastEnter = 0;
  int  typeGap = 200;
  int  charGap = 200;
  int  dotD = 50;
  int  dotF = 2000;
  int  dashD = 3*dotD;
  int  dashF = 2000;
  int  lastDot = 0;
  int  lastDash = 0;
  int  lastDotS = 0;
  int  lastDashS = 0;
  int  shiftD = 150;
  int  shiftF = 3000;
  int  morse[]={0, 3, 2, 2, 2, 2};
  int  count = 1;
  int  x = 0;
  int  y = 0;
  int  currentTime = 1;
  int  limTime = 800;

  

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
  if(shift1 != lastShift || space != lastSpace || backSpace != lastBackSpace || enter != lastEnter){
        if(shift1 == 1 || space == 1 || backSpace == 1 || enter == 1){
          tone(16,shiftF,shiftD);
          }
        }
  if(dot != lastDotS){
    if(dot == 1){
      tone(16,dotF,dotD);
    }
  }
  if(dash != lastDashS){
    if(dash == 1){
      tone(16,dashF,dashD);
    }
  }
  lastShift = shift1;
  lastSpace = space;
  lastBackSpace = backSpace;
  lastEnter = enter;
  lastDotS = dot;
  lastDashS = dash;
  if(shift2 == 0){
    morse[0]=0;
  }
  if(shift2 == 1){
    morse[0] = 1;
  }
  delay(10);
  if(currentTime >= 50 && currentTime <= limTime ){
    //Serial.println(currentTime);
    currentTime = currentTime+10;
  }
 //if(dot == 1 || dash == 1|| currentTime >= 50){
 if(dot != lastDot){
  if(dot == 1 && dash == 0){
    morse[count]=0;
    count++;
    Serial.print("Dot");
  }
  else{
    currentTime = 50;
  }
 }
 if(dash != lastDash){
  if(dot == 0 && dash == 1){
    morse[count]=1;
    count++;
    Serial.print("Dash");
  }
  else{
    currentTime = 50;
  }
 }
 else if(currentTime >= limTime && count != 1){
 if(dot == 0 && dash == 0){
  Serial.print("OVER");
  Serial.print("  count:");
  Serial.print(count);
  if(count<=5){
    if(count<=4){
      if(count<=3){
        if(count==2){
          morse[2]=2;
        }
        morse[3]=2;
      }
      morse[4]=2;
    }
    morse[5]=2;
  }
  count = 6;
 }
 }
 //if(delayTime >= delayTime2 && delayTime < 410){
 //if( delayTime >= 400){
 // morse[count]=3;
  //count = 6;
// }
// }
// delayTime2 = delayTime;
 lastDot = dot;
 lastDash = dash;
 //}
 if(count == 6){
  Serial.print("  ");
  for(x=0;x<6; x++){
    Serial.print(morse[x]);
  }
  Serial.print("  ");
 }
 if(count == 6){
 if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 1){
  Keyboard.write('1');
  Serial.print("1");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 1 && morse[5] == 1){
  Keyboard.write('2');
  Serial.print("2");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 1){
  Keyboard.write('3');
  Serial.print("3");
}
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 1){
  Keyboard.write('4');
  Serial.print("4");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 0){
  Keyboard.write('5');
  Serial.print("5");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 0){
  Keyboard.write('6');
  Serial.print("6");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 0){
  Keyboard.write('7');
  Serial.print("7");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 0 && morse[5] == 0){
  Keyboard.write('8');
  Serial.print("8");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 0){
  Keyboard.write('9');
  Serial.print("9");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 1){
  Keyboard.write('0');
  Serial.print("0");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('A');
  Serial.print("A");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('B');
  Serial.print("B");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('C');
  Serial.print("C");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('D');
  Serial.print("D");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('E');
  Serial.print("E");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('F');
  Serial.print("F");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('G');
  Serial.print("G");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('H');
  Serial.print("H");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('I');
  Serial.print("I");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('J');
  Serial.print("J");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('K');
  Serial.print("K");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('L');
  Serial.print("L");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('M');
  Serial.print("M");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('N');
  Serial.print("N");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('O');
  Serial.print("O");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('P');
  Serial.print("P");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('Q');
  Serial.print("Q");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('R');
  Serial.print("R");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('S');
  Serial.print("S");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('T');
  Serial.print("T");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('U');
  Serial.print("U");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('V');
  Serial.print("V");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('W');
  Serial.print("W");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('X');
  Serial.print("X");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('Y');
  Serial.print("Y");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('Z');
  Serial.print("Z");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('a');
  Serial.print("a");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('b');
  Serial.print("b");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('c');
  Serial.print("c");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('d');
  Serial.print("d");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('e');
  Serial.print("e");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('f');
  Serial.print("f");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('g');
  Serial.print("g");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('h');
  Serial.print("h");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('i');
  Serial.print("i");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('j');
  Serial.print("j");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('k');
  Serial.print("k");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('l');
  Serial.print("l");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('m');
  Serial.print("m");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('n');
  Serial.print("n");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('o');
  Serial.print("o");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('p');
  Serial.print("p");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('q');
  Serial.print("q");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('r');
  Serial.print("r");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('s');
  Serial.print("s");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('t');
  Serial.print("t");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('u');
  Serial.print("u");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('v');
  Serial.print("v");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
  Keyboard.write('w');
  Serial.print("w");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('x');
  Serial.print("x");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2){
  Keyboard.write('y');
  Serial.print("y");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2){
  Keyboard.write('z');
  Serial.print("z");
 }
 int  morse[]={0, 3, 2, 2, 2, 2};
  Serial.println(" over");
 count = 1;
 currentTime = 1;
 delay(200);
 }
  if(space == 1){
  Keyboard.write(' ');
  delay(typeGap);
 }
 else if(backSpace== 1){
  Keyboard.write(0x08);
  delay(typeGap);
 }
 else if(enter == 1){
  Keyboard.write(0xE0);
  delay(typeGap);
 }
  Keyboard.end();
}
