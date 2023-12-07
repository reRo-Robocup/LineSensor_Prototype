/*
 * baseAdcDriver.cpp
 *
 *  Created on: Dec 7, 2023
 */

#include <Devices/Driver/baseAdcDriver.hpp>

baseAdcDriver::baseAdcDriver(MAL* mcu, MAL::Peripheral_ADC p) {
    _mcu = mcu;
    _p = p;
}

uint16_t baseAdcDriver::getRawValue() {
    return _mcu->adcGetValue(_p);
}

float baseAdcDriver::getVoltage() {
    return _mcu->adcGetValue(_p) * _raw2voltage;
}
