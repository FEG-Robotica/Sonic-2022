#include <Arduino.h>
#include "sonic_wrappers/sonicGPIO.h"
#include "sonic_wrappers/sonicPWM.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UTILS_H
#define UTILS_H

const bool FW = 1;
const bool BW = 0;

class Motor
{

private:
    gpio_num_t input_a;
    gpio_num_t input_b;
    gpio_num_t pwm;

public:

    Motor(gpio_num_t input_a, gpio_num_t input_b, gpio_num_t pwm);

    void move(int duty_cycle, const bool direction);

    void stop();

    void brake();
};

#endif

#ifdef __cplusplus
}
#endif