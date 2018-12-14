#include "GuiKegerator.h"

#include "view/QtGuiView.h"

#include "presenter/GuiPresenter.h"

#include "storage/FileWriterImpl.h"
#include "storage/FileReaderImpl.h"
#include "storage/FileRemoverImpl.h"
#include "storage/BoostSerializationFileStorage.h"

#include "interactors/Storage.h"
#include "interactors/TemperatureUpdateInteractor.h"
#include "interactors/TapUpdateInteractor.h"
#include "interactors/TapClearInteractor.h"
#include "interactors/ScreenTouchedInteractor.h"

#include "controller/UserInputControllerImpl.h"
#include "controller/TemperatureSensorController.h"

#include "devices/DS18B20SensorReaderStaticValue.h"
#include "devices/DS18B20Sensor.h"
#include "devices/QmlInputDevice.h"

#include "thread/ApplicationThreadImpl.h"
#include "thread/BoostDeadlineTimer.h"
#include "thread/BoostMutex.h"

#include <QtWidgets/qapplication.h>
#include <QtQml/qqmlapplicationengine.h>
#include <iostream>

using namespace KegeratorDisplay;

boost::asio::io_service ioService;

void workerThread()
{
    try {
        ioService.run();
    }
    catch (boost::thread_interrupted&) {

    }
    catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
}

int main(int argc, char** argv)
{
    try {
        //Application thread
        boost::asio::io_service::work work(ioService);
        boost::thread thread(&workerThread);
        ApplicationThreadImpl applicationThread(&ioService);

        //View
        QApplication qApplication(argc, argv);
        QQmlApplicationEngine qEngine;
        QtGuiView view(qApplication, qEngine);

        //Presenter
        GuiViewModel* viewModel = new GuiViewModel();
        GuiPresenter presenter(view, viewModel);

        //Storage
        FileWriter* fileWriter = new FileWriterImpl();
        FileReader* fileReader = new FileReaderImpl();
        FileRemover* fileRemover = new FileRemoverImpl();
        BoostSerializationFileStorage storage("temp", "left", "right", fileWriter, fileReader, fileRemover);

        //Interactors
        boost::asio::deadline_timer* screenTouchedInteractorBoostDeadlineTimer = new boost::asio::deadline_timer(ioService);
        DeadlineTimer* screenTouchedInteractorTimer = new BoostDeadlineTimer(screenTouchedInteractorBoostDeadlineTimer);
        ScreenTouchedInteractor screenTouchedInteractor(2, screenTouchedInteractorTimer, presenter);
        TemperatureUpdateInteractor temperatureUpdateInteractor(presenter, storage);
        TapUpdateInteractor tapUpdateInteractor(presenter, storage);
        TapClearInteractor tapClearInteractor(presenter, storage);

        //Devices
        DS18B20SensorReader* ds18bSensorReader = new DS18B20SensorReaderStaticValue();
        TemperatureSensor* temperatureSensor = new DS18B20Sensor(ds18bSensorReader);

        //Controllers
        TemperatureSensorController* temperatureSensorController = new TemperatureSensorController(temperatureSensor, temperatureUpdateInteractor);
        UserInputControllerImpl userInputController(applicationThread, tapClearInteractor, screenTouchedInteractor);
        boost::asio::deadline_timer* sensorSamplerBoostDeadlineTimer = new boost::asio::deadline_timer(ioService);
        DeadlineTimer* sensorSamplerTimer = new BoostDeadlineTimer(sensorSamplerBoostDeadlineTimer);
        Mutex* mutex = new BoostMutex();
        SensorSampler* sensorSampler = new SensorSampler(1, sensorSamplerTimer, mutex);
        sensorSampler->addSensorController(temperatureSensorController);

        //Devices
        QmlInputDevice qmlInputDevice(qEngine, userInputController);

        GuiKegerator kegerator(view, sensorSampler, ioService, thread);
        kegerator.startAndRun(argc, argv);
        return 0;
    }
    catch (std::exception& ex) {
        std::cerr << "Error in application, terminating" << std::endl;
        return 1;
    }
}
