#include <Arduino.h>
#include "utils.h"
#include "sonic_wrappers/sonicGPIO.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef STRATS_H
#define STRATS_H

void follower_strat(Motor right, Motor left, int duty_cicle);

#endif

#ifdef __cplusplus
}
#endif