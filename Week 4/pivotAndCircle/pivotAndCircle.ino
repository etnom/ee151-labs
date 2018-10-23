// EE 151 - 02 Pivot and Circle sketch
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

void loop() 
{
  // Move backwards for one sec
  rightMotor(-255);
  leftMotor(-255);
  delay(1000);
  // Halt
  stopAllMotors();
  delay(1000);
  // Pivot and stop
  rightMotor(255);
  leftMotor(-255);
  delay(250);
  stopAllMotors();

  // Wait
  delay(100);

  // Move in a circle
  leftMotor(50);
  rightMotor(150);
  // Do this for 5.29 seconds to complete the proper revolutions
  delay(5290);
  // Stop
  stopAllMotors();

  // Wait for 3 seconds before the loop restarts
  delay(3000);

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

void stopAllMotors() {
  for (int i = 4; i < 8; i++) {
    digitalWrite(i, LOW);
  }
}
