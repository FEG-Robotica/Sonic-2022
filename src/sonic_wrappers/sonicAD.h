/*
 * File:   sonicAD.h
 * Author: Hiro
 *
 * Created on 03 de Dezembro de 2021, 23:39
 */

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef SONIC_AD_H
#define SONIC_AD_H

#define SENSOR_CORRENTE_A GPIO_NUM_34 //SCA
#define SENSOR_CORRENTE_B GPIO_NUM_35 //SCB

/**
 * @brief Configuração ADC sonic
 *
 *        Configura resolução do ADC, largura, ciclos por amostra, quantidade de amostra,
 *        atenuação, pinos do ADC
 * @return
 *     VOID
 *
 */
void adConfig();

#endif

#ifdef __cplusplus
}
#endif