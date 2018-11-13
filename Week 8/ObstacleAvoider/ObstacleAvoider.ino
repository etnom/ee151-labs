// By Jonathon Yu, Drew Evans, Monty Choy, Jackson Meyers
// Lab bench 11 and 12
// Tues, 11/13/18
// EE 151 Lab
// Uses ultrasonic sensor to check distance and make decisions based on object distances

#include <SoftwareSerial.h>

#define ECHO_PIN 5    //echo pin from ultrasonic sensor
#define TRIG_PIN 6    //trigger pin from ultrasonic sensor

#define BUZZER_PIN 3  //buzzer pin
  
#define LED_PIN 13    //built in led pin

#define PULSEIN_TIMEOUT 4000    //pulse timeout for pulseIn()

float distance;   //distance

void setup() {
  Serial.begin(9600);

  //setup pins for ultrasonic sensor, LED, and buzzer
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

}


void loop() {
  pulseUltrasonicTrigger();     //pulse ultrasonic sensor to create a ping

  double pulseWidth = findPulseWidth();   //find pulse width using pulseIn()
  distance = calculateDistanceFromPulseWidth(pulseWidth);   //calculate distance based on pulse width

  //print pulsewidth and distance to serial monitor
  Serial.println("Pulse width: " + (String)pulseWidth);
  Serial.println("Distance: " + (String)distance);


  obstacleDetector(3);    //check if object is within 3 inches of sensor

  delay(500);
}

//pulse ultrasonic sensor to create a ping
void pulseUltrasonicTrigger() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

//find pulse width using pulseIn()
double findPulseWidth() {
  double pulseWidth = pulseIn(ECHO_PIN, HIGH, PULSEIN_TIMEOUT);
  //if pulseWidth less than 300, bad value 
  if (pulseWidth < 300) {
    return 0;
  }

  return pulseWidth;
}

//calculate distance based on pulse width
double calculateDistanceFromPulseWidth(double pulseWidth) {
  return pulseWidth / 74 / 2;   //convert time to inches

}

//check if obstacle is within distance
//if it is, return distance
//if not, reutrn false
float obstacleDistance(float withinInches) {
  //if obstacle not within withinInches, turn LED off and return 0
  if (distance > withinInches) {
    digitalWrite(LED_PIN, LOW);
    return 0;
  }

  tone(BUZZER_PIN, map(distance, 0, 20, 2000, 100), 100);   //buzz buzzer with frequency proportional to distance
  digitalWrite(LED_PIN, HIGH);    //turn on LED
  return distance;    //return distance
}

//check if obstacle is within given distance,  returns true if so
bool obstacleDetector(float withinInches) {
  //check to see if object is within withinInches using obstacleDistance
  return obstacleDistance(withinInches) > 0;
}
