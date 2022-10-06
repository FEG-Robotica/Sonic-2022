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
} command_t;

void follower_strat(Motor right, Motor left, int duty_cicle);

void lock_recover(Motor right, Motor left,int recover_time);

#endif

#ifdef __cplusplus
}
#endif