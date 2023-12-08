/*
 * lineSensorAlgorithm.hpp
 *
 *  Created on: Dec 8, 2023
 */

#ifndef APP_HARDWARECONTROLLER_LINESENSORALGORITHM_HPP_
#define APP_HARDWARECONTROLLER_LINESENSORALGORITHM_HPP_

class lineSensorAlgorithm {
   public:
    lineSensorAlgorithm(Devices* devices);
    void init();
    void update();
    float angle;

   private:
    Devices* _devices;

    float _SinCosTable[2][32] = {0.0};
    const float _theta = 360 / 32;

    const uint16_t _threshold = 2000;

    bool _isOnLine[32] = {false};
    uint16_t _sensorValue[32];

};

#endif /* APP_HARDWARECONTROLLER_LINESENSORALGORITHM_HPP_ */