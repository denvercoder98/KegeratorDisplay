#include "SensorSampler.h"
#include "TemperatureSensorController.h"
#include "src/main/shared/DeadlineTimer.h"
#include "src/main/shared/Mutex.h"
#include <boost/bind.hpp>

namespace KegeratorDisplay {

SensorSampler::SensorSampler(unsigned int sampleRateSeconds,
                             DeadlineTimer* const timer, Mutex* const mutex) :
    m_sampleRateSeconds(sampleRateSeconds),
    m_timer(timer),
    m_mutex(mutex),
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

    delete m_timer;
    delete m_mutex;
}

void SensorSampler::addSensorController(SensorController* sensorController)
{
    m_mutex->lock();
    m_sensors.push_back(sensorController);
    m_mutex->unlock();
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
    m_mutex->lock();
    std::vector<SensorController*>::iterator i;
    for (i = m_sensors.begin(); i != m_sensors.end(); ++i) {
        SensorController* controller = *i;
        controller->process();
    }
    scheduleNextSample();
    m_mutex->unlock();
}

void SensorSampler::scheduleNextSample()
{
    m_timer->asyncWaitSeconds(boost::posix_time::seconds(1),
                              boost::bind(&SensorSampler::run, this, boost::asio::placeholders::error));
}

}
