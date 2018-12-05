#include "Kegerator.h"

#include "presenter/GuiPresenter.h"
#include "presenter/GuiView.h"

#include "storage/FileWriterImpl.h"
#include "storage/FileReaderImpl.h"
#include "storage/FileRemoverImpl.h"
#include "storage/BoostSerializationFileStorage.h"

#include "controller/DS18B20SensorReaderStaticValue.h"
#include "controller/DS18B20Sensor.h"
#include "controller/TemperatureSensor.h"
#include "controller/UserInputController.h"
#include "controller/SensorSampler.h"

#include "interactors/Presenter.h"

#include <iostream>

namespace KegeratorDisplay {

Kegerator::Kegerator() :
    m_presenter(NULL),
    m_storage(NULL),
    m_tapClearInteractor(NULL),
    m_tapUpdateInteractor(NULL),
    m_temperatureUpdateInteractor(NULL),
    m_temperatureSensorController(NULL),
    m_userInputController(NULL),
    m_ioService(NULL),
    m_work(NULL),
    m_thread(NULL),
    m_sensorSampler(NULL),
    p_view(NULL),
    m_started(false)
{
}

Kegerator::~Kegerator()
{
    cleanUp();
}

void Kegerator::startAndRun(int &argc, char** argv)
{
    create(argc, argv);
    start();
    run();
}

void Kegerator::create(int& argc, char** argv)
{
    try {
        doCreate(argc, argv);
    }
    catch(std::exception& ex) {
        std::cerr << "Unable to start kegerator: " << ex.what() << std::endl;
        cleanUp();
    }
}

void Kegerator::doCreate(int& argc, char** argv)
{
    createApplicationThread();
    createView(argc, argv);
    createPresenter();
    createStorage();
    createInteractors();
    createControllers();
    createDevices();
}

void Kegerator::cleanUp()
{
    if (m_sensorSampler) delete m_sensorSampler;
    if (m_thread) delete m_thread;
    if (m_work) delete m_work;
    if (m_ioService) delete m_ioService;
    if (m_userInputController) delete m_userInputController;
    if (m_temperatureSensorController) delete m_temperatureSensorController;
    if (m_tapClearInteractor) delete m_tapClearInteractor;
    if (m_tapUpdateInteractor) delete m_tapUpdateInteractor;
    if (m_temperatureUpdateInteractor) delete m_temperatureUpdateInteractor;
    if (m_storage) delete m_storage;
    if (m_presenter) delete m_presenter;
    if (p_view) delete p_view;
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
    m_ioService->stop();
    m_thread->interrupt();
    m_thread->join();
}

void Kegerator::createPresenter()
{
    GuiViewModel* viewModel = new GuiViewModel();
    Presenter* presenter = new GuiPresenter(p_view, viewModel);
    setPresenter(presenter);
}

void Kegerator::createStorage()
{
    FileWriter* fileWriter = new FileWriterImpl();
    FileReader* fileReader = new FileReaderImpl();
    FileRemover* fileRemover = new FileRemoverImpl();
    m_storage = new BoostSerializationFileStorage("temp", "left", "right", fileWriter, fileReader, fileRemover);
}

void Kegerator::createInteractors()
{
    m_temperatureUpdateInteractor = new TemperatureUpdateInteractor(m_presenter, m_storage);
    m_tapUpdateInteractor = new TapUpdateInteractor(m_presenter, m_storage);
    m_tapClearInteractor = new TapClearInteractor(m_presenter, m_storage);
}

void Kegerator::createApplicationThread()
{
    m_ioService = new boost::asio::io_service();
    m_work = new boost::asio::io_service::work(*m_ioService);
    m_thread = new boost::thread(&Kegerator::workerThread, this);
}

void Kegerator::createControllers()
{
    m_temperatureSensorController = createTemperatureSensorController(m_temperatureUpdateInteractor);
    m_userInputController = createUserInputController(m_tapClearInteractor);

    boost::asio::deadline_timer* boostDeadlineTimer = new boost::asio::deadline_timer(*m_ioService);
    DeadlineTimer* timer = new BoostDeadlineTimer(boostDeadlineTimer);
    Mutex* mutex = new BoostMutex();

    m_sensorSampler = new SensorSampler(1, timer, mutex);
    m_sensorSampler->addSensorController(m_temperatureSensorController);
}

void Kegerator::startControllers()
{
    m_sensorSampler->start();
}

TemperatureSensorController* Kegerator::createTemperatureSensorController(TemperatureUpdateInteractor* temperatureUpdateInteractor)
{
    DS18B20SensorReader* ds18bSensorReader = new DS18B20SensorReaderStaticValue();
    TemperatureSensor* temperatureSensor = new DS18B20Sensor(ds18bSensorReader);
    return new TemperatureSensorController(temperatureSensor, temperatureUpdateInteractor);
}

UserInputController* Kegerator::createUserInputController(TapClearInteractor* tapClearInteractor)
{
    return new KegeratorDisplay::UserInputController(tapClearInteractor);
}

UserInputController* Kegerator::getUserInputController() const
{
    return m_userInputController;
}

void Kegerator::setPresenter(Presenter* presenter)
{
    if (m_presenter) {
        delete m_presenter;
    }
    m_presenter = presenter;
}

void Kegerator::workerThread()
{
    try {
        m_ioService->run();
    }
    catch (boost::thread_interrupted&) {

    }
    catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
}

}
