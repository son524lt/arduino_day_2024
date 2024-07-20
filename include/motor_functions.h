#include <esp32-hal-ledc.h>

void runLeftMotor(float speed) {
    if (speed > 1000) {
        speed = 1000;
    } else if (speed < -1000) {
        speed = -1000;
    }
    speed = speed/1000.0;
    speed = speed * 4095;
    if (speed > 0) {
        ledcWrite(0, (int)speed);
        ledcWrite(1, 0);
    } else {
        ledcWrite(0, 0);
        ledcWrite(1, -(int)speed);
    }
}

void runRightMotor(float speed) {
    if (speed > 1000) {
        speed = 1000;
    } else if (speed < -1000) {
        speed = -1000;
    }
    speed = speed/1000.0;
    speed = speed * 4095;
    if (speed > 0) {
        ledcWrite(2, (int)speed);
        ledcWrite(3, 0);
    } else {
        ledcWrite(2, 0);
        ledcWrite(3, -(int)speed);
    }
}

void stop() {
    ledcWrite(0, 0);
    ledcWrite(1, 0);
    ledcWrite(2, 0);
    ledcWrite(3, 0);
}

void brake() {
    ledcWrite(0, 4095);
    ledcWrite(1, 4095);
    ledcWrite(2, 4095);
    ledcWrite(3, 4095);
}
