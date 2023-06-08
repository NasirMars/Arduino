// Pin definitions
const int bluePin = 9;    // PWM pin for blue
const int redPin = 10;    // PWM pin for red
const int greenPin = 11;  // PWM pin for green
const int potentiometerPin = A0;  // Analog input pin for potentiometer

void setup() {
  // Set the RGB pins as outputs
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Read the potentiometer value
  int potValue = analogRead(potentiometerPin);

  // Map the potentiometer value to the RGB color range
  int red = map(potValue, 0, 1023, 0, 255);
  int green = map(potValue, 0, 1023, 0, 255);
  int blue = map(potValue, 0, 1023, 0, 255);

  // Set the RGB color
  setColor(red, green, blue);

  // Delay for a short duration
  delay(100);
}

// Function to set the RGB color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
