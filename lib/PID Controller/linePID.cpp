#include <linePID.hpp>

linePID::linePID(float kp, float ki, float kd) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->error = 0;
    this->lastError = 0;
    this->integral = 0;
    this->derivative = 0;
    this->output = 0;
}

float linePID::getOutput(float input) {
    this->error = input;
    this->integral += this->error;
    this->derivative = this->error - this->lastError;
    this->output = this->kp * this->error + this->ki * this->integral + this->kd * this->derivative;
    this->lastError = this->error;
    return this->output;
}

void linePID::reset() {
    this->error = 0;
    this->lastError = 0;
    this->integral = 0;
    this->derivative = 0;
    this->output = 0;
    return;
}