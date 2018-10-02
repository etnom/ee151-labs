// Analog and digital signal monitor
// By Jackson Meyers and Monty Choy
// EE 151-2 LAB
// Tuesday, October 02, 2018

#include <SoftwareSerial.h>

#define BAUD_RATE 9600

#define D_PIN 3
#define A_PIN 0

int digVal = 0;
int anVal = 0;

void setup() {
	pinMode(D_PIN, INPUT);
} 

void loop() {
	digVal = digitalRead(D_PIN);
	anVal = analogRead(A_PIN);

	Serial.println("Digital reading: " + (String)digVal);
	Serial.println("Analog reading: " + (String)anVal);
	Serial.println();

	delay(1000);
}