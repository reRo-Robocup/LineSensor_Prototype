/*
 * app_main.cpp
 *
 *  Created on: Dec 7, 2023
 */

#include <app_main.h>
#include <Devices/Devices.hpp>

Devices devices;

void app_init() {
    devices.init();
}
void app_main() {
    app_init();
    while (1) {
        devices.lineSensor->update();
    }
}
