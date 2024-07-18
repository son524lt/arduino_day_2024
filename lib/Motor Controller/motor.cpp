#include <motor.hpp>

esp32_motor::esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, int frequency, int resolution) {
    forward = forward_pin;
    backward = backward_pin;
    forward_channel = channel_number_forward;
    backward_channel = channel_number_backward;
    maxPWM = (uint)pow(2,resolution)-1;
}

void esp32_motor::Init() {
    ledcSetup(backward_channel, frequency, resolution);
    ledcSetup(forward_channel, frequency, resolution);
    ledcAttachPin(forward, forward_channel);
    ledcAttachPin(backward, backward_channel);
}

void esp32_motor::Run(int PWM) {
    if (PWM>maxPWM) {PWM = maxPWM;}
    if (PWM<-maxPWM) {PWM = -maxPWM;}
    ledcWrite(forward, (PWM>0)?(PWM):(0));
    ledcWrite(backward, (PWM>0)?(0):(-PWM));
}

void esp32_motor::RunPercent(float percent) {
    if (percent>100) {percent = 100;}
    if (percent<-100) {percent = -100;}
    Run((int)(percent*maxPWM/100.0));
}

void esp32_motor::Stop() {
    ledcWrite(forward,maxPWM);
    ledcWrite(backward,maxPWM);
}