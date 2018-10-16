#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

void setup() {
  for (int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() 
{
  rightMotor(-255);
  leftMotor(-255);
  delay(1000);
  stopAllMotors();
  delay(1000);
  rightMotor(255);
  leftMotor(-255);
  delay(250);
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

void stopAllMotors() {
  for (int i = 4; i < 8; i++) {
    digitalWrite(i, LOW);
  }
}
