const int bluePin = 9;     // PWM pin for blue
const int redPin = 10;    // PWM pin for red
const int greenPin = 11;  // PWM pin for green
const int fadeDelay = 15; // Delay between color changes

// Define the colors
const int colors[][3] = {
//  {255, 0, 0},     // Red
//  {255, 10, 0},    // Orange
//  {200, 50, 0},    // Yellow
//  {0, 255, 0},     // Green
//  {0, 220, 50},    // Light green
//  {0, 0, 255},     // Blue
//  {128, 0, 128}    // Purple
    {255, 0, 0},
    {128, 128, 0},
    {0, 255, 0},
    {0,128, 128},
    {0, 0, 255},
    {128, 0, 128}
};

int brightness = 80;        // Adjust the brightness level (0-255)
float transitionSpeed = 0.01; // Adjust the speed of color transitions

void setup() {
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Iterate through each color
  for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
    int startColor[3];
    int endColor[3];

    // Set the start and end colors
    for (int j = 0; j < 3; j++) {
      startColor[j] = colors[i][j];
      endColor[j] = colors[(i + 1) % (sizeof(colors) / sizeof(colors[0]))][j];
    }

    // Smoothly transition from the start color to the end color
    for (float step = 0.0; step <= 1.0; step += transitionSpeed) {
      int currentColor[3];

      // Calculate the current color based on the step and brightness
      for (int j = 0; j < 3; j++) {
        int startValue = map(brightness, 0, 255, 0, startColor[j]);
        int endValue = map(brightness, 0, 255, 0, endColor[j]);
        currentColor[j] = lerp(startValue, endValue, step);
      }

      // Set the RGB values
      analogWrite(bluePin, 255-currentColor[0]);
      analogWrite(redPin, 255-currentColor[1]);
      analogWrite(greenPin, 255-currentColor[2]);

      delay(fadeDelay);
    }
  }
}

// Linear interpolation function
int lerp(int startValue, int endValue, float t) {
  return startValue + (endValue - startValue) * t;
}
