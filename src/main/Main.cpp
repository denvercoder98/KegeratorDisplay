#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>
#include <boost/thread.hpp>
#include <thread/BoostDeadlineTimer.h>
#include <thread/BoostMutex.h>

#include "view/CliView.h"

#include "monitor/TemperatureInteractor.h"

#include "presenter/PrintPresenter.h"

#include "storage/BlackholeStorage.h"

#include "controller/DS18B20SensorReaderStaticValue.h"
#include "controller/DS18B20Sensor.h"
#include "controller/TemperatureSensor.h"
#include "controller/TemperatureSensorController.h"
#include "controller/SensorSampler.h"

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

int main(int argc, char** argv)
{
    std::cout << "Test run" << std::endl;

    PrintView* view = new CliView();
    PrintViewModel* viewModel = new PrintViewModel();
    PrintPresenter* presenter = new PrintPresenter(view, viewModel);

    Storage* storage = new BlackholeStorage();

    TemperatureInteractor* interactor = new TemperatureInteractor(presenter, storage);

    DS18B20SensorReader* ds18bSensorReader = new DS18B20SensorReaderStaticValue();
    TemperatureSensor* temperatureSensor = new DS18B20Sensor(ds18bSensorReader);
    TemperatureSensorController* temperatureSensorController = new TemperatureSensorController(temperatureSensor, interactor);

    m_ioService = new boost::asio::io_service();
    boost::asio::io_service::work* work = new boost::asio::io_service::work(*m_ioService);
    boost::thread* thread = new boost::thread(&workerThread);
    boost::asio::deadline_timer* boostDeadlineTimer = new boost::asio::deadline_timer(*m_ioService);
    DeadlineTimer* timer = new BoostDeadlineTimer(boostDeadlineTimer);
    Mutex* mutex = new BoostMutex();
    SensorSampler* sensorSampler = new SensorSampler(1, timer, mutex);
    sensorSampler->addSensorController(temperatureSensorController);
    sensorSampler->start();

    sleep(10);

    m_ioService->stop();
    thread->interrupt();
    thread->join();

    delete sensorSampler;
    delete thread;
    delete work;
    delete m_ioService;
    delete interactor;
    delete storage;
    delete presenter;

    return 0;
}
