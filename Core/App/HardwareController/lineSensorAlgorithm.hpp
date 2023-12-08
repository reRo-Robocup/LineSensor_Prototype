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

   private:
    Devices* _devices;
};

#endif /* APP_HARDWARECONTROLLER_LINESENSORALGORITHM_HPP_ */