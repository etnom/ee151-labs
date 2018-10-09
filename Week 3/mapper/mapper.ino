#include <SoftwareSerial.h>

#define VAL_TO_MAP 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println((String)mapper(VAL_TO_MAP));
}

int mapper (int ds) {
  return map(ds, 0, 100, 0, 255);
}