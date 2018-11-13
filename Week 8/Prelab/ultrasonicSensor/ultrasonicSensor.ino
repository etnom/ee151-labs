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

#define SERVO_PIN 11    //servo pin
#define LED_PIN 13    //led pin, built in
#define BUZZER_PIN 50

Servo ultrasonicServo;

void setup() {
  Serial.begin(9600);

  initMotorPins();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  //init servo stuff
  ultrasonicServo.attach(SERVO_PIN);
  ultrasonicServo.write(90);

}

void loop() {
  //set echo pin to high for 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  //read echo pin
  double pulseWidth = pulseIn(ECHO_PIN, HIGH, 4000); 

  //calcualte distance
  double distance = calculateDistanceFromPulseWidth(pulseWidth);  

  toggleLED(distance);  //turn LED or/off depending on distance
  buzzBuzzer(distance);   // play buzzer depending on distance
  
  //print distance and pulse width to Serial
  Serial.println("Pulse length: " + (String)pulseWidth);
  Serial.println("Distance: " + (String)distance);

  delay(500);

}


//function to set pinModes of motor pins
void initMotorPins() {
  for (int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);   //set all motor pins as output
    digitalWrite(i, LOW);
  }
}

//calculate distance based on pulse width
double calculateDistanceFromPulseWidth(double pulseWidth) {
  if (pulseWidth < 300){
    return 0;
  } else {
    return pulseWidth / 37;
  }

}

//turn LED or/off depending on distance
void toggleLED(double distance) {
  if (distance < 6){
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
  }
}

// play buzzer depending on distance
void buzzBuzzer(double distance) {
  if (distance < 20){
    int f = map(distance, 0, 20, 2000, 100);
    tone(BUZZER_PIN, f);
  }
}


