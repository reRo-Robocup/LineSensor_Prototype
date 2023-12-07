/*
 * stm32f446AbstractionLayer.cpp
 *
 *  Created on: Dec 7, 2023
 */

#include <Devices/McuAbstractionLayer/stm32f446AbstractionLayer.hpp>
#include "adc.h"

void stm32f446AbstractionLayer::init() {
    _initADC();
}

// ADC
uint16_t stm32f446AbstractionLayer::_data[16] = {0};

void stm32f446AbstractionLayer::_initADC(void) {
    if (HAL_ADC_Start_DMA(&hadc1, (uint32_t*)this->_data, sizeof(uint16_t)) * hadc1.Init.NbrOfConversion !=
        HAL_OK) {
        Error_Handler();
    }
}

uint16_t stm32f446AbstractionLayer::adcGetValue(Peripheral_ADC p) {
    switch (p) {
        default:
            return 0;
            break;
    }
    return 0;
}

// GPIO

void stm32f446AbstractionLayer::gpioSetValue(Peripheral_GPIO p, bool value) {
    switch (p) {
        default:
            break;
    }
}

bool stm32f446AbstractionLayer::gpioGetValue(Peripheral_GPIO p) {
    return false;
}
