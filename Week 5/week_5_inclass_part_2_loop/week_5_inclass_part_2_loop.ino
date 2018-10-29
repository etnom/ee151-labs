const int time90deg = 200; //time to rotate 90 degrees
const int timeForward = 1000; //time robot moves forward in square
const int L1 = 6; //set L1 equal to pin 6, left motor backward
const int L2 = 7; //set L2 equal to pin 7, left motor forward
const int R1 = 4; //set R1 equal to pin 4, right motor backward
const int R2 = 5; //set R2 equal to pin 5, right motor foreward
const int led = 13; // set led equal to pin 13
const int timeLoop = 3000; //set loop time to 3 seconds

void setup() {
  pinMode(L1,OUTPUT); // set L1 as an output
  pinMode(L2,OUTPUT); //set L2 as an output
  pinMode(R1,OUTPUT); //set R1 as an output
  pinMode(R2,OUTPUT); //set R2 as an output

  pinMode(led,OUTPUT); //set led as an output

 
}

void loop(){
  trace1Side();
  pivotRight();
  trace1Side();
  pivotRight();
  trace1Side();
  pivotRight();
  trace1Side();
  pivotRight();
  flashLED();
  flashLED();
  delay(timeLoop);
}


void trace1Side(){
  digitalWrite(R2,HIGH); //move the right wheel forward
  digitalWrite(L2,HIGH); // move the left wheel forward
  delay(timeForward); //time to move forward
  digitalWrite(R2,LOW);//turn right motor off
  digitalWrite(L2,LOW); //turn right motor off 
}

void pivotRight(){
  digitalWrite(R2,HIGH); //move the right wheel forward
  digitalWrite(L1,HIGH); // move the left wheel backward
  delay(time90deg); //time to turn
  digitalWrite(R2,LOW); //turn the right motor off
  digitalWrite(L1,LOW); //turn the left motor off
}

void flashLED(){
  digitalWrite(led,HIGH); //turn LED light on
  delay(1000); //time for the light to be on
  digitalWrite(led,LOW); //turn the LED light off
  delay(1000); //time the LED to be off
}
