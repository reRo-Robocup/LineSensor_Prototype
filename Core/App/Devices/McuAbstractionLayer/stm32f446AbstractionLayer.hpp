/*
 * stm32f446AbstractionLayer.hpp
 *
 *  Created on: Dec 7, 2023
 */

#ifndef APP_DEVICES_stm32f446ABSTRACTIONLAYER_stm32f446ABSTRACTIONLAYER_HPP_
#define APP_DEVICES_stm32f446ABSTRACTIONLAYER_stm32f446ABSTRACTIONLAYER_HPP_

#include <Devices/McuAbstractionLayer/baseMcuAbstractionLayer.hpp>

class stm32f446AbstractionLayer : public baseMcuAbstractionLayer {
   public:
    virtual void init(void);

    virtual uint16_t adcGetValue(Peripheral_ADC p);

    virtual void gpioSetValue(Peripheral_GPIO p, bool value);
    virtual bool gpioGetValue(Peripheral_GPIO p);

   private:
    // ADC
    void _initADC();
    static uint16_t _data[16];
};

#endif /* APP_DEVICES_stm32f446ABSTRACTIONLAYER_stm32f446ABSTRACTIONLAYER_HPP_ */