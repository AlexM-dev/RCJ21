#include "Light.h"

LightSensor::LightSensor(){
  line = false;
  angle = 0;

  /*lineSerial = new SoftwareSerial(LINE_RX, LINE_TX);
  lineSerial->begin(115200);*/
  Wire.begin();
}

void LightSensor::update(){
  angle = getValueFromSensor();
}


int LightSensor::getAngle(){
  return angle;
}

bool LightSensor::isLine(){
  return line;
}

int LightSensor::getValueFromSensor(){

  Wire.requestFrom(8, 1);

  if (Wire.available()) {
    int c = Wire.read();
    line = false;
    if(c > 0) 
      line = true;
    angle = c;
  }

  return angle;
}
