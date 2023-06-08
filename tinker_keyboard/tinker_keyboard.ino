  int  shift1 = 0;
  int  shift2 = 0;
  int  lastShift = 0;
  int  lastSpace = 0;
  int  lastBackSpace = 0;
  int  lastEnter = 0;//                                                                             
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
  int  morse[]={0, 3, 2, 2, 2, 2, 2};
  int  count = 1;
  int  x = 0;
  int  y = 0;
  int  currentTime = 1;
  int  limTime = 600;

  

void setup() {
  pinMode(A0,INPUT);  //Shift
  pinMode(A1,INPUT);  //Dot
  pinMode(A2,INPUT);  //Dash
  pinMode(A3,INPUT);  //Space
  pinMode(A4,INPUT);  //Backspace
  pinMode(A5,INPUT);  //Enter
  pinMode(13,OUTPUT);  //Buzzer
  Serial.begin(9600);
  Serial.println("ready");
}

void loop() {
  int  dot = digitalRead(A1);
  int  dash = digitalRead(A2);
  int  space = digitalRead(A3);
  int  backSpace = digitalRead(A4);
  int  enter = digitalRead(A5);
  int  shift1 = digitalRead(A0);
  int  shift2 = digitalRead(A0);
  if(shift1 != lastShift || space != lastSpace || backSpace != lastBackSpace || enter != lastEnter){
        if(shift1 == 1 || space == 1 || backSpace == 1 || enter == 1){
          tone(13,shiftF,shiftD);
          delay(20);
          }
        }
  if(dot != lastDotS){
    if(dot == 1){
      tone(13,dotF,dotD);
    }
  }
  if(dash != lastDashS){
    if(dash == 1){
      tone(13,dashF,dashD);
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
 else if(currentTime >= limTime){
 if(dot == 0 && dash == 0){
  Serial.print("OVER");
  Serial.print("  count:");
  Serial.print(count);
  if(count<=6){
    if(count<=5){
      if(count<=4){
        if(count<=3){
          if(count<=2){
            if(count==1){
              morse[1]=2;}
            morse[2]=2;}
          morse[3]=2;}
        morse[4]=2;}
      morse[5]=2;}
    morse[6]=2;}
  count = 7;
 }
 }
 lastDot = dot;
 lastDash = dash;
 if(count == 7){
  Serial.print("  ");
  for(x=0;x<7; x++){
    Serial.print(morse[x]);
  }
  Serial.print("  ");
 }
 if(count == 7){
 if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 1 && morse[6] == 2){
  Serial.print("1");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 1 && morse[5] == 1 && morse[6] == 2){
  Serial.print("2");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 1 && morse[6] == 2){
  Serial.print("3");
}
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 1 && morse[6] == 2){
  Serial.print("4");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 0 && morse[6] == 2){
  Serial.print("5");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 0 && morse[6] == 2){
  Serial.print("6");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 0 && morse[6] == 2){
  Serial.print("7");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 0 && morse[5] == 0 && morse[6] == 2){
  Serial.print("8");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 0 && morse[6] == 2){
  Serial.print("9");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 1 && morse[6] == 2){
  Serial.print("0");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("A");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("B");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("C");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("D");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2 && count != 1){
  Serial.print("E");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("F");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("G");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("H");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("I");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("J");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("K");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("L");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("M");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("N");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("O");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("P");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("Q");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("R");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("S");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2 && count != 1){
  Serial.print("T");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("U");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("V");
 }
 else if(morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("W");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("X");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("Y");
 }
 else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("Z");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("a");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("b");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("c");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("d");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2 && count != 1){
  Serial.print("e");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("f");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("g");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("h");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("i");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("j");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("k");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("l");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("m");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("n");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("o");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("p");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("q");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("r");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("s");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2 && count != 1){
  Serial.print("t");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("u");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("v");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2 && morse[6] == 2){
  Serial.print("w");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 0 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("x");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 1 && morse[5] == 2 && morse[6] == 2){
  Serial.print("y");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 2 && morse[6] == 2){
  Serial.print("z");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 1 && morse[4] ==0  && morse[5] == 1 && morse[6] == 0){
  Serial.print("@");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 0 && morse[6] == 2){
  Serial.print("&");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse[3] == 1 && morse[4] == 0 && morse[5] == 1 && morse[6] == 1){
  Serial.print("!");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse[3] == 1 && morse[4] == 1 && morse[5] == 0 && morse[6] == 0){
  Serial.print("?");
 }
 else if(morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse[3] == 0 && morse[4] == 0 && morse[5] == 1 && morse[6] == 1){
  Serial.print(",");
 }
 else if(morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse[3] == 0 && morse[4] == 1 && morse[5] == 0 && morse[6] == 1){
  Serial.print(".");
 }
 int  morse[]={0, 3, 2, 2, 2, 2, 2};
  Serial.println(" over");
 count = 1;
 currentTime = 1;
 delay(200);
 }
  if(space == 1){
  Serial.write(' ');
  delay(typeGap);
 }
 else if(backSpace== 1){
  Serial.write(0x08);
  delay(typeGap);
 }
 else if(enter == 1){
  Serial.write(0xE0);
  delay(typeGap);
 }
}
