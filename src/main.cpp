#include <main.hpp>

// esp32_motor leftMotor(PWM_PIN_L_A, PWM_PIN_L_B, left_motor_chanel_a, left_motor_chanel_b, 5000, 12);
// esp32_motor rightMotor(PWM_PIN_R_A, PWM_PIN_R_B, right_motor_chanel_a, right_motor_chanel_b, 5000, 12);

Adafruit_TCS34725 color = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);

rData rawColor;
colorData floatColor;

void setup() {
  Wire.begin();
  color.begin();
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  pinMode(PWM_PIN_L_A, OUTPUT);
  pinMode(PWM_PIN_L_B, OUTPUT);
  pinMode(PWM_PIN_R_A, OUTPUT);
  pinMode(PWM_PIN_R_B, OUTPUT);
  digitalWrite(PWM_PIN_L_A, LOW);
  digitalWrite(PWM_PIN_L_B, LOW);
  digitalWrite(PWM_PIN_R_A, LOW);
  digitalWrite(PWM_PIN_R_B, LOW);
  pinMode(W_LED, OUTPUT);
  digitalWrite(W_LED, LOW);
  pinMode(IR_LED, OUTPUT);
  digitalWrite(IR_LED, LOW);
}

void loop() {
  color.getRawData(&(rawColor.r), (&rawColor.g), (&rawColor.b), (&rawColor.c));
  color.getRGB(&(floatColor.r), &(floatColor.g), &(floatColor.b));
  Serial.print("R: "); Serial.print(rawColor.r); Serial.print("\tG: "); Serial.print(rawColor.g); Serial.print("\tB: "); Serial.print(rawColor.b); Serial.print("\tC: "); Serial.print(rawColor.c);
  Serial.print("\tRed: "); Serial.print(floatColor.r); Serial.print("\tGreen: "); Serial.print(floatColor.g); Serial.print("\tBlue: "); Serial.println(floatColor.b);
  delay(100);
}