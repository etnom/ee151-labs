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