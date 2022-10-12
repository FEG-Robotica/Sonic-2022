#include <Arduino.h>
#include "devices/Motor.h"
#include "sonic_wrappers/sonicGPIO.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef STRATS_H
#define STRATS_H

typedef enum {
    STOP_CMD = 0,
    LED_CMD = 1,
    FOLLOWER_STRAT_CMD = 2,
    ARCH_CMD = 3,
    FORWARD_TEST_CMD = 4,
    SENSOR_TEST_CMD = 5,
    LINE_TEST_CMD = 6,
} command_t;

typedef enum {
    RIGHT_ARCH= 0,
    LEFT_ARCH = 1,
} direction_arch_t;

void follower_strat(Motor right, Motor left, int duty_cicle);

void lock_recover(Motor right, Motor left,int recover_time);

bool arch(Motor right, Motor left, int speed, int time, direction_arch_t direction);

void line_detected(Motor right, Motor left);

#endif

#ifdef __cplusplus
}
#endif