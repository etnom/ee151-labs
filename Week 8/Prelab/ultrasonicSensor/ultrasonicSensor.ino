// By Monty Choy 
// Monday 11/12/18
// Week 8 Prelab
// Test and verify operation of ultrasonic sensor

#include <Servo.h>
#include <SoftwareSerial.h>

//pins for motors
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

//pins for ultrasonic sensor
#define TRIG_PIN 40 
#define ECHO_PIN 41

#define RANGE_TIMEOUT 4000		//timeout value

#define SERVO_PIN 11		//servo pin



Servo ultrasonicServo;

void setup() {
	Serial.begin(9600);

	initMotorPins();
	disableMotors();

	//init servo stuff
	ultrasonicServo.attach(SERVO_PIN);
	ultrasonicServo.write(90);

}

void loop() {

}


//function to set pinModes of motor pins
void initMotorPins() {
	for (int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);		//set all motor pins as output
  }
}

//function to disable motor pins
void disableMotors() {
	for (int i = 4; i < 8; i++) {
  }
}

