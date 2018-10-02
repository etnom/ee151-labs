// Arduino digtal voltmeter
// Prints onto Serial monitor the voltage calulcated based on an analog voltage input
// By Jackson Meyers and Monty Choy
// EE 151-2 LAB
// Tuesday, October 02, 2018

#include <SoftwareSerial.h>			//serial library to utilize serial functions

#define BAUD_RATE 9600				//baud rate 

#define VOLT_IN 5.0f				//input reference voltage

#define A_PIN 0						//analog pin to read from

float anVal = 0;					//variable to store analog  reading

void setup() {
  Serial.begin(BAUD_RATE);			//setup digital pin as an input
} 

void loop() {
  anVal = VOLT_IN * (float)(analogRead(A_PIN) / 1023.0); // Read the analog value in and convert to voltage.

  Serial.println("Voltage: " + (String)anVal);		//print voltage
  Serial.println();					//print new line

  delay(1000);						//delay by 1 second
}
