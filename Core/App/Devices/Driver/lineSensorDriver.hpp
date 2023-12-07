/*
 * lineSensorDriver.hpp
 *
 *  Created on: Dec 7, 2023
 */

#ifndef APP_DEVICES_DRIVER_LINESENSORDRIVER_H_
#define APP_DEVICES_DRIVER_LINESENSORDRIVER_H_
#include <Devices/McuAbstractionLayer/baseMcuAbstractionLayer.hpp>

class lineSensorDriver {
   public:
    lineSensorDriver(MAL* mcu, MAL::Peripheral_ADC p);
    void update();

   private:
    MAL* _mcu;
    MAL::Peripheral_ADC _p;

    const bool MuxA_SigPattern[16][4] = {

    };
    const bool MuxB_SigPattern[16][4] = {

    }
};

#endif /* APP_DEVICES_DRIVER_LINESENSORDRIVER_H_ */
