#include <Arduino.h>
#include <motor.hpp>
#include <linePID.hpp>
#include <color_sensor.hpp>

#define PWM_PIN_L_A 2
#define PWM_PIN_L_B 10
#define PWM_PIN_R_A 6
#define PWM_PIN_R_B 5

#define W_LED 20
#define IR_LED 21

#define SENSOR_1_PIN 4
#define SENSOR_2_PIN 3
#define SENSOR_3_PIN 1
#define SENSOR_4_PIN 0

struct rData {
    uint16_t r = 0;
    uint16_t g = 0;
    uint16_t b = 0;
    uint16_t c = 0;
};

struct colorData {
    float r = 0;
    float g = 0;
    float b = 0;
};

void start() {
    digitalWrite(W_LED, HIGH);
    digitalWrite(IR_LED, HIGH);
    delay(1000);
}