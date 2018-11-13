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
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);

	unsigned long pulseWidth = pulseIn(ECHO_PIN, HIGH);
	float distance = calculateDistanceFromPulseWidth(pulseWidth);

	Serial.println("DIstance: " + (String)distance);

	delay(500);
}

//calculate distance based on pulse width
double calculateDistanceFromPulseWidth(double pulseWidth) {
  if (pulseWidth < 300){
    return 0;
  } else {
    return pulseWidth / 144;
  }

}
