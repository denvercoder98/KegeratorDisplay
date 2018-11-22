#ifndef SRC_MAIN_CONTROLLER_SENSORSAMPLER_H_
#define SRC_MAIN_CONTROLLER_SENSORSAMPLER_H_

#include <vector>

namespace KegeratorDisplay {

class SensorController;

class SensorSampler
{
public:
    SensorSampler();
    virtual ~SensorSampler();

    void addSensorController(SensorController* sensor);
    void sample();

private:
    std::vector<SensorController*> m_sensors;
};

}

#endif
