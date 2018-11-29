const float SteeringGain = 10;
const int DesiredSpeed = 255;
const float sensorWidth = 5;
const int threshold = 50;

#define LEFTFORWARD 7
#define LEFTBACK 6
#define RIGHTFORWARD 5
#define RIGHTBACK 4


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float PathError = SensePathPositionError(GetPathSensorStates());
  if (PathError < = 2 * sensorWidth){
    AdjustMotorSpeeds(PathError);
    UpdatePointingAngle(PathError);
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
  else if(PathSensorStates == byte(12))distance = -.5; //sensors 2 and 3 read a black line
  else if(PathSensorStates == byte(8)) distance = -1; //sensor 3 reads a black line
  else if(PathSensorStates == byte(24)) distance = -1.5; //sensors 1 and 2 read a black line
  else if(PathSensorStates == byte(16)) distance = -2; //sensor 1 reads a black line
  else if(PathSensorStates == byte(6)) distance = .5; //sensor3 and 4 read a black line
  else if(PathSensorStates == byte(2)) distance = 1; // sensor 4 reads a black line
  else if(PathSensorStates == byte(3)) distance = 1.5; //sensor4 and 5 read a black line
  else if(PathSensorStates == byte(1)) distance = 2; //sensor 5 reads a black line
  else distance = 50;
  
  return sensorWidth * distance;
}

void Move(int LeftSpeed, int RightSpeed){
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
    bitWrite(sensorCode, i, ReadLineSensor2((1 + i), (51 - 2*i)));
  }

  //Serial.println(sensorCode, BIN);
  return sensorCode;
}

