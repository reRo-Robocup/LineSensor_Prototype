/*
 * baseMcuAbstractionLayer.hpp
 *
 *  Created on: Dec 7, 2023
 */

#ifndef APP_DEVICES_BASEMCUABSTRACTIONLAYER_MCUABSTRACTIONLAYER_HPP_
#define APP_DEVICES_BASEMCUABSTRACTIONLAYER_MCUABSTRACTIONLAYER_HPP_

#include <stdint.h>

class baseMcuAbstractionLayer {
   public:
    enum Peripheral_ADC {
        MuxA,
        MuxB,
    };

    enum Peripheral_GPIO {
        MuxA_Sig0,
        MuxA_Sig1,
        MuxA_Sig2,
        MuxA_Sig3,
        MuxB_Sig0,
        MuxB_Sig1,
        MuxB_Sig2,
        MuxB_Sig3,
    };

    virtual void init(void) = 0;

    virtual uint16_t adcGetValue(Peripheral_ADC p) = 0;
    virtual bool isAdcConvCplt(Peripheral_ADC p) = 0;

    virtual void gpioSetValue(Peripheral_GPIO p, bool value) = 0;
    virtual bool gpioGetValue(Peripheral_GPIO p) = 0;

    virtual void wait_ms(uint32_t ms) = 0;
};

typedef baseMcuAbstractionLayer MAL;

#endif /* APP_DEVICES_BASEMCUABSTRACTIONLAYER_MCUABSTRACTIONLAYER_HPP_ */