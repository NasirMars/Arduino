int redPin = 10;
int greenPin = 11;
int bluePin = 9;

const int delayTime = 1000;
const int darkTime = 500;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);     // Red
  setDark();
  setColor(255, 10, 0);   // Orange
  setDark();
  setColor(200, 50, 0);   // Yellow
  setDark();
  setColor(0, 255, 0);     // Green
  setDark();
  setColor(0, 220, 50);     // Light green
  setDark();
  setColor(0, 0, 255);     // Blue
  setDark();
  setColor(128, 0, 128);   // Purple
  setDark();
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, 255-redValue);
  analogWrite(greenPin, 255-greenValue);
  analogWrite(bluePin, 255-blueValue);
  delay(delayTime);
}
void setDark(){
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  delay(darkTime);
}
