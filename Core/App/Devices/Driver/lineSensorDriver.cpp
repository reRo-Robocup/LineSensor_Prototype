/*
 * lineSensorDriver.cpp
 *
 *  Created on: Dec 7, 2023
 */

#include <Devices/Driver/lineSensorDriver.hpp>

lineSensorDriver::lineSensorDriver(MAL* mcu, MAL::Peripheral_ADC p) {
    _mcu = mcu;
    _p = p;
}

uint16_t lineSensorDriver::getRawValue() {
    return _mcu->adcGetValue(_p);
}

float lineSensorDriver::getVoltage() {
    return _mcu->adcGetValue(_p) * _raw2voltage;
}