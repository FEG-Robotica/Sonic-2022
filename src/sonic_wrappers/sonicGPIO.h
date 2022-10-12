/*
 * File:   sonicGPIO.h
 * Author: Hiro
 *
 * Created on 03 de Dezembro de 2021, 23:39
 */

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SONIC_GPIO_H
#define SONIC_GPIO_H

#define SENSOR_LAT_DIR GPIO_NUM_17  //_SDA
#define SENSOR_FRONT_DIR GPIO_NUM_16  //_SDB
#define SENSOR_LAT_ESQ  GPIO_NUM_18 //_SDC
#define SENSOR_FRONT_ESQ GPIO_NUM_5 //_SDD
#define LEDPIN GPIO_NUM_2

#define IN1 GPIO_NUM_33
#define IN2 GPIO_NUM_32
#define IN3 GPIO_NUM_26
#define IN4 GPIO_NUM_25


/**
 * @brief Configuração GPIO sonic
 *
 *        Configura modo GPIO ,pull-up,pull-down,tipo de interrupção
 * @return
 *     - true   Successo
 *     - false  Erro
 *
 */
bool gpioConfig();

#endif

#ifdef __cplusplus
}
#endif