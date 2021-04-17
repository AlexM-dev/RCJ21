#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); 
}

bool line;

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(0x08, 1);
  if (Wire.available()) {
    int an = Wire.read();
    line = false;
    if(an > 50)
      line = true;
    Serial.println(an);
  } else
  Serial.println("error");
}
