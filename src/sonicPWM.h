/*
 * File:   sonicPWM.h
 * Author: Hiro
 *
 * Created on 03 de Dezembro de 2021, 23:39
 */

#include <Arduino.h>
#include "driver/mcpwm.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PWMA GPIO_NUM_23 //PWMA
#define PWMB GPIO_NUM_19 //PWMB

/**
 * @brief Configuração PWM
 *          
 *        Configura frequência, modo assimétrico, ciclo de trabalho, deadtime, unidade de geração
 *        e pinos de PWM
 * 
 */
void pwmConfig();

/**
 * @brief Define ciclo de trabalho do PWMA
 * 
 * @param duty porcentagem do ciclo de trabalho i.e para 50% de ciclo de trabalho, duty = 50.0
 */
void pwmASetDuty(float duty);

/**
 * @brief Define ciclo de trabalho do PWMB
 * 
 * @param duty porcentagem do ciclo de trabalho i.e para 50% de ciclo de trabalho, duty = 50.0
 */
void pwmBSetDuty(float duty);


#ifdef __cplusplus
}
#endif