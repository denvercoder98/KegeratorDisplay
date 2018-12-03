#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>
#include <boost/thread.hpp>
#include "interactors/TapUpdateInteractor.h"
#include "interactors/TapClearInteractor.h"
#include "interactors/TemperatureUpdateInteractor.h"
#include <storage/BoostSerializationFileStorage.h>
#include <thread/BoostDeadlineTimer.h>
#include <thread/BoostMutex.h>

#include "view/CliView.h"
#include "view/QtGuiView.h"

#include "presenter/PrintPresenter.h"
#include "presenter/GuiPresenter.h"

#include "storage/FileWriterImpl.h"
#include "storage/FileReaderImpl.h"
#include "storage/FileRemoverImpl.h"
#include "controller/DS18B20SensorReaderStaticValue.h"
#include "controller/DS18B20Sensor.h"
#include "controller/TemperatureSensor.h"
#include "controller/TemperatureSensorController.h"
#include "controller/SensorSampler.h"
#include "controller/UserInputController.h"
#include "devices/QtQmlInputDevice.h"

//TODO exception safety

using namespace KegeratorDisplay;

boost::asio::io_service* m_ioService;

void workerThread()
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

Storage* createStorage()
{
    FileWriter* fileWriter = new FileWriterImpl();
    FileReader* fileReader = new FileReaderImpl();
    FileRemover* fileRemover = new FileRemoverImpl();
    Storage* storage = new BoostSerializationFileStorage("temp", "left", "right", fileWriter, fileReader, fileRemover);
    return storage;
}

TemperatureSensorController* createTemperatureSensorController(TemperatureUpdateInteractor* temperatureUpdateInteractor)
{
    // CONTROLLERS
    DS18B20SensorReader* ds18bSensorReader =
        new DS18B20SensorReaderStaticValue();
    TemperatureSensor* temperatureSensor = new DS18B20Sensor(ds18bSensorReader);
    TemperatureSensorController* temperatureSensorController =
        new TemperatureSensorController(temperatureSensor,
            temperatureUpdateInteractor);
    return temperatureSensorController;
}

UserInputController* createUserInputController(TapClearInteractor* tapClearInteractor)
{
    UserInputController* userInputController =
        new KegeratorDisplay::UserInputController(tapClearInteractor);
    return userInputController;
}

int main(int argc, char** argv)
{
    std::cout << "Test run" << std::endl;

    QApplication* m_qApplication = new QApplication(argc, argv);
    QQmlApplicationEngine* m_qEngine = new QQmlApplicationEngine();

    // VIEW and PRESENTER
    Presenter* presenter;
    View* view;
    bool printView = false;
    if (printView) {
        PrintView* printView = new CliView();
        PrintViewModel* viewModel = new PrintViewModel();
        presenter = new PrintPresenter(printView, viewModel);
        view = dynamic_cast<View*>(printView);
    }
    else {
        GuiView* guiView = new QtGuiView(m_qApplication, m_qEngine);
        GuiViewModel* viewModel = new GuiViewModel();
        presenter = new GuiPresenter(guiView, viewModel);
        view = dynamic_cast<View*>(guiView);
    }

    Storage* storage = createStorage();

    // INTERACTORS
    TemperatureUpdateInteractor* temperatureUpdateInteractor = new TemperatureUpdateInteractor(presenter, storage);
    TapUpdateInteractor* tapUpdateInteractor = new TapUpdateInteractor(presenter, storage);
    TapClearInteractor* tapClearInteractor = new TapClearInteractor(presenter, storage);

    // CONTROLLERS
    TemperatureSensorController* temperatureSensorController = createTemperatureSensorController(temperatureUpdateInteractor);
    UserInputController* userInputController = createUserInputController(tapClearInteractor);

    // DEVICES
    QtQmlInputDevice* keyboardInputDevice = new QtQmlInputDevice(m_qEngine, userInputController); //TODO turn controller into interface?

    m_ioService = new boost::asio::io_service();
    boost::asio::io_service::work* work = new boost::asio::io_service::work(*m_ioService);
    boost::thread* thread = new boost::thread(&workerThread);
    boost::asio::deadline_timer* boostDeadlineTimer = new boost::asio::deadline_timer(*m_ioService);
    DeadlineTimer* timer = new BoostDeadlineTimer(boostDeadlineTimer);
    Mutex* mutex = new BoostMutex();
    SensorSampler* sensorSampler = new SensorSampler(1, timer, mutex);
    sensorSampler->addSensorController(temperatureSensorController);
    sensorSampler->start();

    view->run(argc, argv);

    m_ioService->stop();
    thread->interrupt();
    thread->join();

    delete sensorSampler;
    delete thread;
    delete work;
    delete m_ioService;
    delete tapUpdateInteractor;
    delete temperatureUpdateInteractor;
    delete storage;
    delete presenter;
    delete m_qEngine;
    delete m_qApplication;

    return 0;
}
