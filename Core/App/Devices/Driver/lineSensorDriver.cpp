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

void lineSensorDriver::update() {
    _mcu->adcGetValue(_p);
}
