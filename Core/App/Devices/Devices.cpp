/*
 * Devices.cpp
 *
 *  Created on: Dec 7, 2023
 */

#include <Devices/Devices.hpp>

Devices::Devices() {
    mcu = new stm32f446AbstractionLayer();
}

void Devices::init() {
    mcu->init();
}
