#include "strats.h"

void follower_strat(Motor right, Motor left, int duty_cicle)
{
    if(gpio_get_level(SENSOR_LAT_DIR) && !gpio_get_level(SENSOR_FRONT_DIR))
    {
        right.move(duty_cicle, BW);
        left.move(duty_cicle, FW);
    }

    if(gpio_get_level(SENSOR_LAT_DIR) && gpio_get_level(SENSOR_FRONT_DIR))
    {
        right.move(duty_cicle*0.8, BW);
        left.move(duty_cicle, FW);
    }

    if(gpio_get_level(SENSOR_FRONT_DIR) && !gpio_get_level(SENSOR_FRONT_ESQ))
    {
        right.move(duty_cicle, FW);
        left.move(duty_cicle*0.6, FW);
    }

    if(gpio_get_level(SENSOR_FRONT_DIR) && gpio_get_level(SENSOR_FRONT_ESQ))
    {
        unsigned long int last_millis = millis();
        while(millis() - last_millis < 3000)
        {
            right.move(duty_cicle, FW);
            left.move(duty_cicle, FW);
        } 
        
        lock_recover(right, left, 400);


    }

    if(gpio_get_level(SENSOR_FRONT_ESQ) && !gpio_get_level(SENSOR_FRONT_DIR))
    {
        right.move(duty_cicle*0.6, FW);
        left.move(duty_cicle, FW);
    }

    if(gpio_get_level(SENSOR_FRONT_ESQ) && gpio_get_level(SENSOR_LAT_ESQ))
    {
        right.move(duty_cicle, FW);
        left.move(duty_cicle*0.8, BW);
    }

    if(!gpio_get_level(SENSOR_LAT_ESQ) && gpio_get_level(SENSOR_FRONT_ESQ))
    {
        right.move(duty_cicle, FW);
        left.move(duty_cicle, BW);
    }

    if(!gpio_get_level(SENSOR_LAT_ESQ) && !gpio_get_level(SENSOR_FRONT_ESQ) && !gpio_get_level(SENSOR_FRONT_DIR) && ! gpio_get_level(SENSOR_LAT_DIR))
    {
        right.move(0, FW);
        left.move(0, FW);
    }
}

void lock_recover(Motor right, Motor left,int recover_time)
{
    unsigned long int last_millis = millis();

    right.move(100, BW);
    left.move(0, BW);
    delay(recover_time);

}