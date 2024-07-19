#include <main.hpp>
#include <Wire.h>
// // esp32_motor leftMotor(PWM_PIN_L_A, PWM_PIN_L_B, left_motor_chanel_a, left_motor_chanel_b, 5000, 12);
// // esp32_motor rightMotor(PWM_PIN_R_A, PWM_PIN_R_B, right_motor_chanel_a, right_motor_chanel_b, 5000, 12);

// Adafruit_TCS34725 color = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
TCS34725 tcs;
// rData rawColor;
// colorData floatColor;

void scan_i2c();

void setup() {
  // set wire clock to 400kHz
  // Wire.begin(8,9,400000);
  Serial.begin(9600);
  Wire.begin();
  // if (!tcs.attach(Wire))
  //   Serial.println("ERROR: TCS34725 NOT FOUND !!!");
  // tcs.integrationTime(33); // ms
  // tcs.gain(TCS34725::Gain::X01);
  // pinMode(7, INPUT_PULLUP);
  // pinMode(PWM_PIN_L_A, OUTPUT);
  // pinMode(PWM_PIN_L_B, OUTPUT);
  // pinMode(PWM_PIN_R_A, OUTPUT);
  // pinMode(PWM_PIN_R_B, OUTPUT);
  // digitalWrite(PWM_PIN_L_A, LOW);
  // digitalWrite(PWM_PIN_L_B, LOW);
  // digitalWrite(PWM_PIN_R_A, LOW);
  // digitalWrite(PWM_PIN_R_B, LOW);
  // pinMode(W_LED, OUTPUT);
  // digitalWrite(W_LED, LOW);
  // pinMode(IR_LED, OUTPUT);
  // digitalWrite(IR_LED, LOW);
}

void loop() {
  if (tcs.available()) {
    TCS34725::Color color = tcs.color();
    Serial.print("Color Temp : "); Serial.print(tcs.colorTemperature());
    Serial.print("\tLux        : "); Serial.print(tcs.lux());
    Serial.print("\tR          : "); Serial.print(color.r);
    Serial.print("\tG          : "); Serial.print(color.g);
    Serial.print("\tB          : "); Serial.println(color.b);
  }
}

void scan_i2c() {
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    Serial.print("Scanning at: ");
    Serial.println(address, HEX);
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    } else if (error==4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }
    delay(10);
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
}