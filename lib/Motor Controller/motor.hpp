#ifndef _ESP32_MOTOR_H_
#define _ESP32_MOTOR_H_
#include "unistd.h"
#include "esp32-hal-ledc.h"
#include "math.h"

class esp32_motor
{
private:
    int8_t forward_pin, backward_pin;
    int8_t channel_number_forward, channel_number_backward;
    int frequency, resolution;
    int maxPWM;
    uint8_t forward, backward;
public:
    esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, int frequency, int resolution);
    void Init();
    void Run(int PWM);
    void RunPercent(float percent);
    void Stop();
};

#endif