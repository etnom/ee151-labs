// Prelab assignment: Joystick remote control interpreter
// Prints onto Serial monitor analog, voltage, and interpreted readings of joystic position
// By Monty Choy
// EE 151-2 LAB
// Monday, October 08, 2018

#include <SoftwareSerial.h>		//lib for serial functions

#define V_AR 4.7		//voltage of arduino

#define X_PIN 0			//X axis of joystick at analog pin 0
#define Y_PIN 1			//Y axis of joystick at analog pin 1

void setup() {
	Serial.begin(9600);		//begin serial at 9600 Baud
}

void loop() {
	//use loop so I only need to type code once
	for (int i = 0; i < 2; i++) {
    //determine whether X or Y
		int r = i ? analogRead(Y_PIN) : analogRead(X_PIN);		
    //string to concat based on whether reading X or Y
		String xOrY = " " + (String)(i ? "Y" : "X") + ": ";		
		float v = V_AR * ((float)r/1023.0);		//voltage 

		//print analog reading of pin
		Serial.print("Analog reading" + xOrY + (String)r + "   ");
    //print voltage	
		Serial.print("Voltage" + xOrY + (String)v + "   ");			
    //print computed val
		Serial.print("Position" + xOrY + (String)map(v, 0, 4.7, -100, 100) + "\n");	
	}

  //print extra 2 lines to differentiate between readings
	Serial.println("\n");	
  	
	delay(500);
}
