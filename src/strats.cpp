#include "strats.h"
#include "sonic_wrappers/sonicAD.h"
void line_detected(Motor right, Motor left)
{
    right.move(100, BW);
    left.move(70, BW);
    delay(500);
}

void follower_strat(Motor right, Motor left, int duty_cicle)
{

    if (analogRead(SENSOR_DE_LINHA_A) < 1000 || analogRead(SENSOR_DE_LINHA_B) < 1000)
        {
            right.move(100, BW);
            left.move(100, BW);
        }
    else
    {
        //Serial.println("Follower");
        if (gpio_get_level(SENSOR_LAT_DIR) && !gpio_get_level(SENSOR_FRONT_DIR))
        {
            right.move(duty_cicle, BW);
            left.move(duty_cicle, FW);
        }

        if (gpio_get_level(SENSOR_LAT_DIR) && gpio_get_level(SENSOR_FRONT_DIR))
        {
            right.move(duty_cicle * 0.8, BW);
            left.move(duty_cicle, FW);
        }

        if (gpio_get_level(SENSOR_FRONT_DIR) && !gpio_get_level(SENSOR_FRONT_ESQ))
        {
            right.move(duty_cicle, FW);
            left.move(duty_cicle * 0.6, FW);
        }

        if (gpio_get_level(SENSOR_FRONT_DIR) && gpio_get_level(SENSOR_FRONT_ESQ))
        {
            unsigned long int last_millis = millis();
            while (millis() - last_millis < 3000)
            {
                right.move(duty_cicle, FW);
                left.move(duty_cicle, FW);
            }

            lock_recover(right, left, 400);
        }

        if (gpio_get_level(SENSOR_FRONT_ESQ) && !gpio_get_level(SENSOR_FRONT_DIR))
        {
            right.move(duty_cicle * 0.6, FW);
            left.move(duty_cicle, FW);
        }

        if (gpio_get_level(SENSOR_FRONT_ESQ) && gpio_get_level(SENSOR_LAT_ESQ))
        {
            right.move(duty_cicle, FW);
            left.move(duty_cicle * 0.8, BW);
        }

        if (!gpio_get_level(SENSOR_LAT_ESQ) && gpio_get_level(SENSOR_FRONT_ESQ))
        {
            right.move(duty_cicle, FW);
            left.move(duty_cicle, BW);
        }

        if (!gpio_get_level(SENSOR_LAT_ESQ) && !gpio_get_level(SENSOR_FRONT_ESQ) && !gpio_get_level(SENSOR_FRONT_DIR) && !gpio_get_level(SENSOR_LAT_DIR))
        {
            right.move(0, FW);
            left.move(0, FW);
        }
    }
}

void lock_recover(Motor right, Motor left, int recover_time)
{
    unsigned long int last_millis = millis();

    right.move(100, BW);
    left.move(0, BW);
    delay(recover_time);
}

bool arch(Motor right, Motor left, int speed, int time, direction_arch_t direction)
{
    if (direction == LEFT_ARCH)
    {
        right.move(speed, FW);
        left.move(speed * 0.7, FW);
        delay(time);
    }

    if (direction == RIGHT_ARCH)
    {
        right.move(speed * 0.7, FW);
        left.move(speed, FW);
        delay(time);
    }

    return false;
}

void sensor_test()
{
    Serial.println("Sensor test");
    if (gpio_get_level(SENSOR_LAT_DIR) && !gpio_get_level(SENSOR_FRONT_DIR))
    {
        gpio_set_level(GPIO_NUM_2, HIGH);
    }

    if (gpio_get_level(SENSOR_LAT_DIR) && gpio_get_level(SENSOR_FRONT_DIR))
    {
        gpio_set_level(GPIO_NUM_2, HIGH);
    }

    if (gpio_get_level(SENSOR_FRONT_DIR) && !gpio_get_level(SENSOR_FRONT_ESQ))
    {
        gpio_set_level(GPIO_NUM_2, HIGH);
    }

    if (gpio_get_level(SENSOR_FRONT_DIR) && gpio_get_level(SENSOR_FRONT_ESQ))
    {
        gpio_set_level(GPIO_NUM_2, HIGH);
    }

    if (gpio_get_level(SENSOR_FRONT_ESQ) && !gpio_get_level(SENSOR_FRONT_DIR))
    {
        gpio_set_level(GPIO_NUM_2, HIGH);
    }

    if (gpio_get_level(SENSOR_FRONT_ESQ) && gpio_get_level(SENSOR_LAT_ESQ))
    {
        gpio_set_level(GPIO_NUM_2, HIGH);
    }

    if (!gpio_get_level(SENSOR_LAT_ESQ) && gpio_get_level(SENSOR_FRONT_ESQ))
    {
        gpio_set_level(GPIO_NUM_2, HIGH);
        ;
    }

    if (!gpio_get_level(SENSOR_LAT_ESQ) && !gpio_get_level(SENSOR_FRONT_ESQ) && !gpio_get_level(SENSOR_FRONT_DIR) && !gpio_get_level(SENSOR_LAT_DIR))
    {
        gpio_set_level(GPIO_NUM_2, LOW);
    }
}