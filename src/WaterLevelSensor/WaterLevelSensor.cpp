#include <WaterLevelSensor.h>


WaterLevelSensor::WaterLevelSensor(){
  waterLevel = 0;
  low_data = new unsigned char[8];
  high_data = new unsigned char[12];
}

//Connect the sensor to the I2C wire object in Wire.h
void WaterLevelSensor::begin(TwoWire &I2Cpipe){
  dataBus=I2Cpipe;
}

WaterLevelSensor::~WaterLevelSensor(){
  delete[] low_data;
  delete[] high_data;
}


void WaterLevelSensor::retrieveData(){
  WaterLevelSensor::getLow8SectionValue();
  WaterLevelSensor::getHigh12SectionValue();
}

void WaterLevelSensor::getHigh12SectionValue()
{
  //Requesting 12 bytes of data at address 0x78
  dataBus.requestFrom(0x78, 12);
  while (12 != dataBus.available());

  for (int i = 0; i < 12; i++) {
    high_data[i] = dataBus.read();
  }
  delay(10); 
}


void WaterLevelSensor::getLow8SectionValue()
{
  //Requesting 8 bytes of data at address 0x78
  dataBus.requestFrom(0x77, 8);
  while (8 != dataBus.available());

  for (int i = 0; i < 8 ; i++) {
    low_data[i] = dataBus.read(); // receive a byte as character
  }
  delay(10); //Delay to prevent stack errors
}

int WaterLevelSensor::getPercentage(){
    
    WaterLevelSensor::retrieveData();
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

    return  trig_section*5;
}
