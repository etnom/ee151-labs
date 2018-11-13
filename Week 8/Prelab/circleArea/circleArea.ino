#include <SoftwareSerial.h>

float area = 0;

void setup() {
	Serial.begin(9600);

	area = circleArea(9.2);

	Serial.print("Area of circle is: ");
	Serial.println(area, 4);
}

void loop() {

}

double circleArea(float radius) {
	float result;

	result = 3.141592654 * radius * radius;

	return result;
}
