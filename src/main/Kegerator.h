#ifndef SRC_MAIN_KEGERATOR_H_
#define SRC_MAIN_KEGERATOR_H_

#include "interactors/TapUpdateInteractor.h"
#include "interactors/TapClearInteractor.h"
#include "interactors/TemperatureUpdateInteractor.h"
#include "interactors/ScreenTouchedInteractor.h"
#include "controller/TemperatureSensorController.h"
#include "thread/BoostDeadlineTimer.h"
#include "thread/BoostMutex.h"

#include <boost/asio/io_service.hpp>
#include <boost/thread.hpp>

namespace KegeratorDisplay {

class Storage;
class Presenter;
class View;
class UserInputController;
class SensorSampler;
class GuiView;

class Kegerator
{
public:
    Kegerator();
    virtual ~Kegerator();

    void startAndRun(int &argc, char** argv);
    void stop();

protected:
    virtual void doCreateView(int &argc, char** argv) {};
    virtual void doCreateDevices() {};

    void createStorage();
    void createView(int &argc, char** argv);
    void createPresenter();
    void createInteractors();
    void createSensors();
    void createControllers();
    void createDevices();

    UserInputController* getUserInputController() const;
    void setPresenter(Presenter* presenter);

    virtual void run() = 0;

    GuiView* p_view;

private:
    TemperatureSensorController* createTemperatureSensorController(TemperatureSensor* temperatureSensor, TemperatureUpdateInteractor* temperatureUpdateInteractor);
    UserInputController* createUserInputController(TapClearInteractor* tapClearInteractor, ScreenTouchedInteractor* screenTouchedInteractor);
    SensorSampler* createSensorSampler();
    void startControllers();
    void workerThread();

    void setStarted();
    bool wasStarted() const;
    void create(int& argc, char** argv);
    void start();
    void doCreate(int& argc, char** argv);
    void cleanUp();
    void createApplicationThread();

    Presenter* m_presenter;
    Storage* m_storage;
    TemperatureSensor* m_temperatureSensor;
    TemperatureUpdateInteractor* m_temperatureUpdateInteractor;
    TapUpdateInteractor* m_tapUpdateInteractor;
    TapClearInteractor* m_tapClearInteractor;
    ScreenTouchedInteractor* m_screenTouchedInteractor;
    TemperatureSensorController* m_temperatureSensorController;
    UserInputController* m_userInputController;
    boost::asio::io_service* m_ioService;
    boost::asio::io_service::work* m_work;
    boost::thread* m_thread;
    SensorSampler* m_sensorSampler;
    bool m_started;
};

}

#endif
