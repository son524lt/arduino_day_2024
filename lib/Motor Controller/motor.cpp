#include <motor.hpp>

esp32_motor::esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, int frequency, int resolution) {
    forward = channel_number_forward;
    backward = channel_number_backward;
    maxPWM = (uint)pow(2,resolution)-1;
}

void esp32_motor::Init() {
    ledcSetup(channel_number_backward, frequency, resolution);
    ledcSetup(channel_number_forward, frequency, resolution);
    ledcAttachPin(forward_pin, channel_number_forward);
    ledcAttachPin(backward_pin, channel_number_backward);
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