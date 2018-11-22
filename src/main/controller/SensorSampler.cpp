#include "SensorSampler.h"
#include "TemperatureSensorController.h"

namespace KegeratorDisplay {

SensorSampler::SensorSampler() :
    m_sensors()
{
}

SensorSampler::~SensorSampler()
{
    std::vector<SensorController*>::iterator i;
    while (!m_sensors.empty()) {
        SensorController* controller = m_sensors.back();
        m_sensors.pop_back();
        delete controller;
   }
}

void SensorSampler::addSensorController(SensorController* sensorController)
{
    m_sensors.push_back(sensorController);
}

void SensorSampler::sample()
{
    std::vector<SensorController*>::iterator i;
    for (i = m_sensors.begin(); i != m_sensors.end(); ++i) {
        SensorController* controller = *i;
        controller->process();
    }
}

}
