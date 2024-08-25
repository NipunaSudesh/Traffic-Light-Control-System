//Q)01

// Define LED pins
const int pedestrianRed = 8;
const int pedestrianGreen = 9;
const int vehicleRed = 2;
const int vehicleYellow = 3;
const int vehicleGreen = 4;

// Define button pin
const int buttonPin = 7;

// Variable to store button state
int buttonState = 0;

// Timing constants
const unsigned long pedestrianDelay = 6000; // 6 seconds
const unsigned long vehicleYellowBlinkInterval = 1000; // 1 second
const unsigned long vehicleYellowBlinkDuration = 3000; // 3 seconds

void setup() {
  // Initialize LED pins as output
  pinMode(pedestrianRed, OUTPUT);
  pinMode(pedestrianGreen, OUTPUT);
  pinMode(vehicleRed, OUTPUT);
  pinMode(vehicleYellow, OUTPUT);
  pinMode(vehicleGreen, OUTPUT);

  // Initialize button pin as input
  pinMode(buttonPin, INPUT);

  // Initialize LEDs to default state
  digitalWrite(pedestrianRed, HIGH);
  digitalWrite(pedestrianGreen, LOW);
  digitalWrite(vehicleRed, LOW);
  digitalWrite(vehicleYellow, LOW);
  digitalWrite(vehicleGreen, HIGH);
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // Delay before changing the vehicle light
    delay(2000);

    // Switch vehicle lights: Green to Yellow
    digitalWrite(vehicleGreen, LOW);
    digitalWrite(vehicleYellow, HIGH);

    // Blink Yellow light for 3 seconds
    unsigned long startMillis = millis();
    while (millis() - startMillis < vehicleYellowBlinkDuration) {
      if ((millis() - startMillis) % (vehicleYellowBlinkInterval * 2) < vehicleYellowBlinkInterval) {
        digitalWrite(vehicleYellow, HIGH);
      } else {
        digitalWrite(vehicleYellow, LOW);
      }
      delay(10); // Small delay to debounce blinking
    }

    // Switch vehicle lights: Yellow to Red
    digitalWrite(vehicleYellow, LOW);
    digitalWrite(vehicleRed, HIGH);

    // Switch pedestrian lights: Red to Green
    digitalWrite(pedestrianRed, LOW);
    digitalWrite(pedestrianGreen, HIGH);

    // Delay before switching back pedestrian lights
    delay(pedestrianDelay);

    // Switch pedestrian lights: Green to Red
    digitalWrite(pedestrianGreen, LOW);
    digitalWrite(pedestrianRed, HIGH);

    // Switch vehicle lights: Red to Green
    digitalWrite(vehicleRed, LOW);
    digitalWrite(vehicleGreen, HIGH);
  }
}
