#include <Kegerator.h>

//#include "view/CliView.h"

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
    m_sensorSampler(NULL)
{
}

Kegerator::~Kegerator()
{
    delete m_sensorSampler;
    delete m_thread;
    delete m_work;
    delete m_ioService;
    delete m_userInputController;
    delete m_temperatureSensorController;
    delete m_tapClearInteractor;
    delete m_tapUpdateInteractor;
    delete m_temperatureUpdateInteractor;
    delete m_storage;
    delete m_presenter;
}

void Kegerator::start(int &argc, char** argv)
{
    //TODO exception safety
    //TODO refactor, create AcceptanceTestKegerator
    createViewAndPresenter(argc, argv);
    createStorage();
    createInteractors();
    createControllers();

    //TODO move to function
    m_sensorSampler->start();

    run(argc, argv);
}

void Kegerator::stop()
{
    m_ioService->stop();
    m_thread->interrupt();
    m_thread->join();
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

void Kegerator::createControllers()
{
    m_temperatureSensorController = createTemperatureSensorController(m_temperatureUpdateInteractor);
    m_userInputController = createUserInputController(m_tapClearInteractor);

    //TODO move to generic function
    m_ioService = new boost::asio::io_service();
    m_work = new boost::asio::io_service::work(*m_ioService);
    m_thread = new boost::thread(&Kegerator::workerThread, this);

    boost::asio::deadline_timer* boostDeadlineTimer = new boost::asio::deadline_timer(*m_ioService);
    DeadlineTimer* timer = new BoostDeadlineTimer(boostDeadlineTimer);
    Mutex* mutex = new BoostMutex();

    m_sensorSampler = new SensorSampler(1, timer, mutex);
    m_sensorSampler->addSensorController(m_temperatureSensorController);
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
