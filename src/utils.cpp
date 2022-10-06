#include "utils.h"


Motor::Motor(gpio_num_t input_a, gpio_num_t input_b, gpio_num_t pwm)
{
    this->input_a = input_a;
    this->input_b = input_b;
    this->pwm = pwm;
}

void Motor::move(int duty_cycle, const bool direction)
{
    if (direction == FW)
    {
        gpio_set_level(input_a, HIGH);
        gpio_set_level(input_b, LOW);
    }

    if (direction == BW)
    {
        gpio_set_level(input_a, LOW);
        gpio_set_level(input_b, HIGH);
    }

    if (pwm == PWMA)
    {
        pwmASetDuty(duty_cycle);
    }

    if (pwm == PWMB)
    {
        pwmBSetDuty(duty_cycle);
    }
}

void Motor::stop()
{
    gpio_set_level(input_a, LOW);
    gpio_set_level(input_b, LOW);

    if (pwm == PWMA)
    {
        pwmASetDuty(0);
    }

    if (pwm == PWMB)
    {
        pwmBSetDuty(0);
    }
}

void Motor::brake()
{
    gpio_set_level(input_a, HIGH);
    gpio_set_level(input_b, HIGH);

    if (pwm == PWMA)
    {
        pwmASetDuty(0);
    }

    if (pwm == PWMB)
    {
        pwmBSetDuty(0);
    }
}
