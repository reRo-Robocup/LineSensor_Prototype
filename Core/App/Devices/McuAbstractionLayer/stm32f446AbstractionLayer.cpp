/*
 * stm32f446AbstractionLayer.cpp
 *
 *  Created on: Dec 7, 2023
 */

#include <Devices/McuAbstractionLayer/stm32f446AbstractionLayer.hpp>
#include "adc.h"
#include "usart.h"

void stm32f446AbstractionLayer::init() {
    _initADC();
}

// ADC
uint16_t stm32f446AbstractionLayer::_data[2] = {0};
bool stm32f446AbstractionLayer::_adcCplt[2] = {0};

void stm32f446AbstractionLayer::_initADC(void) {
    if (HAL_ADC_Start_DMA(&hadc1, (uint32_t*)this->_data, sizeof(uint16_t)) * hadc1.Init.NbrOfConversion !=
        HAL_OK) {
        Error_Handler();
    }
}

uint16_t stm32f446AbstractionLayer::adcGetValue(Peripheral_ADC p) {
    switch (p) {
        case Peripheral_ADC::MuxA:
            return this->_data[0];
            break;

        case Peripheral_ADC::MuxB:
            return this->_data[1];
            break;

        default:
            return 0;
            break;
    }
    return 0;
}

bool stm32f446AbstractionLayer::isAdcConvCplt(Peripheral_ADC p) {
    bool t = _adcCplt[0];
    _adcCplt[0] = 0;
    return t;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle) {
    if (AdcHandle == &hadc1) {
        stm32f446AbstractionLayer::_adcCplt[0] = true;
    }
}
// GPIO

void stm32f446AbstractionLayer::gpioSetValue(Peripheral_GPIO p, bool value) {
    GPIO_PinState state = GPIO_PIN_RESET;
    if (value) {
        state = GPIO_PIN_SET;
    }

    switch (p) {
        case Peripheral_GPIO::MuxA_Sig0:
            HAL_GPIO_WritePin(MuxA_Sig0_GPIO_Port, MuxA_Sig0_Pin, state);
            break;

        case Peripheral_GPIO::MuxA_Sig1:
            HAL_GPIO_WritePin(MuxA_Sig1_GPIO_Port, MuxA_Sig1_Pin, state);
            break;

        case Peripheral_GPIO::MuxA_Sig2:
            HAL_GPIO_WritePin(MuxA_Sig2_GPIO_Port, MuxA_Sig2_Pin, state);
            break;

        case Peripheral_GPIO::MuxA_Sig3:
            HAL_GPIO_WritePin(MuxA_Sig3_GPIO_Port, MuxA_Sig3_Pin, state);
            break;

        case Peripheral_GPIO::MuxB_Sig0:
            HAL_GPIO_WritePin(MuxB_Sig0_GPIO_Port, MuxB_Sig0_Pin, state);
            break;

        case Peripheral_GPIO::MuxB_Sig1:
            HAL_GPIO_WritePin(MuxB_Sig1_GPIO_Port, MuxB_Sig1_Pin, state);
            break;

        case Peripheral_GPIO::MuxB_Sig2:
            HAL_GPIO_WritePin(MuxB_Sig2_GPIO_Port, MuxB_Sig2_Pin, state);
            break;

        case Peripheral_GPIO::MuxB_Sig3:
            HAL_GPIO_WritePin(MuxB_Sig3_GPIO_Port, MuxB_Sig3_Pin, state);
            break;

        default:
            break;
    }
}

bool stm32f446AbstractionLayer::gpioGetValue(Peripheral_GPIO p) {
    // bool state = HAL_GPIO_ReadPin(GPIOx,GPIO_PIN_num);
    return false;
}

// UART
void stm32f446AbstractionLayer::uartSendByte(Peripheral_UART p, uint8_t* data, uint32_t size) {
    switch (p) {
        case Peripheral_UART::MainController:
            HAL_UART_Transmit(&huart6, data, size, 100);
            break;
    }
}

void stm32f446AbstractionLayer::wait_ms(uint32_t ms) {
    HAL_Delay(ms);
}
