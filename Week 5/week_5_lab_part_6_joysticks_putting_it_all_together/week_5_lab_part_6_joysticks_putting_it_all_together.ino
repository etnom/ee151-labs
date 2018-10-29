const int time90deg = 200; //time to rotate 90 degrees
const int timeForward = 1000; //time robot moves forward in square
const int L1 = 6; //set L1 equal to pin 6, left motor backward
const int L2 = 7; //set L2 equal to pin 7, left motor forward
const int R1 = 4; //set R1 equal to pin 4, right motor backward
const int R2 = 5; //set R2 equal to pin 5, right motor foreward
const int led = 13; // set led equal to pin 13
const int timeLoop = 3000; //set loop time to 3 seconds
const int leftStick = 1; //set left stick equal to analog pin 0, analog pins are always set up input
const int rightStick = 0; //set right stick equal to anlog pin 1, analogpins are always set up as input
int leftY = 0; //setting the initial value of left stick equal to 0, will be value between 1 and 1024
int rightY = 0; // setting the initial value of right stick equal to 0, will be value between 1 and 1024
int yL = 0; //set up variables mapped variables
int yR = 0;



void setup() {
  pinMode(L1,OUTPUT); // set L1 as an output
  pinMode(L2,OUTPUT); //set L2 as an output
  pinMode(R1,OUTPUT); //set R1 as an output
  pinMode(R2,OUTPUT); //set R2 as an output
  pinMode(led,OUTPUT); //set led as an output
}

void loop(){
  leftY = analogRead(leftStick);
  rightY = analogRead(rightStick);
  yL = map(leftY,0,1023,100,-100); //inputs for our motor
  yR= map(rightY, 0,1023,100,-100);

  move(yL,yR);
}


void move(int leftSpeed, int rightSpeed){
  int leftSpeedPWM = leftSpeed*2.55;
  int rightSpeedPWM = rightSpeed*2.55;
  
  //turn both motors off
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);

  //make left motor move
  if (leftSpeedPWM < 0) {
    analogWrite(L1, abs(leftSpeedPWM));
  } else {
    analogWrite(L2, leftSpeedPWM);
  }

  //make right motor move
  if (rightSpeedPWM < 0) {
    analogWrite(R1, abs(rightSpeedPWM));
  } else {
    analogWrite(R2, rightSpeedPWM);
  }
}
