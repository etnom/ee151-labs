// By Monty Choy 
// Monday 11/12/18
// Week 8 Prelab
// Test and verify operation of ultrasonic sensor

//pins for motors
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

void setup() {
	initMotorPins();
	disableMotors();
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
    digitalWrite(i, LOW);		//set all pins to low
  }
}
