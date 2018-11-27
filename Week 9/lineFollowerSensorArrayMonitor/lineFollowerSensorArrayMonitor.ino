// Monty Choy 
// EE 151-02
// Mon - 11/26/18
// Reads all 5 line sensors and returns a single digital code word that indicates 
// if each sensor is over a black or white surface

//pins for line sensors in arr, parallels arr for digital outputs
//first item far left sensor pin, goes from left to right
const int SENSOR_PINS[] = {15, 14, 13, 12, 11};

//digital pins corresponding to line sensors, parallels SENSOR_PINS
const int DIGITAL_PINS[] = {43, 45, 47, 49, 51};

const int ARR_LENGTH = 5;				//length of arrays that store pins 
 
const int THRESHOLD = 10;				//threshold for when reading should be determined as white or black surface

void setup() {
	Serial.begin(9600);					//begin serial at 9600 baud rate

	//set all digital pins as outputs
	for (int i = 0; i < ARR_LENGTH; i++) {
		pinMode(DIGITAL_PINS[i], OUTPUT);
	}

}

void loop() {

}

bool getPathSensorStates() {
	byte sensorStates;

	for (int i = 0; i < ARR_LENGTH; i++) {
		//read sensors for all sensor pins, store the return value of that as a sensor state
		bitWrite(sensorStates, (i + 1), readLineSensor(SENSOR_PINS[i], DIGITAL_PINS[i]));
	}

	Serial.println(sensorStates, BIN);

	return sensorStates;
}

//reads line sensor and returns a value and writes to a pin depending on reading
int readLineSensor(int sensorAnalogInPin, int sensorDigitalOutPin) {
	int analogReading = analogRead(sensorAnalogInPin);		//store reading in var 
	Serial.print((String)analogReading + " ");

	//analog reading greater than threshold, so over black
	if (analogReading > THRESHOLD) {
		digitalWrite(sensorDigitalOutPin, HIGH);
		return 1;
	}

	//analog reading less than threshold or equal to threshold, so over white
	digitalWrite(sensorDigitalOutPin, LOW);
	return 0;
}
