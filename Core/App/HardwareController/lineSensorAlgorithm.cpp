/*
 * lineSensorAlgorithm.cpp
 *
 *  Created on: Dec 8, 2023
 */

#include <math.h>
#include <Devices/Devices.hpp>
#include <HardwareController/lineSensorAlgorithm.hpp>

#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

lineSensorAlgorithm::lineSensorAlgorithm(Devices* devices) {
    _devices = devices;
}

void lineSensorAlgorithm::init() {
    for (int i = 0; i < 32; i++) {
        _SinCosTable[0][i] = sin(deg_to_rad(i * _theta));
        _SinCosTable[1][i] = cos(deg_to_rad(i * _theta));
    }
}

void lineSensorAlgorithm::update() {
    float x = 0.0;
    float y = 0.0;
    for (int i = 0; i < 32; i++) {
        _sensorValue[i] = _devices->lineSensor->sensorValue[i];
        if (_sensorValue[i] > _threshold) {
            _line_ison_cnt++;
            x += _SinCosTable[1][i];
            y += _SinCosTable[0][i];
        }
    }
    if (_line_ison_cnt > 0) {
        angle = rad_to_deg(atan2(y, x)) - 90;
        if (angle > 359)
            angle -= 360;
        else if (angle < 0)
            angle += 360;
    } else {
        angle = 1023;
    }
    uint8_t sendData[2];
    sendData[0] = angle >> 8 & 0xFF;
    sendData[1] = angle & 0xFF;
    _devices->mcu->uartSendByte(MAL::Peripheral_UART::MainController, sendData, 2);
}

uint16_t lineSensorAlgorithm::getLineR() {
    float r = 0;
    float constant = 1.0;   // fix constant(~cm)
    uint8_t base_angle = 0; // IMU data
    while(base_angle > 180)  base_angle -= 360;
    while(base_angle < -180) base_angle += 360;
    r =  cos(deg_to_rad(base_angle + lineSensorAlgorithm::angle));
    r *= constant * lineSensorAlgorithm::SensorPCB_R;
    return r;
}