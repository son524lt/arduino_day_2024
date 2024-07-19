#include <color_sensor.hpp>

TCS::TCS(uint8_t address)
  : _address(address) {}

void TCS::begin() {
  Wire.begin();
  
  // Enable the sensor
  write8(0x00, 0x01);  // Power on
  delay(3);  // Wait for power up
  write8(0x00, 0x03);  // Enable ADC

  // Set integration time (2.4 ms)
  write8(0x01, 0xFF);

  // Set gain (1x)
  write8(0x0F, 0x00);
}

void TCS::setIntegrationTime(uint8_t time) {
  write8(0x01, time);
}

void TCS::setGain(uint8_t gain) {
  write8(0x0F, gain);
}

void TCS::write8(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(_address);
  Wire.write(0x80 | reg);  // Command register
  Wire.write(value);
  Wire.endTransmission();
}

uint16_t TCS::read16(uint8_t reg) {
  Wire.beginTransmission(_address);
  Wire.write(0x80 | reg);  // Command register
  Wire.endTransmission();

  Wire.requestFrom(_address, 2);
  uint16_t value = Wire.read();
  value |= (Wire.read() << 8);

  return value;
}

void TCS::readRawData(uint16_t &r, uint16_t &g, uint16_t &b, uint16_t &c) {
  r = read16(0x16);  // Red channel
  g = read16(0x18);  // Green channel
  b = read16(0x1A);  // Blue channel
  c = read16(0x14);  // Clear channel
}