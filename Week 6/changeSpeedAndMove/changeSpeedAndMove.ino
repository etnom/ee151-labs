#define IN1 4 //right motor backward
#define IN2 5 //right motor forward
#define IN3 6 //left motor backward
#define IN4 7 //left motor forward
int speed = 0;

void setup() {
 
  for (int i = 4; i < 8; i++) { // from pin 4 to pin 7 because 7 is less than 8, i++ means i+1 
    pinMode(i,OUTPUT);
  }
}


void loop() {
  

}

void changeSpeed(int speedVar) { //speedVar is the number that we input
  speed = 25.5*speedVar; //we multiply speedVar (a number multiplied by 25.5 because 25.5 is 10% of 255 which the analog value. do get a percentage of speed
  if(speedVar == 0) {
    speed = 255; // if speedVar is 0, the speed is 255 which is equal to 100% of the speed because dutycycle is from 0-255
  }
     
}

void moveForward() {
  digitalWrite(IN1, LOW); //turn right motor backward off
  digitalWrite(IN2, speed); //turn right motor forward on at the speed that we set it to
  digitalWrite(IN3, LOW); //turn left motor backward off 
  digitalWrite(IN4, speed); //turn left motor forward on at the speed that we set it to
  
  
  
}

void rightPivot() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,speed);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
}

void leftPivot() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,speed);
}

void stop () {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

