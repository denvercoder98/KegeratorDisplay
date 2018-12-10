#include <controller/UserInputControllerImpl.h>
#include "Kegerator.h"

#include "presenter/GuiPresenter.h"
#include "presenter/GuiView.h"

#include "storage/FileWriterImpl.h"
#include "storage/FileReaderImpl.h"
#include "storage/FileRemoverImpl.h"
#include "storage/BoostSerializationFileStorage.h"

#include "devices/DS18B20SensorReaderStaticValue.h"
#include "devices/DS18B20Sensor.h"
#include "controller/TemperatureSensor.h"
#include "controller/SensorSampler.h"

#include "interactors/Presenter.h"

#include <iostream>

namespace KegeratorDisplay {

Kegerator::Kegerator(SensorSampler* sensorSampler, boost::asio::io_service* ioService) :
    m_ioService(ioService),
    m_work(NULL),
    m_thread(NULL),
    m_sensorSampler(sensorSampler),
    m_started(false)
{
}

Kegerator::~Kegerator()
{
    cleanUp();
}

void Kegerator::startAndRun(int &argc, char** argv)
{
    start();
    run();
}

void Kegerator::cleanUp()
{
    if (m_sensorSampler) delete m_sensorSampler;
    if (m_thread) delete m_thread;
    if (m_work) delete m_work;
    if (m_ioService) delete m_ioService;

    m_sensorSampler = NULL;
    m_thread = NULL;
    m_work = NULL;
    m_ioService = NULL;
}

void Kegerator::start()
{
    startControllers();
    setStarted();
}

void Kegerator::setStarted()
{
    m_started = true;
}

bool Kegerator::wasStarted() const
{
    return m_started;
}

void Kegerator::stop()
{
    if (m_ioService) {
        m_ioService->stop();
    }
    if (m_thread) {
        m_thread->interrupt();
        m_thread->join();
    }
}

void Kegerator::startControllers()
{
    m_sensorSampler->start();
}

}
