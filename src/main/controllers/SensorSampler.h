#ifndef SRC_MAIN_CONTROLLERS_SENSORSAMPLER_H_
#define SRC_MAIN_CONTROLLERS_SENSORSAMPLER_H_

#include "thread/DeadlineTimer.h"
#include <vector>

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
    void sampleControllers();
    void sampleController(SensorController* controller);

    unsigned int m_sampleRateSeconds;
    DeadlineTimer* const m_timer;
    Mutex* const m_mutex;
    std::vector<SensorController*> m_sensors;
};

}

#endif
