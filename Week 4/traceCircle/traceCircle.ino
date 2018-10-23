// EE151 - 02 Circle sketch
// Jackson Meyers, Monty Choy

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

// setup pins
void setup() {
	for (int i = 4; i < 8; i++) {
		pinMode(i, OUTPUT);
	}
}

void loop() {
	// Move right faster than left to turn in a circle
	leftMotor(50);
	rightMotor(150);
	// do this for 5.29 seconds
	delay(5290);
	// stop
	stopAllMotors();
}

//neg speed = backwards
void rightMotor(int speed) {
	if (speed > 0) {
		digitalWrite(IN1, LOW);
		analogWrite(IN2, abs(speed));

		return;
	}

	digitalWrite(IN2, LOW);
	analogWrite(IN1, abs(speed));

}

//neg speed = backwards
void leftMotor(int speed) {
	if (speed > 0) {
		digitalWrite(IN3, LOW);
		analogWrite(IN4, abs(speed));

		return;
	}

	digitalWrite(IN4, LOW);
	analogWrite(IN3, abs(speed));

}

void stopRightMotor() {
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}

void stopLeftMotor() {
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}

void stopAllMotors() {
	for (int i = 4; i < 8; i++) {
		digitalWrite(i, LOW);
	}
}

