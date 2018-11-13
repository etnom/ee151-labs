//

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

	pulseLED(distance);
	buzz(distance, 100);
	

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
  if (pulseWidth < 300){
    return 0;
  } 

	return pulseWidth / 74 / 2;

}

void pulseLED(float distance) {
	if (distance < 6) {
		digitalWrite(LED_PIN, HIGH);
	} else {
		digitalWrite(LED_PIN, LOW);
	}
}

void buzz(float distance, int buzzerDuration) {
	if (distance < 20) {
  	tone(BUZZER_PIN, map(distance, 0, 20, 2000, 100), buzzerDuration);
	} else {
		noTone(BUZZER_PIN);	
	}
}

bool obstacleDetector(float withinInches) {
	if (distance < withinInches) {
		return true;
	}

	return false;
}
