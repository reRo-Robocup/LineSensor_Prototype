/*
 * app_main.cpp
 *
 *  Created on: Dec 7, 2023
 */

#include <app_main.h>
#include <Devices/Devices.hpp>

Devices devices;

uint16_t sensor[32] = {0};
bool isOnLine[32] = {0};

void app_init() {
    devices.init();
}
void app_main() {
    app_init();
    const int threshold = 2000;
    while (1) {
        devices.lineSensor->update();
        for (int i = 0; i < 32; i++) {
            sensor[i] = devices.lineSensor->sensorValue[i];
            isOnLine[i] = (sensor[i] > threshold);
        }
    }
}
