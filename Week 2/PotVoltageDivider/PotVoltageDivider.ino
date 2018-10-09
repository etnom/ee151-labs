#include <SoftwareSerial.h>

#define V_AR 4.7

void setup() {
	Serial.begin(9600);
}

void loop() {
	int r = analogRead(0);
	float v = V_AR * ((float)r/1023.0);
	float r1 = v/V_AR * 10000.0;

	Serial.print("aRead: " + (String)r + "  ");
	Serial.print("v: " + (String)(v) + "  ");
	Serial.print("R1: " + (String)(r1) + "  ");
	Serial.print("R2: " + (String)(10000.0 - r1) + "  \n\n");

	delay(500);
}