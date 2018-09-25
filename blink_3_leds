// By: Jackson Meyers and Monty Choy
// Blink 3 LEDs
// EE 151-2 LAB
// September 25, 2018

#define BLINK_DELAY 500

void setup() {
  // From 2 - 5, set pins as output.
  for (int i = 2; i < 5; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // From pins 2 - 5, do this:
  for (int i = 2; i < 5; i++) {
    // Set the pin to HIGH, (turn on)
    digitalWrite(i, HIGH);
    // Wait 500 ms
    delay(BLINK_DELAY);
    // Set pin to LOW, (turn off)
    digitalWrite(i, LOW);
    // Wait another 500 ms 
    delay(BLINK_DELAY);
  }
}
