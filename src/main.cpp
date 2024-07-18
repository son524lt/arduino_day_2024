#include <main.hpp>

esp32_motor leftMotor(PWM_PIN_L_A, PWM_PIN_L_B, left_motor_chanel_a, left_motor_chanel_b, 5000, 12);
esp32_motor rightMotor(PWM_PIN_R_A, PWM_PIN_R_B, right_motor_chanel_a, right_motor_chanel_b, 5000, 12);

void setup() {
  leftMotor.Init();
  rightMotor.Init();
}

void loop() {
  leftMotor.RunPercent(100);
  rightMotor.RunPercent(100);
  delay(1000);
  leftMotor.RunPercent(0);
  rightMotor.RunPercent(0);
  delay(1000);
  leftMotor.RunPercent(-100);
  rightMotor.RunPercent(-100);
  delay(1000);
  leftMotor.Stop();
  rightMotor.Stop();
  delay(1000);
}