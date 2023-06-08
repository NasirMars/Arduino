// Pin definitions
const int bluePin = 9;    // PWM pin for blue
const int redPin = 10;    // PWM pin for red
const int greenPin = 11; // PWM pin for green
const int delayTime = 500;
const int darkTime = 500;

void setup() {
  // Set the RGB pins as outputs
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Set the RGB color
  setColor(0, 0, 255);
  delay(delayTime);
  setDark();
  delay(darkTime);
  setColor(255, 0, 0);
  delay(delayTime);
  setDark();
  delay(darkTime);
  setColor(0, 255, 0);
  delay(delayTime);
  setDark();
  delay(darkTime);

}

// Function to set the RGB color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue);
}

void setDark() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}
