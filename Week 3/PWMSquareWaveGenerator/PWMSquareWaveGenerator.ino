void setup() {

}

void loop() {
	analogWrite(3, mapperForPWM(5));
	analogWrite(5, mapperForPWM(20));
	analogWrite(6, mapperForPWM(40));
	analogWrite(9, mapperForPWM(60));
	analogWrite(10, mapperForPWM(80));
	analogWrite(11, mapperForPWM(95));

}

int mapperForPWM (int ds) {
	return map(ds, 0, 100, 0, 255);
}
