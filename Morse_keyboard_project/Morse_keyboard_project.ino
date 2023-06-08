//#include<Keyboard.h>
int button1State = 0;
int button2State = 0;
int lastButtonState = 0;
void setup(){
  pinMode(8,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop(){
//  Keyboard.begin();
  button1State = digitalRead(A0);
  button2State = digitalRead(A1);
  if(button1State == 1 or button2State ==1){
//  Serial.print(button1State);
//  Serial.println(button2State);
    if(button1State == 1){
//      Keyboard.write('e');
      tone(8,2000,50);
      Serial.print("e");
      delay(10);
    }
    else{
      tone(8,2000,200);
      Serial.print("t");
      delay(10);
    }
    }
}
