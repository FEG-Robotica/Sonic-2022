/*
 * File:   sonicGPIO.cpp
 * Author: Hiro
 *
 * Created on 03 de Dezembro de 2021, 23:39
 */

#include "sonicGPIO.h"

bool gpioConfig(){

    /**
    * @brief Configuração GPIO18 
    * _SDA Sensor de distância 
    *
    */
    gpio_config_t gpio18;
    gpio18.pin_bit_mask = (1ULL << GPIO_NUM_18); /*!< Atribui mask GPIO18                 */
    gpio18.mode = GPIO_MODE_INPUT;               /*!< Seta modo GPIO como input           */
    gpio18.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< Desliga GPIO pull-up                */
    gpio18.pull_down_en = GPIO_PULLDOWN_ENABLE;  /*!< Liga GPIO pull-down                 */
    gpio18.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio18);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio18) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO5
    * _SDB Sensor de distância 
    *
    */
    gpio_config_t gpio5;
    gpio5.pin_bit_mask = (1ULL << GPIO_NUM_5);  /*!< Atribui mask GPIO5                  */
    gpio5.mode = GPIO_MODE_INPUT;               /*!< seta modo GPIO como input           */
    gpio5.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< Desliga GPIO pull-up                */
    gpio5.pull_down_en = GPIO_PULLDOWN_ENABLE;  /*!< Liga GPIO pull-down                 */
    gpio5.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio5);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio5) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO17
    * _SDC Sensor de distância 
    * 
    */
    gpio_config_t gpio17;
    gpio17.pin_bit_mask = (1ULL << GPIO_NUM_17); /*!< Atribui mask GPIO17                 */
    gpio17.mode = GPIO_MODE_INPUT;               /*!< seta modo GPIO como input           */
    gpio17.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< Desiga GPIO pull-up                 */
    gpio17.pull_down_en = GPIO_PULLDOWN_ENABLE;  /*!<  Liga GPIO pull-down                */
    gpio17.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio17);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio17) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO16
    * _SDD Sensor de distância 
    * 
    */
    gpio_config_t gpio16;
    gpio16.pin_bit_mask = (1ULL << GPIO_NUM_16); /*!< Atribui mask GPIO16                 */
    gpio16.mode = GPIO_MODE_INPUT;               /*!< seta modo GPIO como input           */
    gpio16.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< Desliga GPIO pull-up                */
    gpio16.pull_down_en = GPIO_PULLDOWN_ENABLE;  /*!< Liga GPIO pull-down                 */
    gpio16.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio16);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio16) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO32
    * IN1 Enable ponte H 
    * 
    */
    gpio_config_t gpio32;
    gpio32.pin_bit_mask = (1ULL << GPIO_NUM_32); /*!< Atribui mask GPIO32                 */
    gpio32.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio32.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio32.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio32.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio32);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio32) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO33
    * IN2 Enable ponte H 
    * 
    */
    gpio_config_t gpio33;
    gpio33.pin_bit_mask = (1ULL << GPIO_NUM_33); /*!< Atribui mask GPIO33                 */
    gpio33.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio33.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio33.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio33.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio33);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio33) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO25
    * IN3 Enable ponte H 
    * 
    */
    gpio_config_t gpio25;
    gpio25.pin_bit_mask = (1ULL << GPIO_NUM_25); /*!< Atribui mask GPIO25                 */
    gpio25.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio25.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio25.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio25.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio25);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio25) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO26
    * IN4 Enable ponte H 
    * 
    */
    gpio_config_t gpio26;
    gpio26.pin_bit_mask = (1ULL << GPIO_NUM_26); /*!< Atribui mask GPIO26                 */
    gpio26.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio26.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio26.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio26.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio26);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio26) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO03
    * DISPA Primeiro bit BCD
    * 
    */
    gpio_config_t gpio3;
    gpio3.pin_bit_mask = (1ULL << GPIO_NUM_3); /*!< Atribui mask GPIO3                   */
    gpio3.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio3.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio3.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio3.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio3);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio3) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO04
    * DISPB Segundo bit BCD
    * 
    */
    gpio_config_t gpio4;
    gpio4.pin_bit_mask = (1ULL << GPIO_NUM_4); /*!< Atribui mask GPIO4                   */
    gpio4.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio4.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio4.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio4.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio4);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio4) == ESP_ERR_INVALID_ARG){
        return false;
    }
    
    /**
    * @brief Configuração GPIO15
    * DISPC Terceiro bit BCD
    * 
    */
    gpio_config_t gpio15;
    gpio15.pin_bit_mask = (1ULL << GPIO_NUM_15); /*!< Atribui mask GPIO15                 */
    gpio15.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio15.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio15.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio15.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio15);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio15) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO01
    * DISPD Quarto bit BCD
    * 
    */
    pinMode(GPIO_NUM_1,OUTPUT);

    /**
    * @brief Configuração GPIO14
    * Input módulo Start
    * 
    */
    gpio_config_t gpio14;
    gpio14.pin_bit_mask = (1ULL << GPIO_NUM_14); /*!< Atribui mask GPIO14                 */
    gpio14.mode = GPIO_MODE_INPUT;              /*!< seta modo GPIO como output          */
    gpio14.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio14.pull_down_en = GPIO_PULLDOWN_ENABLE; /*!< Desliga GPIO pull-down              */
    gpio14.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio14);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio14) == ESP_ERR_INVALID_ARG){
        return false;
    }

    /**
    * @brief Configuração GPIO12
    * Chip Select BCD
    * 
    */
    gpio_config_t gpio12;
    gpio12.pin_bit_mask = (1ULL << GPIO_NUM_12); /*!< Atribui mask GPIO12                 */
    gpio12.mode = GPIO_MODE_OUTPUT;              /*!< seta modo GPIO como output          */
    gpio12.pull_up_en = GPIO_PULLUP_DISABLE;     /*!< DesLiga GPIO pull-up                */
    gpio12.pull_down_en = GPIO_PULLDOWN_DISABLE; /*!< Desliga GPIO pull-down              */
    gpio12.intr_type = GPIO_INTR_DISABLE;        /*!< Desabilita Interrupção GPIO         */
    gpio_config(&gpio12);                        /*!< Configuração final GPIO por ponteiro*/

    if(gpio_config(&gpio12) == ESP_ERR_INVALID_ARG){
        return false;
    }


    Serial.println("GPIO configurados - SUCESSO");
    return true;
}