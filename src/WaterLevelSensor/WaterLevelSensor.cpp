#include <WaterLevelSensor.h>


WaterLevelSensor::WaterLevelSensor(){
    Wire.begin();
    waterLevel = 0;
}

void WaterLevelSensor::displayData(){

}

void WaterLevelSensor::retrieveData(){

}

void WaterLevelSensor::getHigh12SectionValue()
{
  memset(high_data, 0, sizeof(high_data));
  Wire.requestFrom(0x78, 12);
  while (12 != Wire.available());

  for (int i = 0; i < 12; i++) {
    high_data[i] = Wire.read();
  }
  delay(10);
}


void WaterLevelSensor::getLow8SectionValue()
{
  memset(low_data, 0, sizeof(low_data));
  Wire.requestFrom(0x77, 8);
  while (8 != Wire.available());

  for (int i = 0; i < 8 ; i++) {
    low_data[i] = Wire.read(); // receive a byte as character
  }
  delay(10);
}

int WaterLevelSensor::getPercentage(){
    
    WaterLevelSensor::getLow8SectionValue();
    WaterLevelSensor::getHigh12SectionValue();
    uint32_t touch_val = 0;
    uint8_t trig_section = 0;

    for (int i = 0 ; i < 8; i++) {
      if (low_data[i] > 100) {
        touch_val |= 1 << i;

      }
    }
    for (int i = 0 ; i < 12; i++) {
      if (high_data[i] > 100) {
        touch_val |= (uint32_t)1 << (8 + i);
      }
    }

    while (touch_val & 0x01)
    {
      trig_section++;
      touch_val >>= 1;
    }
    return ((int) trig_section * 5);
}

void WaterLevelSensor::calibrate(){ //Calibration to be used when there is no water
    for (int i = 0; i < 12; i++) {
        high_data[i] = 0;
    }
    for (int i = 0; i < 8 ; i++) {
        low_data[i] = 0; // receive a byte as character
    }
}