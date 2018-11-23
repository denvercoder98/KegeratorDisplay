#ifndef SRC_MAIN_CONTROLLER_SENSORSAMPLER_H_
#define SRC_MAIN_CONTROLLER_SENSORSAMPLER_H_

#include <vector>
#include "shared/DeadlineTimer.h"

namespace KegeratorDisplay {

class Mutex;
class SensorController;

class SensorSampler
{
public:
    SensorSampler(unsigned int sampleRate,
                  DeadlineTimer* const deadlineTimer,
                  Mutex* const mutex);
    virtual ~SensorSampler();

    void addSensorController(SensorController* sensor);
    void start();
    void stop();

    void run(const boost::system::error_code& error);

private:
    void sample();
    void scheduleNextSample();

    unsigned int m_sampleRateSeconds;
    DeadlineTimer* const m_timer;
    Mutex* const m_mutex;
    std::vector<SensorController*> m_sensors;
};

}

#endif
