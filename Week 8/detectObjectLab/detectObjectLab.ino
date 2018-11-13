#include <Servo.h>

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define ECHO_PIN 41    //echo pin from ultrasonic sensor
#define TRIG_PIN 40    //trigger pin from ultrasonic sensor

#define BUZZER_PIN 3  //buzzer pin

#define LED_PIN 13    //built in led pin
#define PULSEIN_TIMEOUT 4000    //pulse timeout for pulseIn()


const float withinDistance = 6.5;
const float maxDistance = 20.0;
int servoPin = 11;
Servo Servo1;

double distance;

void setup() {
  Serial.begin(9600);

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Servo1.attach(servoPin);

}


void loop() {
  pulseUltrasonicTrigger();     
  double pulseWidth = findPulseWidth();   //find pulse width using pulseIn()

  distance = calculateDistanceFromPulseWidth(pulseWidth);   //calculate distance based on pulse width

  //print pulsewidth and distance to serial monitor
  Serial.println("Pulse width: " + (String)pulseWidth);
  Serial.println("Distance: " + (String)distance);
  
  if (ObstacleDetected(withinDistance)) {
    float leftDistance = 0.0;
    float rightDistance = 0.0;
    allStop();
    Servo1.write(0);
    leftDistance = ObstacleDistance(maxDistance); //finding the distance away from object to the left side
    Servo1.write(180);
    rightDistance = ObstacleDistance(maxDistance); //finding the distance away from object to the right side
    Servo1.write(90);
    if (leftDistance != 0 || rightDistance != 0) { // if left distance is not 0 or right distance is not 0, then move backward and stop
      moveBackward();
      delay(250);
      allStop();
    }

    if (leftDistance != 0 && rightDistance != 0) {
      rightPivot();
      delay(1000);
      allStop();
    }

    else if (leftDistance < rightDistance) {
      rightPivot();
      delay(500);
    }

    else {
      leftPivot();
      delay(500);

    }

  } else {
    moveForward();

  }

}

void allStop () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(IN1, 200); //turn right motor backward off
  digitalWrite(IN2, LOW); //turn right motor forward on at the speed that we set it to
  analogWrite(IN3, 200); //turn left motor backward off
  digitalWrite(IN4, LOW); //turn left motor forward on at the speed that we set it to
}

void moveForward() {
  digitalWrite(IN1, LOW); //turn right motor backward off
  analogWrite(IN2, 200); //turn right motor forward on at the speed that we set it to
  digitalWrite(IN3, LOW); //turn left motor backward off
  analogWrite(IN4, 200); //turn left motor forward on at the speed that we set it to

}

void rightPivot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void leftPivot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void pulseUltrasonicTrigger() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

//find pulse width using pulseIn()
double findPulseWidth() {
  double pulseWidth = pulseIn(ECHO_PIN, HIGH, PULSEIN_TIMEOUT);
  //if pulseWidth less than 300, bad value
  if (pulseWidth < 300) {
    return 0;
  }

  return pulseWidth;
}

//calculate distance based on pulse width
double calculateDistanceFromPulseWidth(double pulseWidth) {
  return pulseWidth / 74 / 2;   //convert time to inches

}

//check if obstacle is within distance
//if it is, return distance
//if not, reutrn false
float ObstacleDistance(float withinInches) {
  //if obstacle not within withinInches, turn LED off and return 0
  if (distance > withinInches) {
    digitalWrite(LED_PIN, LOW);
    return 0;
  }

  tone(BUZZER_PIN, map(distance, 0, 20, 2000, 100), 100);   //buzz buzzer with frequency proportional to distance
  digitalWrite(LED_PIN, HIGH);    //turn on LED
  return distance;    //return distance
}

//check if obstacle is within given distance,  returns true if so
bool ObstacleDetected(float withinInches) {
  //check to see if object is within withinInches using obstacleDistance
  if (ObstacleDistance(withinInches) > 0) {
    return true;
  }

  return false;
}
