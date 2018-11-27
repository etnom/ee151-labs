// Monty Choy 
// EE 151-02
// Mon - 11/26/18
// Sketch to read and evaluate analog reading from one line sensor 
// Function returns 1 and sets digital output to high if over a black line
// returns 0 and sets digital output to low if over white

#define SENSOR_ANALOG_IN_PIN 0			//pin for sensor
#define SENSOR_DIGITAL_OUT_PIN 3		//

const int THRESHOLD = 10;				//threshold for when reading should be determined as white or black surface

void setup() {
	Serial.begin(9600);					//begin serial at 9600 baud rate

	pinMode(SENSOR_DIGITAL_OUT_PIN, OUTPUT);		//digital pin set to output
}

void loop() {
	readLineSensor(SENSOR_ANALOG_IN_PIN, SENSOR_DIGITAL_OUT_PIN);
}

//reads line sensor and returns a value and writes to a pin depending on reading
int readLineSensor(int sensorAnalogInPin, int sensorDigitalOutPin) {
	int analogReading = analogRead(sensorAnalogInPin);		//store reading in var 
	Serial.print((String)analogReading);

	//analog reading greater than threshold, so over black
	if (analogReading > THRESHOLD) {
		digitalWrite(sensorDigitalOutPin, HIGH);
		return 1;
	}

	//analog reading less than threshold or equal to threshold, so over white
	digitalWrite(sensorDigitalOutPin, LOW);
	return 0;
}
