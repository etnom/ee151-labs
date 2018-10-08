// Analog and digital signal monitor
// Prints to serial digital and analog readings 
// By Jackson Meyers and Monty Choy
// EE 151-2 LAB
// Tuesday, October 02, 2018

#include <SoftwareSerial.h>			//serial library to utilize serial functions

#define BAUD_RATE 9600				//baud rate 

#define D_PIN 3						//digital pin to read from
#define A_PIN 0						//analog pin to read from

int digVal = 0;						//variable to store digital reading
int anVal = 0;						//variable to store analog  reading

//function that executes once upon startup 
void setup() {
	Serial.begin(BAUD_RATE);		//being serial communication at specific baud rate
	pinMode(D_PIN, INPUT);			//setup digital pin as an input
} 

//function that continually executes throughout lifespan of Arduino
void loop() {
	digVal = digitalRead(D_PIN);	//store digital reading
	anVal = analogRead(A_PIN);		//variable to store analog  reading

	Serial.println("Digital reading: " + (String)digVal);	//print digital reading
	Serial.println("Analog reading: " + (String)anVal);		//print analog reading
	Serial.println();				//print new line

	delay(1000);					//delay by 1 second
}
	