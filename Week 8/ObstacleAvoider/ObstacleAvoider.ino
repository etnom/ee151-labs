//

#include <SoftwareSerial.h>

#define ECHO_PIN 5
#define TRIG_PIN 6

#define BUZZER_PIN 3

#define LED_PIN 13


void setup() {
	Serial.begin(9600);

	pinMode(ECHO_PIN, INPUT);
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(BUZZER_PIN, OUTPUT);
	pinMode(LED_PIN, OUTPUT);

}


void loop() {
	pulseUltrasonicTrigger();	

	double pulseWidth = pulseIn(ECHO_PIN, HIGH);
	float distance = calculateDistanceFromPulseWidth(pulseWidth);

	Serial.println("Pulse width: " + (String)pulseWidth);
	Serial.println("Distance: " + (String)distance);

	if (distance > 6) {
		digitalWrite(LED_PIN, HIGH);
	} else {
		digitalWrite(LED_PIN, LOW);
	}

	if (distance > 20) {
    	tone(BUZZER_PIN, map(distance, 0, 20, 2000, 100));
	}

	delay(500);
}

void pulseUltrasonicTrigger() {
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);
}

//calculate distance based on pulse width
double calculateDistanceFromPulseWidth(double pulseWidth) {
  if (pulseWidth < 300){
    return 0;
  } 

	return pulseWidth / 74 / 2;

}
