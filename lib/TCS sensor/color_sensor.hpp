#ifndef _color_sensor_hpp_ 
#define _color_sensor_hpp_
#include <Wire.h>

#define INTERGRATION_TIME_2_4MS 0xFF
#define INTERGRATION_TIME_24MS 0xF6
#define INTERGRATION_TIME_50MS 0xEB
#define INTERGRATION_TIME_101MS 0xD5
#define INTERGRATION_TIME_154MS 0xC0
#define INTERGRATION_TIME_700MS 0x00

#define GAIN_1X 0x00
#define GAIN_4X 0x01
#define GAIN_16X 0x02
#define GAIN_60X 0x03

class TCS {
  public:
    TCS(uint8_t address = 0x29);
    void begin();
    void readRawData(uint16_t &r, uint16_t &g, uint16_t &b, uint16_t &c);
    void setIntegrationTime(uint8_t time);
    void setGain(uint8_t gain);
    
  private:
    void write8(uint8_t reg, uint8_t value);
    uint16_t read16(uint8_t reg);
    
    uint8_t _address;
};
#endif