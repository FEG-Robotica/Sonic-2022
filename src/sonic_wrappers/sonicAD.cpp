/*
 * File:   sonicAD.cpp
 * Author: Hiro
 *
 * Created on 03 de Dezembro de 2021, 23:39
 */

#include "sonicAD.h"

void adConfig(){
    analogReadResolution(12);       /*!< Resolução de 12 bits (0 - 4095) */
    analogSetWidth(12);
    analogSetAttenuation(ADC_11db); /*!< Resolução de 12 bits (0 - 4095) */
    adcAttachPin(SENSOR_DE_LINHA_A);      /*!< Atribui ADC aos pinos           */
    adcAttachPin(SENSOR_DE_LINHA_B);
    adcAttachPin(SENSOR_CORRENTE_A);
    adcAttachPin(SENSOR_CORRENTE_B);

    Serial.println("ADC configurado - SUCESSO");
}