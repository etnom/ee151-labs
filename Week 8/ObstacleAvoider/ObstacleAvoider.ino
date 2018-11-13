
#include <SoftwareSerial.h>

#define ECHO_PIN 5
#define TRIG_PIN 6

#define BUZZER_PIN 3

#define LED_PIN 13

#define PULSEIN_TIMEOUT 4000

float distance;

void setup() {
  Serial.begin(9600);

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

}


void loop() {
  pulseUltrasonicTrigger(); 

  double pulseWidth = findPulseWidth();
  distance = calculateDistanceFromPulseWidth(pulseWidth);

  Serial.println("Pulse width: " + (String)pulseWidth);
  Serial.println("Distance: " + (String)distance);

  obstacleDetector(3);
  
  // pulseLED(distance);
  // buzz(distance, 100);
  

  delay(500);
}

void pulseUltrasonicTrigger() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

double findPulseWidth() {
  double pulseWidth = pulseIn(ECHO_PIN, HIGH, PULSEIN_TIMEOUT);
  if (pulseIn < 300) {
    return 0;
  }

  return pulseWidth;
}

//calculate distance based on pulse width
double calculateDistanceFromPulseWidth(double pulseWidth) {
  if (pulseWidth < 300.0){
    return 0;
  } 

  return pulseWidth / 74 / 2;

}

float obstacleDistance(float withinInches) {
  if (distance > withinInches) {
    digitalWrite(LED_PIN, LOW);
    return 0;
  }

  tone(BUZZER_PIN, map(distance, 0, 20, 2000, 100), 100);
  digitalWrite(LED_PIN, HIGH);
  return distance;
}

bool obstacleDetector(float withinInches) {
  if (obstacleDistance(withinInches) > 0) {
    return true;
  }

  return false;
}
