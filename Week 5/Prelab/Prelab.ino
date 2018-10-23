// Monty Choy
// Tues -  10/23/18
// Prelab: Arduino Project #1a 
// Arduino Mega sketch that makes your Robot move 
//along a square path, then stop, and then flash the built‐in digital pin 13 LED

//pins to control motor driver
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define LED_PIN 13

//PWM vals to write to motors to determine speed
#define LINEAR_SPEED 255
#define ROTATIONAL_SPEED 255

#define SIDE_DELAY 1000		//delay time to move one side
#define ROTATION_DELAY 100	//delay time to rotate 90 degrees

void setup() {
	//setup pin mode for motor driver pins and LED pin
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode (LED_PIN, OUTPUT);

	//move forward 
	digitalWrite(IN1, LOW);
	analogWrite(IN2, LINEAR_SPEED);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, LINEAR_SPEED);
	delay(SIDE_DELAY);

	//rotate 90 degrees right
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, ROTATIONAL_SPEED);
	delay(ROTATION_DELAY);

	//move forward 
	digitalWrite(IN1, LOW);
	analogWrite(IN2, LINEAR_SPEED);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, LINEAR_SPEED);
	delay(SIDE_DELAY);

	//rotate 90 degrees right
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, ROTATIONAL_SPEED);
	delay(ROTATION_DELAY);

	//move forward 
	digitalWrite(IN1, LOW);
	analogWrite(IN2, LINEAR_SPEED);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, LINEAR_SPEED);
	delay(SIDE_DELAY);

	//rotate 90 degrees right
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, ROTATIONAL_SPEED);
	delay(ROTATION_DELAY);

	//move forward 
	digitalWrite(IN1, LOW);
	analogWrite(IN2, LINEAR_SPEED);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, LINEAR_SPEED);
	delay(SIDE_DELAY);

	//rotate 90 degrees right
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, ROTATIONAL_SPEED);
	delay(ROTATION_DELAY);

	//stop all motors
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);

	//flash LED
	digitalWrite(LED_PIN, HIGH);
	delay(100);
	digitalWrite(LED_PIN, LOW);
	delay(100);
	digitalWrite(LED_PIN, HIGH);
	delay(100);
	digitalWrite(LED_PIN, LOW);
	delay(100);
	digitalWrite(LED_PIN, HIGH);
	delay(100);
	digitalWrite(LED_PIN, LOW);

}

void loop() {
	
}