//servo library
#include <Servo.h>

//pins for motor control
#define LEFTFORWARD 7
#define LEFTBACK 6
#define RIGHTFORWARD 5
#define RIGHTBACK 4

//pin for buzzer
#define BUZZER 48

//pins for ultrasonic sensor
#define ECHOPIN 41
#define TRIGGERPIN 40

//pin for servo with ultrasonic sensor mounted on it
#define SERVOPIN 11   

//pin for servo that drops the egg
#define EGGPIN 18

//constants for properly rotating and positioning servos and motors
const float SteeringGain = 10;
const int DesiredSpeed = 80;
const float sensorWidth = 6;
const int threshold = 35;
const int PointStraightAheadAngle = 90;
const float PointingGain = 1.5;

//servo objects 
Servo pointy_servo;
Servo egg_servo;

//flags to determine movement
bool is_stopped = false;
bool still_there = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //set up servos 
  pointy_servo.attach(SERVOPIN);
  egg_servo.attach(EGGPIN);
  egg_servo.write(90);

  //pinmode setup
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGGERPIN, OUTPUT);
  delay(1000);
}

void loop() {
  //this code will loop repeatedly

  DetectObstacle();

  if(!is_stopped){
  // put your main code here, to run repeatedly:
    float PathError = SensePathPositionError(GetPathSensorStates());
    if (PathError <= 2 * sensorWidth){
      AdjustMotorSpeeds(PathError);
      pointy_servo.write(UpdatePointingAngle(PathError));
    }
  }
}

void AdjustMotorSpeeds(float PathError){
  float SpeedAdjustmentPercent = SteeringGain * PathError;
  
  int RightMotorSpeed = (100.0 - SpeedAdjustmentPercent)*DesiredSpeed/100;
  int LeftMotorSpeed = (100.0 + SpeedAdjustmentPercent)*DesiredSpeed/100;
  if (LeftMotorSpeed > 255) LeftMotorSpeed = 255;
  if (RightMotorSpeed > 255) RightMotorSpeed = 255;
  Serial.print("RIGHT: " + String(RightMotorSpeed));
  Serial.println("   LEFT: " + String(LeftMotorSpeed) + "\n");
  Move(LeftMotorSpeed, RightMotorSpeed);
}

float SensePathPositionError( byte PathSensorStates){
  float distance;
  if (PathSensorStates == byte(4))return 0.0;
  //sensors 2 and 3 read a black line
  else if(PathSensorStates == byte(12))distance = -.5; 
  //sensor 3 reads a black line
  else if(PathSensorStates == byte(8)) distance = -1; 
  //sensors 1 and 2 read a black line
  else if(PathSensorStates == byte(24)) distance = -1.5; 
  else if (PathSensorStates == byte(28)) distance = -1.75;
  //sensor 1 reads a black line
  else if(PathSensorStates == byte(16)) distance = -2; 
  //sensor3 and 4 read a black line
  else if(PathSensorStates == byte(6)) distance = .5;
  // sensor 4 reads a black line 
  else if(PathSensorStates == byte(2)) distance = 1; 
  //sensor4 and 5 read a black line
  else if(PathSensorStates == byte(3)) distance = 1.5; 
  //sensor 3, 4, and 5 read a black line
  else if (PathSensorStates == byte(7)) distance = 1.75; 
  //sensor 5 reads a black line
  else if(PathSensorStates == byte(1)) distance = 2; 
  else if(PathSensorStates == byte(31)){
    is_stopped = true;
    Move(0,0);
    ReleaseEgg();
    
  }
  else distance = 50;
  
  return sensorWidth * distance;
}

//function to move
void Move(int LeftSpeed, int RightSpeed){
  //
  analogWrite(LEFTFORWARD, LeftSpeed);
  analogWrite(RIGHTFORWARD, RightSpeed);
}


int ReadLineSensor(int SensorAnalogInPin, int SensorDigitalOutPin)
{
  int analogVal = analogRead(SensorAnalogInPin);
  //Serial.print(analogVal);
  //Serial.print(" ");
  
  //evaluate based on threshold
  if(analogVal >= threshold)
  {
    //output to digital pin
    digitalWrite(SensorDigitalOutPin, HIGH);
      
    return 1;
  }
  else
  {
    //output to digital pin
    digitalWrite(SensorDigitalOutPin, LOW);
    
    return 0;
  }
}

//function to get a byte form for sensor states
byte GetPathSensorStates()
{
  //initialize variable for return
  byte sensorCode = 0;

  ReadLineSensor(5, 43);
  ReadLineSensor(4, 45);
  ReadLineSensor(3, 47);
  ReadLineSensor(2, 49);
  ReadLineSensor(1, 51);

  for(int i=0; i<=4; i++)
  {
    bitWrite(sensorCode, i, ReadLineSensor((1 + i), (51 - 2*i)));
  }

  //Serial.println(sensorCode, BIN);
  return sensorCode;
}


int UpdatePointingAngle( float PathError){
  return PointStraightAheadAngle + PointingGain * PathError;
}

//function to release egg
void ReleaseEgg() {
  //number of times to beep
  int numBeeps = 3;
  //beep 3 times with buzzer
  for (int i = 0; i < numBeeps; i++){
    
    tone(BUZZER,440,100.0);
    delay(250);
  }
  //drop egg
  egg_servo.write(0);
  //robot is stopped
  is_stopped = true;
  //infinite for loop
  for(;;){}
}

//function to detect obstacles
void DetectObstacle(){ 
  //nothing is in front of robot 
  if (!still_there){  
    //get distance using ultrasonic sensor
    double pulse = PulseForObstacle();

    //print out distance
    Serial.println(pulse);
  
    //if robot can crash into a detected object
    if(pulse < 10 && pulse > 0){
      //print that the robot has stopped
      Serial.println("Stopped");
      //stop the robot
      Move(0,0);
      //set flag that it has stopped
      is_stopped = true;
      //output tone through buzzer
      tone(BUZZER,440,100.0);
      //delay for two seconds
      delay(2000);
      //check if obstacle is still there
      double secpulse = PulseForObstacle();
      //if obstacle is still there
      if (secpulse < 10 && secpulse > 0){
        //stop object flag
        is_stopped = false;
        //obstacle is still there
        still_there = true;
      }

      //return, so else statement no longerneeded
      return;
    } 
  
    is_stopped = false;
  }
}

//function for operation of ultrasonic sensor
double PulseForObstacle(){
  //send pulse to trigger of ultrasonic sensor
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN,LOW);
  
  //read pulse and convert to inches
  double pulse = pulseIn(ECHOPIN,HIGH,4000)/74.0/2.0;

  //return pulse
  return pulse;
}
