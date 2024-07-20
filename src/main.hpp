#include <Arduino.h>
#include <TCS34725.h>
#include <motor_functions.h>
#include <parse_error.h>

#define threshold 1900
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

TCS34725 tcs;

// void start() {
//     digitalWrite(W_LED, HIGH);
//     digitalWrite(IR_LED, HIGH);
//     delay(1000);
// }


struct colorValue {
    float temp;
    float lux;
    float r;
    float g;
    float b;
} colorVals;

int8_t pre = 0;
int8_t error = 0;

#define Kp 5
#define Ki 0
#define Kd 0.5

float P = 0;
float I = 0;
float D = 0;
float output = 0;

u16_t sensor_1_state;
u16_t sensor_2_state;
u16_t sensor_3_state;
u16_t sensor_4_state;

void readIR() {
    sensor_1_state = analogRead(SENSOR_1_PIN);
    sensor_2_state = analogRead(SENSOR_2_PIN);
    sensor_3_state = analogRead(SENSOR_3_PIN);
    sensor_4_state = analogRead(SENSOR_4_PIN);
}

void printIR() {
    Serial.print("IR: ");
    Serial.print(sensor_1_state);
    Serial.print(" ");
    Serial.print(sensor_2_state);
    Serial.print(" ");
    Serial.print(sensor_3_state);
    Serial.print(" ");
    Serial.println(sensor_4_state);
}
uint8_t irArray, middle_value=0;
// evaluate the middle value through colorVals
void getMidVal() {
    if (colorVals.r > 50 && colorVals.g < 50 && colorVals.b < 50) {
        middle_value = 2;
    } else if (colorVals.lux < 800) {
        middle_value = 0;
    } else {
        middle_value = 1;
    }
}
void getError() {
    readIR();
    getMidVal();
    irArray = 0;
    irArray += (sensor_1_state >= threshold);
    irArray<<=1;
    irArray += (sensor_2_state >= threshold);
    irArray<<=1;
    irArray += middle_value;
    irArray<<=1;
    irArray += (sensor_3_state >= threshold);
    irArray<<=1;
    irArray += (sensor_4_state >= threshold);
    error = parseError(pre, middle_value, irArray);
}

void printColor() {
    Serial.print("Color: ");
    Serial.print(colorVals.r);
    Serial.print(" ");
    Serial.print(colorVals.g);
    Serial.print(" ");
    Serial.print(colorVals.b);
    Serial.print(" ");
    Serial.print(colorVals.temp);
    Serial.print(" ");
    Serial.print(colorVals.lux);
    Serial.println();
}

void print5digitBIN(bool linespace = true) {
    for (int i = 4; i >= 0; --i) {
        Serial.print(bitRead(irArray, i));
    }
    if (linespace) {
        Serial.println();
    }
}

void calculateOutput() {
    P = Kp * error;
    I += Ki * error;
    D = Kd * (error - pre);
    output = P + I + D;
    pre = error;
    Serial.println(error);
    // Serial.println(output);
}