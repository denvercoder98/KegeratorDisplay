#include <controllers/SensorSampler.h>
#include <controllers/TemperatureSensor.h>
#include <controllers/UserInputControllerImpl.h>
#include "Kegerator.h"

#include "presenter/GuiPresenter.h"
#include "presenter/GuiView.h"

#include "storage/FileWriterImpl.h"
#include "storage/FileReaderImpl.h"
#include "storage/FileRemoverImpl.h"
#include "storage/BoostSerializationFileStorage.h"

#include "devices/DS18B20SensorReaderStaticValue.h"
#include "devices/DS18B20Sensor.h"
#include "interactors/Presenter.h"

#include <iostream>

namespace KegeratorDisplay {

Kegerator::Kegerator(SensorSampler* sensorSampler, boost::asio::io_service& ioService, boost::thread& thread) :
    m_ioService(ioService),
    m_thread(thread),
    m_sensorSampler(sensorSampler),
    m_started(false)
{
    //TODO throw if missing sensorSampler
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
    if (m_sensorSampler) {
        delete m_sensorSampler;
        m_sensorSampler = NULL;
    }
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
    m_ioService.stop();
    m_thread.interrupt();
    m_thread.join();
}

void Kegerator::startControllers()
{
    m_sensorSampler->start();
}

}
