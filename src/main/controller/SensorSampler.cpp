#include "SensorSampler.h"
#include "TemperatureSensorController.h"
#include "InvalidSensorSamplerArgumentException.h"
#include "shared/DeadlineTimer.h"
#include "shared/Mutex.h"
#include "shared/ScopedMutex.h"
#include <boost/bind.hpp>

namespace KegeratorDisplay {

SensorSampler::SensorSampler(unsigned int sampleRateSeconds,
                             DeadlineTimer* const timer, Mutex* const mutex) :
    m_sampleRateSeconds(sampleRateSeconds),
    m_timer(timer),
    m_mutex(mutex),
    m_sensors()
{
    if (m_timer == NULL) {
        throw InvalidSensorSamplerArgumentException("Missing DeadlineTimer dependency");
    }

    if (m_mutex == NULL) {
        throw InvalidSensorSamplerArgumentException("Missing Mutex dependency");
    }
}

SensorSampler::~SensorSampler()
{
    std::vector<SensorController*>::iterator i;
    while (!m_sensors.empty()) {
        SensorController* controller = m_sensors.back();
        m_sensors.pop_back();
        delete controller;
   }

    delete m_timer;
    delete m_mutex;
}

void SensorSampler::addSensorController(SensorController* sensorController)
{
    ScopedMutex lock(m_mutex);
    m_sensors.push_back(sensorController);
}

void SensorSampler::start()
{
    scheduleNextSample();
}

void SensorSampler::stop()
{
}

void SensorSampler::run(const boost::system::error_code& error)
{
    sample();
}

void SensorSampler::sample()
{
    ScopedMutex lock(m_mutex);
    std::vector<SensorController*>::iterator i;
    for (i = m_sensors.begin(); i != m_sensors.end(); ++i) {
        SensorController* controller = *i;
        controller->process();
    }
    scheduleNextSample();
}

void SensorSampler::scheduleNextSample()
{
    m_timer->asyncWaitSeconds(boost::posix_time::seconds(1),
                              boost::bind(&SensorSampler::run, this, boost::asio::placeholders::error));
}

}
