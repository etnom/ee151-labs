#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

void setup() {
	for (int i = 4; i < 8; i++) {
		pinMode(i, OUTPUT);
	}
}

void loop() {
	rightMotor(100);
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
