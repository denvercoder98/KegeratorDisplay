#ifndef SRC_MAIN_KEGERATOR_H_
#define SRC_MAIN_KEGERATOR_H_

#include <boost/asio/io_service.hpp>
#include <boost/thread.hpp>
#include <controllers/SensorSampler.h>

namespace KegeratorDisplay {

class Kegerator
{
public:
    Kegerator(SensorSampler* sensorSampler, boost::asio::io_service& ioService, boost::thread& thread);
    virtual ~Kegerator();

    void startAndRun(int &argc, char** argv);
    void stop();

protected:
    virtual void run() = 0;

private:
    void startControllers();

    void setStarted();
    bool wasStarted() const;
    void start();
    void doCreate(int& argc, char** argv);
    void cleanUp();

    boost::asio::io_service& m_ioService;
    boost::thread& m_thread;
    SensorSampler* m_sensorSampler;
    bool m_started;
};

}

#endif
